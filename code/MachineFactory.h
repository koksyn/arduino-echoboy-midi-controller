#ifndef MACHINE_FACTORY_H
#define MACHINE_FACTORY_H

#include "Machine.h"

#define MACHINE_SYNC_TIME     0
#define MACHINE_PRIME_NUMBERS 1
#define MACHINE_ECHO_1        2
#define MACHINE_ECHO_2        3
#define MACHINE_MODE          4
#define MACHINE_BYPASS        5
#define MACHINE_STYLE_TAPE    6
#define MACHINE_STYLE_ECHO    7
#define MACHINE_STYLE_BBD     8
#define MACHINE_STYLE_BIAS    9
#define MACHINE_STYLE_CHORUS  10
#define MACHINE_STYLE_ATMO    11

// AMOUNT OF MACHINES
#define MACHINES 12

class MachineFactory {
private:
    static Machine* machines[MACHINES];
public:
    static void initialize();
    static Machine* get(uint8_t key);
};

#endif
