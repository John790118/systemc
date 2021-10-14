

#ifndef __PKT_RECEIVER_H__
#define __PKT_RECEIVER_H__

#include "systemc.h"
#include "pkt.h"

struct pkt_receiver: sc_module
{
  sc_in<pkt> pkt_in;
  int first;
  SC_CTOR(pkt_receiver)
  {
    SC_THREAD(pkt_receiver_prc);
    dont_initialize();
    sensitive << pkt_in;
    first = 1;
  }
  void pkt_receiver_prc();
};

#endif// _PKT_RECEIVER_H_