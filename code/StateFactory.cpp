#include "StateFactory.h"

#include "PinFactory.h"

State* StateFactory::states[STATES];

void StateFactory::initialize()
{
    // ---------- SYNC TIME ----------
    states[STATE_SYNC_TIME_DISABLED] = new State([&]() {
        // midi

        // led
        PinFactory::get(PIN_LED_SYNC_TIME)->write(LOW); // off
    });

    states[STATE_SYNC_TIME_ENABLED] = new State([&]() {
        // midi

        // led
        PinFactory::get(PIN_LED_SYNC_TIME)->write(HIGH); // on
    });

    states[STATE_SYNC_TIME_DISABLED]->setNextState(states[STATE_SYNC_TIME_ENABLED]);
    states[STATE_SYNC_TIME_ENABLED]->setNextState(states[STATE_SYNC_TIME_DISABLED]);

    // ---------- PRIME NUMBERS ----------
    states[STATE_PRIME_NUMBERS_DISABLED] = new State([&]() {
        // midi

        // led
        PinFactory::get(PIN_LED_PRIME_NUMBERS)->write(LOW); // off
    });

    states[STATE_PRIME_NUMBERS_ENABLED] = new State([&]() {
        // midi

        // led
        PinFactory::get(PIN_LED_PRIME_NUMBERS)->write(HIGH); // on
    });

    states[STATE_PRIME_NUMBERS_DISABLED]->setNextState(states[STATE_PRIME_NUMBERS_ENABLED]);
    states[STATE_PRIME_NUMBERS_ENABLED]->setNextState(states[STATE_PRIME_NUMBERS_DISABLED]);

    // ---------- ECHO 1 ----------
    states[STATE_ECHO_1_TIME] = new State([&]() {
        // midi

        // led
        PinFactory::get(PIN_LED_ECHO_1_NOTE)->write(HIGH); // off
        PinFactory::get(PIN_LED_ECHO_1_TIME)->write(LOW);
    });

    states[STATE_ECHO_1_NOTE] = new State([&]() {
        // midi

        // led
        PinFactory::get(PIN_LED_ECHO_1_NOTE)->write(LOW);
        PinFactory::get(PIN_LED_ECHO_1_TIME)->write(HIGH); // off
    });

    states[STATE_ECHO_1_TIME]->setNextState(states[STATE_ECHO_1_NOTE]);
    states[STATE_ECHO_1_NOTE]->setNextState(states[STATE_ECHO_1_TIME]);

    // ---------- ECHO 2 ----------
    states[STATE_ECHO_2_TIME] = new State([&]() {
        // midi

        // led
        PinFactory::get(PIN_LED_ECHO_2_NOTE)->write(HIGH); // off
        PinFactory::get(PIN_LED_ECHO_2_TIME)->write(LOW);
    });

    states[STATE_ECHO_2_NOTE] = new State([&]() {
        // midi

        // led
        PinFactory::get(PIN_LED_ECHO_2_NOTE)->write(LOW);
        PinFactory::get(PIN_LED_ECHO_2_TIME)->write(HIGH); // off
    });

    states[STATE_ECHO_2_TIME]->setNextState(states[STATE_ECHO_2_NOTE]);
    states[STATE_ECHO_2_NOTE]->setNextState(states[STATE_ECHO_2_TIME]);

    // ---------- MODE ----------
    states[STATE_MODE_PONG] = new State([&]() {
        // midi

        // led
        PinFactory::get(PIN_LED_MODE_PING_PONG)->write(LOW);
        PinFactory::get(PIN_LED_MODE_DUAL)->write(HIGH); // off (for initial state - disabling light on LED)
        PinFactory::get(PIN_LED_MODE_RHYTM)->write(HIGH); // off (for initial state - disabling light on LED)
        PinFactory::get(PIN_LED_MODE_SINGLE)->write(HIGH); // off
    });

    states[STATE_MODE_DUAL] = new State([&]() {
        // midi

        // led
        PinFactory::get(PIN_LED_MODE_DUAL)->write(LOW);
        PinFactory::get(PIN_LED_MODE_PING_PONG)->write(HIGH); // off
    });

    states[STATE_MODE_RHYTM] = new State([&]() {
        // midi

        // led
        PinFactory::get(PIN_LED_MODE_RHYTM)->write(LOW);
        PinFactory::get(PIN_LED_MODE_DUAL)->write(HIGH); // off
    });

    states[STATE_MODE_SINGLE] = new State([&]() {
        // midi

        // led
        PinFactory::get(PIN_LED_MODE_SINGLE)->write(LOW);
        PinFactory::get(PIN_LED_MODE_RHYTM)->write(HIGH); // off
    });

    states[STATE_MODE_PONG]->setNextState(states[STATE_MODE_DUAL]);
    states[STATE_MODE_DUAL]->setNextState(states[STATE_MODE_RHYTM]);
    states[STATE_MODE_RHYTM]->setNextState(states[STATE_MODE_SINGLE]);
    states[STATE_MODE_SINGLE]->setNextState(states[STATE_MODE_PONG]);

    // ---------- BYPASS ----------
    states[STATE_BYPASS_DISABLED] = new State([&]() {
        // midi

        // led
        PinFactory::get(PIN_LED_BYPASS)->write(LOW); // off
    });

    states[STATE_BYPASS_ENABLED] = new State([&]() {
        // midi

        // led
        PinFactory::get(PIN_LED_BYPASS)->write(HIGH); // on
    });

    states[STATE_BYPASS_DISABLED]->setNextState(states[STATE_BYPASS_ENABLED]);
    states[STATE_BYPASS_ENABLED]->setNextState(states[STATE_BYPASS_DISABLED]);

    // ---------- STYLE TAPE ----------
    states[STATE_STYLE_TAPE_DISABLED] = new State([&]() {
        // midi

        // leds
        PinFactory::get(PIN_LED_TAPE_STUDIO)->write(HIGH); // off
        PinFactory::get(PIN_LED_TAPE_CHEAP)->write(HIGH); // off
        PinFactory::get(PIN_LED_TAPE_TUBE)->write(HIGH); // off
        PinFactory::get(PIN_LED_TAPE_MASTER)->write(HIGH); // off
    });

    states[STATE_STYLE_TAPE_STUDIO] = new State([&]() {
        // midi

        // leds
        PinFactory::get(PIN_LED_TAPE_STUDIO)->write(LOW);
        PinFactory::get(PIN_LED_TAPE_CHEAP)->write(HIGH); // off (for initial state - disabling light on LED)
        PinFactory::get(PIN_LED_TAPE_TUBE)->write(HIGH); // off (for initial state - disabling light on LED)
        PinFactory::get(PIN_LED_TAPE_MASTER)->write(HIGH); // off
    });

    states[STATE_STYLE_TAPE_CHEAP] = new State([&]() {
        // midi

        // leds
        PinFactory::get(PIN_LED_TAPE_STUDIO)->write(HIGH); // off
        PinFactory::get(PIN_LED_TAPE_CHEAP)->write(LOW);
    });

    states[STATE_STYLE_TAPE_TUBE] = new State([&]() {
        // midi

        // leds
        PinFactory::get(PIN_LED_TAPE_CHEAP)->write(HIGH); // off
        PinFactory::get(PIN_LED_TAPE_TUBE)->write(LOW);
    });

    states[STATE_STYLE_TAPE_MASTER] = new State([&]() {
        // midi

        // leds
        PinFactory::get(PIN_LED_TAPE_TUBE)->write(HIGH); // off
        PinFactory::get(PIN_LED_TAPE_MASTER)->write(LOW);
    });

    states[STATE_STYLE_TAPE_DISABLED]->setNextState(states[STATE_STYLE_TAPE_STUDIO]);
    states[STATE_STYLE_TAPE_STUDIO]->setNextState(states[STATE_STYLE_TAPE_CHEAP]);
    states[STATE_STYLE_TAPE_CHEAP]->setNextState(states[STATE_STYLE_TAPE_TUBE]);
    states[STATE_STYLE_TAPE_TUBE]->setNextState(states[STATE_STYLE_TAPE_MASTER]);
    states[STATE_STYLE_TAPE_MASTER]->setNextState(states[STATE_STYLE_TAPE_STUDIO]);

    // ---------- STYLE ECHO ----------
    states[STATE_STYLE_ECHO_DISABLED] = new State([&]() {
        // midi

        // leds
        PinFactory::get(PIN_LED_ECHO_PLEX)->write(HIGH); // off
        PinFactory::get(PIN_LED_ECHO_SPACE)->write(HIGH); // off
        PinFactory::get(PIN_LED_ECHO_TEL_RAY)->write(HIGH); // off
        PinFactory::get(PIN_LED_ECHO_BINSONETTE)->write(HIGH); // off
    });

    states[STATE_STYLE_ECHO_PLEX] = new State([&]() {
        // midi

        // leds
        PinFactory::get(PIN_LED_ECHO_PLEX)->write(LOW);
        PinFactory::get(PIN_LED_ECHO_BINSONETTE)->write(HIGH); // off
    });

    states[STATE_STYLE_ECHO_SPACE] = new State([&]() {
        // midi

        // leds
        PinFactory::get(PIN_LED_ECHO_PLEX)->write(HIGH); // off
        PinFactory::get(PIN_LED_ECHO_SPACE)->write(LOW);
    });

    states[STATE_STYLE_ECHO_TEL_RAY] = new State([&]() {
        // midi

        // leds
        PinFactory::get(PIN_LED_ECHO_SPACE)->write(HIGH); // off
        PinFactory::get(PIN_LED_ECHO_TEL_RAY)->write(LOW);
    });

    states[STATE_STYLE_ECHO_BINSONETTE] = new State([&]() {
        // midi

        // leds
        PinFactory::get(PIN_LED_ECHO_TEL_RAY)->write(HIGH); // off
        PinFactory::get(PIN_LED_ECHO_BINSONETTE)->write(LOW);
    });

    states[STATE_STYLE_ECHO_DISABLED]->setNextState(states[STATE_STYLE_ECHO_PLEX]);
    states[STATE_STYLE_ECHO_PLEX]->setNextState(states[STATE_STYLE_ECHO_SPACE]);
    states[STATE_STYLE_ECHO_SPACE]->setNextState(states[STATE_STYLE_ECHO_TEL_RAY]);
    states[STATE_STYLE_ECHO_TEL_RAY]->setNextState(states[STATE_STYLE_ECHO_BINSONETTE]);
    states[STATE_STYLE_ECHO_BINSONETTE]->setNextState(states[STATE_STYLE_ECHO_PLEX]);

    // ---------- STYLE BBD ----------
    states[STATE_STYLE_BBD_DISABLED] = new State([&]() {
        // midi

        // leds
        PinFactory::get(PIN_LED_BBD_MEMORY_MAN)->write(HIGH); // off
        PinFactory::get(PIN_LED_BBD_ANALOG)->write(HIGH); // off
        PinFactory::get(PIN_LED_BBD_AM_RADIO)->write(HIGH); // off
        PinFactory::get(PIN_LED_BBD_DM_2)->write(HIGH); // off
    });

    states[STATE_STYLE_BBD_MEMORY_MAN] = new State([&]() {
        // midi

        // leds
        PinFactory::get(PIN_LED_BBD_MEMORY_MAN)->write(LOW);
        PinFactory::get(PIN_LED_BBD_DM_2)->write(HIGH); // off
    });

    states[STATE_STYLE_BBD_ANALOG] = new State([&]() {
        // midi

        // leds
        PinFactory::get(PIN_LED_BBD_MEMORY_MAN)->write(HIGH); // off
        PinFactory::get(PIN_LED_BBD_ANALOG)->write(LOW);
    });

    states[STATE_STYLE_BBD_AM_RADIO] = new State([&]() {
        // midi

        // leds
        PinFactory::get(PIN_LED_BBD_ANALOG)->write(HIGH); // off
        PinFactory::get(PIN_LED_BBD_AM_RADIO)->write(LOW);
    });

    states[STATE_STYLE_BBD_DM_2] = new State([&]() {
        // midi

        // leds
        PinFactory::get(PIN_LED_BBD_AM_RADIO)->write(HIGH); // off
        PinFactory::get(PIN_LED_BBD_DM_2)->write(LOW);
    });

    states[STATE_STYLE_BBD_DISABLED]->setNextState(states[STATE_STYLE_BBD_MEMORY_MAN]);
    states[STATE_STYLE_BBD_MEMORY_MAN]->setNextState(states[STATE_STYLE_BBD_ANALOG]);
    states[STATE_STYLE_BBD_ANALOG]->setNextState(states[STATE_STYLE_BBD_AM_RADIO]);
    states[STATE_STYLE_BBD_AM_RADIO]->setNextState(states[STATE_STYLE_BBD_DM_2]);
    states[STATE_STYLE_BBD_DM_2]->setNextState(states[STATE_STYLE_BBD_MEMORY_MAN]);

    // ---------- STYLE BIAS ----------
    states[STATE_STYLE_BIAS_DISABLED] = new State([&]() {
        // midi

        // leds
        PinFactory::get(PIN_LED_BIAS_TRANSMITTER)->write(HIGH); // off
        PinFactory::get(PIN_LED_BIAS_DISTORTED)->write(HIGH); // off
        PinFactory::get(PIN_LED_BIAS_SATURATED)->write(HIGH); // off
        PinFactory::get(PIN_LED_BIAS_QUEEKED)->write(HIGH); // off
    });

    states[STATE_STYLE_BIAS_TRANSMITTER] = new State([&]() {
        // midi

        // leds
        PinFactory::get(PIN_LED_BIAS_TRANSMITTER)->write(LOW);
        PinFactory::get(PIN_LED_BIAS_QUEEKED)->write(HIGH); // off
    });

    states[STATE_STYLE_BIAS_DISTORTED] = new State([&]() {
        // midi

        // leds
        PinFactory::get(PIN_LED_BIAS_TRANSMITTER)->write(HIGH); // off
        PinFactory::get(PIN_LED_BIAS_DISTORTED)->write(LOW);
    });

    states[STATE_STYLE_BIAS_SATURATED] = new State([&]() {
        // midi

        // leds
        PinFactory::get(PIN_LED_BIAS_DISTORTED)->write(HIGH); // off
        PinFactory::get(PIN_LED_BIAS_SATURATED)->write(LOW);
    });

    states[STATE_STYLE_BIAS_QUEEKED] = new State([&]() {
        // midi

        // leds
        PinFactory::get(PIN_LED_BIAS_SATURATED)->write(HIGH); // off
        PinFactory::get(PIN_LED_BIAS_QUEEKED)->write(LOW);
    });

    states[STATE_STYLE_BIAS_DISABLED]->setNextState(states[STATE_STYLE_BIAS_TRANSMITTER]);
    states[STATE_STYLE_BIAS_TRANSMITTER]->setNextState(states[STATE_STYLE_BIAS_DISTORTED]);
    states[STATE_STYLE_BIAS_DISTORTED]->setNextState(states[STATE_STYLE_BIAS_SATURATED]);
    states[STATE_STYLE_BIAS_SATURATED]->setNextState(states[STATE_STYLE_BIAS_QUEEKED]);
    states[STATE_STYLE_BIAS_QUEEKED]->setNextState(states[STATE_STYLE_BIAS_TRANSMITTER]);

    // ---------- STYLE CHORUS ----------
    states[STATE_STYLE_CHORUS_DISABLED] = new State([&]() {
        // midi

        // leds
        PinFactory::get(PIN_LED_CHORUS_CE_1)->write(HIGH); // off
        PinFactory::get(PIN_LED_CHORUS_ANALOG)->write(HIGH); // off
        PinFactory::get(PIN_LED_CHORUS_VIBRATO)->write(HIGH); // off
        PinFactory::get(PIN_LED_CHORUS_DIGITAL)->write(HIGH); // off
    });

    states[STATE_STYLE_CHORUS_CE_1] = new State([&]() {
        // midi

        // leds
        PinFactory::get(PIN_LED_CHORUS_CE_1)->write(LOW);
        PinFactory::get(PIN_LED_CHORUS_DIGITAL)->write(HIGH); // off
    });

    states[STATE_STYLE_CHORUS_ANALOG] = new State([&]() {
        // midi

        // leds
        PinFactory::get(PIN_LED_CHORUS_CE_1)->write(HIGH); // off
        PinFactory::get(PIN_LED_CHORUS_ANALOG)->write(LOW);
    });

    states[STATE_STYLE_CHORUS_VIBRATO] = new State([&]() {
        // midi

        // leds
        PinFactory::get(PIN_LED_CHORUS_ANALOG)->write(HIGH); // off
        PinFactory::get(PIN_LED_CHORUS_VIBRATO)->write(LOW);
    });

    states[STATE_STYLE_CHORUS_DIGITAL] = new State([&]() {
        // midi

        // leds
        PinFactory::get(PIN_LED_CHORUS_VIBRATO)->write(HIGH); // off
        PinFactory::get(PIN_LED_CHORUS_DIGITAL)->write(LOW);
    });

    states[STATE_STYLE_CHORUS_DISABLED]->setNextState(states[STATE_STYLE_CHORUS_CE_1]);
    states[STATE_STYLE_CHORUS_CE_1]->setNextState(states[STATE_STYLE_CHORUS_ANALOG]);
    states[STATE_STYLE_CHORUS_ANALOG]->setNextState(states[STATE_STYLE_CHORUS_VIBRATO]);
    states[STATE_STYLE_CHORUS_VIBRATO]->setNextState(states[STATE_STYLE_CHORUS_DIGITAL]);
    states[STATE_STYLE_CHORUS_DIGITAL]->setNextState(states[STATE_STYLE_CHORUS_CE_1]);

    // ---------- STYLE ATMO ----------
    states[STATE_STYLE_ATMO_DISABLED] = new State([&]() {
        // midi

        // leds
        PinFactory::get(PIN_LED_ATMO_AMBIENT)->write(HIGH); // off
        PinFactory::get(PIN_LED_ATMO_VERBED)->write(HIGH); // off
        PinFactory::get(PIN_LED_ATMO_DIFFUSED)->write(HIGH); // off
        PinFactory::get(PIN_LED_ATMO_SPLATTERED)->write(HIGH); // off
    });

    states[STATE_STYLE_ATMO_AMBIENT] = new State([&]() {
        // midi

        // leds
        PinFactory::get(PIN_LED_ATMO_AMBIENT)->write(LOW);
        PinFactory::get(PIN_LED_ATMO_SPLATTERED)->write(HIGH); // off
    });

    states[STATE_STYLE_ATMO_VERBED] = new State([&]() {
        // midi

        // leds
        PinFactory::get(PIN_LED_ATMO_AMBIENT)->write(HIGH); // off
        PinFactory::get(PIN_LED_ATMO_VERBED)->write(LOW);
    });

    states[STATE_STYLE_ATMO_DIFFUSED] = new State([&]() {
        // midi

        // leds
        PinFactory::get(PIN_LED_ATMO_VERBED)->write(HIGH); // off
        PinFactory::get(PIN_LED_ATMO_DIFFUSED)->write(LOW);
    });

    states[STATE_STYLE_ATMO_SPLATTERED] = new State([&]() {
        // midi

        // leds
        PinFactory::get(PIN_LED_ATMO_DIFFUSED)->write(HIGH); // off
        PinFactory::get(PIN_LED_ATMO_SPLATTERED)->write(LOW);
    });

    states[STATE_STYLE_ATMO_DISABLED]->setNextState(states[STATE_STYLE_ATMO_AMBIENT]);
    states[STATE_STYLE_ATMO_AMBIENT]->setNextState(states[STATE_STYLE_ATMO_VERBED]);
    states[STATE_STYLE_ATMO_VERBED]->setNextState(states[STATE_STYLE_ATMO_DIFFUSED]);
    states[STATE_STYLE_ATMO_DIFFUSED]->setNextState(states[STATE_STYLE_ATMO_SPLATTERED]);
    states[STATE_STYLE_ATMO_SPLATTERED]->setNextState(states[STATE_STYLE_ATMO_AMBIENT]);
}

State* StateFactory::get(int key)
{
    return states[key];
}
