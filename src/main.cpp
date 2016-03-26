/*
 * ESP Boilerplate OS - main.cpp
 * (c) by Christoph (doebi) Döberl
 * esplightmini by doebi and mik
 *
 */
#include "ESPThing.h"
#include "FastLED.h"

#define NUM_LEDS 10
#define DATA_PIN D2

CRGB leds[NUM_LEDS];

void set_cb(const MQTT::Publish& pub) {
    if (pub.payload_len() >= NUM_LEDS) {
        String DATA = pub.payload_string();
        for (int i = 0; i < NUM_LEDS; i++) {
            char s = DATA.charAt(i);
            if (s == 'r') {
                leds[i] = CRGB::Red;
            }
            if (s == 'g') {
                leds[i] = CRGB::Green;
            }
            if (s == 'b') {
                leds[i] = CRGB::Blue;
            }
            if (s == 'w') {
                leds[i] = CRGB::White;
            }
            if (s == 'n') {
                leds[i] = CRGB::Black;
            }
        }
        FastLED.show();
    }
}

void setrgb_cb(const MQTT::Publish& pub) {
    if (pub.payload_len() >= NUM_LEDS*6) {
        String DATA = pub.payload_string();
        for (int i = 0; i < NUM_LEDS; i++) {
            leds[i].r = strtol(DATA.substring(i*6,   i*6+2).c_str(), NULL, 16);
            leds[i].g = strtol(DATA.substring(i*6+2, i*6+4).c_str(), NULL, 16);
	    leds[i].b = strtol(DATA.substring(i*6+4, i*6+6).c_str(), NULL, 16);
        }
        FastLED.show();
    }
}

void setup() {
    Serial.begin(115200);
    FastLED.addLeds<WS2811, DATA_PIN, RGB>(leds, NUM_LEDS);
    Thing.addInput(Input("set", set_cb));
    Thing.addInput(Input("setrgb", setrgb_cb));
}

void loop() {
    Thing.loop();
}

