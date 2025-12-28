//
// Created by wikto on 26/12/2025.
//

#include "IR.h"

IR::IR(int p, volatile bool &b) : pin(p), buffor(b){
}


int IR::read() {
    if(buffor){ //if the buffor was set by the ISR
        buffor = false; //reset it
        return 1;
    }
    return 0;
}