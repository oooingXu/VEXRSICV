package paski 

import spinal.core._
import spinal.lib.IMasterSlave

case class DDR3_Interface() extends Bundle with IMasterSlave {

  val O_ddr_addr = Bits(13 bits)
  val O_ddr_ba = Bits(3 bits)
  val O_ddr_cs_n = Bool()
  val O_ddr_ras_n = Bool()
  val O_ddr_cas_n = Bool()
  val O_ddr_we_n = Bool()
  val O_ddr_clk = Bool()
  val O_ddr_clk_n = Bool()
  val O_ddr_cke = Bool()
  val O_ddr_odt = Bool()
  val O_ddr_reset_n = Bool()
  val O_ddr_dqm = Bits(2 bits)
  val pll_stop = Bool() //out define
  val pll_lock = Bool() //
  val IO_ddr_dq = Analog(Bits(16 bits))    /* wxz */
  val IO_ddr_dqs = Analog(Bits(2 bits))    /* wxz */
  val IO_ddr_dqs_n = Analog(Bits(2 bits))  /* wxz */

  override def asMaster() : Unit = {
    out(O_ddr_addr, O_ddr_ba, O_ddr_cs_n, O_ddr_ras_n, O_ddr_cas_n, O_ddr_we_n, O_ddr_clk, O_ddr_clk_n, O_ddr_cke, O_ddr_odt, O_ddr_reset_n, O_ddr_dqm,pll_stop)
    //inout(Analog(16 bits)) /* wxz */
    //inout(Analog(2 bits))  /* wxz */
    //inout(Analog(2 bits))  /* wxz */
    in(pll_lock)
    inout(IO_ddr_dq, IO_ddr_dqs, IO_ddr_dqs_n)
  }

}
