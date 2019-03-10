#include "StateFactory.h"

#include "PinFactory.h"

State* StateFactory::states[STATES];

void StateFactory::initialize()
{
    // ---------- SYNC TIME ----------
    states[STATE_SYNC_TIME_DISABLED] = new State([&]() {
        // midi

        // led
        PinFactory::get(PIN_LED_SYNC_TIME)->off();
    });

    states[STATE_SYNC_TIME_ENABLED] = new State([&]() {
        // midi

        // led
        PinFactory::get(PIN_LED_SYNC_TIME)->on();
    });

    states[STATE_SYNC_TIME_DISABLED]->setNextState(states[STATE_SYNC_TIME_ENABLED]);
    states[STATE_SYNC_TIME_ENABLED]->setNextState(states[STATE_SYNC_TIME_DISABLED]);

    // ---------- PRIME NUMBERS ----------
    states[STATE_PRIME_NUMBERS_DISABLED] = new State([&]() {
        // midi

        // led
        PinFactory::get(PIN_LED_PRIME_NUMBERS)->off();
    });

    states[STATE_PRIME_NUMBERS_ENABLED] = new State([&]() {
        // midi

        // led
        PinFactory::get(PIN_LED_PRIME_NUMBERS)->on();
    });

    states[STATE_PRIME_NUMBERS_DISABLED]->setNextState(states[STATE_PRIME_NUMBERS_ENABLED]);
    states[STATE_PRIME_NUMBERS_ENABLED]->setNextState(states[STATE_PRIME_NUMBERS_DISABLED]);

    // ---------- ECHO 1 ----------
    states[STATE_ECHO_1_TIME] = new State([&]() {
        // midi

        // led
        PinFactory::get(PIN_LED_ECHO_1_NOTE)->off();
        PinFactory::get(PIN_LED_ECHO_1_TIME)->on();
    });

    states[STATE_ECHO_1_NOTE] = new State([&]() {
        // midi

        // led
        PinFactory::get(PIN_LED_ECHO_1_NOTE)->on();
        PinFactory::get(PIN_LED_ECHO_1_TIME)->off();
    });

    states[STATE_ECHO_1_TIME]->setNextState(states[STATE_ECHO_1_NOTE]);
    states[STATE_ECHO_1_NOTE]->setNextState(states[STATE_ECHO_1_TIME]);

    // ---------- ECHO 2 ----------
    states[STATE_ECHO_2_TIME] = new State([&]() {
        // midi

        // led
        PinFactory::get(PIN_LED_ECHO_2_NOTE)->off();
        PinFactory::get(PIN_LED_ECHO_2_TIME)->on();
    });

    states[STATE_ECHO_2_NOTE] = new State([&]() {
        // midi

        // led
        PinFactory::get(PIN_LED_ECHO_2_NOTE)->on();
        PinFactory::get(PIN_LED_ECHO_2_TIME)->off();
    });

    states[STATE_ECHO_2_TIME]->setNextState(states[STATE_ECHO_2_NOTE]);
    states[STATE_ECHO_2_NOTE]->setNextState(states[STATE_ECHO_2_TIME]);

    // ---------- MODE ----------
    states[STATE_MODE_PONG] = new State([&]() {
        // midi

        // led
        PinFactory::get(PIN_LED_MODE_PING_PONG)->on();
        PinFactory::get(PIN_LED_MODE_SINGLE)->off();
    });

    states[STATE_MODE_DUAL] = new State([&]() {
        // midi

        // led
        PinFactory::get(PIN_LED_MODE_DUAL)->on();
        PinFactory::get(PIN_LED_MODE_PING_PONG)->off();
    });

    states[STATE_MODE_RHYTM] = new State([&]() {
        // midi

        // led
        PinFactory::get(PIN_LED_MODE_RHYTM)->on();
        PinFactory::get(PIN_LED_MODE_DUAL)->off();
    });

    states[STATE_MODE_SINGLE] = new State([&]() {
        // midi

        // led
        PinFactory::get(PIN_LED_MODE_SINGLE)->on();
        PinFactory::get(PIN_LED_MODE_RHYTM)->off();
    });

    states[STATE_MODE_PONG]->setNextState(states[STATE_MODE_DUAL]);
    states[STATE_MODE_DUAL]->setNextState(states[STATE_MODE_RHYTM]);
    states[STATE_MODE_RHYTM]->setNextState(states[STATE_MODE_SINGLE]);
    states[STATE_MODE_SINGLE]->setNextState(states[STATE_MODE_PONG]);

    // ---------- BYPASS ----------
    states[STATE_BYPASS_DISABLED] = new State([&]() {
        // midi

        // led
        PinFactory::get(PIN_LED_BYPASS)->off();
    });

    states[STATE_BYPASS_ENABLED] = new State([&]() {
        // midi

        // led
        PinFactory::get(PIN_LED_BYPASS)->on();
    });

    states[STATE_BYPASS_DISABLED]->setNextState(states[STATE_BYPASS_ENABLED]);
    states[STATE_BYPASS_ENABLED]->setNextState(states[STATE_BYPASS_DISABLED]);

    // ---------- STYLE TAPE ----------
    states[STATE_STYLE_TAPE_DISABLED] = new State([&]() {
        // midi

        // leds
        PinFactory::get(PIN_LED_TAPE_STUDIO)->off();
        PinFactory::get(PIN_LED_TAPE_CHEAP)->off();
        PinFactory::get(PIN_LED_TAPE_TUBE)->off();
        PinFactory::get(PIN_LED_TAPE_MASTER)->off();
    });

    states[STATE_STYLE_TAPE_STUDIO] = new State([&]() {
        // midi

        // leds
        PinFactory::get(PIN_LED_TAPE_STUDIO)->on();
        PinFactory::get(PIN_LED_TAPE_MASTER)->off();
    });

    states[STATE_STYLE_TAPE_CHEAP] = new State([&]() {
        // midi

        // leds
        PinFactory::get(PIN_LED_TAPE_STUDIO)->off();
        PinFactory::get(PIN_LED_TAPE_CHEAP)->on();
    });

    states[STATE_STYLE_TAPE_TUBE] = new State([&]() {
        // midi

        // leds
        PinFactory::get(PIN_LED_TAPE_CHEAP)->off();
        PinFactory::get(PIN_LED_TAPE_TUBE)->on();
    });

    states[STATE_STYLE_TAPE_MASTER] = new State([&]() {
        // midi

        // leds
        PinFactory::get(PIN_LED_TAPE_TUBE)->off();
        PinFactory::get(PIN_LED_TAPE_MASTER)->on();
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
        PinFactory::get(PIN_LED_ECHO_PLEX)->off();
        PinFactory::get(PIN_LED_ECHO_SPACE)->off();
        PinFactory::get(PIN_LED_ECHO_TEL_RAY)->off();
        PinFactory::get(PIN_LED_ECHO_BINSONETTE)->off();
    });

    states[STATE_STYLE_ECHO_PLEX] = new State([&]() {
        // midi

        // leds
        PinFactory::get(PIN_LED_ECHO_PLEX)->on();
        PinFactory::get(PIN_LED_ECHO_BINSONETTE)->off();
    });

    states[STATE_STYLE_ECHO_SPACE] = new State([&]() {
        // midi

        // leds
        PinFactory::get(PIN_LED_ECHO_PLEX)->off();
        PinFactory::get(PIN_LED_ECHO_SPACE)->on();
    });

    states[STATE_STYLE_ECHO_TEL_RAY] = new State([&]() {
        // midi

        // leds
        PinFactory::get(PIN_LED_ECHO_SPACE)->off();
        PinFactory::get(PIN_LED_ECHO_TEL_RAY)->on();
    });

    states[STATE_STYLE_ECHO_BINSONETTE] = new State([&]() {
        // midi

        // leds
        PinFactory::get(PIN_LED_ECHO_TEL_RAY)->off();
        PinFactory::get(PIN_LED_ECHO_BINSONETTE)->on();
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
        PinFactory::get(PIN_LED_BBD_MEMORY_MAN)->off();
        PinFactory::get(PIN_LED_BBD_ANALOG)->off();
        PinFactory::get(PIN_LED_BBD_AM_RADIO)->off();
        PinFactory::get(PIN_LED_BBD_DM_2)->off();
    });

    states[STATE_STYLE_BBD_MEMORY_MAN] = new State([&]() {
        // midi

        // leds
        PinFactory::get(PIN_LED_BBD_MEMORY_MAN)->on();
        PinFactory::get(PIN_LED_BBD_DM_2)->off();
    });

    states[STATE_STYLE_BBD_ANALOG] = new State([&]() {
        // midi

        // leds
        PinFactory::get(PIN_LED_BBD_MEMORY_MAN)->off();
        PinFactory::get(PIN_LED_BBD_ANALOG)->on();
    });

    states[STATE_STYLE_BBD_AM_RADIO] = new State([&]() {
        // midi

        // leds
        PinFactory::get(PIN_LED_BBD_ANALOG)->off();
        PinFactory::get(PIN_LED_BBD_AM_RADIO)->on();
    });

    states[STATE_STYLE_BBD_DM_2] = new State([&]() {
        // midi

        // leds
        PinFactory::get(PIN_LED_BBD_AM_RADIO)->off();
        PinFactory::get(PIN_LED_BBD_DM_2)->on();
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
        PinFactory::get(PIN_LED_BIAS_TRANSMITTER)->off();
        PinFactory::get(PIN_LED_BIAS_DISTORTED)->off();
        PinFactory::get(PIN_LED_BIAS_SATURATED)->off();
        PinFactory::get(PIN_LED_BIAS_QUEEKED)->off();
    });

    states[STATE_STYLE_BIAS_TRANSMITTER] = new State([&]() {
        // midi

        // leds
        PinFactory::get(PIN_LED_BIAS_TRANSMITTER)->on();
        PinFactory::get(PIN_LED_BIAS_QUEEKED)->off();
    });

    states[STATE_STYLE_BIAS_DISTORTED] = new State([&]() {
        // midi

        // leds
        PinFactory::get(PIN_LED_BIAS_TRANSMITTER)->off();
        PinFactory::get(PIN_LED_BIAS_DISTORTED)->on();
    });

    states[STATE_STYLE_BIAS_SATURATED] = new State([&]() {
        // midi

        // leds
        PinFactory::get(PIN_LED_BIAS_DISTORTED)->off();
        PinFactory::get(PIN_LED_BIAS_SATURATED)->on();
    });

    states[STATE_STYLE_BIAS_QUEEKED] = new State([&]() {
        // midi

        // leds
        PinFactory::get(PIN_LED_BIAS_SATURATED)->off();
        PinFactory::get(PIN_LED_BIAS_QUEEKED)->on();
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
        PinFactory::get(PIN_LED_CHORUS_CE_1)->off();
        PinFactory::get(PIN_LED_CHORUS_ANALOG)->off();
        PinFactory::get(PIN_LED_CHORUS_VIBRATO)->off();
        PinFactory::get(PIN_LED_CHORUS_DIGITAL)->off();
    });

    states[STATE_STYLE_CHORUS_CE_1] = new State([&]() {
        // midi

        // leds
        PinFactory::get(PIN_LED_CHORUS_CE_1)->on();
        PinFactory::get(PIN_LED_CHORUS_DIGITAL)->off();
    });

    states[STATE_STYLE_CHORUS_ANALOG] = new State([&]() {
        // midi

        // leds
        PinFactory::get(PIN_LED_CHORUS_CE_1)->off();
        PinFactory::get(PIN_LED_CHORUS_ANALOG)->on();
    });

    states[STATE_STYLE_CHORUS_VIBRATO] = new State([&]() {
        // midi

        // leds
        PinFactory::get(PIN_LED_CHORUS_ANALOG)->off();
        PinFactory::get(PIN_LED_CHORUS_VIBRATO)->on();
    });

    states[STATE_STYLE_CHORUS_DIGITAL] = new State([&]() {
        // midi

        // leds
        PinFactory::get(PIN_LED_CHORUS_VIBRATO)->off();
        PinFactory::get(PIN_LED_CHORUS_DIGITAL)->on();
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
        PinFactory::get(PIN_LED_ATMO_AMBIENT)->off();
        PinFactory::get(PIN_LED_ATMO_VERBED)->off();
        PinFactory::get(PIN_LED_ATMO_DIFFUSED)->off();
        PinFactory::get(PIN_LED_ATMO_SPLATTERED)->off();
    });

    states[STATE_STYLE_ATMO_AMBIENT] = new State([&]() {
        // midi

        // leds
        PinFactory::get(PIN_LED_ATMO_AMBIENT)->on();
        PinFactory::get(PIN_LED_ATMO_SPLATTERED)->off();
    });

    states[STATE_STYLE_ATMO_VERBED] = new State([&]() {
        // midi

        // leds
        PinFactory::get(PIN_LED_ATMO_AMBIENT)->off();
        PinFactory::get(PIN_LED_ATMO_VERBED)->on();
    });

    states[STATE_STYLE_ATMO_DIFFUSED] = new State([&]() {
        // midi

        // leds
        PinFactory::get(PIN_LED_ATMO_VERBED)->off();
        PinFactory::get(PIN_LED_ATMO_DIFFUSED)->on();
    });

    states[STATE_STYLE_ATMO_SPLATTERED] = new State([&]() {
        // midi

        // leds
        PinFactory::get(PIN_LED_ATMO_DIFFUSED)->off();
        PinFactory::get(PIN_LED_ATMO_SPLATTERED)->on();
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
