package scala.virtualization.lms
package internal

import util.OverloadHack
import scala.collection.{immutable,mutable}
import scala.reflect.SourceContext
import scala.virtualization.lms.common.WorklistTransformer

trait AbstractTransformer {
  val IR: Expressions with Blocks with OverloadHack
  import IR._
  
  def hasContext = false
  def reflectBlock[A](xs: Block[A]): Exp[A] = sys.error("reflectBlock not supported by context-free transformers")
  
  def apply[A](x: Exp[A]): Exp[A]
  def apply[A:Manifest](xs: Block[A]): Block[A] = {
    // should be overridden by transformers with context
    assert(!hasContext) 
    Block(apply(xs.res)) 
  }
  def apply[A](xs: List[Exp[A]]): List[Exp[A]] = xs map (e => apply(e))
  def apply[A](xs: Seq[Exp[A]]): Seq[Exp[A]] = xs map (e => apply(e))
  def apply[X,A](f: X=>Exp[A]): X=>Exp[A] = (z:X) => apply(f(z))
  def apply[X,Y,A](f: (X,Y)=>Exp[A]): (X,Y)=>Exp[A] = (z1:X,z2:Y) => apply(f(z1,z2))
  //def apply[A](xs: Summary): Summary = xs //TODO
  def onlySyms[A](xs: List[Sym[A]]): List[Sym[A]] = xs map (e => apply(e)) collect { case e: Sym[A] => e }
  
}

trait AbstractSubstTransformer extends AbstractTransformer {
  import IR._
  var subst = immutable.Map.empty[Exp[Any], Exp[Any]]
  
  def withSubstScope[A](extend: (Exp[Any],Exp[Any])*)(block: => A): A = 
    withSubstScope {
      subst ++= extend
      block
    }

  def withSubstScope[A](block: => A): A = {
    val save = subst
    val r = block
    subst = save
    r
  }

  // TBD: should this be transitive or not? see note in ForwardTransformer
  def apply[A](x: Exp[A]): Exp[A] = subst.get(x) match { 
    case Some(y) if y != x => apply(y.asInstanceOf[Exp[A]]) case _ => x 
  }
}


trait Transforming extends Expressions with Blocks with OverloadHack {
  self => 
  
  /*abstract class Transformer extends AbstractTransformer { // a polymorphic function, basically...
    val IR: self.type = self    
  }*/

  type Transformer = AbstractTransformer { val IR: self.type }

  class SubstTransformer extends /*AbstractSubstTransformer*/ AbstractTransformer { val IR: self.type = self 
    val subst = new mutable.HashMap[Exp[Any], Exp[Any]]
    def apply[A](x: Exp[A]): Exp[A] = subst.get(x) match { 
      case Some(y) if y != x => apply(y.asInstanceOf[Exp[A]]) case _ => x 
    }
  }

  /*object IdentityTransformer extends Transformer {
    def apply[A](x: Exp[A]) = x
  }*/

  // FIXME: mirroring for effects!

  def mtype[A,B](m:Manifest[A]): Manifest[B] = m.asInstanceOf[Manifest[B]] // hack: need to pass explicit manifest during mirroring
  def mpos(s: List[SourceContext]): SourceContext = if (s.nonEmpty) s.head else implicitly[SourceContext] // hack: got list of pos but need to pass single pos to mirror

  
  
  def mirror[A:Manifest](e: Def[A], f: Transformer)(implicit pos: SourceContext): Exp[A] = mirrorDef(e,f)

  def mirrorDef[A:Manifest](e: Def[A], f: Transformer)(implicit pos: SourceContext): Def[A] = sys.error("don't know how to mirror " + e)

  def mirrorFatDef[A:Manifest](e: Def[A], f: Transformer)(implicit pos: SourceContext): Def[A] = sys.error("don't know how to mirror " + e) //hm...
  
}


trait FatTransforming extends Transforming with FatExpressions {
  
  override def mirror[A:Manifest](e: Def[A], f: Transformer)(implicit pos: SourceContext): Exp[A] = (e match {
    case Forward(x) => toAtom(Forward(f(x)))(mtype(manifest[A]),pos)
    case _ => super.mirror(e,f)
  }).asInstanceOf[Exp[A]] 
  
  //def mirror[A:Manifest](e: FatDef, f: Transformer): Exp[A] = sys.error("don't know how to mirror " + e)  
  
}

/* Lewis: adapted from LMS TestWorklistTransform2.scala */
trait LoweringTransform extends FatTransforming with Effects { self =>  
  trait LoweringTransformer extends WorklistTransformer { val IR: self.type = self }

  // ---------- Exp api
  implicit def toAfter[A:Manifest](x: Def[A]) = new { def atPhase(t: LoweringTransformer)(y: => Exp[A]) = transformAtPhase(x)(t)(y) }
  implicit def toAfter[A](x: Exp[A]) = new { def atPhase(t: LoweringTransformer)(y: => Exp[A]) = transformAtPhase(x)(t)(y) }

  // transform x to y at the *next* iteration of t. 
  // note: if t is currently active, it will continue the current pass with x = x.
  // do we need a variant that replaces x -> y immediately if t is active?
  def transformAtPhase[A](x: Exp[A])(t: LoweringTransformer)(y: => Exp[A]): Exp[A] = {
    t.register(x)(y)
    x
  }
    
  def onCreate[A:Manifest](s: Sym[A], d: Def[A]): Exp[A] = s
  
  override def createDefinition[T](s: Sym[T], d: Def[T]): Stm = {
    onCreate(s,d)(s.tp)
    super.createDefinition(s,d)
  }
}
