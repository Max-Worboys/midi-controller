## MIDI Controller

# May 31st 10:00 to 14:00

## Picking parts and deciding on a design

Inspired by the launchpad by novatio I decided to recreate it for myself with a few additional features.  The original launchpad has a 9x9 grid of buttons including an 8x8 grid of touch capacitive ones.  The outer buttons control functions of the software while the inner buttons act like a traditional beatpad.  For my recreation I am going to make an 8x8 grid of keyboard style switches as these are easier to source and a bank of four faders for additional control over my software (Serato DJ Pro).  To be able to interact with this software it needs to be able to output midi signals and for the faders to work the board I am going to use will need analouge pins.  To forfill these demands I have decided to use an **Arduino Micro**.  Additionally as the board doen't have enough pins to support all 64 switches I have decided to use the **CD74HC4067SM96** Multiplexer by texas instruments.

# June 1st 14:00 to 16:00

I plan to only use a cutom pcb to house the 8x8 grid of switches as not every component I plan to use has a footprint on kicad the software I am using to design the PCB.  The switches are spaced into 20x20mm squares to make desiging the casing easier and have the ground wire built into the pcb to save on unessecary soldering.

![image](https://github.com/user-attachments/assets/485d65af-4fc8-461f-91d4-634d26412d45)

The other components will be housed on protoboards as previously mentioned kicad doesn't have footprints for them.  Each component will have an individual protoboard wich will slot into a dedicated space in the 3d printed casing with space for the wires to run beneath them.

# June 1st 19:00 to 21:00

Finalised PCB Design.

PCB:

![image](https://github.com/user-attachments/assets/3f36cc6e-e690-4221-8b38-333b14fea154)

Schematic:

![image](https://github.com/user-attachments/assets/611897cb-d52a-4e6c-931f-49b8770946b4)

The only component not on the pcb is the arduino micro as no footprint exists and I don't trust myself to make a correct one.

# June 2nd 19:00 to 21:00

Designed housing for the PCB in Fusion 360.

The main PCB sits 10 mm down from the top of the case and above the arduino which has a dedicated place at the back of the casing.
