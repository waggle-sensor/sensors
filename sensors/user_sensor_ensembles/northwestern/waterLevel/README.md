# "Nano-Waggle" Water Level Probe
Water level sensor array and logger based on Particle IoT platform (Particle.io)

Prototypes deployed at Tuley Park Field House, Chatham, Chicago, IL

## Parts List
### Circuit Construction
- 1 x Solderable PCB with pads, at least 18 x 24, 0.1" pitch (http://a.co/isHuxrb or similar)
- 2 x 18-pin header sockets, 0.1" pitch (DigiKey 1212-1206-ND or similar); for mounting Electron
- 3 x 3-pin headers (DigiKey 732-5323-ND or similar); for connecting sensors
- 2 x 6-pin sockets (DigiKey S7071-ND or similar); for inserting resistors
- 22G flexible wire; red, black, green  
### Logger Construction
- 1 x [Particle Electron](https://docs.particle.io/datasheets/electron-(cellular)/electron-datasheet/ "Electron datasheet")
- 1 x Antenna ([Taoglas PC104 included](http://www.taoglas.com/wp-content/uploads/2015/06/PC104.07.0165C.pdf "PDF doc sheet") with Particle Electron; or similar GSM antenna with MHFI connector)
- 1 x Battery (2000 mAh Li-Po battery included with Particle Electron; or similar with JST 2-pin connector)
- 3 x Water Level Sensor (https://www.amazon.com/Solu-Detection-Arduino-Sensitivity-Surface/dp/B00UJ0DVN4 or similar)
- 3 x VALUE?? resistors
- 9 x 12" jumper wires, female-female, 3 red, 3 black, 3 green
- 1 x micro-USB-B power cord with charging source (e.g. wall wart, power bank); this will top off the LiPo battery, so an outlet is best  
### Mounting and Housing
- Housing for board, at least 10 cm x 10 cm and 3 cm deep
- Electrical tape
- Small cable ties for managing wires
- Acrylic plate, at least 30 cm in height x 15 cm in width, 3/8" thickness or less
- 1/8" plastic screws and nuts; for affixing sensors to plate
- Adhesive velcro; for affixing logger housing to plate
- 1/4" masonry screws; for affixing plate to wall  

## Build diagrams
### Circuit
Figure out how to embed a pdf

### Acrylic cutting
Add dimensioning to this and upload

### Logger assembly
Take some photos

## Build recipe
### In the lab
1. Assemble circuit according to above circuit diagram
2. Slot Particle Electron into two 18-pin connectors with black wires aligning with VIN at top and green wire aligning with A0 at bottom.
3. Slot 3 identical resistors into 6-pin sockets, taking care to not cross or touch legs
4. Create holes in acrylic plate according to cutting diagram (laser cutter recommended)
5. Mount PCB and battery to interior of the housing using velcro
6. Mount water level sensors to acrylic plate using two screws and two nuts apiece
7. Mount housing to acrylic plate using velcro
8. Using jumper wires, connect lowest water level sensor (nearest the floor) to lowest three-pin header  
   * 'S' -> Green
   * '+' -> Red
   * '-' -> Black  
 So, nearest sensor to the floor is sensor 0, top sensor is sensor 2.
9. Connect antenna and carefully position outside the housing; tape in place. Make sure that the wire will not be pinched when the housing is closed
10. Tidy up wires with small cable ties, taking care not to pinch
11. Connect USB-B cable and flash firmware (Particle CLI recommended)
### In the field
12. Mount acrylic plate to wall with masonry screws, ensuring that sensors are level; that is, parallel to the direction of gravity, not aligned with the wall or floor
13. Connect battery and power supply
15. Wait for internet connection
16. Close housing, taking care not to pinch wires
