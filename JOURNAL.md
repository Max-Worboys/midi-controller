# Time Spent 4 + 2 + 5 + 2 + 1 = 14

## MIDI Controller

# May 31st 10:00 to 14:00

## Picking parts and deciding on a design

Inspired by the launchpad by novatio I decided to recreate it for myself with a few additional features.  The original launchpad has a 9x9 grid of buttons including an 8x8 grid of touch capacitive ones.  The outer buttons control functions of the software while the inner buttons act like a traditional beatpad.  For my recreation I am going to make an 8x8 grid of keyboard style switches as these are easier to source and a bank of four faders for additional control over my software (Serato DJ Pro).  To be able to interact with this software it needs to be able to output midi signals and for the faders to work the board I am going to use will need analouge pins.  To forfill these demands I have decided to use an **Arduino Micro**.  Additionally as the board doen't have enough pins to support all 64 switches I have decided to use the **CD74HC4067SM96** Multiplexer by texas instruments.

# June 1st 14:00 to 16:00

## Started designing PCB

I plan to only use a cutom pcb to house the 8x8 grid of switches as not every component I plan to use has a footprint on kicad the software I am using to design the PCB.  The switches are spaced into 20x20mm squares to make desiging the casing easier and have the ground wire built into the pcb to save on unessecary soldering.

![image](https://github.com/user-attachments/assets/485d65af-4fc8-461f-91d4-634d26412d45)

The other components will be housed on protoboards as previously mentioned kicad doesn't have footprints for them.  Each component will have an individual protoboard wich will slot into a dedicated space in the 3d printed casing with space for the wires to run beneath them.

# June 1st 18:00 to 23:00

## Finalised PCB

After much scouring of the internet and slightly changing the components I plan to use I decided to instead of only having a custom PCB for the switches to have a PCB which houses all of the componets except the Arduino Micro as I didn't find a sutible footprint and don't feel confident enough to design my own.  The PCB has dedicated soldering holes for all of the wires that need to go to the PCB in the top left corner of the board. The Arduino Micro will sit on a protoboard below the main PCB this increase the hight of the casing but it will make the internal wiring easier to manage.  All of the switches have their own individual connection to the multiplexer which then has 5 connections to the PCB 4 shared 1 individual.

Schematic:

![image](https://github.com/user-attachments/assets/611897cb-d52a-4e6c-931f-49b8770946b4)

The Arduino is shown in the schematic as I created a component symbol for it based on the pinout diagram provided by the Arduino website.

PCB:

![image](https://github.com/user-attachments/assets/3f36cc6e-e690-4221-8b38-333b14fea154)

Each connection to the switch was painfull to draw in as Kicad's path generation constantly blocked the path of the other connections, I originally attempted to make the PCB one sided as to be quite frankly honest I didn't know how to make the tracks be on the other side of the board, I quickly learned how after consulting the genius who is gigicat who ridiculled me for the suffering I put myself through.

# June 5nd 19:00 to 21:00

## Designed the 3d printed housing

I designed the casing in fusion 360 (eww ik i'm sorry).  It is 213x224x28mm and has a +0.2mm tolerance around the circuit board.  The main PCB sits on the top platform approximately 10mm down from the top plate which has holes for the switches / keycpas as well as spaces for the sliding potentiometers.  There is a spot for the protoboard which holds the macropad at a lower level to the main PCB with the same +0.2mm tolerance.  The entire unit takes around 6 hours to print and uses 260g of filament.  I am going to use PLA to print the casing on my Bambu Lab P1S as it doesn't need to be particularly strong and I already have loads of it.

![image](https://github.com/user-attachments/assets/2f52a91e-b8e0-4546-a23b-dd07ee309175)

# June 8th 19:00 to 20:00
## Made some changes to the pcb

After looking at the feedback other people have recieved on their project I have added a ground plane, still not entirely sure what it does but it is there, I rounded the corners beacuse that makes it nicer?, and I added some artwork!

![image](https://github.com/user-attachments/assets/ac83f835-de08-4cd5-ac21-11cae833fd8d)

## Updated the casing

I have chamfered all of the edges of the casing to improve the asthetics of the model, I have also added scew holes so the lid can be saftely attached to the base.

![image](https://github.com/user-attachments/assets/9644392f-d454-4877-af9b-b9d59091b1f6)

