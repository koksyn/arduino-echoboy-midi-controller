#ifndef MACHINE_FACTORY_H
#define MACHINE_FACTORY_H

#include "Machine.h"

#define MACHINE_SYNC_TIME 0

// AMOUNT OF MACHINES
#define MACHINES 1

class MachineFactory {
private:
    static Machine* machines[MACHINES];
public:
    static void initialize();
    static Machine* get(int key);
};

#endif
