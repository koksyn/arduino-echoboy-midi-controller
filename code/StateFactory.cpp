#include "StateFactory.h"

#include "PinFactory.h"

State* StateFactory::states[STATES];

void StateFactory::initialize()
{
    // ---------- SYNC TIME ----------
    states[STATE_SYNC_TIME_DISABLED] = new State([&]() {
        // midi

        // led
        PinFactory::get(PIN_LED_SYNC_TIME)->writeLow();
    });

    states[STATE_SYNC_TIME_ENABLED] = new State([&]() {
        // midi

        // led
        PinFactory::get(PIN_LED_SYNC_TIME)->writeHigh();
    });

    states[STATE_SYNC_TIME_DISABLED]->setNextState(states[STATE_SYNC_TIME_ENABLED]);
    states[STATE_SYNC_TIME_ENABLED]->setNextState(states[STATE_SYNC_TIME_DISABLED]);

    // ---------- PRIME NUMBERS ----------
    states[STATE_PRIME_NUMBERS_DISABLED] = new State([&]() {
        // midi

        // led
        PinFactory::get(PIN_LED_PRIME_NUMBERS)->writeLow();
    });

    states[STATE_PRIME_NUMBERS_ENABLED] = new State([&]() {
        // midi

        // led
        PinFactory::get(PIN_LED_PRIME_NUMBERS)->writeHigh();
    });

    states[STATE_PRIME_NUMBERS_DISABLED]->setNextState(states[STATE_PRIME_NUMBERS_ENABLED]);
    states[STATE_PRIME_NUMBERS_ENABLED]->setNextState(states[STATE_PRIME_NUMBERS_DISABLED]);

    // ---------- ECHO 1 ----------
    states[STATE_ECHO_1_TIME] = new State([&]() {
        // midi

        // led
        PinFactory::get(PIN_LED_ECHO_1_NOTE)->writeLow();
        PinFactory::get(PIN_LED_ECHO_1_TIME)->writeHigh();
    });

    states[STATE_ECHO_1_NOTE] = new State([&]() {
        // midi

        // led
        PinFactory::get(PIN_LED_ECHO_1_NOTE)->writeHigh();
        PinFactory::get(PIN_LED_ECHO_1_TIME)->writeLow();
    });

    states[STATE_ECHO_1_TIME]->setNextState(states[STATE_ECHO_1_NOTE]);
    states[STATE_ECHO_1_NOTE]->setNextState(states[STATE_ECHO_1_TIME]);

    // ---------- ECHO 2 ----------
    states[STATE_ECHO_2_TIME] = new State([&]() {
        // midi

        // led
        PinFactory::get(PIN_LED_ECHO_2_NOTE)->writeLow();
        PinFactory::get(PIN_LED_ECHO_2_TIME)->writeHigh();
    });

    states[STATE_ECHO_2_NOTE] = new State([&]() {
        // midi

        // led
        PinFactory::get(PIN_LED_ECHO_2_NOTE)->writeHigh();
        PinFactory::get(PIN_LED_ECHO_2_TIME)->writeLow();
    });

    states[STATE_ECHO_2_TIME]->setNextState(states[STATE_ECHO_2_NOTE]);
    states[STATE_ECHO_2_NOTE]->setNextState(states[STATE_ECHO_2_TIME]);

    // ---------- MODE ----------
    states[STATE_MODE_PONG] = new State([&]() {
        // midi

        // led
        PinFactory::get(PIN_LED_MODE_PING_PONG)->writeHigh();
        PinFactory::get(PIN_LED_MODE_SINGLE)->writeLow();
    });

    states[STATE_MODE_DUAL] = new State([&]() {
        // midi

        // led
        PinFactory::get(PIN_LED_MODE_DUAL)->writeHigh();
        PinFactory::get(PIN_LED_MODE_PING_PONG)->writeLow();
    });

    states[STATE_MODE_RHYTM] = new State([&]() {
        // midi

        // led
        PinFactory::get(PIN_LED_MODE_RHYTM)->writeHigh();
        PinFactory::get(PIN_LED_MODE_DUAL)->writeLow();
    });

    states[STATE_MODE_SINGLE] = new State([&]() {
        // midi

        // led
        PinFactory::get(PIN_LED_MODE_SINGLE)->writeHigh();
        PinFactory::get(PIN_LED_MODE_RHYTM)->writeLow();
    });

    states[STATE_MODE_PONG]->setNextState(states[STATE_MODE_DUAL]);
    states[STATE_MODE_DUAL]->setNextState(states[STATE_MODE_RHYTM]);
    states[STATE_MODE_RHYTM]->setNextState(states[STATE_MODE_SINGLE]);
    states[STATE_MODE_SINGLE]->setNextState(states[STATE_MODE_PONG]);

    // ---------- BYPASS ----------
    states[STATE_BYPASS_DISABLED] = new State([&]() {
        // midi

        // led
        PinFactory::get(PIN_LED_BYPASS)->writeLow();
    });

    states[STATE_BYPASS_ENABLED] = new State([&]() {
        // midi

        // led
        PinFactory::get(PIN_LED_BYPASS)->writeHigh();
    });

    states[STATE_BYPASS_DISABLED]->setNextState(states[STATE_BYPASS_ENABLED]);
    states[STATE_BYPASS_ENABLED]->setNextState(states[STATE_BYPASS_DISABLED]);

    // ---------- STYLE TAPE ----------
    states[STATE_STYLE_TAPE_DISABLED] = new State([&]() {
        // midi

        // leds
        PinFactory::get(PIN_LED_TAPE_STUDIO)->writeLow();
        PinFactory::get(PIN_LED_TAPE_CHEAP)->writeLow();
        PinFactory::get(PIN_LED_TAPE_TUBE)->writeLow();
        PinFactory::get(PIN_LED_TAPE_MASTER)->writeLow();
    });

    states[STATE_STYLE_TAPE_STUDIO] = new State([&]() {
        // midi

        // leds
        PinFactory::get(PIN_LED_TAPE_STUDIO)->writeHigh();
        PinFactory::get(PIN_LED_TAPE_MASTER)->writeLow();
    });

    states[STATE_STYLE_TAPE_CHEAP] = new State([&]() {
        // midi

        // leds
        PinFactory::get(PIN_LED_TAPE_STUDIO)->writeLow();
        PinFactory::get(PIN_LED_TAPE_CHEAP)->writeHigh();
    });

    states[STATE_STYLE_TAPE_TUBE] = new State([&]() {
        // midi

        // leds
        PinFactory::get(PIN_LED_TAPE_CHEAP)->writeLow();
        PinFactory::get(PIN_LED_TAPE_TUBE)->writeHigh();
    });

    states[STATE_STYLE_TAPE_MASTER] = new State([&]() {
        // midi

        // leds
        PinFactory::get(PIN_LED_TAPE_TUBE)->writeLow();
        PinFactory::get(PIN_LED_TAPE_MASTER)->writeHigh();
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
        PinFactory::get(PIN_LED_ECHO_PLEX)->writeLow();
        PinFactory::get(PIN_LED_ECHO_SPACE)->writeLow();
        PinFactory::get(PIN_LED_ECHO_TEL_RAY)->writeLow();
        PinFactory::get(PIN_LED_ECHO_BINSONETTE)->writeLow();
    });

    states[STATE_STYLE_ECHO_PLEX] = new State([&]() {
        // midi

        // leds
        PinFactory::get(PIN_LED_ECHO_PLEX)->writeHigh();
        PinFactory::get(PIN_LED_ECHO_BINSONETTE)->writeLow();
    });

    states[STATE_STYLE_ECHO_SPACE] = new State([&]() {
        // midi

        // leds
        PinFactory::get(PIN_LED_ECHO_PLEX)->writeLow();
        PinFactory::get(PIN_LED_ECHO_SPACE)->writeHigh();
    });

    states[STATE_STYLE_ECHO_TEL_RAY] = new State([&]() {
        // midi

        // leds
        PinFactory::get(PIN_LED_ECHO_SPACE)->writeLow();
        PinFactory::get(PIN_LED_ECHO_TEL_RAY)->writeHigh();
    });

    states[STATE_STYLE_ECHO_BINSONETTE] = new State([&]() {
        // midi

        // leds
        PinFactory::get(PIN_LED_ECHO_TEL_RAY)->writeLow();
        PinFactory::get(PIN_LED_ECHO_BINSONETTE)->writeHigh();
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
        PinFactory::get(PIN_LED_BBD_MEMORY_MAN)->writeLow();
        PinFactory::get(PIN_LED_BBD_ANALOG)->writeLow();
        PinFactory::get(PIN_LED_BBD_AM_RADIO)->writeLow();
        PinFactory::get(PIN_LED_BBD_DM_2)->writeLow();
    });

    states[STATE_STYLE_BBD_MEMORY_MAN] = new State([&]() {
        // midi

        // leds
        PinFactory::get(PIN_LED_BBD_MEMORY_MAN)->writeHigh();
        PinFactory::get(PIN_LED_BBD_DM_2)->writeLow();
    });

    states[STATE_STYLE_BBD_ANALOG] = new State([&]() {
        // midi

        // leds
        PinFactory::get(PIN_LED_BBD_MEMORY_MAN)->writeLow();
        PinFactory::get(PIN_LED_BBD_ANALOG)->writeHigh();
    });

    states[STATE_STYLE_BBD_AM_RADIO] = new State([&]() {
        // midi

        // leds
        PinFactory::get(PIN_LED_BBD_ANALOG)->writeLow();
        PinFactory::get(PIN_LED_BBD_AM_RADIO)->writeHigh();
    });

    states[STATE_STYLE_BBD_DM_2] = new State([&]() {
        // midi

        // leds
        PinFactory::get(PIN_LED_BBD_AM_RADIO)->writeLow();
        PinFactory::get(PIN_LED_BBD_DM_2)->writeHigh();
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
        PinFactory::get(PIN_LED_BIAS_TRANSMITTER)->writeLow();
        PinFactory::get(PIN_LED_BIAS_DISTORTED)->writeLow();
        PinFactory::get(PIN_LED_BIAS_SATURATED)->writeLow();
        PinFactory::get(PIN_LED_BIAS_QUEEKED)->writeLow();
    });

    states[STATE_STYLE_BIAS_TRANSMITTER] = new State([&]() {
        // midi

        // leds
        PinFactory::get(PIN_LED_BIAS_TRANSMITTER)->writeHigh();
        PinFactory::get(PIN_LED_BIAS_QUEEKED)->writeLow();
    });

    states[STATE_STYLE_BIAS_DISTORTED] = new State([&]() {
        // midi

        // leds
        PinFactory::get(PIN_LED_BIAS_TRANSMITTER)->writeLow();
        PinFactory::get(PIN_LED_BIAS_DISTORTED)->writeHigh();
    });

    states[STATE_STYLE_BIAS_SATURATED] = new State([&]() {
        // midi

        // leds
        PinFactory::get(PIN_LED_BIAS_DISTORTED)->writeLow();
        PinFactory::get(PIN_LED_BIAS_SATURATED)->writeHigh();
    });

    states[STATE_STYLE_BIAS_QUEEKED] = new State([&]() {
        // midi

        // leds
        PinFactory::get(PIN_LED_BIAS_SATURATED)->writeLow();
        PinFactory::get(PIN_LED_BIAS_QUEEKED)->writeHigh();
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
        PinFactory::get(PIN_LED_CHORUS_CE_1)->writeLow();
        PinFactory::get(PIN_LED_CHORUS_ANALOG)->writeLow();
        PinFactory::get(PIN_LED_CHORUS_VIBRATO)->writeLow();
        PinFactory::get(PIN_LED_CHORUS_DIGITAL)->writeLow();
    });

    states[STATE_STYLE_CHORUS_CE_1] = new State([&]() {
        // midi

        // leds
        PinFactory::get(PIN_LED_CHORUS_CE_1)->writeHigh();
        PinFactory::get(PIN_LED_CHORUS_DIGITAL)->writeLow();
    });

    states[STATE_STYLE_CHORUS_ANALOG] = new State([&]() {
        // midi

        // leds
        PinFactory::get(PIN_LED_CHORUS_CE_1)->writeLow();
        PinFactory::get(PIN_LED_CHORUS_ANALOG)->writeHigh();
    });

    states[STATE_STYLE_CHORUS_VIBRATO] = new State([&]() {
        // midi

        // leds
        PinFactory::get(PIN_LED_CHORUS_ANALOG)->writeLow();
        PinFactory::get(PIN_LED_CHORUS_VIBRATO)->writeHigh();
    });

    states[STATE_STYLE_CHORUS_DIGITAL] = new State([&]() {
        // midi

        // leds
        PinFactory::get(PIN_LED_CHORUS_VIBRATO)->writeLow();
        PinFactory::get(PIN_LED_CHORUS_DIGITAL)->writeHigh();
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
        PinFactory::get(PIN_LED_ATMO_AMBIENT)->writeLow();
        PinFactory::get(PIN_LED_ATMO_VERBED)->writeLow();
        PinFactory::get(PIN_LED_ATMO_DIFFUSED)->writeLow();
        PinFactory::get(PIN_LED_ATMO_SPLATTERED)->writeLow();
    });

    states[STATE_STYLE_ATMO_AMBIENT] = new State([&]() {
        // midi

        // leds
        PinFactory::get(PIN_LED_ATMO_AMBIENT)->writeHigh();
        PinFactory::get(PIN_LED_ATMO_SPLATTERED)->writeLow();
    });

    states[STATE_STYLE_ATMO_VERBED] = new State([&]() {
        // midi

        // leds
        PinFactory::get(PIN_LED_ATMO_AMBIENT)->writeLow();
        PinFactory::get(PIN_LED_ATMO_VERBED)->writeHigh();
    });

    states[STATE_STYLE_ATMO_DIFFUSED] = new State([&]() {
        // midi

        // leds
        PinFactory::get(PIN_LED_ATMO_VERBED)->writeLow();
        PinFactory::get(PIN_LED_ATMO_DIFFUSED)->writeHigh();
    });

    states[STATE_STYLE_ATMO_SPLATTERED] = new State([&]() {
        // midi

        // leds
        PinFactory::get(PIN_LED_ATMO_DIFFUSED)->writeLow();
        PinFactory::get(PIN_LED_ATMO_SPLATTERED)->writeHigh();
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
