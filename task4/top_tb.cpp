#include "Vtop.h"
#include "verilated.h" 
#include "verilated_vcd_c.h"


int main(int argc, char **argv, char **env) {
    int i;
    int clk; 
    
    Verilated::commandArgs(argc, argv);
    // init top verilog instance
    Vtop* top = new Vtop;
    // init trace dump
    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC;

    top->trace (tfp, 99); 
    tfp->open ("counter.vcd"); 

    top->en = 1;
    // initialize simulation inputs
    top->clk = 1;
    top->rst = 1;



// run simulation for many clock cycles thmisflmfonh

    for (int i = 0; i < 3000; i++){
        for (clk=0; clk<2; clk++) {
            tfp->dump (2*i+clk); // unit is in p5!!!
            top->clk = !top->clk;
            top->eval ();
        } 





        top->rst = (i<2)|(i==15);
        //top->en = (i>4);


        if (Verilated::gotFinish()) exit(0);
    }

        

    tfp->close();
    exit(0);
}