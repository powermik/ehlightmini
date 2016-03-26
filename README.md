# ehlightmini
mqtt -> nodemcu -> 10 WS2811 Leds on a Strip on Easterhegg 2016

Based on ESPThing by doebi: https://github.com/doebi/ESPThing
and FastLED https://github.com/FastLED/FastLED/

don't forget to edit lib/espthing/config.h for WIFI and MQTT Settings 


## Base Colors
just publish on "\<BASE\>"/set  for example 'rgbwrgbnrg' 

rgb: red,green,blue
w: white
n: black

## RGB Colors in HEX
"\<BASE\>"/setrgb D7C38DDA3E841975AD4B3A5630E6BBB672882A70FA2314177FFC854B9800

RRGGBB in hex values
