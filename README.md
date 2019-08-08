# esp32JTAGActivator
Arduino project to activate the JTAG interface on the Esp32 based hardware like ESP32-WROOM-32

If you want to debug realtime with for example the open source platformIO tool using the JTAG interface, then you first need to activate 
the signals MTDI, MTCK, MTMS and MTDO on the Esp32 cpu. These occupy the pins 12,13,14 and 15 of the Esp32 cpu but are not normally active.
Run this Arduino sketch once on your Esp32 cpu and these pins can be used for realtime debugging. Make sure you do not use these pins for
other purposes in your project.
