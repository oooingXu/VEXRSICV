package millbuild

import _root_.mill.runner.MillBuildRootModule

@scala.annotation.nowarn
object MiscInfo_build {
  implicit lazy val millBuildRootModuleInfo: _root_.mill.runner.MillBuildRootModule.Info = _root_.mill.runner.MillBuildRootModule.Info(
    Vector("/home/romeo/VEXRSICV/VexRiscv/out/mill-launcher/0.11.12.jar").map(_root_.os.Path(_)),
    _root_.os.Path("/home/romeo/VEXRSICV/VexRiscv"),
    _root_.os.Path("/home/romeo/VEXRSICV/VexRiscv"),
  )
  implicit lazy val millBaseModuleInfo: _root_.mill.main.RootModule.Info = _root_.mill.main.RootModule.Info(
    millBuildRootModuleInfo.projectRoot,
    _root_.mill.define.Discover[build]
  )
}
import MiscInfo_build.{millBuildRootModuleInfo, millBaseModuleInfo}
object build extends build
class build extends _root_.mill.main.RootModule {

//MILL_ORIGINAL_FILE_PATH=/home/romeo/VEXRSICV/VexRiscv/build.sc
//MILL_USER_CODE_START_MARKER
import mill._, scalalib._

val spinalVersion = "1.10.1"

object ivys {
  val sv = "2.11.12"
  val spinalCore = ivy"com.github.spinalhdl::spinalhdl-core:$spinalVersion"
  val spinalLib = ivy"com.github.spinalhdl::spinalhdl-lib:$spinalVersion"
  val spinalPlugin = ivy"com.github.spinalhdl::spinalhdl-idsl-plugin:$spinalVersion"
  val scalatest = ivy"org.scalatest::scalatest:3.2.5"
  val macroParadise = ivy"org.scalamacros:::paradise:2.1.1"
  val yaml = ivy"org.yaml:snakeyaml:1.8"
}

trait Common extends ScalaModule  {
  override def scalaVersion = ivys.sv
  override def scalacPluginIvyDeps = Agg(ivys.macroParadise, ivys.spinalPlugin)
  override def ivyDeps = Agg(ivys.spinalCore, ivys.spinalLib, ivys.yaml, ivys.scalatest)
  override def scalacOptions = Seq("-Xsource:2.11")
}

object VexRiscv extends Common with SbtModule{
  override def millSourcePath = os.pwd
  override def moduleDeps: Seq[JavaModule] = super.moduleDeps

  object test extends SbtModuleTests with TestModule.ScalaTest
}


}