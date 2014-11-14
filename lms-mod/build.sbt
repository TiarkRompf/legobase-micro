name := "LMS"

version := "0.3-SNAPSHOT"

organization := "EPFL"

scalaSource in Compile <<= baseDirectory(_ / "src")

scalaSource in Test <<= baseDirectory(_ / "test-src")

libraryDependencies += scalaTest

// tests are not thread safe
parallelExecution in Test := false

// disable publishing of main docs
publishArtifact in (Compile, packageDoc) := false

// continuations
autoCompilerPlugins := true

addCompilerPlugin("org.scala-lang.virtualized.plugins" % "continuations" % virtScala)

scalacOptions += "-P:continuations:enable"

testGrouping <<= definedTests in Test map { tests =>
  tests.map { test =>
    import Tests._
    new Group(
      name = test.name,
      tests = Seq(test),
      runPolicy = InProcess)
  }.sortWith(_.name < _.name)
}

//***************************************************************************************/
// Compiling option 1 : Default inlinining and scala virtualized						*/
//***************************************************************************************/

scalaOrganization := "org.scala-lang.virtualized"

scalaVersion := "2.10.2"

scalacOptions += "-optimise"

//scalacOptions += "-Yvirtualize"

scalacOptions += "-language:postfixOps"

// needed for scala.tools, which is apparently not included in sbt's built in version
libraryDependencies += "org.scala-lang.virtualized" % "scala-library" % virtScala

libraryDependencies += "org.scala-lang.virtualized" % "scala-compiler" % virtScala

libraryDependencies += "org.scala-lang" % "scala-actors" % virtScala // for ScalaTest

//***************************************************************************************/
// Compiling option 2 : Patched scala compiler as specified in ScalaCompilerPatches.txt */
//***************************************************************************************/

// scalaHome := Some(file("patched-scala/build/pack"))

// unmanagedBase <<= baseDirectory { base => base / "patched-scala/build/pack" }

// unmanagedJars in Compile <<= baseDirectory map { base => (base ** "*.jar").classpath }
