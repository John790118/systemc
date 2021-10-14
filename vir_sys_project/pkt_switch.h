
#ifndef _PKT_SWITCH_H_
#define _PKT_SWITCH_H_

#include "systemc.h"
#include "pkt.h"

struct pkt_switch : sc_module 
{
    sc_in_clk   clock1;
    sc_in<pkt>  in0;
    sc_out<pkt>  out0;

    SC_CTOR(pkt_switch) 
     {
      SC_THREAD(pkt_switch_prc);
      sensitive << in0;
      sensitive << clock1.pos();
    }  

  void pkt_switch_prc();  
 
};
#endif // _PKT_SWITCH_H_
