/**
 ** /coresensors/v3/pbay/v3.3
 ** integrated.ino V3 (pbay)
 **/

#include <SPI.h>
#include <Wire.h> 
#include "./libs/DueTimer/DueTimer.h"   //** TIMER3 library
extern TwoWire Wire1;
#include <OneWire.h>
#include "config.cpp"

#include "./variable.h"     //** byte arrays, variables for all sensors and integrated.ino
#include "./setsensor.h"    //** add variables for sensors on airsense and lightsense boards depening on its availability 

void setup()
{
    //** Let us wait for the processor and the sensors to settle down
    delay(2000);

    //** initialize the super-packet
    //** and sub-packets
    //** sensors_setup.ino, set pinMode and put MACID of airsense
    assemble_packet_empty();
    sensor_buff_initialization();
    initializeSensorBoard();

    //** begin communication lines
    Wire.begin(); // Sensors are on the first I2C Bus, air and light sensor boards
    SerialUSB.begin(USBSERIAL_INTERFACE_DATARATE); // Serial data line to the host computer
    Serial3.begin(CHEMSENSE_DATARATE); // data from the Chemsense board arrives here.
    SPI.begin(); // data from the ****************************************************** alphasensor

#ifdef CHEMSENSE_INCLUDE
    digitalWrite(PIN_CHEMSENSE_POW, LOW);  //** Power on the Chemsense board
#endif

    //** sensors_setup.ino, initialize sensors in airsense and lightsense boards
    Sensors_Setup();    // TMP112 config(); Chemsense turned off, This has to come later than chemsense digital write
    delay(1000);

    //** begin I2C interface
#ifdef I2C_INTERFACE
    I2C_READ_COMPLETE = false;
    Wire1.begin(I2C_SLAVE_ADDRESS);
    Wire1.onRequest(requestEvent);
#endif
    
    Timer3.attachInterrupt(handler).setPeriod(1000000 * 1).start();

#ifdef ALPHASENSE_INCLUDE
    alphasense_on();
    SerialUSB.print("on");

    alphasense_firmware();
    alphasense_config();

    flag_alpha = true;
#endif
}

void loop()
{
#ifdef AIRSENSE_INCLUDE
    airsense_acquire();
#endif

#ifdef LIGHTSENSE_INCLUDE
    lightsense_acquire();
#endif

    while (count < 15)       // every 24 sec
    {
        if (repeat < count)
        {
            repeat++;
        #ifdef HMC5883L_include
            HMC5883L_acquire();
        #endif

        #ifdef LIGHTSENSE_INCLUDE
        #ifdef SPV1840LR5HB_include
            SPV1840LR5HB_acquire();
        #endif
        #ifdef MMA8452Q_INCLUDE
            MMA8452Q_acquire();
        #endif
        #endif

        #ifdef ALPHASENSE_INCLUDE
            alphasense_histo();

            if (count == 14)        // every 23 sec
            {
                count_conf++;
                if (count_conf == 13)       // every 598 secs, about 10 min
                {
                    alphasense_config();
                    alphasense_firmware();

                    flag_alpha = true;
                    count_conf = 0;
                }
            }
        #endif
        }

    flag_CHEM_WHILE = true;
    #ifdef CHEMSENSE_INCLUDE
        chemsense_acquire();
    #endif
    }

    // #ifdef ALPHASENSE_INCLUDE
    // alphasense_off();
    // SerialUSB.print("off");
    // delay(1000);
    // #endif

    assemble_packet_whole();        //******** packetize air/light/chem
    for (byte i = 0x00; i < packet_whole[0x02] + 0x05; i++)
        SerialUSB.write(packet_whole[i]);

#ifdef ALPHASENSE_INCLUDE
    alpha_packet_whole();           //******** packetize histo/firmware/config(part)
    for (byte i = 0x00; i < packet_whole[0x02] + 0x05; i++)
        SerialUSB.write(packet_whole[i]);

    if (flag_alpha == true)
    {
        alpha_packet_config();       //******** packetize config(part)

        for (byte i = 0x00; i < packet_whole[0x02] + 0x05; i++)
            SerialUSB.write(packet_whole[i]);
    }

    flag_alpha = false;
#endif
    
    count = 0;
    repeat = 0;

#ifdef OIX_DEBUG
    //************************** test OIX sub-packet
    SerialUSB.print("OIX_count ");
    SerialUSB.print(OIX_count);
    SerialUSB.print(" OIX_packet_count ");
    SerialUSB.println(OIX_packet_count);

    for (byte i = 0x00; i < packet_whole[0x02] + 0x05; i++)
    {
        SerialUSB.print(packet_whole[i], HEX);
        if (i < packet_whole[0x02] + 0x04)
            SerialUSB.print(":");
    }
    SerialUSB.print("\n");
#endif

    OIX_count = 0;
    OIX_packet_count = 0;
    //************************** test OIX sub-packet

}

#ifdef I2C_INTERFACE
void requestEvent()
{
    #ifdef I2C_INTERFACE_CONST_SIZE
    Wire1.write(packet_whole, I2C_PACKET_SIZE);

    #else
    char bytes_to_send;
    bytes_to_send = packet_whole[0x02] + 0x05;
    Wire1.write(packet_whole, bytes_to_send );
    #endif

    I2C_READ_COMPLETE = true;
    assemble_packet_empty();
}
#endif

void handler()
{
    count++;
    UP_DOWN =! UP_DOWN;
    digitalWrite(PIN_HBT, UP_DOWN);
}


