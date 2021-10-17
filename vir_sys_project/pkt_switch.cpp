
#include "systemc.h"
#include "pkt.h"
#include "pkt_switch.h"
#include "fifo.h"
#define SIM_NUM 500

void pkt_switch :: pkt_switch_prc()
{
  wait();

//  int sim_count;
  int pkt_count;
  int drop_count;

  fifo q0_in;

  fifo q0_out;

  // initialization
  pkt_count = 0;
  drop_count = 0;
//  sim_count  = 0;

  q0_in.pntr = 0;
  q0_in.full  = false;
  q0_in.empty = true;
  q0_out.pntr = 0;
  q0_out.full = false;
  q0_out.empty = true;
  
  wait();
  // functionality
//  while( sim_count++ < SIM_NUM )
  while(1)
    { 
      wait();

      /////read input packets//////////////////////////////////     
      if (in0.event()) 
      {
        pkt_count++;
	      if (q0_in.full == true) drop_count++;
          else q0_in.pkt_in(in0.read());
      };

//      if((bool)switch_cntrl && switch_cntrl.event())
      if(clock1 && clock1.event())
	    {
	      /////write the register values to output fifos////////////
        if ((!q0_out.full)&&(!q0_in.empty))
        {
          q0_out.pkt_in(q0_in.pkt_out());
        }

	    /////write the packets out//////////////////////////////////    
	    if (!q0_out.empty) out0.write(q0_out.pkt_out()); 
	    }
    } 

//  sc_stop();

  cout << endl << endl << "-------------------------------------------------------------------------------" << endl;
  cout << "End of switch operation..." << endl;
  cout << "Total number of packets received: " <<  pkt_count << endl;
  cout << "Total number of packets dropped: " <<  drop_count << endl;
  cout << "Percentage packets dropped:  " <<  drop_count*100/pkt_count << endl;
  cout << "-------------------------------------------------------------------------------" << endl;
  
}
