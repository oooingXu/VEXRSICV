package paski 

import spinal.core._
import spinal.lib.IMasterSlave

case class Flash_Interface() extends Bundle with IMasterSlave {

  val O_flash_ck = Bool()
  val O_flash_cs_n = Bool()
  val IO_flash_hold_n = Analog(Bool())
  val IO_flash_wp_n = Analog(Bool())
  val IO_flash_do = Analog(Bool())
  val IO_flash_di = Analog(Bool())

  override def asMaster() : Unit = {
    out(O_flash_ck, O_flash_cs_n)
    //inout(Analog(16 bits)) /* wxz */
    //inout(Analog(2 bits))  /* wxz */
    //inout(Analog(2 bits))  /* wxz */
    inout(IO_flash_hold_n, IO_flash_wp_n, IO_flash_do, IO_flash_di)
  }

}
