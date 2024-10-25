package paski

import spinal.core._
import spinal.lib.master

case class Gowin_Flash(sysclk : ClockDomain, memclk : ClockDomain) extends BlackBox {
  val io = new Bundle {
    val I_pclk = in Bool()
    val I_presetn = in Bool() 
    val I_paddr = in UInt(32 bits)
    val I_penable = in Bool()
    val O_prdata = out Bits(32 bits)
    val O_pready = out Bool()
    val I_psel = in Bits(1 bit)
    val I_pwdata = in Bits(32 bits)
    val I_pwrite = in Bool()
    val I_spi_clock = in Bool()
    val I_spi_rstn = in Bool()

    val O_flash_ck = out Bool()
    val O_flash_cs_n = out Bool()
    val IO_flash_hold_n = inout(Analog(Bool()))
    val IO_flash_wp_n = inout(Analog(Bool()))
    val IO_flash_do = inout(Analog(Bool()))
    val IO_flash_di = inout(Analog(Bool()))
  }

  def connectFlashInterface(iface: Flash_Interface): Unit = {
    iface.O_flash_ck      :=  io.O_flash_ck 
    iface.O_flash_cs_n    :=  io.O_flash_cs_n 
    iface.IO_flash_hold_n :=  io.IO_flash_hold_n 
    iface.IO_flash_wp_n   :=  io.IO_flash_wp_n 
    iface.IO_flash_do     :=  io.IO_flash_do 
    iface.IO_flash_di     :=  io.IO_flash_di
  }
    noIoPrefix()
    mapClockDomain(sysclk, clock = io.I_pclk, reset = io.I_presetn, resetActiveLevel = LOW)
    mapClockDomain(memclk, clock = io.I_spi_clock, reset = io.I_spi_rstn, resetActiveLevel = LOW)
    setDefinitionName("SPI_Flash_Interface_Top")
}
