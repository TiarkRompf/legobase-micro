import sbt._

object MyBuild extends Build {
  // Declare a project in the root directory of the build with ID "root".
  // Declare an execution dependency on sub1.
  lazy val root = Project("root", file(".")) dependsOn(sub2 % "compile")

  System.setProperty("showSuppressedErrors", "false")

  // Declare a project with ID 'sub2' in directory 'b'.
  // Declare a configuration dependency on the root project.
  lazy val sub2: ProjectRef = ProjectRef(file("../lms-mod"), "LMS")
}
