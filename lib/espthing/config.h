/*
 * ESP Boilerplate OS - config.h
 * (c) by Christoph (doebi) Döberl
 *
 */
#include "Arduino.h"

typedef struct {
    std::vector<WifiAPlist_t> APlist;
    String friendlyName;
    String mqttServer;
    String mqttDomain;
    int connectTime;
    int reconnectTime;
} thing_config_t;

thing_config_t config = {
    {
        { "<essid>", "<wpakey>" }
    },
    "<THINGNAME",
    "<MQTT_SERVER>",
    "devlol/things",
    60,
    60 * 15
};
