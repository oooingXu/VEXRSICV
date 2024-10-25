package paski 

import spinal.core._
import spinal.lib.bus.amba3.apb.{Apb3, Apb3Config} 
import spinal.lib.io.InOutWrapper
import spinal.lib.{master, slave}

object Generate_Paski_GowinFlashCompatible {
  def main(args: Array[String]) {
    SpinalVerilog(
      InOutWrapper(
        Paski_GowinFlash_Compatible(
          ClockDomain.external("sys_clk", config = ClockDomainConfig(resetKind = ASYNC, resetActiveLevel = LOW)),
          ClockDomain.external("mem_clk", config = ClockDomainConfig(resetKind = ASYNC, resetActiveLevel = LOW))
        )
      )
    ).printPruned()
  }
}

case class Paski_GowinFlash_Compatible(sys_clk: ClockDomain, mem_clk: ClockDomain) extends Component{
  val inst = Paski_GowinFlash(sys_clk, mem_clk)
  val apbConfig = inst.apbConfig

  val io = new Bundle() {
    val apb = slave(Apb3(apbConfig))
    val flash_iface = master(Flash_Interface())
  }

  val sys_area = new ClockingArea(sys_clk) {
    inst.io.apb << io.apb
    io.flash_iface := inst.io.flash_iface
  }
}

case class Paski_GowinFlash(sys_clk: ClockDomain, mem_clk: ClockDomain) extends Component{

  val gowin_Flash = Gowin_Flash(
    sys_clk,
    mem_clk
  )

  val apbConfig = Apb3Config(
    addressWidth = 24,
    dataWidth = 32,
    useSlaveError = false
  )

  val io = new Bundle() {
    val apb = slave(Apb3(apbConfig))
    val flash_iface = master(Flash_Interface())
  }

  val sys_area = new ClockingArea(sys_clk) {
    
    gowin_Flash.io.I_paddr := io.apb.PADDR.resize(32)
    gowin_Flash.io.I_penable := io.apb.PENABLE 
    io.apb.PRDATA := gowin_Flash.io.O_prdata
    io.apb.PREADY := gowin_Flash.io.O_pready
    gowin_Flash.io.I_psel := io.apb.PSEL
    gowin_Flash.io.I_pwdata := io.apb.PWDATA
    gowin_Flash.io.I_pwrite := io.apb.PWRITE

    gowin_Flash.connectFlashInterface(io.flash_iface)
  }

}
