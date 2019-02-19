#include "MachineFactory.h"

#include "StateFactory.h"

Machine* MachineFactory::machines[MACHINES];

void MachineFactory::initialize()
{
    machines[MACHINE_SYNC_TIME] = new Machine(StateFactory::get(STATE_SYNC_TIME_DISABLED));
    machines[MACHINE_PRIME_NUMBERS] = new Machine(StateFactory::get(STATE_PRIME_NUMBERS_DISABLED));

    machines[MACHINE_ECHO_1] = new Machine(StateFactory::get(STATE_ECHO_1_NOTE));
    machines[MACHINE_ECHO_2] = new Machine(StateFactory::get(STATE_ECHO_2_NOTE));

    machines[MACHINE_MODE] = new Machine(StateFactory::get(STATE_MODE_PONG));
    machines[MACHINE_BYPASS] = new Machine(StateFactory::get(STATE_BYPASS_DISABLED));

    // Only one Style active
    machines[MACHINE_STYLE_TAPE] = new Machine(StateFactory::get(STATE_STYLE_TAPE_STUDIO));

    // Rest styles disabled
    machines[MACHINE_STYLE_ECHO] = new Machine(StateFactory::get(STATE_STYLE_ECHO_DISABLED));
    machines[MACHINE_STYLE_BBD] = new Machine(StateFactory::get(STATE_STYLE_BBD_DISABLED));
    machines[MACHINE_STYLE_BIAS] = new Machine(StateFactory::get(STATE_STYLE_BIAS_DISABLED));
    machines[MACHINE_STYLE_CHORUS] = new Machine(StateFactory::get(STATE_STYLE_CHORUS_DISABLED));
    machines[MACHINE_STYLE_ATMO] = new Machine(StateFactory::get(STATE_STYLE_ATMO_DISABLED));
}

Machine* MachineFactory::get(int key)
{
    return machines[key];
}
