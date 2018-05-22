<!--
waggle_topic=IGNORE
-->

# "Nano-Waggle" Soil Moisture Probe
Soil moisture sensor array and logger based on Particle IoT platform (Particle.io)

## Parts List
### Circuit Construction
- 1 x Solderable PCB with pads, at least 18 x 24, 0.1" pitch (http://a.co/isHuxrb or similar)
- 2 x 18-pin header sockets, 0.1" pitch (DigiKey 1212-1206-ND or similar); for mounting Electron
- Hookup wire
- 3 x female barrel connectors with wire ends, 2.5mm (DigiKey 839-1303-ND or similar)
- 6 x 22k resistor  
### Logger Construction
- 1 x [Particle Electron](https://docs.particle.io/datasheets/electron-(cellular)/electron-datasheet/ "Electron datasheet")
- 1 x Antenna ([Taoglas PC104 included](http://www.taoglas.com/wp-content/uploads/2015/06/PC104.07.0165C.pdf "PDF doc sheet") with Particle Electron; or similar GSM antenna with MHFI connector)
- 1 x Battery (2000 mAh Li-Po battery included with Particle Electron; or similar with JST 2-pin connector)
- 3 x Soil moisture sensors ([YL-69](https://randomnerdtutorials.com/guide-for-soil-moisture-sensor-yl-69-or-hl-69-with-the-arduino/) or similar, discard potentiometer)
- 3 x male barrel connectors with wire ends, 2.5 mm (DigiKey 839-1300-ND or similar)
- Adhesive-lined marine heatshrink (sufficient diameter for barrel connectors)
- Conformal coating/waterproof non-conductive epoxy
- Waterproof cable gland (still to be selected)
- Plumbers putty
- 1 x micro-USB-B power cord with charging source (e.g. wall wart, power bank); this will top off the LiPo battery, so an outlet is best

### Mounting and Housing
- Housing for board, at least 10 cm x 10 cm and 3 cm deep, plumbing PVC recommended; see [Cave Pearl Documentation](http://www.mdpi.com/1424-8220/18/2/530 "Beddows and Mallon, 2018") for weatherproof housing build

## Build diagrams
### Circuit
Figure out how to embed a pdf

### PVC sizing and cutting
Add dimensioning to this and upload

### Logger assembly
Take some photos

## Build recipe
### In the lab
1. Assemble circuit according to above circuit diagram
2. Slot Particle Electron into two 18-pin connectors
3. Drill housing according to cutting diagram (drill press recommended)
4. Mount PCB, antenna, and battery to interior of the housing using velcro
5. Mark female barrel connector to identify sensors, then pass through housing and fix in place with plumbers putty
6. Solder male barrel connector wire ends to terminals on sensor, + to solid black, - to white stripe, coat well in conformal coating/epoxy, and mark to identify sensors (deepest = #0). 
7. Tidy up wires with small cable ties
8. Connect USB-B cable and flash firmware (Particle CLI recommended)
### In the field
9. Use a twist auger or similar to dig holes with minimal disturbance to surrounding soils
10. Press sensors into undisturbed soils in the walls of dug holes, prongs parallel to the ground surface
11. Connect male to female barrel connectors and weatherproof (testing in progress); ensure that deepest sensor is lowest number and sensor nearest the ground surface is largest number
12. Backfill holes, attempt to return soil to original compaction and keep wires untangled.
13. Pass USB cable through cable gland and connect to power source
14. Connect antenna and battery
15. Wait for internet connection
16. Close housing, taking care not to pinch wires, and tighten cable gland well
17. Clear vegetation and partially bury closed housing to ensure a low profile

Notes: Consider using these instead of barrel connectors
http://www.bulgin.com/media/bulgin/data/400_power.pdf
