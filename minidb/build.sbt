scalaOrganization := "org.scala-lang.virtualized"

scalaVersion := "2.11.2"

//libraryDependencies += "EPFL" %% "lms" % "0.3-SNAPSHOT"

scalacOptions += "-language:postfixOps"

scalacOptions += "-language:implicitConversions"

scalacOptions += "-deprecation"

//scalacOptions += "-Ystatistics"


//scalacOptions += "-optimise"

//scalacOptions += "-Yinline-warnings"

//scalacOptions += "-Yvirtualize"

unmanagedJars in Compile <<= baseDirectory map { base => (base ** "*.jar").classpath }
