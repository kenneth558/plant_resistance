EESchema Schematic File Version 4
LIBS:uno shield v1.0 project SMD-cache
EELAYER 30 0
EELAYER END
$Descr A2 23386 16535
encoding utf-8
Sheet 1 2
Title ""
Date "10-Oct-2019"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L power:GNDA #PWR014
U 1 1 5C19D658
P 14800 5800
F 0 "#PWR014" H 14800 5550 50  0001 C CNN
F 1 "GNDA" H 14805 5627 50  0000 C CNN
F 2 "" H 14800 5800 50  0001 C CNN
F 3 "" H 14800 5800 50  0001 C CNN
	1    14800 5800
	1    0    0    -1  
$EndComp
Text Notes 19125 15772 0    47   ~ 0
GWAAMC Training Aid Main Board for UNO with MCP4262 HX711 LM334 REF200 MMBF5462 (2N5462)
Text Notes 18925 15522 0    58   ~ 0
 1 2
$Comp
L power:GNDD #PWR016
U 1 1 5C5C35A0
P 15575 5800
F 0 "#PWR016" H 15575 5550 50  0001 C CNN
F 1 "GNDD" H 15575 5650 50  0000 C CNN
F 2 "" H 15575 5800 50  0001 C CNN
F 3 "" H 15575 5800 50  0001 C CNN
	1    15575 5800
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR021
U 1 1 5C7E6F1E
P 13000 12200
F 0 "#PWR021" H 13000 11950 50  0001 C CNN
F 1 "GNDD" H 13004 12045 50  0000 C CNN
F 2 "" H 13000 12200 50  0001 C CNN
F 3 "" H 13000 12200 50  0001 C CNN
	1    13000 12200
	1    0    0    -1  
$EndComp
Text Label 20650 2200 0    60   ~ 0
A0
Text Label 20650 2300 0    60   ~ 0
A1
Text Label 20650 2400 0    60   ~ 0
A2
Text Label 20650 2500 0    60   ~ 0
A3
Text Label 22249 2700 0    60   ~ 0
2
Text Label 22250 2600 0    60   ~ 0
3(**)
Text Label 22200 2000 0    60   ~ 0
8
Text Label 22250 2400 0    60   ~ 0
5(**)
Text Label 22250 2300 0    60   ~ 0
6(**)
Text Label 22249 2200 0    60   ~ 0
7
Text Notes 20225 850  0    60   ~ 0
Arduino "Uno" board Rev 3. J2 shown\naccommodates the advanced style with A6 and \nA7.  Ordinarily J2 is numbered 1 to 8.
NoConn ~ 22500 847 
NoConn ~ 22600 847 
NoConn ~ 22700 847 
NoConn ~ 22800 847 
Wire Notes Line
	22925 997  22425 997 
Wire Notes Line
	22425 997  22425 497 
Text Label 21075 4250 0    50   ~ 0
MOSI(1)
Text Label 21075 4350 0    50   ~ 0
GND(4)
Text Label 20575 4250 2    50   ~ 0
SCK(1)
NoConn ~ 20575 4150
NoConn ~ 20575 4350
$Comp
L power:+5V #PWR026
U 1 1 5CAAC3A7
P 21475 4075
F 0 "#PWR026" H 21475 3925 50  0001 C CNN
F 1 "+5V" V 21475 4275 50  0000 C CNN
F 2 "" H 21475 4075 50  0001 C CNN
F 3 "" H 21475 4075 50  0001 C CNN
	1    21475 4075
	0    1    1    0   
$EndComp
$Comp
L power:GNDD #PWR027
U 1 1 5CB66292
P 21075 4350
F 0 "#PWR027" H 21075 4100 50  0001 C CNN
F 1 "GNDD" H 21079 4195 50  0000 C CNN
F 2 "" H 21075 4350 50  0001 C CNN
F 3 "" H 21075 4350 50  0001 C CNN
	1    21075 4350
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR033
U 1 1 5CB9E79B
P 22825 1225
F 0 "#PWR033" H 22825 975 50  0001 C CNN
F 1 "GNDD" H 22775 1075 50  0000 C CNN
F 2 "" H 22825 1225 50  0001 C CNN
F 3 "" H 22825 1225 50  0001 C CNN
	1    22825 1225
	1    0    0    -1  
$EndComp
Wire Notes Line
	20250 3822 21600 3822
$Sheet
S 2200 1800 884  150 
U 5D5A7B87
F0 "Sheet5D5A7B86" 50
F1 "Coax Cable and Diagnostic DUT.sch" 50
$EndSheet
Text Notes 20050 9097 0    50   ~ 0
Magnification \namplitude
Text Notes 21610 9082 0    50   ~ 0
Gain\nadjust\n3 settings
$Comp
L power:GNDD #PWR029
U 1 1 5C90D427
P 21450 9425
F 0 "#PWR029" H 21450 9175 50  0001 C CNN
F 1 "GNDD" H 21454 9270 50  0000 C CNN
F 2 "" H 21450 9425 50  0001 C CNN
F 3 "" H 21450 9425 50  0001 C CNN
	1    21450 9425
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR028
U 1 1 5C90D42E
P 21450 9125
F 0 "#PWR028" H 21450 8975 50  0001 C CNN
F 1 "+5V" H 21467 9298 50  0000 C CNN
F 2 "" H 21450 9125 50  0001 C CNN
F 3 "" H 21450 9125 50  0001 C CNN
	1    21450 9125
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR023
U 1 1 5DD017AA
P 20800 9425
F 0 "#PWR023" H 20800 9175 50  0001 C CNN
F 1 "GNDD" H 20804 9270 50  0000 C CNN
F 2 "" H 20800 9425 50  0001 C CNN
F 3 "" H 20800 9425 50  0001 C CNN
	1    20800 9425
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR022
U 1 1 5DD0CD99
P 20800 9125
F 0 "#PWR022" H 20800 8975 50  0001 C CNN
F 1 "+5V" H 20817 9298 50  0000 C CNN
F 2 "" H 20800 9125 50  0001 C CNN
F 3 "" H 20800 9125 50  0001 C CNN
	1    20800 9125
	1    0    0    -1  
$EndComp
Connection ~ 13400 4775
Wire Wire Line
	13100 4775 13400 4775
Text Notes 725  4725 0    100  Italic 20
!
Text Notes 700  4900 0    50   Italic 10
    NOT \n    FOR \nVOLTAGE
Wire Wire Line
	22450 2600 21900 2600
Wire Wire Line
	22400 2700 21900 2700
Wire Wire Line
	21900 2300 22500 2300
Wire Wire Line
	21900 2200 22550 2200
$Comp
L power:+5V #PWR015
U 1 1 5C19D6AB
P 15350 4175
F 0 "#PWR015" H 15350 4025 50  0001 C CNN
F 1 "+5V" H 15375 4350 50  0000 C CNN
F 2 "" H 15350 4175 50  0001 C CNN
F 3 "" H 15350 4175 50  0001 C CNN
	1    15350 4175
	1    0    0    -1  
$EndComp
Wire Wire Line
	15575 5500 15575 5775
Wire Wire Line
	15575 5500 15350 5500
Connection ~ 12700 3750
Wire Wire Line
	12700 3750 12700 3850
Wire Wire Line
	12700 3750 12900 3750
Text Notes 12250 8125 0    60   ~ 0
NOTE - These resistors are valued for 5V operation to \nset the reference input of the HX711 for highest gain.\nFuture research is yet to be done for 3.3V operation \nof the HX711 to determine if this value will need to \nbe changed.  It is not expected to be different, based \nsimply on the reasoning that this reference voltage is \nabout half of 3.3V already.\n\nNOTE - These resistors are spec'd tightly to mitigate \ntemperature drift.  If a different tempco is found to \nbe required for ADC1 balance, changing the tempcos \nof these resistors would be the solution.
$Comp
L power:+5V #PWR07
U 1 1 5D6F12A4
P 12700 5700
F 0 "#PWR07" H 12700 5550 50  0001 C CNN
F 1 "+5V" H 12775 5700 50  0000 C CNN
F 2 "" H 12700 5700 50  0001 C CNN
F 3 "" H 12700 5700 50  0001 C CNN
	1    12700 5700
	1    0    0    -1  
$EndComp
NoConn ~ 7875 6450
NoConn ~ 12800 6300
$Comp
L power:GNDA #PWR06
U 1 1 5D6610C1
P 7775 6450
F 0 "#PWR06" H 7775 6200 50  0001 C CNN
F 1 "GNDA" H 7625 6375 50  0000 C CNN
F 2 "" H 7775 6450 50  0001 C CNN
F 3 "" H 7775 6450 50  0001 C CNN
	1    7775 6450
	1    0    0    -1  
$EndComp
Wire Wire Line
	9500 4775 9500 5225
Wire Wire Line
	10750 4000 10750 4425
$Comp
L power:GNDD #PWR011
U 1 1 5D5FFC74
P 9850 4975
F 0 "#PWR011" H 9850 4725 50  0001 C CNN
F 1 "GNDD" H 9854 4820 50  0000 C CNN
F 2 "" H 9850 4975 50  0001 C CNN
F 3 "" H 9850 4975 50  0001 C CNN
	1    9850 4975
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR013
U 1 1 5D5FF76B
P 11325 4975
F 0 "#PWR013" H 11325 4725 50  0001 C CNN
F 1 "GNDD" H 11329 4820 50  0000 C CNN
F 2 "" H 11325 4975 50  0001 C CNN
F 3 "" H 11325 4975 50  0001 C CNN
	1    11325 4975
	1    0    0    -1  
$EndComp
$Comp
L power:GNDA #PWR08
U 1 1 5D5FE8B7
P 13075 6600
F 0 "#PWR08" H 13075 6350 50  0001 C CNN
F 1 "GNDA" H 13080 6427 50  0000 C CNN
F 2 "" H 13075 6600 50  0001 C CNN
F 3 "" H 13075 6600 50  0001 C CNN
	1    13075 6600
	1    0    0    -1  
$EndComp
Wire Wire Line
	7475 4350 7475 3750
Wire Wire Line
	7475 3750 7775 3750
Connection ~ 7475 3750
Wire Wire Line
	7775 3750 8575 3750
Wire Wire Line
	8575 3750 8875 3750
Connection ~ 8575 3750
Wire Wire Line
	10950 4325 10975 4325
Wire Wire Line
	10950 3950 10950 4325
Wire Wire Line
	9075 3950 10950 3950
Wire Wire Line
	10750 4425 10975 4425
Wire Wire Line
	8575 4350 8575 3750
Connection ~ 8875 3750
Wire Wire Line
	6400 4950 6400 4850
$Comp
L power:+5V #PWR012
U 1 1 5C182632
P 11325 4175
F 0 "#PWR012" H 11325 4025 50  0001 C CNN
F 1 "+5V" H 11275 4325 50  0000 C CNN
F 2 "" H 11325 4175 50  0001 C CNN
F 3 "" H 11325 4175 50  0001 C CNN
	1    11325 4175
	1    0    0    -1  
$EndComp
NoConn ~ 10200 4675
NoConn ~ 11675 4675
Connection ~ 7775 3750
$Comp
L power:+5V #PWR010
U 1 1 5C1825F8
P 9850 4175
F 0 "#PWR010" H 9850 4025 50  0001 C CNN
F 1 "+5V" H 9950 4200 50  0000 C CNN
F 2 "" H 9850 4175 50  0001 C CNN
F 3 "" H 9850 4175 50  0001 C CNN
	1    9850 4175
	1    0    0    -1  
$EndComp
Wire Wire Line
	10200 4425 10350 4425
Wire Wire Line
	10200 4575 10250 4575
Wire Wire Line
	13075 6600 13575 6600
Wire Wire Line
	8875 3750 12700 3750
Wire Wire Line
	12700 6300 12700 6350
Wire Wire Line
	12500 4150 12250 4150
Wire Wire Line
	12500 4775 12250 4775
Wire Wire Line
	13100 4150 13400 4150
Wire Wire Line
	13400 4150 13400 4500
Wire Wire Line
	14450 6400 14500 6400
Wire Wire Line
	13400 4775 14500 4775
Wire Wire Line
	14225 4450 14225 5500
$Comp
L power:+5V #PWR09
U 1 1 5D58A5AC
P 6150 3225
F 0 "#PWR09" H 6150 3075 50  0001 C CNN
F 1 "+5V" H 6150 3400 50  0000 C CNN
F 2 "" H 6150 3225 50  0001 C CNN
F 3 "" H 6150 3225 50  0001 C CNN
	1    6150 3225
	1    0    0    -1  
$EndComp
Connection ~ 14500 4775
Connection ~ 14500 6400
Wire Wire Line
	15750 5150 16925 5150
Wire Wire Line
	22400 3650 22400 2700
Wire Wire Line
	15750 5050 17075 5050
Wire Wire Line
	22450 3775 22450 2600
Wire Wire Line
	22500 2300 22500 5500
Wire Wire Line
	22550 2200 22550 5050
Text Notes 10850 12700 0    50   ~ 0
NOTE:  Check sketch macros for which LED is controlled by which MCU pin.
Text Notes 22775 9975 1    50   ~ 0
NOTE:  Check sketch macros for which LED is controlled by which MCU pin.
Text Notes 22775 6875 1    50   ~ 0
NOTE:  Check sketch macros for which LED is controlled by which MCU pin.
Text Notes 525  15750 0    200  ~ 40
NOTE: Except where indicated otherwise, \ncomponent part numbers and vendors are \nsuggested based on likely imperfect research\nof pricing and availability for the USA in the \nspring of 2019.
Wire Notes Line
	5900 4625 7775 4625
Text Notes 1050 3125 0    60   ~ 0
Blue dashes indicate traces that ought to be guarded using similar \nvoltage guard trace.  Remove solder mask from the guard traces to \nguard against surface leakage due to contamination. In addition to \nthe guard traces on the primary side, route a guard trace around any \nvias in the input net on the other side of the board as well.
$Comp
L power:GNDA #PWR05
U 1 1 5CFC03A8
P 6150 4125
F 0 "#PWR05" H 6150 3875 50  0001 C CNN
F 1 "GNDA" H 6155 3952 50  0000 C CNN
F 2 "" H 6150 4125 50  0001 C CNN
F 3 "" H 6150 4125 50  0001 C CNN
	1    6150 4125
	1    0    0    -1  
$EndComp
Text Notes 4400 3500 0    70   ~ 0
2nd stage guard trace source
Text Notes 5950 4550 0    60   ~ 0
2nd stage guard trace route
Text Notes 1825 4525 0    60   ~ 0
1st stage guard trace route
Text Notes 10175 5975 0    60   ~ 0
3rd stage guard trace route
Wire Wire Line
	10975 4775 10975 5225
Wire Wire Line
	10975 4675 10900 4675
Wire Wire Line
	10900 4675 10900 5300
Wire Wire Line
	10900 5300 9400 5300
Wire Wire Line
	9400 4775 9400 5300
Wire Wire Line
	3750 4750 3800 4750
Text Notes 2675 3600 0    60   ~ 0
1st stage guard trace source
Wire Notes Line
	3650 4100 3775 4100
Wire Notes Line
	3775 4100 3775 4900
Wire Notes Line
	3775 4900 3800 4900
$Comp
L power:GNDD #PWR03
U 1 1 5D4815B2
P 3025 7250
F 0 "#PWR03" H 3025 7000 50  0001 C CNN
F 1 "GNDD" H 3029 7095 50  0000 C CNN
F 2 "" H 3025 7250 50  0001 C CNN
F 3 "" H 3025 7250 50  0001 C CNN
	1    3025 7250
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR01
U 1 1 5D4F4A1E
P 1675 4200
F 0 "#PWR01" H 1675 3950 50  0001 C CNN
F 1 "GNDD" H 1679 4045 50  0000 C CNN
F 2 "" H 1675 4200 50  0001 C CNN
F 3 "" H 1675 4200 50  0001 C CNN
	1    1675 4200
	1    0    0    -1  
$EndComp
Wire Wire Line
	1675 4200 1500 4200
Wire Wire Line
	1500 4200 1500 4300
NoConn ~ 1700 4500
Text Label 2000 3825 0    60   ~ 0
1st_stage_guard_trace
Wire Wire Line
	3150 4075 3150 3925
Wire Wire Line
	3150 3925 2000 3925
Wire Wire Line
	2000 3925 2000 3825
Wire Wire Line
	3575 4650 3800 4650
$Comp
L power:GNDA #PWR02
U 1 1 5D8F459E
P 2625 4175
F 0 "#PWR02" H 2625 3925 50  0001 C CNN
F 1 "GNDA" H 2630 4002 50  0000 C CNN
F 2 "" H 2625 4175 50  0001 C CNN
F 3 "" H 2625 4175 50  0001 C CNN
	1    2625 4175
	1    0    0    -1  
$EndComp
Wire Wire Line
	3025 4175 3025 4075
Wire Wire Line
	3025 4075 3150 4075
Wire Wire Line
	3050 4325 2825 4325
Text Label 6150 3925 2    60   ~ 0
2nd_stage_guard_trace
$Comp
L power:GNDA #PWR04
U 1 1 5D99BDAB
P 4425 3725
F 0 "#PWR04" H 4425 3475 50  0001 C CNN
F 1 "GNDA" H 4430 3552 50  0000 C CNN
F 2 "" H 4425 3725 50  0001 C CNN
F 3 "" H 4425 3725 50  0001 C CNN
	1    4425 3725
	1    0    0    -1  
$EndComp
Wire Wire Line
	4400 3725 4425 3725
Wire Wire Line
	4000 3725 3150 3725
Wire Wire Line
	3150 3725 3150 3925
Connection ~ 3150 3925
Wire Wire Line
	4200 3875 4200 4075
Wire Wire Line
	4200 4075 3950 4075
Wire Wire Line
	3250 4450 3250 4325
Text Notes 2350 10500 0    60   ~ 0
When used as designed (body \nsoldered to PCB and cover used \nremoveably) the height of this \nshield is 10mm and not hermetically \nsealed.\n\nInstead, hermetic sealing is \nsuggested to provide you with \nthe ultimate in long term \nsensitivity stability in scientific\ninstrumentation class useages,\nwhich will also benefit from J1\nbeing a triax connector instead\nof the phone connector shown.\n\n\nHermetic sealing is achieved by: \n\n#1) Solder sealing all micro-vias of\nthe PCB under the shield, and\n\n#2) not using the shield body, only \ncarefully and thoroughly soldering \nthe shield top in place with the \ndried dessicant package (supplied \nby manufacturer with U4) stuffed \ninside to minimize moisture \nabsorption by U4 that could degrade\nU4 performance slightly over time in \nhumid environments.
Wire Notes Line
	9425 4750 9425 5325
Wire Notes Line
	11000 5325 11000 4825
Wire Notes Line
	11000 4825 11100 4825
Wire Notes Line
	11075 4300 10975 4300
Wire Notes Line
	10975 4300 10975 3925
Wire Notes Line
	11075 4650 10850 4650
Wire Notes Line
	10875 4650 10875 5200
Wire Notes Line
	9525 5200 9525 4800
Wire Notes Line
	9525 4800 9600 4800
Wire Notes Line
	9600 4800 9600 4825
Wire Notes Line
	11075 4450 10725 4450
Wire Notes Line
	10725 4450 10725 4025
Wire Notes Line
	9525 4275 9600 4275
Wire Notes Line
	9600 4275 9600 4300
Text Notes 10100 3900 0    60   ~ 0
1st stage guard trace route
Text Notes 9800 5400 0    60   ~ 0
1st stage guard trace route
Text Notes 12250 3600 0    70   ~ 0
3rd stage guard trace source
Text Label 13400 4200 0    60   ~ 0
3rd_stage_guard_trace
Text Notes 1175 5425 0    60   ~ 0
GNDA used for \nguard trace between\nS and R1
$Comp
L power:GNDD #PWR031
U 1 1 5DC90CA3
P 18600 9575
F 0 "#PWR031" H 18600 9325 50  0001 C CNN
F 1 "GNDD" H 18604 9420 50  0000 C CNN
F 2 "" H 18600 9575 50  0001 C CNN
F 3 "" H 18600 9575 50  0001 C CNN
	1    18600 9575
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR030
U 1 1 5DC91A88
P 18600 8975
F 0 "#PWR030" H 18600 8825 50  0001 C CNN
F 1 "+5V" H 18617 9148 50  0000 C CNN
F 2 "" H 18600 8975 50  0001 C CNN
F 3 "" H 18600 8975 50  0001 C CNN
	1    18600 8975
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR024
U 1 1 5DC922E1
P 17900 9075
F 0 "#PWR024" H 17900 8925 50  0001 C CNN
F 1 "+5V" H 17917 9248 50  0000 C CNN
F 2 "" H 17900 9075 50  0001 C CNN
F 3 "" H 17900 9075 50  0001 C CNN
	1    17900 9075
	1    0    0    -1  
$EndComp
Text Notes 18100 10100 0    50   ~ 0
Developer-user 2
Text Notes 17325 10100 0    50   ~ 0
Developer-user 1
Text Notes 13750 10800 0    50   ~ 0
If using the UNO SMD MCU version with an ATMEGA128P-AU (a \nTQFP package specifically instead of the UNO with a DIP \nATMEGA128P), there are two analog input pins available at the \nTQFP package on the MCU board that are often not wired out to \nany connector.  Their TQFP pin numbers are 19 (A6) and 22 (A7).\n\nWhile you are building this project and before deciding on the \nlength of J2, look at your Arduino to see if A6 and A7 are wired \nout to some connector.  If so, you're in luck - just build \nthis board as is.  If your Arduino does not break out A6 and A7 \nfor you, decide whether you have a use for A6 &/or A7.  If so, \nyou will connect with PH-MVS-5370 pogo pins soldered atop \nslightly retracted J2 pins 9 and 1 (this board) and FFC bare pad \n(MCU board) instead of socket and pin.  \n\nExample of an Arduino with the directly pinout supported at\nhttps://www.aliexpress.com\n/item\n/Real-tracking-number-100-new-chip-high-quality-UNO-R3-MEGA328P-CH340G-for-Arduino-Compatible-Improved\n/1933684816.html?spm=a2g0o.cart.0.0.7cd53c00hidtIP
Text Label 22250 1400 0    50   ~ 0
GNDD
Text Notes 22550 997  0    60   ~ 0
Holes
Wire Wire Line
	22650 1225 22650 1400
Wire Wire Line
	21900 1400 22650 1400
Wire Wire Line
	22650 1225 22825 1225
NoConn ~ 21900 1100
NoConn ~ 21900 1200
NoConn ~ 21900 1300
NoConn ~ 21900 1500
NoConn ~ 21900 1600
NoConn ~ 21900 1700
NoConn ~ 21900 1800
NoConn ~ 21900 1900
Wire Wire Line
	21425 4250 21425 4550
NoConn ~ 21150 2600
NoConn ~ 21150 2700
Wire Wire Line
	11900 11497 11900 11500
Wire Wire Line
	17450 8775 17450 8950
Wire Wire Line
	17450 9150 17175 9150
Text Label 21050 1100 0    60   ~ 0
A6
Wire Wire Line
	21050 1100 21150 1100
Text Label 21000 1900 0    60   ~ 0
A7
Text Label 17175 9150 0    60   ~ 0
A7
Text Label 17175 9375 0    60   ~ 0
A6
Wire Wire Line
	21150 1700 21150 1600
NoConn ~ 21150 1200
NoConn ~ 21150 1300
NoConn ~ 21150 1800
Wire Wire Line
	17175 9375 17375 9375
Wire Wire Line
	17325 8950 17450 8950
Connection ~ 17450 8950
Wire Wire Line
	17450 8950 17450 9150
Wire Wire Line
	17375 9025 17225 9025
Wire Wire Line
	17225 9025 17225 8950
Connection ~ 17375 9375
Wire Wire Line
	17375 9375 17550 9375
Connection ~ 17225 9025
Wire Wire Line
	17325 8975 17325 8950
Wire Wire Line
	3075 4600 3075 4650
Wire Wire Line
	1700 4600 3075 4600
Wire Notes Line
	1800 4550 3100 4550
Wire Notes Line
	3100 4550 3100 4625
Wire Notes Line
	3100 4625 4100 4625
Text Notes 575  4150 0    60   ~ 0
With triax cabling employed \n(not shown) GNDD will \njoin to cable's guard \nconductor
Wire Wire Line
	6200 4650 7775 4650
Wire Wire Line
	6200 4850 6400 4850
Wire Wire Line
	6200 4750 6275 4750
Wire Wire Line
	3800 4950 3800 5450
Wire Wire Line
	6150 3925 6275 3925
Text Notes 20750 2650 0    47   ~ 0
A4 SDA(1)
Text Notes 20750 2750 0    47   ~ 0
A5 SCL(1)
Text Notes 20275 4150 0    47   ~ 0
MISO(1)
Text Notes 21950 1100 0    47   ~ 0
A5(SCL)(2)
Text Notes 21950 1200 0    47   ~ 0
A4(SDA)(2)
Text Notes 21950 1300 0    47   ~ 0
AREF
Text Notes 21950 1500 0    47   ~ 0
13(SCK)(2)
Text Notes 21950 1600 0    47   ~ 0
12(MISO)(2)
Wire Wire Line
	13075 6400 13575 6400
Wire Wire Line
	3075 4650 3250 4650
Connection ~ 3250 4650
Wire Wire Line
	3250 4650 3375 4650
Connection ~ 6150 3925
Wire Wire Line
	13200 3750 14225 3750
Connection ~ 12900 3750
Wire Wire Line
	13150 3925 13200 3925
Wire Wire Line
	13200 3925 13200 3750
Connection ~ 13200 3750
Wire Wire Line
	12950 3925 12900 3925
Wire Wire Line
	12900 3750 12900 3925
Wire Wire Line
	13400 4700 13400 4775
Wire Wire Line
	15225 4450 15350 4450
Connection ~ 15350 4450
Wire Wire Line
	15325 4175 15350 4175
Wire Wire Line
	15350 4175 15350 4450
Wire Wire Line
	14800 5800 14800 5500
Connection ~ 14800 5500
Wire Wire Line
	14800 5500 15000 5500
Wire Wire Line
	14225 5500 14800 5500
Wire Wire Line
	15025 4175 15025 4450
Wire Wire Line
	12700 4450 14225 4450
Connection ~ 14225 4450
Wire Wire Line
	15025 4450 14225 4450
Connection ~ 15025 4450
Wire Wire Line
	14225 3750 14225 4450
Wire Wire Line
	15350 4450 15350 4650
Connection ~ 15350 4175
Text Notes 21950 1700 0    47   ~ 0
11(**/MOSI)
Text Notes 21950 1825 0    47   ~ 0
10(**/SS)
Text Notes 21950 1925 0    47   ~ 0
9(**)
$Comp
L power:PWR_FLAG #FLG0102
U 1 1 5D340082
P 15575 5775
F 0 "#FLG0102" H 15575 5850 50  0001 C CNN
F 1 "PWR_FLAG" V 15575 5903 50  0001 L CNN
F 2 "" H 15575 5775 50  0001 C CNN
F 3 "~" H 15575 5775 50  0001 C CNN
	1    15575 5775
	0    1    1    0   
$EndComp
Connection ~ 15575 5775
Wire Wire Line
	15575 5775 15575 5800
$Comp
L power:+5V #PWR032
U 1 1 5C76F5BF
P 13000 11200
F 0 "#PWR032" H 13000 11050 50  0001 C CNN
F 1 "+5V" H 13017 11373 50  0000 C CNN
F 2 "" H 13000 11200 50  0001 C CNN
F 3 "" H 13000 11200 50  0001 C CNN
	1    13000 11200
	1    0    0    -1  
$EndComp
Wire Wire Line
	11900 11197 11900 11200
Wire Wire Line
	13000 11200 11900 11200
Connection ~ 13000 11200
Connection ~ 11900 11200
Wire Wire Line
	11900 11200 11900 11300
Wire Wire Line
	12100 11500 11900 11500
Wire Wire Line
	12700 11700 12700 11500
Wire Wire Line
	12700 11500 12100 11500
Connection ~ 12100 11500
Wire Wire Line
	12700 11900 12700 12000
Connection ~ 12700 12000
Wire Wire Line
	13000 11400 13000 11500
Wire Wire Line
	13000 12200 12400 12200
Connection ~ 13000 12200
Connection ~ 12100 12200
Wire Wire Line
	11900 11500 11575 11500
Connection ~ 11900 11500
Connection ~ 11575 12200
Wire Wire Line
	11575 12200 12100 12200
Wire Wire Line
	12500 12000 12400 12000
Wire Wire Line
	12400 12000 12400 12200
Connection ~ 12400 12200
Wire Wire Line
	12400 12200 12100 12200
Wire Wire Line
	9700 12200 10725 12200
Connection ~ 10725 12200
Wire Wire Line
	10725 12200 11575 12200
Wire Wire Line
	22600 12525 11275 12525
Wire Wire Line
	11275 12525 11275 12000
Wire Wire Line
	22550 12450 11800 12450
Wire Wire Line
	11800 12450 11800 12000
Wire Wire Line
	10725 11800 11575 11800
Connection ~ 11575 11800
Wire Wire Line
	9700 11200 9700 11600
Wire Wire Line
	9700 11200 11900 11200
Wire Wire Line
	9700 11800 10425 11800
Wire Wire Line
	10425 11800 10425 12000
Connection ~ 9700 11800
Wire Wire Line
	14900 4850 14750 4850
Wire Wire Line
	14750 4850 14750 4800
Wire Wire Line
	14900 5350 14750 5350
Wire Wire Line
	14750 5350 14750 5400
Wire Wire Line
	14700 5150 14600 5150
Wire Wire Line
	14600 5150 14600 5200
Wire Wire Line
	14700 5050 14600 5050
Wire Wire Line
	14600 5050 14600 5000
Wire Wire Line
	14600 5200 14500 5200
Wire Wire Line
	14500 5200 14500 5350
Connection ~ 14600 5200
Wire Wire Line
	14750 5350 14500 5350
Connection ~ 14750 5350
Connection ~ 14500 5350
Wire Wire Line
	14500 5350 14500 6400
Wire Wire Line
	14600 5000 14500 5000
Wire Wire Line
	14500 4775 14500 4850
Connection ~ 14600 5000
Wire Wire Line
	14750 4850 14500 4850
Connection ~ 14750 4850
Connection ~ 14500 4850
Wire Wire Line
	14500 4850 14500 5000
Wire Wire Line
	15300 4700 15150 4700
Wire Wire Line
	3800 5450 5000 5450
Wire Wire Line
	15350 5500 15350 5700
Wire Wire Line
	15350 5700 15150 5700
Connection ~ 15350 5500
Wire Wire Line
	5000 6450 7775 6450
Connection ~ 15000 5500
Wire Wire Line
	15000 5500 15035 5500
Wire Wire Line
	15000 5700 15035 5700
Connection ~ 15150 5500
Text Notes 20225 4350 0    47   ~ 0
RESET(2)
Wire Wire Line
	15825 9025 15825 8925
Wire Wire Line
	15825 9025 17225 9025
Wire Wire Line
	15925 8975 15925 8925
Wire Wire Line
	15925 8975 17325 8975
Wire Wire Line
	21000 1900 21150 1900
Wire Wire Line
	14950 4800 14950 4775
Wire Wire Line
	14950 4775 14750 4775
Wire Wire Line
	14750 4775 14750 4800
Connection ~ 14950 4800
Connection ~ 14750 4800
Wire Wire Line
	14800 5000 14800 4965
Wire Wire Line
	14800 4965 14600 4965
Wire Wire Line
	14600 4965 14600 5000
Connection ~ 14800 5000
Wire Wire Line
	14800 5200 14800 5230
Wire Wire Line
	14800 5230 14600 5230
Wire Wire Line
	14600 5230 14600 5200
Connection ~ 14800 5200
Wire Wire Line
	14950 5400 14950 5425
Wire Wire Line
	14950 5425 14750 5425
Wire Wire Line
	14750 5425 14750 5400
Connection ~ 14750 5400
Connection ~ 14950 5400
Wire Wire Line
	15035 5500 15035 5700
Connection ~ 15035 5500
Connection ~ 17325 8950
Connection ~ 3150 4075
Connection ~ 3750 4075
Connection ~ 7775 6450
Connection ~ 13075 6600
Wire Wire Line
	14500 2200 21150 2200
Wire Wire Line
	14500 2200 14500 4775
Wire Wire Line
	16475 2300 21150 2300
Wire Wire Line
	16475 2300 16475 6400
Wire Wire Line
	19875 2400 21150 2400
Wire Wire Line
	20575 4250 17425 4250
Wire Wire Line
	21425 4550 17550 4550
Wire Wire Line
	22550 5450 22550 12450
Wire Wire Line
	22050 5050 22050 7875
Wire Wire Line
	21300 8850 21300 9275
Wire Wire Line
	20650 9275 19875 9275
Wire Wire Line
	19875 2400 19875 9275
Wire Wire Line
	19975 2500 19975 8850
Wire Wire Line
	19975 2500 21150 2500
Wire Wire Line
	19975 8850 21300 8850
Wire Wire Line
	22400 3650 16925 3650
Wire Wire Line
	22450 3775 17075 3775
Wire Wire Line
	17075 3775 17075 5050
Wire Wire Line
	16925 3650 16925 5150
$Comp
L power:+5V #PWR019
U 1 1 5D27E6CE
P 13650 1525
F 0 "#PWR019" H 13650 1375 50  0001 C CNN
F 1 "+5V" V 13600 1700 50  0000 C CNN
F 2 "" H 13650 1525 50  0001 C CNN
F 3 "" H 13650 1525 50  0001 C CNN
	1    13650 1525
	0    1    1    0   
$EndComp
$Comp
L power:GNDD #PWR018
U 1 1 5D297599
P 14125 1375
F 0 "#PWR018" H 14125 1125 50  0001 C CNN
F 1 "GNDD" H 14129 1220 50  0000 C CNN
F 2 "" H 14125 1375 50  0001 C CNN
F 3 "" H 14125 1375 50  0001 C CNN
	1    14125 1375
	1    0    0    -1  
$EndComp
Text Label 21900 2800 0    60   ~ 0
Tx
Text Label 21900 2900 0    60   ~ 0
Rx
Text Label 13575 1225 0    60   ~ 0
Tx
Text Label 13575 1325 0    60   ~ 0
Rx
Text Notes 13550 975  0    60   ~ 0
STATE_LED
NoConn ~ 13575 1025
Wire Wire Line
	13850 1125 13575 1125
Wire Wire Line
	13575 1525 13650 1525
Wire Wire Line
	14125 1375 13975 1375
Wire Wire Line
	13725 1375 13725 1425
Wire Wire Line
	13725 1425 13575 1425
Wire Wire Line
	13975 1625 13975 1375
Connection ~ 13975 1375
Wire Wire Line
	13975 1375 13725 1375
Wire Wire Line
	14250 1125 14250 1300
Wire Wire Line
	14250 1300 13975 1300
Wire Wire Line
	13975 1300 13975 1375
Wire Wire Line
	21150 1700 20400 1700
Connection ~ 21150 1700
Text Label 20400 1675 2    50   ~ 0
GNDD
Text Label 20400 1750 2    50   ~ 0
GNDD
Wire Wire Line
	20400 1675 20400 1700
Wire Wire Line
	20400 1750 20400 1700
Connection ~ 20400 1700
Wire Wire Line
	19925 1500 19575 1500
Wire Wire Line
	19925 1400 19700 1400
Wire Wire Line
	19700 1400 19700 1100
Wire Wire Line
	19700 1100 19575 1100
Wire Wire Line
	19225 1300 19425 1300
Text Notes 19075 750  0    60   ~ 0
Not included - not\nenough board space
NoConn ~ 19925 1500
NoConn ~ 19925 1400
Text Label 21050 1100 0    60   ~ 0
A6
Wire Wire Line
	20625 1200 20625 1225
Wire Wire Line
	20450 1175 20450 1225
$Comp
L power:+5V #PWR0101
U 1 1 5D3E8669
P 20450 1175
F 0 "#PWR0101" H 20450 1025 50  0001 C CNN
F 1 "+5V" H 20465 1348 50  0000 C CNN
F 2 "" H 20450 1175 50  0001 C CNN
F 3 "" H 20450 1175 50  0001 C CNN
	1    20450 1175
	1    0    0    -1  
$EndComp
$Comp
L power:PWR_FLAG #FLG0101
U 1 1 5D3E866F
P 20625 1200
F 0 "#FLG0101" H 20625 1275 50  0001 C CNN
F 1 "PWR_FLAG" V 20725 1150 50  0001 C CNN
F 2 "" H 20625 1200 50  0001 C CNN
F 3 "~" H 20625 1200 50  0001 C CNN
	1    20625 1200
	1    0    0    -1  
$EndComp
Wire Wire Line
	20625 1225 20525 1225
Wire Wire Line
	20450 1225 20525 1225
Connection ~ 20525 1225
Wire Wire Line
	21150 1500 20525 1500
NoConn ~ 21150 1400
Text Notes 19175 1025 0    60   ~ 0
+5/3.3V
Wire Wire Line
	19225 1075 19225 1300
NoConn ~ 19225 1075
Wire Notes Line
	19950 775  20075 775 
Wire Notes Line
	19025 800  19150 800 
Wire Notes Line
	20075 575  20075 2125
Wire Notes Line
	19025 2175 20075 2175
Wire Wire Line
	17425 4250 17425 6875
Wire Wire Line
	17550 4550 17550 6950
Wire Notes Line
	20200 747  20200 4600
Wire Notes Line
	20250 3825 20200 3825
Wire Notes Line
	20200 4600 22675 4600
Wire Notes Line
	22675 3825 22675 4600
Wire Notes Line
	19925 1400 21150 1400
Wire Notes Line
	19925 1500 20500 1500
Wire Wire Line
	21075 4250 21425 4250
Text Notes 11200 1950 0    60   ~ 0
Only a single jumper to be used at a time.\nThere are two pinouts of HC-05 style \nmodules and a third for ESP-01 \nadapter, though only one of the modules\ncan be chosen from that lineup.  If\nJ6 pin 3 is needed to be GND for an\nESP-01 adapter, use not only the JP4 shunt \nbut also solder-jumper on board front\nto surrounding copper.  If it is needed for\nconnect to Rx, pad jumpering is available \nnearby.  Note that Tx of one device \nconnects to Rx of the other & vice versa.\nThat is why you'll notice Tx printed on the \nwireless module goes to MCU Rx.
Wire Notes Line
	8075 12750 8075 15550
Wire Notes Line
	18650 15575 18650 12775
Text Notes 8050 13350 0    500  ~ 0
Helpful Parts Not In Circuit
Wire Notes Line
	9025 13475 17925 13475
Text Notes 9625 15900 0    65   ~ 0
· 1 roll Polyimide (Kapton) tape 3/8" wide 6' length or greater.  Use as electrical insulator and place assist. P/N 3057 from Arrow \nor equivalent\n· 38ga magnet wire for trace repairs.  P/N 3522 from Arrow or equivalent\n· Solder wick P/N TOL-09327 from Arrow or equivalent\n· Soldering colophony (pine or gum ROSIN - NOT with zinc nor ammonium chlorides) flux (can make it yourself)\n· RG316 Coaxial cable 2m/6ft min length\n· Multi-conductor flat IDC ribbon cable or hookup wire.  P/N 2001 to 2006 from Arrow\n· Electrode clamshells; one per leaf electrode.  Having attachment means and gripping spring somewhere along hinge axis and \nhaving enough suspending points spread out to hold clamshell in any specific orientation needed.  \n· 2 Electrode clamshell cushions made from white or ivory color "Kayser-Roth No nonsense knee high 100% nylon socks MADE \nIN USA" UPC 70011195323 (https://www.upcindex.com/70011195323), partially filled with craft-spec styrofoam balls, aka "beads" \nor "beans", approx. 3mm dia.  Per Kayser Roth Consumer Care: "You are able to order the Nononsense Knee Highs on our online \nwebsite nononsense.com. If you are wanting to order them locally you might be able to find them at a Shop-Rite, Walgreens, \nRite-Aid, Food Lion, Harris Teeter, HEB, CVS, or local supermarkets around you."  Yet I actually found them at Wal-Mart.\n· Electrode suspension device of your own making that won't sink into ground and extends a guy strings hang point above DUT\n· Carbon fiber tow, non-impregnated with a gold-plated transition pin per electrode (we have no source yet, but "non-impregnated" \nbasically means "not the shiny type").  The transition pin will interface between the carbon fiber and wiring to the receptacle that\nreceives the coaxial cable plug.  Ensure that conductor material transitions are both (excitation/sense side and return sides of \nthe coax cable) identical so the transitions' galvanic voltages cancel out.\n\nNOTE - Very high temp solder (K100) not allowed on U4.  The best solder will always be "No Heat SAC305" if you can find it, but \nyou still MUST cleanse gold from pads.  Avoid Pb (leaded) solder unless you understand the behavior of eutectics, how Pb ruins \nother solders, and how gold from ENIG ruins Pb solder.\n
Wire Notes Line
	21575 3825 22915 3825
Wire Wire Line
	21075 4075 21075 4150
Wire Notes Line
	8075 12725 18650 12725
Wire Notes Line
	8075 15950 18650 15950
$Comp
L power:GNDD #PWR0102
U 1 1 5D43F169
P 17900 9675
F 0 "#PWR0102" H 17900 9425 50  0001 C CNN
F 1 "GNDD" H 17904 9520 50  0000 C CNN
F 2 "" H 17900 9675 50  0001 C CNN
F 3 "" H 17900 9675 50  0001 C CNN
	1    17900 9675
	1    0    0    -1  
$EndComp
NoConn ~ 17500 9075
NoConn ~ 17500 9675
NoConn ~ 18200 8975
NoConn ~ 18200 9575
Wire Wire Line
	18075 9275 18075 8775
Wire Wire Line
	18075 9275 18250 9275
Wire Wire Line
	17450 8775 18075 8775
Wire Wire Line
	7775 4550 7775 4650
Text Notes 7550 3400 0    60   ~ 0
NOTE: Vcc net will remain labeled +5V until +3.3V\noperation is fully validated.  Operation currently at \n+3.3V is a lttle sickly, likely due to the following note.\n\nNOTE FOR 3.3V OPERATION - In 3.3V operation, \nthe voltage drop that Q2 adds for the sake of\nhighest output impedance against U4C might not \nallow 3.3V operation with an outboard ADC.  If \nthat is found to be the case, that JFET may be \nshorted across D to S with the expected result to \nbe reduced signal formation.\n\nMMBF5460 (2N5460) NOTE: SMD Source & Drain \nMUST BE interchangeable due to starting off this \nproject with a backwards SMD footprint.  This \nrestriction should not be a problem b/c the \nmanufacturer states that specific interchangeability \nis present in the MMBF5460 SMD package anyway.\nAlso note:  Q1 contributes nothing to functionality\nexcept to permit using the same voltage guard trace \nfor both U7 and U8 since they are co-located, distant\nfrom other guard traces, and their guard trace weaves\nbetween board sides leaving no room for another.
Text Notes 19775 15900 0    39   ~ 0
                         (C) Copyright Kenneth L. Anderson 2018-2019             Ver. 1.0
Wire Notes Line
	19025 575  19025 2125
Text Notes 2400 6325 0    50   ~ 0
Stock shield symbol below slightly \nincorrect:  It is the top that connects \nto GNDD while the bottom is not used
Text Notes 21400 3100 0    50   ~ 0
Directions are of MCU\nfunctions in link to PC
Text Label 13575 1825 0    60   ~ 0
Rx
Text Label 13575 1725 0    60   ~ 0
Tx
Text Notes 22375 1200 0    50   ~ 0
A6 (SCA) and A7 (SCL) on Adafruit Metro M4 Express AirLift\nif you air-wire these over
NoConn ~ 21900 2500
Wire Wire Line
	15035 5500 15100 5500
Connection ~ 15100 5500
Wire Wire Line
	15100 5500 15150 5500
Text Notes 7450 10100 0    60   ~ 0
NOTE - Due to this current mirror being referenced low,\nthe signal gets inverted (higher current=lower voltage).\nNo stage following is also inverting, so unfortunately it \nremains inverted.  It is left to the code to uninvert \nboth, but I haven't done that due to it being unessential \nto the lay operator - not worth my time right now, all \nthings considered.   For now, the operator may just \nhave to envision the plot line as equating to DUT stress \nor electrical resistance instead of conductance.\n\nNOTE - Future temperature compensation is expected to be \naccomplished by examining and balancing the tempco of \neach stage independently (digitally factored in the code) by \nuse of additional TO-92 packaged LM334 bent into contact \nwith each temperature sensitive component.  If possible, \nuse Analog Inputs A4, A5 for this purpose.
Text Notes 19050 2875 0    60   ~ 0
This function has to \nbe done manually \nduring assembly if\nusing 3.3V MCUs!\nAlso see note re:\nICSP1 pin 2 volts\n\n\nIf level translation \non data lines \nbecomes \nnecessary,\nsee AN97055 and\nAN10441 by NXP.
Wire Wire Line
	12250 4150 12250 4775
Connection ~ 12250 4775
Wire Wire Line
	12250 4775 12250 5850
Wire Notes Line
	12225 4175 12550 4175
Wire Notes Line
	12225 4800 12550 4800
Wire Wire Line
	17550 6950 11975 6950
Wire Wire Line
	12050 6875 17425 6875
Wire Wire Line
	17375 9025 17375 9375
Wire Wire Line
	7775 4650 7775 5850
Wire Wire Line
	22600 5450 22550 5450
Wire Wire Line
	21900 2400 22600 2400
Wire Wire Line
	22600 2400 22600 5450
Wire Wire Line
	22650 4725 22650 2000
Wire Wire Line
	21900 2000 22650 2000
Wire Wire Line
	22600 5500 22600 12525
Wire Wire Line
	11675 4425 11800 4425
Connection ~ 3750 4750
Wire Wire Line
	3750 4075 3750 4750
NoConn ~ 6250 3825
Wire Wire Line
	6150 3825 6150 3925
Text Notes 7450 8425 0    50   ~ 0
Q1,2 pinch-off testing:  Q1,2 need to place enough voltage across LM334 \nto permit full current capability of 1 µA to some mA (equi-spaced steps \nat 68K [256 setting in 50K device] to 13K [66 setting in 50K device]) \nwhile at the same time Q2 presents very high impedance load to U4C pin \n4 as found by proving Q2 has not saturated.
Text Label 7300 -975 0    50   ~ 0
8
Text Label 7300 -825 0    50   ~ 0
SCK(1)
NoConn ~ 7300 -725
Text Label 7300 -625 0    50   ~ 0
MOSI(1)
$Comp
L power:GNDD #PWR020
U 1 1 5D6E2568
P 6950 -425
F 0 "#PWR020" H 6950 -675 50  0001 C CNN
F 1 "GNDD" H 6954 -580 50  0000 C CNN
F 2 "" H 6950 -425 50  0001 C CNN
F 3 "" H 6950 -425 50  0001 C CNN
	1    6950 -425
	1    0    0    -1  
$EndComp
Text Label 6600 -625 2    50   ~ 0
U8-Pad8
Text Label 6600 -725 2    50   ~ 0
U8-Pad7
Text Label 6600 -975 2    50   ~ 0
U8-Pad5
Text Label 6600 -1075 2    50   ~ 0
U8-Pad6
$Comp
L power:+5V #PWR017
U 1 1 5D6E70E8
P 6950 -1225
F 0 "#PWR017" H 6950 -1375 50  0001 C CNN
F 1 "+5V" H 6965 -1052 50  0000 C CNN
F 2 "" H 6950 -1225 50  0001 C CNN
F 3 "" H 6950 -1225 50  0001 C CNN
	1    6950 -1225
	1    0    0    -1  
$EndComp
Text Label 10950 4675 2    50   ~ 0
U8-Pad7
Text Label 10975 4775 2    50   ~ 0
U8-Pad8
Text Label 9075 -925 0    50   ~ 0
8
Text Label 9075 -775 0    50   ~ 0
SCK(1)
NoConn ~ 9075 -675
Text Label 9075 -575 0    50   ~ 0
MOSI(1)
$Comp
L power:GNDD #PWR034
U 1 1 5D79DE0A
P 8725 -375
F 0 "#PWR034" H 8725 -625 50  0001 C CNN
F 1 "GNDD" H 8729 -530 50  0000 C CNN
F 2 "" H 8725 -375 50  0001 C CNN
F 3 "" H 8725 -375 50  0001 C CNN
	1    8725 -375
	1    0    0    -1  
$EndComp
Text Label 8375 -575 2    50   ~ 0
U8-Pad8
Text Label 8375 -675 2    50   ~ 0
U8-Pad7
Text Label 8375 -925 2    50   ~ 0
U8-Pad5
Text Label 8375 -1025 2    50   ~ 0
U8-Pad6
$Comp
L power:+5V #PWR025
U 1 1 5D79DE14
P 8725 -1175
F 0 "#PWR025" H 8725 -1325 50  0001 C CNN
F 1 "+5V" H 8740 -1002 50  0000 C CNN
F 2 "" H 8725 -1175 50  0001 C CNN
F 3 "" H 8725 -1175 50  0001 C CNN
	1    8725 -1175
	1    0    0    -1  
$EndComp
Text Label 10675 -950 0    50   ~ 0
8
Text Label 10675 -800 0    50   ~ 0
SCK(1)
NoConn ~ 10675 -700
Text Label 10675 -600 0    50   ~ 0
MOSI(1)
$Comp
L power:GNDD #PWR036
U 1 1 5D7B739A
P 10325 -400
F 0 "#PWR036" H 10325 -650 50  0001 C CNN
F 1 "GNDD" H 10329 -555 50  0000 C CNN
F 2 "" H 10325 -400 50  0001 C CNN
F 3 "" H 10325 -400 50  0001 C CNN
	1    10325 -400
	1    0    0    -1  
$EndComp
Text Label 9975 -600 2    50   ~ 0
U8-Pad8
Text Label 9975 -700 2    50   ~ 0
U8-Pad7
Text Label 9975 -950 2    50   ~ 0
U8-Pad5
Text Label 9975 -1050 2    50   ~ 0
U8-Pad6
$Comp
L power:+5V #PWR035
U 1 1 5D7B73A4
P 10325 -1200
F 0 "#PWR035" H 10325 -1350 50  0001 C CNN
F 1 "+5V" H 10340 -1027 50  0000 C CNN
F 2 "" H 10325 -1200 50  0001 C CNN
F 3 "" H 10325 -1200 50  0001 C CNN
	1    10325 -1200
	1    0    0    -1  
$EndComp
Text Label 12300 -925 0    50   ~ 0
8
Text Label 12300 -775 0    50   ~ 0
SCK(1)
NoConn ~ 12300 -675
Text Label 12300 -575 0    50   ~ 0
MOSI(1)
$Comp
L power:GNDD #PWR038
U 1 1 5D7D0E5E
P 11950 -375
F 0 "#PWR038" H 11950 -625 50  0001 C CNN
F 1 "GNDD" H 11954 -530 50  0000 C CNN
F 2 "" H 11950 -375 50  0001 C CNN
F 3 "" H 11950 -375 50  0001 C CNN
	1    11950 -375
	1    0    0    -1  
$EndComp
Text Label 11600 -575 2    50   ~ 0
U8-Pad8
Text Label 11600 -675 2    50   ~ 0
U8-Pad7
Text Label 11600 -925 2    50   ~ 0
U8-Pad5
Text Label 11600 -1025 2    50   ~ 0
U8-Pad6
$Comp
L power:+5V #PWR037
U 1 1 5D7D0E68
P 11950 -1175
F 0 "#PWR037" H 11950 -1325 50  0001 C CNN
F 1 "+5V" H 11965 -1002 50  0000 C CNN
F 2 "" H 11950 -1175 50  0001 C CNN
F 3 "" H 11950 -1175 50  0001 C CNN
	1    11950 -1175
	1    0    0    -1  
$EndComp
Text Label 14050 -900 0    50   ~ 0
8
Text Label 14050 -750 0    50   ~ 0
SCK(1)
NoConn ~ 14050 -650
Text Label 14050 -550 0    50   ~ 0
MOSI(1)
$Comp
L power:GNDD #PWR040
U 1 1 5D7E9C90
P 13700 -350
F 0 "#PWR040" H 13700 -600 50  0001 C CNN
F 1 "GNDD" H 13704 -505 50  0000 C CNN
F 2 "" H 13700 -350 50  0001 C CNN
F 3 "" H 13700 -350 50  0001 C CNN
	1    13700 -350
	1    0    0    -1  
$EndComp
Text Label 13350 -550 2    50   ~ 0
U8-Pad8
Text Label 13350 -650 2    50   ~ 0
U8-Pad7
Text Label 13350 -900 2    50   ~ 0
U8-Pad5
Text Label 13350 -1000 2    50   ~ 0
U8-Pad6
$Comp
L power:+5V #PWR039
U 1 1 5D7E9C9A
P 13700 -1150
F 0 "#PWR039" H 13700 -1300 50  0001 C CNN
F 1 "+5V" H 13715 -977 50  0000 C CNN
F 2 "" H 13700 -1150 50  0001 C CNN
F 3 "" H 13700 -1150 50  0001 C CNN
	1    13700 -1150
	1    0    0    -1  
$EndComp
Text Label 15575 -900 0    50   ~ 0
8
Text Label 15575 -750 0    50   ~ 0
SCK(1)
NoConn ~ 15575 -650
Text Label 15575 -550 0    50   ~ 0
MOSI(1)
$Comp
L power:GNDD #PWR042
U 1 1 5D8038AD
P 15225 -350
F 0 "#PWR042" H 15225 -600 50  0001 C CNN
F 1 "GNDD" H 15229 -505 50  0000 C CNN
F 2 "" H 15225 -350 50  0001 C CNN
F 3 "" H 15225 -350 50  0001 C CNN
	1    15225 -350
	1    0    0    -1  
$EndComp
Text Label 14875 -550 2    50   ~ 0
U8-Pad8
Text Label 14875 -650 2    50   ~ 0
U8-Pad7
Text Label 14875 -900 2    50   ~ 0
U8-Pad5
Text Label 14875 -1000 2    50   ~ 0
U8-Pad6
$Comp
L power:+5V #PWR041
U 1 1 5D8038B7
P 15225 -1150
F 0 "#PWR041" H 15225 -1300 50  0001 C CNN
F 1 "+5V" H 15240 -977 50  0000 C CNN
F 2 "" H 15225 -1150 50  0001 C CNN
F 3 "" H 15225 -1150 50  0001 C CNN
	1    15225 -1150
	1    0    0    -1  
$EndComp
Connection ~ 8875 4150
Wire Wire Line
	7950 4150 7775 4150
Connection ~ 7775 4150
Text Label 7250 -2650 0    50   ~ 0
8
Text Label 7250 -2500 0    50   ~ 0
SCK(1)
NoConn ~ 7250 -2400
Text Label 7250 -2300 0    50   ~ 0
MOSI(1)
$Comp
L power:GNDD #PWR0103
U 1 1 5D88DECC
P 6900 -2100
F 0 "#PWR0103" H 6900 -2350 50  0001 C CNN
F 1 "GNDD" H 6904 -2255 50  0000 C CNN
F 2 "" H 6900 -2100 50  0001 C CNN
F 3 "" H 6900 -2100 50  0001 C CNN
	1    6900 -2100
	1    0    0    -1  
$EndComp
Text Label 6550 -2300 2    50   ~ 0
U8-Pad8
Text Label 6550 -2400 2    50   ~ 0
U8-Pad7
Text Label 6550 -2650 2    50   ~ 0
U8-Pad5
Text Label 6550 -2750 2    50   ~ 0
U8-Pad6
$Comp
L power:+5V #PWR0104
U 1 1 5D88DED6
P 6900 -2900
F 0 "#PWR0104" H 6900 -3050 50  0001 C CNN
F 1 "+5V" H 6915 -2727 50  0000 C CNN
F 2 "" H 6900 -2900 50  0001 C CNN
F 3 "" H 6900 -2900 50  0001 C CNN
	1    6900 -2900
	1    0    0    -1  
$EndComp
Text Label 9025 -2600 0    50   ~ 0
8
Text Label 9025 -2450 0    50   ~ 0
SCK(1)
NoConn ~ 9025 -2350
Text Label 9025 -2250 0    50   ~ 0
MOSI(1)
$Comp
L power:GNDD #PWR0105
U 1 1 5D88DEEB
P 8675 -2050
F 0 "#PWR0105" H 8675 -2300 50  0001 C CNN
F 1 "GNDD" H 8679 -2205 50  0000 C CNN
F 2 "" H 8675 -2050 50  0001 C CNN
F 3 "" H 8675 -2050 50  0001 C CNN
	1    8675 -2050
	1    0    0    -1  
$EndComp
Text Label 8325 -2250 2    50   ~ 0
U8-Pad8
Text Label 8325 -2350 2    50   ~ 0
U8-Pad7
Text Label 8325 -2600 2    50   ~ 0
U8-Pad5
Text Label 8325 -2700 2    50   ~ 0
U8-Pad6
$Comp
L power:+5V #PWR0106
U 1 1 5D88DEF5
P 8675 -2850
F 0 "#PWR0106" H 8675 -3000 50  0001 C CNN
F 1 "+5V" H 8690 -2677 50  0000 C CNN
F 2 "" H 8675 -2850 50  0001 C CNN
F 3 "" H 8675 -2850 50  0001 C CNN
	1    8675 -2850
	1    0    0    -1  
$EndComp
Text Label 10625 -2625 0    50   ~ 0
8
Text Label 10625 -2475 0    50   ~ 0
SCK(1)
NoConn ~ 10625 -2375
Text Label 10625 -2275 0    50   ~ 0
MOSI(1)
$Comp
L power:GNDD #PWR0107
U 1 1 5D88DF0A
P 10275 -2075
F 0 "#PWR0107" H 10275 -2325 50  0001 C CNN
F 1 "GNDD" H 10279 -2230 50  0000 C CNN
F 2 "" H 10275 -2075 50  0001 C CNN
F 3 "" H 10275 -2075 50  0001 C CNN
	1    10275 -2075
	1    0    0    -1  
$EndComp
Text Label 9925 -2275 2    50   ~ 0
U8-Pad8
Text Label 9925 -2375 2    50   ~ 0
U8-Pad7
Text Label 9925 -2625 2    50   ~ 0
U8-Pad5
Text Label 9925 -2725 2    50   ~ 0
U8-Pad6
$Comp
L power:+5V #PWR0108
U 1 1 5D88DF14
P 10275 -2875
F 0 "#PWR0108" H 10275 -3025 50  0001 C CNN
F 1 "+5V" H 10290 -2702 50  0000 C CNN
F 2 "" H 10275 -2875 50  0001 C CNN
F 3 "" H 10275 -2875 50  0001 C CNN
	1    10275 -2875
	1    0    0    -1  
$EndComp
Text Label 12250 -2600 0    50   ~ 0
8
Text Label 12250 -2450 0    50   ~ 0
SCK(1)
NoConn ~ 12250 -2350
Text Label 12250 -2250 0    50   ~ 0
MOSI(1)
$Comp
L power:GNDD #PWR0109
U 1 1 5D88DF29
P 11900 -2050
F 0 "#PWR0109" H 11900 -2300 50  0001 C CNN
F 1 "GNDD" H 11904 -2205 50  0000 C CNN
F 2 "" H 11900 -2050 50  0001 C CNN
F 3 "" H 11900 -2050 50  0001 C CNN
	1    11900 -2050
	1    0    0    -1  
$EndComp
Text Label 11550 -2250 2    50   ~ 0
U8-Pad8
Text Label 11550 -2350 2    50   ~ 0
U8-Pad7
Text Label 11550 -2600 2    50   ~ 0
U8-Pad5
Text Label 11550 -2700 2    50   ~ 0
U8-Pad6
$Comp
L power:+5V #PWR0110
U 1 1 5D88DF33
P 11900 -2850
F 0 "#PWR0110" H 11900 -3000 50  0001 C CNN
F 1 "+5V" H 11915 -2677 50  0000 C CNN
F 2 "" H 11900 -2850 50  0001 C CNN
F 3 "" H 11900 -2850 50  0001 C CNN
	1    11900 -2850
	1    0    0    -1  
$EndComp
Text Label 14000 -2575 0    50   ~ 0
8
Text Label 14000 -2425 0    50   ~ 0
SCK(1)
NoConn ~ 14000 -2325
Text Label 14000 -2225 0    50   ~ 0
MOSI(1)
$Comp
L power:GNDD #PWR0111
U 1 1 5D88DF48
P 13650 -2025
F 0 "#PWR0111" H 13650 -2275 50  0001 C CNN
F 1 "GNDD" H 13654 -2180 50  0000 C CNN
F 2 "" H 13650 -2025 50  0001 C CNN
F 3 "" H 13650 -2025 50  0001 C CNN
	1    13650 -2025
	1    0    0    -1  
$EndComp
Text Label 13300 -2225 2    50   ~ 0
U8-Pad8
Text Label 13300 -2325 2    50   ~ 0
U8-Pad7
Text Label 13300 -2575 2    50   ~ 0
U8-Pad5
Text Label 13300 -2675 2    50   ~ 0
U8-Pad6
$Comp
L power:+5V #PWR0112
U 1 1 5D88DF52
P 13650 -2825
F 0 "#PWR0112" H 13650 -2975 50  0001 C CNN
F 1 "+5V" H 13665 -2652 50  0000 C CNN
F 2 "" H 13650 -2825 50  0001 C CNN
F 3 "" H 13650 -2825 50  0001 C CNN
	1    13650 -2825
	1    0    0    -1  
$EndComp
Text Label 15525 -2575 0    50   ~ 0
8
Text Label 15525 -2425 0    50   ~ 0
SCK(1)
NoConn ~ 15525 -2325
Text Label 15525 -2225 0    50   ~ 0
MOSI(1)
$Comp
L power:GNDD #PWR0113
U 1 1 5D88DF67
P 15175 -2025
F 0 "#PWR0113" H 15175 -2275 50  0001 C CNN
F 1 "GNDD" H 15179 -2180 50  0000 C CNN
F 2 "" H 15175 -2025 50  0001 C CNN
F 3 "" H 15175 -2025 50  0001 C CNN
	1    15175 -2025
	1    0    0    -1  
$EndComp
Text Label 14825 -2225 2    50   ~ 0
U8-Pad8
Text Label 14825 -2325 2    50   ~ 0
U8-Pad7
Text Label 14825 -2575 2    50   ~ 0
U8-Pad5
Text Label 14825 -2675 2    50   ~ 0
U8-Pad6
$Comp
L power:+5V #PWR0114
U 1 1 5D88DF71
P 15175 -2825
F 0 "#PWR0114" H 15175 -2975 50  0001 C CNN
F 1 "+5V" H 15190 -2652 50  0000 C CNN
F 2 "" H 15175 -2825 50  0001 C CNN
F 3 "" H 15175 -2825 50  0001 C CNN
	1    15175 -2825
	1    0    0    -1  
$EndComp
Text Label 7225 -4475 0    50   ~ 0
8
Text Label 7225 -4325 0    50   ~ 0
SCK(1)
NoConn ~ 7225 -4225
Text Label 7225 -4125 0    50   ~ 0
MOSI(1)
$Comp
L power:GNDD #PWR0115
U 1 1 5D8ACEFB
P 6875 -3925
F 0 "#PWR0115" H 6875 -4175 50  0001 C CNN
F 1 "GNDD" H 6879 -4080 50  0000 C CNN
F 2 "" H 6875 -3925 50  0001 C CNN
F 3 "" H 6875 -3925 50  0001 C CNN
	1    6875 -3925
	1    0    0    -1  
$EndComp
Text Label 6525 -4125 2    50   ~ 0
U8-Pad8
Text Label 6525 -4225 2    50   ~ 0
U8-Pad7
$Comp
L power:+5V #PWR0116
U 1 1 5D8ACF05
P 6875 -4725
F 0 "#PWR0116" H 6875 -4875 50  0001 C CNN
F 1 "+5V" H 6890 -4552 50  0000 C CNN
F 2 "" H 6875 -4725 50  0001 C CNN
F 3 "" H 6875 -4725 50  0001 C CNN
	1    6875 -4725
	1    0    0    -1  
$EndComp
Text Label 9000 -4425 0    50   ~ 0
8
Text Label 9000 -4275 0    50   ~ 0
SCK(1)
NoConn ~ 9000 -4175
Text Label 9000 -4075 0    50   ~ 0
MOSI(1)
$Comp
L power:GNDD #PWR0117
U 1 1 5D8ACF1A
P 8650 -3875
F 0 "#PWR0117" H 8650 -4125 50  0001 C CNN
F 1 "GNDD" H 8654 -4030 50  0000 C CNN
F 2 "" H 8650 -3875 50  0001 C CNN
F 3 "" H 8650 -3875 50  0001 C CNN
	1    8650 -3875
	1    0    0    -1  
$EndComp
Text Label 8300 -4075 2    50   ~ 0
U8-Pad8
Text Label 8300 -4175 2    50   ~ 0
U8-Pad7
$Comp
L power:+5V #PWR0118
U 1 1 5D8ACF24
P 8650 -4675
F 0 "#PWR0118" H 8650 -4825 50  0001 C CNN
F 1 "+5V" H 8665 -4502 50  0000 C CNN
F 2 "" H 8650 -4675 50  0001 C CNN
F 3 "" H 8650 -4675 50  0001 C CNN
	1    8650 -4675
	1    0    0    -1  
$EndComp
Text Label 10600 -4450 0    50   ~ 0
8
Text Label 10600 -4300 0    50   ~ 0
SCK(1)
NoConn ~ 10600 -4200
Text Label 10600 -4100 0    50   ~ 0
MOSI(1)
$Comp
L power:GNDD #PWR0119
U 1 1 5D8ACF39
P 10250 -3900
F 0 "#PWR0119" H 10250 -4150 50  0001 C CNN
F 1 "GNDD" H 10254 -4055 50  0000 C CNN
F 2 "" H 10250 -3900 50  0001 C CNN
F 3 "" H 10250 -3900 50  0001 C CNN
	1    10250 -3900
	1    0    0    -1  
$EndComp
Text Label 9900 -4100 2    50   ~ 0
U8-Pad8
Text Label 9900 -4200 2    50   ~ 0
U8-Pad7
Text Label 9900 -4450 2    50   ~ 0
U8-Pad5
Text Label 9900 -4550 2    50   ~ 0
U8-Pad6
$Comp
L power:+5V #PWR0120
U 1 1 5D8ACF43
P 10250 -4700
F 0 "#PWR0120" H 10250 -4850 50  0001 C CNN
F 1 "+5V" H 10265 -4527 50  0000 C CNN
F 2 "" H 10250 -4700 50  0001 C CNN
F 3 "" H 10250 -4700 50  0001 C CNN
	1    10250 -4700
	1    0    0    -1  
$EndComp
Text Label 12225 -4425 0    50   ~ 0
8
Text Label 12225 -4275 0    50   ~ 0
SCK(1)
NoConn ~ 12225 -4175
Text Label 12225 -4075 0    50   ~ 0
MOSI(1)
$Comp
L power:GNDD #PWR0121
U 1 1 5D8ACF58
P 11875 -3875
F 0 "#PWR0121" H 11875 -4125 50  0001 C CNN
F 1 "GNDD" H 11879 -4030 50  0000 C CNN
F 2 "" H 11875 -3875 50  0001 C CNN
F 3 "" H 11875 -3875 50  0001 C CNN
	1    11875 -3875
	1    0    0    -1  
$EndComp
Text Label 11525 -4075 2    50   ~ 0
U8-Pad8
Text Label 11525 -4175 2    50   ~ 0
U8-Pad7
Text Label 11525 -4425 2    50   ~ 0
U8-Pad5
Text Label 11525 -4525 2    50   ~ 0
U8-Pad6
$Comp
L power:+5V #PWR0122
U 1 1 5D8ACF62
P 11875 -4675
F 0 "#PWR0122" H 11875 -4825 50  0001 C CNN
F 1 "+5V" H 11890 -4502 50  0000 C CNN
F 2 "" H 11875 -4675 50  0001 C CNN
F 3 "" H 11875 -4675 50  0001 C CNN
	1    11875 -4675
	1    0    0    -1  
$EndComp
Text Label 13975 -4400 0    50   ~ 0
8
Text Label 13975 -4250 0    50   ~ 0
SCK(1)
NoConn ~ 13975 -4150
Text Label 13975 -4050 0    50   ~ 0
MOSI(1)
$Comp
L power:GNDD #PWR0123
U 1 1 5D8ACF77
P 13625 -3850
F 0 "#PWR0123" H 13625 -4100 50  0001 C CNN
F 1 "GNDD" H 13629 -4005 50  0000 C CNN
F 2 "" H 13625 -3850 50  0001 C CNN
F 3 "" H 13625 -3850 50  0001 C CNN
	1    13625 -3850
	1    0    0    -1  
$EndComp
Text Label 13275 -4050 2    50   ~ 0
U8-Pad8
Text Label 13275 -4150 2    50   ~ 0
U8-Pad7
Text Label 13275 -4400 2    50   ~ 0
U8-Pad5
Text Label 13275 -4500 2    50   ~ 0
U8-Pad6
$Comp
L power:+5V #PWR0124
U 1 1 5D8ACF81
P 13625 -4650
F 0 "#PWR0124" H 13625 -4800 50  0001 C CNN
F 1 "+5V" H 13640 -4477 50  0000 C CNN
F 2 "" H 13625 -4650 50  0001 C CNN
F 3 "" H 13625 -4650 50  0001 C CNN
	1    13625 -4650
	1    0    0    -1  
$EndComp
Text Label 15500 -4400 0    50   ~ 0
8
Text Label 15500 -4250 0    50   ~ 0
SCK(1)
NoConn ~ 15500 -4150
Text Label 15500 -4050 0    50   ~ 0
MOSI(1)
$Comp
L power:GNDD #PWR0125
U 1 1 5D8ACF96
P 15150 -3850
F 0 "#PWR0125" H 15150 -4100 50  0001 C CNN
F 1 "GNDD" H 15154 -4005 50  0000 C CNN
F 2 "" H 15150 -3850 50  0001 C CNN
F 3 "" H 15150 -3850 50  0001 C CNN
	1    15150 -3850
	1    0    0    -1  
$EndComp
Text Label 14800 -4050 2    50   ~ 0
U8-Pad8
Text Label 14800 -4150 2    50   ~ 0
U8-Pad7
Text Label 14800 -4400 2    50   ~ 0
U8-Pad5
Text Label 14800 -4500 2    50   ~ 0
U8-Pad6
$Comp
L power:+5V #PWR0126
U 1 1 5D8ACFA0
P 15150 -4650
F 0 "#PWR0126" H 15150 -4800 50  0001 C CNN
F 1 "+5V" H 15165 -4477 50  0000 C CNN
F 2 "" H 15150 -4650 50  0001 C CNN
F 3 "" H 15150 -4650 50  0001 C CNN
	1    15150 -4650
	1    0    0    -1  
$EndComp
Text Label 7200 -6300 0    50   ~ 0
8
Text Label 7200 -6150 0    50   ~ 0
SCK(1)
NoConn ~ 7200 -6050
Text Label 7200 -5950 0    50   ~ 0
MOSI(1)
$Comp
L power:GNDD #PWR0127
U 1 1 5D8CCFA8
P 6850 -5750
F 0 "#PWR0127" H 6850 -6000 50  0001 C CNN
F 1 "GNDD" H 6854 -5905 50  0000 C CNN
F 2 "" H 6850 -5750 50  0001 C CNN
F 3 "" H 6850 -5750 50  0001 C CNN
	1    6850 -5750
	1    0    0    -1  
$EndComp
Text Label 6500 -5950 2    50   ~ 0
U8-Pad8
Text Label 6500 -6050 2    50   ~ 0
U8-Pad7
$Comp
L power:+5V #PWR0128
U 1 1 5D8CCFB2
P 6850 -6550
F 0 "#PWR0128" H 6850 -6700 50  0001 C CNN
F 1 "+5V" H 6865 -6377 50  0000 C CNN
F 2 "" H 6850 -6550 50  0001 C CNN
F 3 "" H 6850 -6550 50  0001 C CNN
	1    6850 -6550
	1    0    0    -1  
$EndComp
Text Label 8975 -6250 0    50   ~ 0
8
Text Label 8975 -6100 0    50   ~ 0
SCK(1)
NoConn ~ 8975 -6000
Text Label 8975 -5900 0    50   ~ 0
MOSI(1)
$Comp
L power:GNDD #PWR0129
U 1 1 5D8CCFC7
P 8625 -5700
F 0 "#PWR0129" H 8625 -5950 50  0001 C CNN
F 1 "GNDD" H 8629 -5855 50  0000 C CNN
F 2 "" H 8625 -5700 50  0001 C CNN
F 3 "" H 8625 -5700 50  0001 C CNN
	1    8625 -5700
	1    0    0    -1  
$EndComp
Text Label 8275 -5900 2    50   ~ 0
U8-Pad8
Text Label 8275 -6000 2    50   ~ 0
U8-Pad7
Text Label 8275 -6250 2    50   ~ 0
U8-Pad5
Text Label 8275 -6350 2    50   ~ 0
U8-Pad6
$Comp
L power:+5V #PWR0130
U 1 1 5D8CCFD1
P 8625 -6500
F 0 "#PWR0130" H 8625 -6650 50  0001 C CNN
F 1 "+5V" H 8640 -6327 50  0000 C CNN
F 2 "" H 8625 -6500 50  0001 C CNN
F 3 "" H 8625 -6500 50  0001 C CNN
	1    8625 -6500
	1    0    0    -1  
$EndComp
Text Label 10575 -6275 0    50   ~ 0
8
Text Label 10575 -6125 0    50   ~ 0
SCK(1)
NoConn ~ 10575 -6025
Text Label 10575 -5925 0    50   ~ 0
MOSI(1)
$Comp
L power:GNDD #PWR0131
U 1 1 5D8CCFE6
P 10225 -5725
F 0 "#PWR0131" H 10225 -5975 50  0001 C CNN
F 1 "GNDD" H 10229 -5880 50  0000 C CNN
F 2 "" H 10225 -5725 50  0001 C CNN
F 3 "" H 10225 -5725 50  0001 C CNN
	1    10225 -5725
	1    0    0    -1  
$EndComp
Text Label 9875 -5925 2    50   ~ 0
U8-Pad8
Text Label 9875 -6025 2    50   ~ 0
U8-Pad7
Text Label 9875 -6275 2    50   ~ 0
U8-Pad5
Text Label 9875 -6375 2    50   ~ 0
U8-Pad6
$Comp
L power:+5V #PWR0132
U 1 1 5D8CCFF0
P 10225 -6525
F 0 "#PWR0132" H 10225 -6675 50  0001 C CNN
F 1 "+5V" H 10240 -6352 50  0000 C CNN
F 2 "" H 10225 -6525 50  0001 C CNN
F 3 "" H 10225 -6525 50  0001 C CNN
	1    10225 -6525
	1    0    0    -1  
$EndComp
Text Label 12200 -6250 0    50   ~ 0
8
Text Label 12200 -6100 0    50   ~ 0
SCK(1)
NoConn ~ 12200 -6000
Text Label 12200 -5900 0    50   ~ 0
MOSI(1)
$Comp
L power:GNDD #PWR0133
U 1 1 5D8CD005
P 11850 -5700
F 0 "#PWR0133" H 11850 -5950 50  0001 C CNN
F 1 "GNDD" H 11854 -5855 50  0000 C CNN
F 2 "" H 11850 -5700 50  0001 C CNN
F 3 "" H 11850 -5700 50  0001 C CNN
	1    11850 -5700
	1    0    0    -1  
$EndComp
Text Label 11500 -5900 2    50   ~ 0
U8-Pad8
Text Label 11500 -6000 2    50   ~ 0
U8-Pad7
Text Label 11500 -6250 2    50   ~ 0
U8-Pad5
Text Label 11500 -6350 2    50   ~ 0
U8-Pad6
$Comp
L power:+5V #PWR0134
U 1 1 5D8CD00F
P 11850 -6500
F 0 "#PWR0134" H 11850 -6650 50  0001 C CNN
F 1 "+5V" H 11865 -6327 50  0000 C CNN
F 2 "" H 11850 -6500 50  0001 C CNN
F 3 "" H 11850 -6500 50  0001 C CNN
	1    11850 -6500
	1    0    0    -1  
$EndComp
Text Label 13950 -6225 0    50   ~ 0
8
Text Label 13950 -6075 0    50   ~ 0
SCK(1)
NoConn ~ 13950 -5975
Text Label 13950 -5875 0    50   ~ 0
MOSI(1)
$Comp
L power:GNDD #PWR0135
U 1 1 5D8CD024
P 13600 -5675
F 0 "#PWR0135" H 13600 -5925 50  0001 C CNN
F 1 "GNDD" H 13604 -5830 50  0000 C CNN
F 2 "" H 13600 -5675 50  0001 C CNN
F 3 "" H 13600 -5675 50  0001 C CNN
	1    13600 -5675
	1    0    0    -1  
$EndComp
Text Label 13250 -5875 2    50   ~ 0
U8-Pad8
Text Label 13250 -5975 2    50   ~ 0
U8-Pad7
Text Label 13250 -6225 2    50   ~ 0
U8-Pad5
Text Label 13250 -6325 2    50   ~ 0
U8-Pad6
$Comp
L power:+5V #PWR0136
U 1 1 5D8CD02E
P 13600 -6475
F 0 "#PWR0136" H 13600 -6625 50  0001 C CNN
F 1 "+5V" H 13615 -6302 50  0000 C CNN
F 2 "" H 13600 -6475 50  0001 C CNN
F 3 "" H 13600 -6475 50  0001 C CNN
	1    13600 -6475
	1    0    0    -1  
$EndComp
Text Label 15475 -6225 0    50   ~ 0
8
Text Label 15475 -6075 0    50   ~ 0
SCK(1)
NoConn ~ 15475 -5975
Text Label 15475 -5875 0    50   ~ 0
MOSI(1)
$Comp
L power:GNDD #PWR0137
U 1 1 5D8CD043
P 15125 -5675
F 0 "#PWR0137" H 15125 -5925 50  0001 C CNN
F 1 "GNDD" H 15129 -5830 50  0000 C CNN
F 2 "" H 15125 -5675 50  0001 C CNN
F 3 "" H 15125 -5675 50  0001 C CNN
	1    15125 -5675
	1    0    0    -1  
$EndComp
Text Label 14775 -5875 2    50   ~ 0
U8-Pad8
Text Label 14775 -5975 2    50   ~ 0
U8-Pad7
Text Label 14775 -6225 2    50   ~ 0
U8-Pad5
Text Label 14775 -6325 2    50   ~ 0
U8-Pad6
$Comp
L power:+5V #PWR0138
U 1 1 5D8CD04D
P 15125 -6475
F 0 "#PWR0138" H 15125 -6625 50  0001 C CNN
F 1 "+5V" H 15140 -6302 50  0000 C CNN
F 2 "" H 15125 -6475 50  0001 C CNN
F 3 "" H 15125 -6475 50  0001 C CNN
	1    15125 -6475
	1    0    0    -1  
$EndComp
Wire Wire Line
	3225 5350 3225 5450
Connection ~ 3800 5450
Wire Wire Line
	2325 5450 3225 5450
Connection ~ 3225 5450
$Comp
L power:+5V #PWR0141
U 1 1 5DABF2CF
P 2750 5200
F 0 "#PWR0141" H 2750 5050 50  0001 C CNN
F 1 "+5V" H 2750 5375 50  0000 C CNN
F 2 "" H 2750 5200 50  0001 C CNN
F 3 "" H 2750 5200 50  0001 C CNN
	1    2750 5200
	1    0    0    -1  
$EndComp
Wire Wire Line
	2925 5050 2925 5200
Wire Wire Line
	2925 5200 2750 5200
Wire Wire Line
	3700 5050 3575 5050
Wire Wire Line
	3575 5050 3525 5050
Connection ~ 3575 5050
Wire Wire Line
	3575 5250 3575 5450
Wire Wire Line
	3225 5450 3575 5450
Wire Wire Line
	3575 5450 3800 5450
Connection ~ 3575 5450
$Comp
L audiojack3_ground_switchtr:AudioJack3_Ground_SwitchTR J1
U 1 1 5C536746
P 1500 4800
F 0 "J1" H 1175 4775 50  0000 L CNN
F 1 "Conn_3.5mm" H 1050 5025 50  0000 L CNN
F 2 "multipackage:Jack_3.5mm_CUI_SJ1-3534NS_Horizontal_CircularHoles" H 1500 4800 50  0001 C CNN
F 3 " ~" H 1500 4800 50  0001 C CNN
F 4 "25 Requires Kapton tape affixed all around to protect from electrical shorts against surrounding conductors: use two+ layers if expecting user/operator forces.  Place, then check work for inadvertent shorts and opens" H -500 3150 50  0001 C CNN "ClickToSortForPlacement"
F 5 "SJ1-3534NS; Kapton tape: 3057" H 1500 4800 50  0001 C CNN "Part_number"
F 6 "http://Arrow.com" H 1500 4800 50  0001 C CNN "Source"
	1    1500 4800
	1    0    0    1   
$EndComp
$Comp
L newkicadversion-rescue:AD8244ARMZ-AD8244_A U2
U 4 1 5C72CF84
P 14150 6400
F 0 "U2" H 14300 6500 50  0000 C CNN
F 1 "AD8244ARMZ" H 14450 6300 50  0000 C CNN
F 2 "multipackage:MSOP-10_3x3mm_P0.5mm" H 14150 6400 50  0001 C CNN
F 3 "http://static6.arrow.com/aropdfconversion/427f47d0fc5e4caf484beffd27781384154f9c66/33171669476397452ad8244.pdf" H 14150 6400 50  0001 C CNN
F 4 "01" H 11450 600 50  0001 C CNN "PlacementOrder"
F 5 "01" H 11450 750 50  0001 C CNN "SortForPlacement"
F 6 "AD8244ARMZ-R7" H 14150 6400 50  0001 C CNN "Part_number"
F 7 "http://Arrow.com" H 14150 6400 50  0001 C CNN "Source"
F 8 "03 Check corner pads for adequate bare metal: ensure the solder mask of all corner pads is scraped off. Place then check work." H 14150 6400 50  0001 C CNN "ClickToSortForPlacement"
	4    14150 6400
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x01 P1
U 1 1 5C7F64C7
P 22500 647
F 0 "P1" V 22600 647 50  0000 C CNN
F 1 "CONN_01X01" V 22600 647 50  0001 C CNN
F 2 "TestPoint:TestPoint_Keystone_5010-5014_Multipurpose" H 22421 721 20  0001 C CNN
F 3 "" H 22500 647 50  0000 C CNN
F 4 "999 " H 11650 -25 50  0001 C CNN "ClickToSortForPlacement"
F 5 "n/a" H 22500 647 50  0001 C CNN "Part_number"
F 6 "0 For clarity: [If not shown] U9-U33 must be ordered as well.  Same part number and source as U8, so order a qty 26 of U8 part number. Also, some components in this project are assigned to multiple sources, sure sure to decide where you'll buy those components from before ordering anything from anywhere so you won't end up ordering them on their own order and incurring additional costs in doing so." H 22500 647 50  0001 C CNN "Source"
	1    22500 647 
	0    -1   -1   0   
$EndComp
$Comp
L Connector_Generic:Conn_01x01 P2
U 1 1 5C7F64CE
P 22600 647
F 0 "P2" V 22700 647 50  0000 C CNN
F 1 "CONN_01X01" V 22700 647 50  0001 C CNN
F 2 "TestPoint:TestPoint_Keystone_5010-5014_Multipurpose" H 22600 647 20  0001 C CNN
F 3 "" H 22600 647 50  0000 C CNN
F 4 "999 " H 11650 -25 50  0001 C CNN "ClickToSortForPlacement"
F 5 "n/a" H 22600 647 50  0001 C CNN "Part_number"
F 6 "0 For clarity: [If not shown] U9-U33 must be ordered as well.  Same part number and source as U8, so order a qty 26 of U8 part number. Also, some components in this project are assigned to multiple sources, sure sure to decide where you'll buy those components from before ordering anything from anywhere so you won't end up ordering them on their own order and incurring additional costs in doing so." H 22600 647 50  0001 C CNN "Source"
	1    22600 647 
	0    -1   -1   0   
$EndComp
$Comp
L Connector_Generic:Conn_01x01 P3
U 1 1 5C7F64D5
P 22700 647
F 0 "P3" V 22800 647 50  0000 C CNN
F 1 "CONN_01X01" V 22800 647 50  0001 C CNN
F 2 "TestPoint:TestPoint_Keystone_5010-5014_Multipurpose" V 22700 647 20  0001 C CNN
F 3 "" H 22700 647 50  0000 C CNN
F 4 "999 " H 11650 -25 50  0001 C CNN "ClickToSortForPlacement"
F 5 "n/a" H 22700 647 50  0001 C CNN "Part_number"
F 6 "0 For clarity: [If not shown] U9-U33 must be ordered as well.  Same part number and source as U8, so order a qty 26 of U8 part number. Also, some components in this project are assigned to multiple sources, sure sure to decide where you'll buy those components from before ordering anything from anywhere so you won't end up ordering them on their own order and incurring additional costs in doing so." H 22700 647 50  0001 C CNN "Source"
	1    22700 647 
	0    -1   -1   0   
$EndComp
$Comp
L Connector_Generic:Conn_01x01 P4
U 1 1 5C7F64DC
P 22800 647
F 0 "P4" V 22900 647 50  0000 C CNN
F 1 "CONN_01X01" V 22900 647 50  0001 C CNN
F 2 "TestPoint:TestPoint_Keystone_5010-5014_Multipurpose" H 22724 569 20  0001 C CNN
F 3 "" H 22800 647 50  0000 C CNN
F 4 "999 " H 11650 -25 50  0001 C CNN "ClickToSortForPlacement"
F 5 "n/a" H 22800 647 50  0001 C CNN "Part_number"
F 6 "0 For clarity: [If not shown] U9-U33 must be ordered as well.  Same part number and source as U8, so order a qty 26 of U8 part number. Also, some components in this project are assigned to multiple sources, sure sure to decide where you'll buy those components from before ordering anything from anywhere so you won't end up ordering them on their own order and incurring additional costs in doing so." H 22800 647 50  0001 C CNN "Source"
	1    22800 647 
	0    -1   -1   0   
$EndComp
$Comp
L Connector_Generic:Conn_02x03_Odd_Even ICSP1
U 1 1 5C7F651F
P 20775 4250
F 0 "ICSP1" H 20675 4575 50  0000 C CNN
F 1 "ICSP Socket" H 20700 4500 50  0000 C CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_2x03_P2.54mm_Vertical" H 20775 4250 50  0001 C CNN
F 3 "~" H 20775 4250 50  0001 C CNN
F 4 "19 Remove the previous JP6 wire and hold the full-size JP6 in its place while placing this.   Set height with all connectors to MCU mated, some connectors may need spaced away from board or otherwise made to fit.   Place using bismuth solder if you have it (provided you used no-lead solder to pre-tin with) for easiest removal.   Then check work for inadvertent shorts and opens.  Replace JP6, if removed, with the style you want - wire or removeable shunt.  Apply Kapton tape anywhere needed as board is mated to MCU, while also ensuring no Vcc conflicts will exist." H 11575 1050 50  0001 C CNN "ClickToSortForPlacement"
F 5 "SSQ-103-03-T-D. Stackables are too often not stocked; unable to source stackable style" H 20775 4250 50  0001 C CNN "Part_number"
F 6 "http://Arrow.com" H 20775 4250 50  0001 C CNN "Source"
	1    20775 4250
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x09_Male J2
U 1 1 5C87197B
P 21350 1500
F 0 "J2" H 21450 2050 50  0000 L CNN
F 1 "Power" V 21275 1375 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x09_P2.54mm_Vertical" H 21350 1500 50  0001 C CNN
F 3 "~" H 21350 1500 50  0001 C CNN
F 4 "20 When MCU is NOT 5V, pin 5 gets removed and pin 4 gets its pad shorted to pin 5 PAD.  When MCU is switchable 5V and 3.3V and you want to be able to switch between the two levels, remove pin 5 still but tie ICSP1 pin 2 into pin 5 PAD with an insulated wire.  Height with all connectors mated, may need to space away from board some.  Place with dessicant inside using bismuth solder if you have it for easiest removal (provided you used no-lead solder to pre-tin with) .  Then check work for inadvertent shorts and opens." H 11800 -100 50  0001 C CNN "ClickToSortForPlacement"
F 5 "part of first TSW-150-05-T-S or 4-103327-0. Stackables are too often not stocked; unable to source stackable style.  Consider whether you want to get hookup wire [22-24 ga or so, stranded, multiconductor flat cable] to allow you to runs some diags before you permanently place these large connectors.  Stranded allows you to also use it with flux as solderwick)." H 21350 1500 50  0001 C CNN "Part_number"
F 6 "http://Arrow.com" H 21350 1500 50  0001 C CNN "Source"
	1    21350 1500
	-1   0    0    -1  
$EndComp
$Comp
L conn_01x08_maleA:Conn_01x08_Male J5
U 1 1 5C8A7B72
P 21850 2500
F 0 "J5" H 21800 2900 50  0000 C CNN
F 1 "Digital" V 21600 2450 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x08_P2.54mm_Vertical" H 21850 2500 50  0001 C CNN
F 3 "~" H 21850 2500 50  0001 C CNN
F 4 "21 Set height with all connectors mated, may need to space away from board some.   Requires more solder than single-sided components and heat for a longer time or the MCU can push the solder pads right off the board.    Use bismuth solder if you have it for easiest removal (provided you used no-lead solder to pre-tin with).  Then check work for inadvertent shorts and opens.  Power up and run diags.  Power down and continue." H 11650 0   50  0001 C CNN "ClickToSortForPlacement"
F 5 "part of first TSW-150-05-T-S or 4-103327-0. Stackables are too often not stocked; unable to source stackable style" H 21850 2500 50  0001 C CNN "Part_number"
F 6 "http://Arrow.com" H 21850 2500 50  0001 C CNN "Source"
	1    21850 2500
	1    0    0    -1  
$EndComp
$Comp
L Device:LED D1
U 1 1 5CC7E1A3
P 11575 11650
F 0 "D1" V 11597 11825 50  0000 R CNN
F 1 "Red: Electrodes shorted" H 12622 11750 50  0000 R CNN
F 2 "multipackage:LED_Rectangular_W5.0mm_H2.0mm" H 11575 11650 50  0001 C CNN
F 3 "~" H 11575 11650 50  0001 C CNN
F 4 "07" H 4925 9250 50  0001 C CNN "PlacementOrder"
F 5 "07" H 4925 9250 50  0001 C CNN "SortForPlacement"
F 6 "08 (Once these get placed, the board won't lay level for placing the other back side components...consider doing those before this if you don't have a heat-resistant, light duty board leveling plan: C3, C4, R8, U6)   For appearance's sake, bend leads all identically.  Then re-tin the pads to the lowest melting point eutectic solder you are able to, then use that same solder to place since LEDs have a very low tolerance to soldering temperatures.  Trying to use dissimilar solder to change the type of tinning will undesireably raise the melting temperature." H 4925 9250 50  0001 C CNN "ClickToSortForPlacement"
F 7 "SSL-LX2573ID" H 11575 11650 50  0001 C CNN "Part_number"
F 8 "http://Arrow.com" H 11575 11650 50  0001 C CNN "Source"
	1    11575 11650
	0    -1   -1   0   
$EndComp
$Comp
L Device:Q_NMOS_GSD Q7
U 1 1 5C9AB0B5
P 12900 12000
F 0 "Q7" H 13100 11900 50  0000 L CNN
F 1 "DMN601K-7" H 13100 11800 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23_Handsoldering" H 13100 11925 50  0001 L CIN
F 3 "https://static6.arrow.com/aropdfconversion/d3486124b1a233cb1531c388ceb5a7bf7f78c2e6/ds30652.pdf" H 12900 12000 50  0001 L CNN
F 4 "03" H 5050 9250 50  0001 C CNN "PlacementOrder"
F 5 "03" H 5050 9250 50  0001 C CNN "SortForPlacement"
F 6 "11 Place then check work.   Heretofore has been components for you to make a judgment whether you're up to this project or not.  Use these quick diagnostics to assess your work: place D1 and D3 by some temporary means like tack soldering (minimal but functional soldering with leads not trimmed for easy removal/reinstall using lowest temp solder available) (observing polarity and leads not touching any other part of board or component condectors!!!!) either side (surface, not edge) of board.  Tack solder 5 volts and ground from unpowered Arduino or other source to ICSP1 pin 2 and ICSP1 pin 6 padded holes and connect your body (if you don't understand research anti-static wrist strap) for the remainder of this project (by a means you'll not forget to re-connect if you have to leave and come back) to circuit ground or PCB ground which most likely is NOT earth ground.   Check for any shorted wiring (especially at the tack soldered items) and apply power across 5VDC and GND and free up your hands.  The green LED should be lit.  Using some tiny metal tool, short across Q3 leads 1 to 2 a few times while watching for the red LED to light up and the green to go out while the short is being applied.  If not full success, remove power, find and fix your circuit mistakes, and try again.  Upon success, remove power.  Tack solder D2.  Fashion a probe wire long enough to touch the probed end to anywhere on the board while the unprobed end is tack soldered to J5 pin pad 1.  Temporary tack solder J2 pin 5 (when MCU is 5V) or J2 pin 4 with its pad shorted to J2 pin 5 pad and J2 pin 5 pin is removed indefinitely or permanently (when MCU is 3.3V) only." H 5050 9250 50  0001 C CNN "ClickToSortForPlacement"
F 7 "DMN601K-7" H 12900 12000 50  0001 C CNN "Part_number"
F 8 "http://Arrow.com" H 12900 12000 50  0001 C CNN "Source"
	1    12900 12000
	1    0    0    -1  
$EndComp
$Comp
L Device:LED D3
U 1 1 5C9AB15E
P 13000 11650
F 0 "D3" V 13100 11650 50  0000 R CNN
F 1 "Green: Proper electrode conductance" H 14900 11750 50  0000 R CNN
F 2 "multipackage:LED_Rectangular_W5.0mm_H2.0mm_green" H 13000 11650 50  0001 C CNN
F 3 "~" H 13000 11650 50  0001 C CNN
F 4 "07" H 5050 9250 50  0001 C CNN "PlacementOrder"
F 5 "07" H 5050 9250 50  0001 C CNN "SortForPlacement"
F 6 "09 Place, then check work" H 5050 9250 50  0001 C CNN "ClickToSortForPlacement"
F 7 "http://Arrow.com" H 13000 11650 50  0001 C CNN "Source"
F 8 "SSL-LX2573GD" H 13000 11650 50  0001 C CNN "Part_number"
	1    13000 11650
	0    -1   -1   0   
$EndComp
$Comp
L Device:R_Small_US R14
U 1 1 5C9AB204
P 13000 11300
F 0 "R14" H 12875 11297 50  0000 C CNN
F 1 "470 Ω" H 13175 11297 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 13040 11290 50  0001 C CNN
F 3 "~" H 13000 11300 50  0001 C CNN
F 4 "02" H 5050 9200 50  0001 C CNN "PlacementOrder"
F 5 "02" H 5050 9200 50  0001 C CNN "SortForPlacement"
F 6 "06 Place then check work" H 5050 9200 50  0001 C CNN "ClickToSortForPlacement"
F 7 "RC0603JR-07470RL" H 13000 11300 50  0001 C CNN "Part_number"
F 8 "http://Arrow.com" H 13000 11300 50  0001 C CNN "Source"
	1    13000 11300
	1    0    0    -1  
$EndComp
$Comp
L Device:R_POT_US VR2
U 1 1 5CB70AF8
P 21450 9275
F 0 "VR2" H 21382 9229 50  0000 R CNN
F 1 "200 KΩ" H 21382 9320 50  0000 R CNN
F 2 "multipackage:Potentiometer_Bourns_PTV09A-2_Single_Horizontal" H 21450 9275 50  0001 C CNN
F 3 "https://www.bourns.com/docs/Product-Datasheets/PTV09.pdf" H 21450 9275 50  0001 C CNN
F 4 "28 Power down first, remove solder-bridges of JP1-3 no cuts needed, check work for inadvertent shorts and opens after" H 12490 3545 50  0001 C CNN "ClickToSortForPlacement"
F 5 "PTV09A-2030U-B204 or may end in B203 or some resistance in between those.  The 2030 may be 2020 or 2015 for shorter shaft" H 21450 9275 50  0001 C CNN "Part_number"
F 6 "http://Arrow.com" H 21450 9275 50  0001 C CNN "Source"
	1    21450 9275
	-1   0    0    1   
$EndComp
$Comp
L Device:R_POT_US VR1
U 1 1 5DCBBC4B
P 20800 9275
F 0 "VR1" H 20732 9229 50  0000 R CNN
F 1 "200 KΩ" H 20732 9320 50  0000 R CNN
F 2 "multipackage:Potentiometer_Bourns_PTV09A-2_Single_Horizontal" H 20800 9275 50  0001 C CNN
F 3 "https://www.bourns.com/docs/Product-Datasheets/PTV09.pdf" H 20800 9275 50  0001 C CNN
F 4 "28 Don't solder, merely press against sides of holes inside them with power on and diags running.  When A0 diags are successful, power down, pull boards apart with great care, then remove J3 and attach it again with a tack solder to J3 pin 2. Power up and run A1 diags using VR2 position similarly (inserted without soldering).   When A1 diags are successful power down, then remove J2, 3, & 4, R1 and solder-bridges of JP1-3 no cuts needed, check work for inadvertent shorts and opens after" H 11840 3545 50  0001 C CNN "ClickToSortForPlacement"
F 5 "PTV09A-2030U-B204 or may end in B203 or some resistance in between those.  The 2030 may be 2020 or 2015 for shorter shaft" H 20800 9275 50  0001 C CNN "Part_number"
F 6 "http://Arrow.com" H 20800 9275 50  0001 C CNN "Source"
	1    20800 9275
	-1   0    0    1   
$EndComp
$Comp
L conn_01x06_male:Conn_01x06_Male J3
U 1 1 5C90EA9D
P 21250 2400
F 0 "J3" H 21250 2700 50  0000 L CNN
F 1 "Analog" V 21400 2250 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x06_P2.54mm_Vertical" H 21350 2300 50  0001 C CNN
F 3 "~" H 21350 2300 50  0001 C CNN
F 4 "20 Requires more solder than single-sided components and heat for a longer time or the MCU can push the solder pads right off the board.    Place with height with all connectors mated, may need to space away from board some.  Use bismuth solder if you have it for easiest removal (provided you used no-lead solder to pre-tin with).  Then check work for inadvertent shorts and opens." H 11650 0   50  0001 C CNN "ClickToSortForPlacement"
F 5 "part of first TSW-150-05-T-S or 4-103327-0. Stackables are too often not stocked; unable to source stackable style" H 21250 2400 50  0001 C CNN "Part_number"
F 6 "http://Arrow.com" H 21250 2400 50  0001 C CNN "Source"
	1    21250 2400
	1    0    0    -1  
$EndComp
$Comp
L newkicadversion-rescue:AD8244ARMZ-AD8244_A U2
U 2 1 5F04F6CF
P 12800 4775
F 0 "U2" H 12950 4875 50  0000 C CNN
F 1 "AD8244ARMZ" H 12975 4975 50  0000 C CNN
F 2 "multipackage:MSOP-10_3x3mm_P0.5mm" H 12800 4775 50  0001 C CNN
F 3 "http://static6.arrow.com/aropdfconversion/427f47d0fc5e4caf484beffd27781384154f9c66/33171669476397452ad8244.pdf" H 12800 4775 50  0001 C CNN
F 4 "AD8244ARMZ-R7" H 12800 4775 50  0001 C CNN "Part_number"
F 5 "http://Arrow.com" H 12800 4775 50  0001 C CNN "Source"
F 6 "03 Check corner pads for adequate bare metal: ensure the solder mask of all corner pads is scraped off. Place then check work." H 12800 4775 50  0001 C CNN "ClickToSortForPlacement"
	2    12800 4775
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C4
U 1 1 5F09FFED
P 13050 3925
F 0 "C4" V 13050 3700 50  0000 C CNN
F 1 "0.1 µF" V 13050 3475 50  0000 C CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 13050 3925 50  0001 C CNN
F 3 "~" H 13050 3925 50  0001 C CNN
F 4 "08" H 7500 125 50  0001 C CNN "PlacementOrder"
F 5 "08" H 8250 75  50  0001 C CNN "SortForPlacement"
F 6 "16 Place then check work as before" H 8250 75  50  0001 C CNN "ClickToSortForPlacement"
F 7 "CL10B104KB8NNNL" H 13050 3925 50  0001 C CNN "Part_number"
F 8 "http://Arrow.com" H 13050 3925 50  0001 C CNN "Source"
	1    13050 3925
	0    -1   -1   0   
$EndComp
$Comp
L newkicadversion-rescue:HX711-hx711 ADC1
U 1 1 5C19811F
P 15350 5100
F 0 "ADC1" H 15800 4950 50  0000 C CNN
F 1 "HX711 module" H 15950 4850 50  0000 C CNN
F 2 "HX711:HX711 module" H 15800 5450 50  0001 L CNN
F 3 "http://www.ti.com/lit/ds/symlink/ads1110.pdf" H 15050 5450 50  0001 C CNN
F 4 "25 Kapton tape should be used to protect shorting to board and to MCU.  Height is set with that tape or other insulator in place and MCU fully seated plugged in.  There may not be enough clearance for socketing ADC1, otherwise socketing is far more flexible, but the pins with ADC1 might be too large for the sockets in which case use any wiring or pins that will fit.   The pins being delivered loose allow top side mounting in case where clearance with the MCU is insufficient and won't allow bottom side mounting, as in the case of the SainSmart UNO.  Run diags.  Then, KEEPING U2 PERFECTLY IMMOBILE, solder all remaining unsealed vias except the two place-assist holes at U3, and run diags once more to make sure you didn't short any vias together.  Assembly instructions after this step are UNDER CONSTRUCTION - references to obsolete jumper settings and situations can be found which you should ignore." H 10100 728 50  0001 C CNN "ClickToSortForPlacement"
F 5 "Sockets: 1 qty SL-106-T-10 + 1 qty SMC-1-04-1-GT from http://Arrow.com (sockets only, remember). Component: least cost - https://www.aliexpress.com/item/1PCS-X-HX711-modules-weigh-sensors-for-AD-module-chip-preferred-DIY-Graduation/32851591970.html?spm=2114.search0104.3.1.7ad07d02cMfLjw&ws_ab_test=searchweb0_0,searchweb201602_4_10065_10130_10068_10890_10547_319_10546_317_10548_10545_10696_453_10084_454_10083_10618_10307_537_536_10059_10884_10887_321_322_10103,searchweb201603_52,ppcSwitch_0&algo_expid=c46a3ce9-e8cf-4d7c-8e89-50e4aff4f628-0&algo_pvid=c46a3ce9-e8cf-4d7c-8e89-50e4aff4f628&transAbTest=ae803_3; fastest arrival https://www.ebay.com/itm/Dual-Channel-HX711-Weighing-Pressure-Sensor-24-bit-Precision-A-D-Module-Arduino/202679288819?hash=item2f30a083f3:g:xyIAAOSwhXtc2wdH" H 15350 5100 50  0001 C CNN "Source"
F 6 "least cost - CN1501541594; fastest arrival - Dual Channel HX711" H 15350 5100 50  0001 C CNN "Part_number"
	1    15350 5100
	1    0    0    -1  
$EndComp
$Comp
L Device:CP C3
U 1 1 5F080FB8
P 13050 3750
F 0 "C3" V 13000 3525 50  0000 C CNN
F 1 "10 µF" V 13000 3300 50  0000 C CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 13050 3750 50  0001 C CNN
F 3 "~" H 13050 3750 50  0001 C CNN
F 4 "08" H 7500 100 50  0001 C CNN "PlacementOrder"
F 5 "08" H 8250 50  50  0001 C CNN "SortForPlacement"
F 6 "16 Observe polarity if electrolytic. Place then check work as before.  " H 8250 50  50  0001 C CNN "ClickToSortForPlacement"
F 7 "CL10A106KP8NNND" H 13050 3750 50  0001 C CNN "Part_number"
F 8 "http://Arrow.com" H 13050 3750 50  0001 C CNN "Source"
	1    13050 3750
	0    -1   -1   0   
$EndComp
$Comp
L Device:Net-Tie_2 NT1
U 1 1 5D4059A2
P 15150 5600
F 0 "NT1" V 15196 5556 50  0001 R CNN
F 1 "Net-Tie_2" V 15275 5575 50  0001 R CNN
F 2 "multipackage:NetTie-2_THT_Pad1.0mm" H 15150 5600 50  0001 C CNN
F 3 "~" H 15150 5600 50  0001 C CNN
F 4 "n/a" H 15150 5600 50  0001 C CNN "Part_number"
F 5 "n/a" H 15150 5600 50  0001 C CNN "Source"
F 6 "99" H 15150 5600 50  0001 C CNN "ClickToSortForPlacement"
	1    15150 5600
	0    1    1    0   
$EndComp
$Comp
L newkicadversion-rescue:AD8244ARMZ-AD8244_A U2
U 1 1 5F04DF16
P 12800 4150
F 0 "U2" H 12900 4250 50  0000 L CNN
F 1 "AD8244ARMZ" H 13100 4250 50  0000 L CNN
F 2 "multipackage:MSOP-10_3x3mm_P0.5mm" H 12800 4150 50  0001 C CNN
F 3 "http://static6.arrow.com/aropdfconversion/427f47d0fc5e4caf484beffd27781384154f9c66/33171669476397452ad8244.pdf" H 12800 4150 50  0001 C CNN
F 4 "AD8244ARMZ-R7" H 12800 4150 50  0001 C CNN "Part_number"
F 5 "http://Arrow.com" H 12800 4150 50  0001 C CNN "Source"
F 6 "03 Check corner pads for adequate bare metal: ensure the solder mask of all corner pads is scraped off. Place then check work." H 12800 4150 50  0001 C CNN "ClickToSortForPlacement"
	1    12800 4150
	1    0    0    -1  
$EndComp
$Comp
L Device:CP C5
U 1 1 5C854E30
P 15175 4175
F 0 "C5" V 15275 4275 50  0000 C CNN
F 1 "10 µF" V 15275 4525 50  0000 C CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 15175 4175 50  0001 C CNN
F 3 "~" H 15175 4175 50  0001 C CNN
F 4 "08" H 9625 525 50  0001 C CNN "PlacementOrder"
F 5 "08" H 10375 475 50  0001 C CNN "SortForPlacement"
F 6 "14 Observe polarity if electrolytic. Place then check work as before.  " H 10375 475 50  0001 C CNN "ClickToSortForPlacement"
F 7 "CL10A106KP8NNND" H 15175 4175 50  0001 C CNN "Part_number"
F 8 "http://Arrow.com" H 15175 4175 50  0001 C CNN "Source"
	1    15175 4175
	0    1    1    0   
$EndComp
$Comp
L Device:R_Small_US R6
U 1 1 5D7C1CE7
P 13075 6500
F 0 "R6" H 13225 6500 50  0000 C CNN
F 1 "44.2 KΩ 0.1% 0.1W(1/10W) ±10ppm/°C (1676343-2)" H 11975 6575 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 13075 6500 50  0001 C CNN
F 3 "~" H 13075 6500 50  0001 C CNN
F 4 "http://Arrow.com" H 13075 6500 50  0001 C CNN "Source"
F 5 "1676343-2" H 13075 6500 50  0001 C CNN "Part_number"
F 6 "14 Note this is a precision value component so its conductive ends and black surface must remain perfectly undamaged. Place then check work as before" H 13075 6500 50  0001 C CNN "ClickToSortForPlacement"
	1    13075 6500
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small_US R7
U 1 1 5D3506B3
P 13575 6500
F 0 "R7" H 13425 6500 50  0000 C CNN
F 1 "22.6 KΩ 0.1% 0.125W(1/8W) ±10ppm/°C (ERA6ARB2262V)" H 14425 6300 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 13575 6500 50  0001 C CNN
F 3 "~" H 13575 6500 50  0001 C CNN
F 4 "http://Arrow.com" H 13575 6500 50  0001 C CNN "Source"
F 5 "ERA6ARB2262V" H 13575 6500 50  0001 C CNN "Part_number"
F 6 "14 Note this is a precision value component so its conductive ends and black surface must remain perfectly undamaged.  Place then check work as before" H 13575 6500 50  0001 C CNN "ClickToSortForPlacement"
	1    13575 6500
	1    0    0    -1  
$EndComp
$Comp
L Reference_Current:REF200AU U4
U 3 1 5D0FCC87
P 7775 6150
F 0 "U4" H 8150 6000 50  0000 L CNN
F 1 "REF200AU" H 7250 6000 50  0000 L CIN
F 2 "Package_SO:SOIC-8_3.9x4.9mm_P1.27mm" H 7650 6175 50  0001 R CIN
F 3 "www.ti.com/lit/ds/symlink/ref200.pdf" H 8075 6150 50  0001 C CIN
F 4 "http://Arrow.com" H 7775 6150 50  0001 C CNN "Source"
F 5 "REF200AU (Requires hermetic sealing, so will have dessicant with it that you'll need to place under SHLD1)" H 7775 6150 50  0001 C CNN "Part_number"
F 6 "26 Before opening this shipping package, perform as complete of diagnostics as possible of all circuitry under SHLD1 placed thus far: solder a shorting wire between pins 4 & 5 of U3 (mix & match with pins 1 of both Q1 and Q2) and load the Arduino with GWAAM-Sea Diagnostics 1 and run them.  Remove short between pins 4 and 5 of U3.  Then, from the bottom side of the board, solder seal any and all via holes left unsoldered located within SHLD1 footprint.  Solder seal any and all place-assist holes located within SHLD1 footprint except U3 place-assist holes.  All this should minimize risk of getting interrupted while U3 is left not heremetically sealed.  Tin SHLD1 around outside of bottom edge that will get soldered to its footprint.  Tin SHLD1 footprint on the board, leaving a very SMOOTH & FLAT surface to mate with SHLD1.  Prepare dessicant (trim pkg for edges to be bent over to fit inside SHLD1 holding like a pinch of the silica or clay granules & held in place by Kapton tape without putting pressure on other components) as soon as U3 is placed, and ensure SHLD1 is handy also.  Place U3 and perform diagnostics of U3.  After diags, solder-seal its place-assist holes.  Immediately perform next step." H 7775 6150 50  0001 C CNN "ClickToSortForPlacement"
	3    7775 6150
	1    0    0    -1  
$EndComp
$Comp
L Reference_Current:REF200AU U4
U 2 1 5D0FB910
P 12700 6000
F 0 "U4" H 12880 6046 50  0000 L CNN
F 1 "REF200AU" H 12880 5955 50  0000 L CIN
F 2 "Package_SO:SOIC-8_3.9x4.9mm_P1.27mm" H 12575 6025 50  0001 R CIN
F 3 "www.ti.com/lit/ds/symlink/ref200.pdf" H 13000 6000 50  0001 C CIN
F 4 "http://Arrow.com" H 12700 6000 50  0001 C CNN "Source"
F 5 "REF200AU (Requires hermetic sealing, so will have dessicant with it that you'll need to place under SHLD1)" H 12700 6000 50  0001 C CNN "Part_number"
F 6 "26 Before opening this shipping package, perform as complete of diagnostics as possible of all circuitry under SHLD1 placed thus far: solder a shorting wire between pins 4 & 5 of U3 (mix & match with pins 1 of both Q1 and Q2) and load the Arduino with GWAAM-Sea Diagnostics 1 and run them.  Remove short between pins 4 and 5 of U3.  Then, from the bottom side of the board, solder seal any and all via holes left unsoldered located within SHLD1 footprint.  Solder seal any and all place-assist holes located within SHLD1 footprint except U3 place-assist holes.  All this should minimize risk of getting interrupted while U3 is left not heremetically sealed.  Tin SHLD1 around outside of bottom edge that will get soldered to its footprint.  Tin SHLD1 footprint on the board, leaving a very SMOOTH & FLAT surface to mate with SHLD1.  Prepare dessicant (trim pkg for edges to be bent over to fit inside SHLD1 holding like a pinch of the silica or clay granules & held in place by Kapton tape without putting pressure on other components) as soon as U3 is placed, and ensure SHLD1 is handy also.  Place U3 and perform diagnostics of U3.  After diags, solder-seal its place-assist holes.  Immediately perform next step." H 12700 6000 50  0001 C CNN "ClickToSortForPlacement"
	2    12700 6000
	1    0    0    -1  
$EndComp
$Comp
L uno-shield-rescue:ADL5315ACPZ-R7-2019-05-19_00-44-38-uno-shield-rescue-uno-shield-rescue U3
U 1 1 5CE2F217
P 3800 4650
F 0 "U3" H 5000 5037 60  0000 C CNN
F 1 "ADL5315ACPZ-R7" H 5000 4931 60  0000 C CNN
F 2 "multipackage:ADL5315ACPZ-R7" H 5000 4890 60  0001 C CNN
F 3 "https://www.analog.com/media/en/technical-documentation/data-sheets/ADL5315.pdf" H 3800 4650 60  0001 C CNN
F 4 "http://Arrow.com" H 3800 4650 50  0001 C CNN "Source"
F 5 "ADL5315ACPZ-R7" H 3800 4650 50  0001 C CNN "Part_number"
F 6 "03 Being careful not to desolder surrounding components (use the otherwise purposeless body of SHLD1 to protect them, if it helps), tin pads on lateral sides of the component itself and the center and largest pad on bottom side of the component itself.  Ensure that none of the solder tinning on the lateral side pads of the component extends below bottom plane as that solder won't melt while soldering bottom pad to allow component to fully seat against board.  It would be ideal to solder center pin 9 from the back side of board and ensure its attachment to the via and pins 1-8 from front of board.  Pin 9 should be soldered first so you can verify it becomes soundly attached and seated against board, but I don't know a technique to do it while ensuring the other pads will all stay lined up.  When finished soldering, check that surrounding components already placed were not disturbed. Check work for inadvertent shorts and opens. " H 3800 4650 50  0001 C CNN "ClickToSortForPlacement"
	1    3800 4650
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small_US R2
U 1 1 5CE335C5
P 3150 4325
F 0 "R2" V 3075 4300 50  0000 L CNN
F 1 "100 Ω" V 3225 4100 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 3150 4325 50  0001 C CNN
F 3 "~" H 3150 4325 50  0001 C CNN
F 4 "http://Arrow.com" H 3150 4325 50  0001 C CNN "Source"
F 5 "RMCF0603FT100R" H 3150 4325 50  0001 C CNN "Part_number"
F 6 "04 Place then check work as before" H 3150 4325 50  0001 C CNN "ClickToSortForPlacement"
	1    3150 4325
	0    1    1    0   
$EndComp
$Comp
L Device:C_Small C1
U 1 1 5CE3497C
P 3250 4550
F 0 "C1" H 3050 4550 50  0000 L CNN
F 1 "390 pF" H 2975 4475 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 3250 4550 50  0001 C CNN
F 3 "~" H 3250 4550 50  0001 C CNN
F 4 "http://Arrow.com" H 3250 4550 50  0001 C CNN "Source"
F 5 "CL10B391KB8NNND" H 3250 4550 50  0001 C CNN "Part_number"
F 6 "02 A tiny 0201-size duplicate C1 pad set is on PCB.  Determine which pad set your C1 fits.  Place (always means solder down herein) C1 where and on side that _level_ reference is silk-screened, not angled reference.  Then check work for inadvertent shorts and opens." H 3250 4550 50  0001 C CNN "ClickToSortForPlacement"
	1    3250 4550
	-1   0    0    1   
$EndComp
$Comp
L Device:C_Small C2
U 1 1 5CE92D72
P 3850 4075
F 0 "C2" V 4075 4025 50  0000 L CNN
F 1 ".22 µF" V 3975 3950 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 3850 4075 50  0001 C CNN
F 3 "~" H 3850 4075 50  0001 C CNN
F 4 "0603YG224ZAT2A" H 3850 4075 50  0001 C CNN "Part_number"
F 5 "http://Arrow.com" H 3850 4075 50  0001 C CNN "Source"
F 6 "14 Place then check work as before" H 3850 4075 50  0001 C CNN "ClickToSortForPlacement"
	1    3850 4075
	0    -1   -1   0   
$EndComp
$Comp
L 2019-03-19_09-09-09:MCP4262-xxxE_UN U8
U 1 1 5CA59032
P 11325 4575
F 0 "U8" H 12275 3675 60  0000 R CNN
F 1 "- U33 all in parallel MCP4262-502E/UN" H 12100 3675 60  0000 R CNN
F 2 "Package_SO:MSOP-10_3x3mm_P0.5mm" H 11870 5000 60  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/22059b.pdf" H 11335 4575 60  0001 R CNN
F 4 "15 Since solder paste template is correct only while the U7 cut-away is still attached, tinning and placing may need to be done then.  Check corner pads for adequate bare metal: ensure the solder mask of all corner pads is scraped off.  Place.  For best immunity from physical vibrations, ensure leads 5,6,7 and 8 make contact with copper trace itself rather than only to solder.  Then check work for inadvertent shorts and opens" H 5725 2675 50  0001 C CNN "ClickToSortForPlacement"
F 5 "MCP4262-502E/UN" H 11325 4575 50  0001 C CNN "Part_number"
F 6 "http://digikey.com" H 11325 4575 50  0001 C CNN "Source"
	1    11325 4575
	-1   0    0    1   
$EndComp
$Comp
L lm334m:LM334M U5
U 1 1 5CDCE965
P 7775 3950
F 0 "U5" H 7825 4225 50  0000 R CNN
F 1 "LM334M" H 7925 4325 50  0000 R CNN
F 2 "Package_SO:SOIC-8_3.9x4.9mm_P1.27mm" H 7800 3800 50  0001 L CIN
F 3 "http://www.ti.com/lit/ds/symlink/lm134.pdf" H 7775 3950 50  0001 C CIN
F 4 "LM334M/NOPB" H 7775 3950 50  0001 C CNN "Part_number"
F 5 "http://Arrow.com" H 7775 3950 50  0001 C CNN "Source"
F 6 "23 Check corner pads for adequate bare metal: ensure the solder mask of all corner pads is scraped off.  Before placing, run the diags that use the ohmmeter.  Place then check work, you may allow up to three of pins 5-8 to fly free since none of them have electrical connection.  Place short between pins 2 and 5 of U4 and place 1.5 MOhm from Q2 pins 1 & 2 to GND.  For best immunity from physical vibrations, ensure U5 and U6 leads 1,2, and 4 make contact with copper trace itself rather than only to solder.  Place a short between pins 1 & 2 of Q1. Make sure the added shorts cannot get bumped so to lift the pads they attach to.  Run diags.  Remove shorts on Q1 and Q2." H 7775 3950 50  0001 C CNN "ClickToSortForPlacement"
	1    7775 3950
	1    0    0    -1  
$EndComp
$Comp
L lm334m:LM334M U6
U 1 1 5CDCF5D4
P 8875 3950
F 0 "U6" H 8925 4225 50  0000 R CNN
F 1 "LM334M" H 9025 4325 50  0000 R CNN
F 2 "Package_SO:SOIC-8_3.9x4.9mm_P1.27mm" H 8900 3800 50  0001 L CIN
F 3 "http://www.ti.com/lit/ds/symlink/lm134.pdf" H 8875 3950 50  0001 C CIN
F 4 "LM334M/NOPB" H 8875 3950 50  0001 C CNN "Part_number"
F 5 "http://Arrow.com" H 8875 3950 50  0001 C CNN "Source"
F 6 "23 Check corner pads for adequate bare metal: ensure the solder mask of all corner pads is scraped off.  Before placing, run the diags that use the ohmmeter.  Place then check work, you may allow up to three of pins 5-8 to fly free since none of them have electrical connection.  Place short between pins 2 and 5 of U4 and place 1.5 MOhm from Q2 pins 1 & 2 to GND.  For best immunity from physical vibrations, ensure U5 and U6 leads 1,2, and 4 make contact with copper trace itself rather than only to solder.  Place a short between pins 1 & 2 of Q1. Make sure the added shorts cannot get bumped so to lift the pads they attach to.  Run diags.  Remove shorts on Q1 and Q2." H 8875 3950 50  0001 C CNN "ClickToSortForPlacement"
	1    8875 3950
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small_US R9
U 1 1 5D44A427
P 13400 4600
F 0 "R9" H 13300 4650 50  0000 C CNN
F 1 "27 Ω" H 13550 4650 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 13400 4600 50  0001 C CNN
F 3 "~" H 13400 4600 50  0001 C CNN
F 4 "02" H 10200 -250 50  0001 C CNN "PlacementOrder"
F 5 "02" H 10200 -250 50  0001 C CNN "SortForPlacement"
F 6 "14 Place then check work as before" H 10200 -250 50  0001 C CNN "ClickToSortForPlacement"
F 7 "NRC-AS06J270TRF RC0603JR-0727RL" H 13400 4600 50  0001 C CNN "Part_number"
F 8 "http://Arrow.com" H 13400 4600 50  0001 C CNN "Source"
	1    13400 4600
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small_US R3
U 1 1 5CED190D
P 3475 4650
F 0 "R3" V 3550 4500 50  0000 L CNN
F 1 "3.9 KΩ" V 3375 4450 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 3475 4650 50  0001 C CNN
F 3 "~" H 3475 4650 50  0001 C CNN
F 4 "http://Arrow.com" H 3475 4650 50  0001 C CNN "Source"
F 5 "RK73B1JTTD392J order an extra one of this value for the first diagnostic step if you can afford it." H 3475 4650 50  0001 C CNN "Part_number"
F 6 "04 Place then check work " H 3475 4650 50  0001 C CNN "ClickToSortForPlacement"
	1    3475 4650
	0    -1   -1   0   
$EndComp
$Comp
L Device:Q_NMOS_GSD Q3
U 1 1 5CED0C82
P 9600 12000
F 0 "Q3" H 9500 11850 50  0000 L CNN
F 1 "DMN601K-7" H 9300 11750 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23_Handsoldering" H 9800 11925 50  0001 L CIN
F 3 "http://www.redrok.com/MOSFET_BS108_200V_250mA_8O_Vth1.5_TO-92.PDF" H 9600 12000 50  0001 L CNN
F 4 "03" H 3050 9250 50  0001 C CNN "PlacementOrder"
F 5 "03" H 3050 9250 50  0001 C CNN "SortForPlacement"
F 6 "07 Place then check work" H 3050 9250 50  0001 C CNN "ClickToSortForPlacement"
F 7 "DMN601K-7" H 9600 12000 50  0001 C CNN "Part_number"
F 8 "http://Arrow.com" H 9600 12000 50  0001 C CNN "Source"
	1    9600 12000
	1    0    0    -1  
$EndComp
$Comp
L Device:Q_NMOS_GSD Q4
U 1 1 5CEFAE8D
P 10625 12000
F 0 "Q4" H 10525 11850 50  0000 L CNN
F 1 "DMN601K-7" H 10325 11750 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23_Handsoldering" H 10825 11925 50  0001 L CIN
F 3 "http://www.redrok.com/MOSFET_BS108_200V_250mA_8O_Vth1.5_TO-92.PDF" H 10625 12000 50  0001 L CNN
F 4 "03" H 4075 9250 50  0001 C CNN "PlacementOrder"
F 5 "03" H 4075 9250 50  0001 C CNN "SortForPlacement"
F 6 "07 Place then check work" H 4075 9250 50  0001 C CNN "ClickToSortForPlacement"
F 7 "DMN601K-7" H 10625 12000 50  0001 C CNN "Part_number"
F 8 "http://Arrow.com" H 10625 12000 50  0001 C CNN "Source"
	1    10625 12000
	1    0    0    -1  
$EndComp
$Comp
L Device:Q_NMOS_GSD Q5
U 1 1 5CC49A39
P 11475 12000
F 0 "Q5" H 11375 11850 50  0000 L CNN
F 1 "DMN601K-7" H 11175 11750 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23_Handsoldering" H 11675 11925 50  0001 L CIN
F 3 "http://www.redrok.com/MOSFET_BS108_200V_250mA_8O_Vth1.5_TO-92.PDF" H 11475 12000 50  0001 L CNN
F 4 "03" H 4925 9250 50  0001 C CNN "PlacementOrder"
F 5 "03" H 4925 9250 50  0001 C CNN "SortForPlacement"
F 6 "07 Place then check work" H 4925 9250 50  0001 C CNN "ClickToSortForPlacement"
F 7 "DMN601K-7" H 11475 12000 50  0001 C CNN "Part_number"
F 8 "http://Arrow.com" H 11475 12000 50  0001 C CNN "Source"
	1    11475 12000
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small_US R10
U 1 1 5D039973
P 9700 11700
F 0 "R10" H 9550 11900 50  0000 C CNN
F 1 "1 MΩ" H 9525 11775 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 9740 11690 50  0001 C CNN
F 3 "~" H 9700 11700 50  0001 C CNN
F 4 "02" H 2050 9100 50  0001 C CNN "PlacementOrder"
F 5 "02" H 2050 9100 50  0001 C CNN "SortForPlacement"
F 6 "06 Place then check work" H 2050 9100 50  0001 C CNN "ClickToSortForPlacement"
F 7 "RK73B1JTTD105J" H 9700 11700 50  0001 C CNN "Part_number"
F 8 "http://Arrow.com" H 9700 11700 50  0001 C CNN "Source"
	1    9700 11700
	1    0    0    -1  
$EndComp
$Comp
L newkicadversion-rescue:AD8244ARMZ-AD8244_A U2
U 3 1 5F050747
P 3450 4075
F 0 "U2" H 3575 3925 50  0000 C CNN
F 1 "AD8244ARMZ" H 3500 3825 50  0000 C CNN
F 2 "multipackage:MSOP-10_3x3mm_P0.5mm" H 3450 4075 50  0001 C CNN
F 3 "http://static6.arrow.com/aropdfconversion/427f47d0fc5e4caf484beffd27781384154f9c66/33171669476397452ad8244.pdf" H 3450 4075 50  0001 C CNN
F 4 "AD8244ARMZ-R7" H 3450 4075 50  0001 C CNN "Part_number"
F 5 "http://Arrow.com" H 3450 4075 50  0001 C CNN "Source"
F 6 "03 Check corner pads for adequate bare metal: ensure the solder mask of all corner pads is scraped off. Place then check work." H 3450 4075 50  0001 C CNN "ClickToSortForPlacement"
	3    3450 4075
	-1   0    0    1   
$EndComp
$Comp
L Device:RF_Shield_Two_Pieces SHLD1
U 1 1 5D39733F
P 3025 6850
F 0 "SHLD1" H 3755 6914 50  0000 L CNN
F 1 "Device_RF_Shield_Two_Pieces_but_use_only_TOP" H 3755 6823 50  0000 L CNN
F 2 "multipackage:Masach_Tech_MS26320_26x19.50mm" H 3025 6750 50  0001 C CNN
F 3 "~" H 3025 6750 50  0001 C CNN
F 4 "MS263-20 (will use only the cover to keep hermetic sealed)" H 3025 6850 50  0001 C CNN "Part_number"
F 5 "http://Arrow.com" H 3025 6850 50  0001 C CNN "Source"
F 6 "27  Verify every place-assist hole inside shield footprint is sealed and take one last opportunity to ensure all other holes there as well are fully sealed against air travel.  Thoroughly solder in place with dessicant inside using bismuth solder if you have it for easiest removal." H 3025 6850 50  0001 C CNN "ClickToSortForPlacement"
	1    3025 6850
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small_US R1
U 1 1 5D398C0C
P 2150 4800
F 0 "R1" V 2250 4825 50  0000 L CNN
F 1 "100 Ω" V 2250 5000 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 2150 4800 50  0001 C CNN
F 3 "~" H 2150 4800 50  0001 C CNN
F 4 "http://Arrow.com" H 2150 4800 50  0001 C CNN "Source"
F 5 "RMCF0603FT100R" H 2150 4800 50  0001 C CNN "Part_number"
F 6 "04 Place then check work" H 2150 4800 50  0001 C CNN "ClickToSortForPlacement"
	1    2150 4800
	0    1    1    0   
$EndComp
$Comp
L Jumper:SolderJumper_3_Bridged12 JP1
U 1 1 5D8B719E
P 2825 4175
F 0 "JP1" H 2650 4250 50  0000 C CNN
F 1 "C1_leak_mitigator" H 2400 4325 50  0000 C CNN
F 2 "Jumper:SolderJumper-3_P1.3mm_Bridged12_RoundedPad1.0x1.5mm_NumberLabels" H 2825 4175 50  0001 C CNN
F 3 "~" H 2825 4175 50  0001 C CNN
F 4 "part of MSB-T plus part of a second TSW-150-05-T-S/4-103327-0" H 2825 4175 50  0001 C CNN "Part_number"
F 5 "00 (TIPS - Always when sorting this page, make the column's title cell show the little sort direction indicator highlighted and pointing up. Solder temperature if using a soldering iron: Use your highest temperature solder for two-lead SMD components so they aren't so easily dislocated later when accidentally bumped with hot iron.  Never allow leaded solder to cross contaminate low-temp [bismuth] solders - lead ruins them.  Do your best to keep SMD component leads clean from adhesive tape glue and other sticky, clingy, slimy contaminates that could leave a film where solder will need to adhere to them.  Plated through holes can only be used once on new boards unless they are Hot Air Solder Leveled [HASL] and you are careful to match solders with the factory solder or you are prepared to ream out plating-contaminated solder from the hole, so do NOT assume that tinning plated through holes to prepare the holes themselves for pins or leads is the right thing to do!  Just use them as-is when the time comes even though they won't take the solder as well, or instead you may plug the holes with stainless steel paste dispensing syringe needle/nozzle 20-21 gauge while you tin the annular ring only on the one side opposite the component.  Take care about LEDs and U3 soldering temperatures - they don't stand the temperatures of other components.   U3 special handling - don't open U3 shipping/storage package until these instructions say to; soldering temperature for U3 must never exceed 250C/500F.)     Cleanse gold from all pads on the board by tinning - twice at least on SMD pads - with the same solder composition you'll use on the respective pads, leaving no gold and as little solder as possible on them - solder wick and rosin flux are invaluable for this task, and use some ingenuity on those plated-through holes to ensure they can be cleared out when done tinning them.  Allow 2 to 5 hours on this step alone, since the only way to do this quicker is by industrial HASL; and, yes, all the melted solder mask will look awful. The reasoning? Plating interferes with solder, making untinned pads almost impossible to solder to with this leadless package type.   Now would be the best time to solder-seal hermetically tight all the micro-vias that let light through, if any, within SHLD1 footprint.  Once the components get placed where they shadow the micro-vias, any non-sealed ones will be totally not findable.  Use a bright light shining through to ensure all vias get sealed, but do not seal place-assist holes yet nor U2 center lead hole.  Whether mere solder mask actually hermetically seals adequately is debatable - I would only trust it if it is thick enough to block all light.  Use solder to seal any suspicious micro-vias.  Solder-short pads 1 to 2 of this JP1, keeping all previous solder joints from melting.  Take that precaution throughout assembly." H 2825 4175 50  0001 C CNN "ClickToSortForPlacement"
	1    2825 4175
	1    0    0    -1  
$EndComp
$Comp
L Jumper:SolderJumper_3_Bridged12 JP2
U 1 1 5D936E95
P 4200 3725
F 0 "JP2" H 4275 3825 50  0000 C CNN
F 1 "C2_bias_reducer" H 3875 3825 50  0000 C CNN
F 2 "Jumper:SolderJumper-3_P1.3mm_Bridged12_RoundedPad1.0x1.5mm_NumberLabels" H 4200 3725 50  0001 C CNN
F 3 "~" H 4200 3725 50  0001 C CNN
F 4 "part of MSB-T plus part of a second TSW-150-05-T-S/4-103327-0" H 4200 3725 50  0001 C CNN "Part_number"
F 5 "01 Solder-short pads 1 to 2." H 4200 3725 50  0001 C CNN "ClickToSortForPlacement"
	1    4200 3725
	-1   0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x10_Male J4
U 1 1 5C8B326A
P 21700 1500
F 0 "J4" H 21800 2000 50  0000 C CNN
F 1 "Digital" V 21600 1450 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x10_P2.54mm_Vertical" H 21700 1500 50  0001 C CNN
F 3 "~" H 21700 1500 50  0001 C CNN
F 4 "20 Requires more solder than single-sided components and heat for a longer time, especially on the GNDD pin or the MCU can push the solder pads right off the board.  Use bismuth solder if you have it for easiest removal (provided you used no-lead solder to pre-tin with).  Place with height with all connectors mated, may need to space away from board some.  Then check work for inadvertent shorts and opens." H 11650 0   50  0001 C CNN "ClickToSortForPlacement"
F 5 "part of first TSW-150-05-T-S or 4-103327-0. Stackables are too often not stocked; unable to source stackable style" H 21700 1500 50  0001 C CNN "Part_number"
F 6 "http://Arrow.com" H 21700 1500 50  0001 C CNN "Source"
	1    21700 1500
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small_US R5
U 1 1 5CFA3142
P 6300 4950
F 0 "R5" V 6200 4925 50  0000 L CNN
F 1 "10 KΩ" V 6100 4775 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 6300 4950 50  0001 C CNN
F 3 "~" H 6300 4950 50  0001 C CNN
F 4 "http://Arrow.com" H 6300 4950 50  0001 C CNN "Source"
F 5 "RC0603JR-1310KL" H 6300 4950 50  0001 C CNN "Part_number"
F 6 "05 Place, then check work as before.   The steps up to this one were to install first stage stability ckt for powering up U3.  Pwr supply stability ckts for U1 and ADC1 are next after diagnostics of the work you've done so far:  You have reached the step of applying power voltage to the board, and you MUST not make any mistakes doing so or you'll all too likely damage components that will cost you extra shipping, handling to replace.  As you prepare to continue, be fully aware that any mistakes you make can destroy components when power gets applied.  BE VERY OBSERVANT.  Determine which of +5V or +3V3 your MCU puts on ICSP1 pin 2 before applying MCU power to this board: 5V is default of this PCB design.  If the MCU instead puts 3V on the ICSP1 pin 2, you MUST modify this board at J2 pins 4 & 5 or you'll stress out your MCU and likely damage it!  Such modification inflexibly renders this board unfit for 5V operation since there was not room for jumpers to make this change flexible.  You will bring the Arduino's Vcc to this board's Vcc (the pad of pin 2 JP6 or install JP6 and use the pad of pin 2 ICSP1) and Arduino GND to this board's GNDD somewhere (the pad of J2 pin 6 or 7 is fine) semi-long-term somehow without power, yet, on the Arduino while ensuring nothing of this wiring can short together now nor later.  If you decide to solder anything down for this purpose, make SURE you cleanse the gold from whatever pads you choose so you can melt the joint later...that non-eutectic composition raises the melting point way higher than you'd think - and this was your last warning of that point for the entire board. Once that is done, power up the Arduino and pay no attention to what the Arduino does except make sure it does something to indicate it has power to it.  Devote your attention to the GWAAM-Sea board where you'll carefully (so as not to short anything out) measure and verify these voltages: the T pad of J1 should have 4.0 VDC on it unless the Arduino is a 3.3V device in which case that same pad will have 2.2-2.3 VDC on it.  (If you didn't already know enough before now to touch one voltmeter lead to ground and the other to the named pad then you are not of sufficient ability to be doing this assembly at all - please power down the Arduino and stop right now in that case and decide what you need to learn about voltmetering.  Learn it before coming back to this step.  We are hoping to put up YouTube videos to help everyone in your situation.)  Remove power from Arduino but keep Arduino and this board wired together.  Temporarily use R10, R12, & R13 (these are all interchangeable) in this way: tack R10 between SHLD1 trace and the pad for pin 5 of U4.  The live end is on the pad of pin 5 U4.  We'll use R12 & R13 after this initial voltage check.  Powered up VDC right now on the live end of the temporary R10 resistor should be less than 0.01 VDC.  Power down Arduino.  Next tack R12 and R13 in series with each other bridging across S and T of J1, powering down the Arduino to do so.  With power on again, the VDC on J1 pad T will be just a tad bit less it was than before.  VDC on the live end of the temporary diag resistor will be half that level.  If you can read the meter while shorting across only one of R12-R13 the reading should rise to 4.0 (or 2.2-2.3 in 3.3V systems).  Remove power to continue the assembly.  Remove R10, R12, & R13 and install the extra R3 or other 3.9K where R10 was just removed from: from U4 pad 5 to SHLD1 trace right next to it.  Decide on a way you'll short between S and T of J1 to make the next voltage measurement and apply the short now or when you make that measurement.  Apply power again and measure the live end of that spare R3 with the aforementioned short placed.    With power on again, the VDC on J1 pad T will be just a tad bit less Vcc-1.   Remove power but leave the spare R3 and short of J1 there for another diagnostic step." H 6300 4950 50  0001 C CNN "ClickToSortForPlacement"
	1    6300 4950
	0    -1   -1   0   
$EndComp
$Comp
L Device:R_Small_US R12
U 1 1 5CFE49AF
P 12600 12000
F 0 "R12" V 12700 12025 50  0000 C CNN
F 1 "1 MΩ" V 12500 12000 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 12640 11990 50  0001 C CNN
F 3 "~" H 12600 12000 50  0001 C CNN
F 4 "02" H 4950 9400 50  0001 C CNN "PlacementOrder"
F 5 "02" H 4950 9400 50  0001 C CNN "SortForPlacement"
F 6 "06 Place then check work" H 4950 9400 50  0001 C CNN "ClickToSortForPlacement"
F 7 "RC0603FR-071ML " H 12600 12000 50  0001 C CNN "Part_number"
F 8 "http://Arrow.com" H 12600 12000 50  0001 C CNN "Source"
	1    12600 12000
	0    -1   -1   0   
$EndComp
$Comp
L Device:R_Small_US R13
U 1 1 5CFE72EE
P 12700 11800
F 0 "R13" H 12800 11700 50  0000 C CNN
F 1 "1 MΩ" H 12850 11775 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 12740 11790 50  0001 C CNN
F 3 "~" H 12700 11800 50  0001 C CNN
F 4 "02" H 5050 9200 50  0001 C CNN "PlacementOrder"
F 5 "02" H 5050 9200 50  0001 C CNN "SortForPlacement"
F 6 "07 Place then check work" H 5050 9200 50  0001 C CNN "ClickToSortForPlacement"
F 7 "RK73B1JTTD105J" H 12700 11800 50  0001 C CNN "Part_number"
F 8 "http://Arrow.com" H 12700 11800 50  0001 C CNN "Source"
	1    12700 11800
	-1   0    0    1   
$EndComp
$Comp
L Device:R_Small_US R11
U 1 1 5D04A72D
P 11900 11400
F 0 "R11" H 11775 11397 50  0000 C CNN
F 1 "470 Ω" H 12075 11397 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 11940 11390 50  0001 C CNN
F 3 "~" H 11900 11400 50  0001 C CNN
F 4 "02" H 3950 9300 50  0001 C CNN "PlacementOrder"
F 5 "02" H 3950 9300 50  0001 C CNN "SortForPlacement"
F 6 "07 Place then check work" H 3950 9300 50  0001 C CNN "ClickToSortForPlacement"
F 7 "RC0603JR-07470RL" H 11900 11400 50  0001 C CNN "Part_number"
F 8 "http://Arrow.com" H 11900 11400 50  0001 C CNN "Source"
	1    11900 11400
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C6
U 1 1 5D06E63A
P 15125 4450
F 0 "C6" V 15200 4325 50  0000 C CNN
F 1 "0.1 µF" V 15200 4075 50  0000 C CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 15125 4450 50  0001 C CNN
F 3 "~" H 15125 4450 50  0001 C CNN
F 4 "08" H 9575 650 50  0001 C CNN "PlacementOrder"
F 5 "08" H 10325 600 50  0001 C CNN "SortForPlacement"
F 6 "14 Place then check work as before.  This completes the power stability ckt" H 10325 600 50  0001 C CNN "ClickToSortForPlacement"
F 7 "CL10B104KB8NNNL" H 15125 4450 50  0001 C CNN "Part_number"
F 8 "http://Arrow.com" H 15125 4450 50  0001 C CNN "Source"
	1    15125 4450
	0    -1   -1   0   
$EndComp
$Comp
L Connector:Conn_01x02_Female J6_A7,A6
U 1 1 5D238E1B
P 17225 8750
F 0 "J6_A7,A6" V 17225 9150 50  0000 R CNN
F 1 "Conn_01x02_gender_unknown" V 17150 9875 50  0000 R CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x02_P2.54mm_Vertical" H 17225 8750 50  0001 C CNN
F 3 "~" H 17225 8750 50  0001 C CNN
F 4 "female:  SSA-102-S-T.  If male is needed use part of a second TSW-150-05-T-S/4-103327-0 " H 17225 8750 50  0001 C CNN "Part_number"
F 5 "99" H 17225 8750 50  0001 C CNN "ClickToSortForPlacement"
F 6 "http://Arrow.com" H 17225 8750 50  0001 C CNN "Source"
	1    17225 8750
	0    -1   -1   0   
$EndComp
$Comp
L Device:R_POT_US VR3
U 1 1 5DC8E599
P 17700 9375
F 0 "VR3" H 17632 9329 50  0000 R CNN
F 1 "200 KΩ" H 17632 9420 50  0000 R CNN
F 2 "multipackage:Potentiometer_Bourns_PTV09A-1_Single_Vertical" H 17700 9375 50  0001 C CNN
F 3 "https://www.bourns.com/docs/Product-Datasheets/PTV09.pdf" H 17700 9375 50  0001 C CNN
F 4 "28 Don't solder, merely press against sides of holes inside them with power on and diags running.  When A0 diags are successful, power down, pull boards apart with great care, then remove J3 and attach it again with a tack solder to J3 pin 2. Power up and run A1 diags using VR2 position similarly (inserted without soldering).   When A1 diags are successful power down, then remove J2, 3, & 4, R1 and solder-bridges of JP1-3 no cuts needed, check work for inadvertent shorts and opens after" H 8740 3645 50  0001 C CNN "ClickToSortForPlacement"
F 5 "User/developer use only: PTV09A-4030U-B204 or may end in B203 or some resistance in between those.  The 4030 may be 4020 or 4015 for shorter shaft. If using the UNO SMD MCU version with an ATMEGA128P-AU (a TQFP package specifically instead of the UNO with a DIP ATMEGA128P), there are two analog input pins available at the TQFP package on the MCU board that not wired out to any connector.  One or both of these can be, if you are willing to attach tiny wires between them and VR3/4 and write the code, used as seventh and eighth analog inputs A6 & A7.  Then air-wire them or connectorize them somehow across to this extention board and buy the PCB mount vertically oriented version of PTV09 pots to get one or two more user developed, run-time analog input controls into the training board." H 17700 9375 50  0001 C CNN "Part_number"
F 6 "http://Arrow.com" H 17700 9375 50  0001 C CNN "Source"
	1    17700 9375
	-1   0    0    1   
$EndComp
$Comp
L Device:LED D2
U 1 1 5CC7E20B
P 12100 11650
F 0 "D2" V 12097 11550 50  0000 R CNN
F 1 "Yellow: Inadequate electrode conductance" H 13797 11475 50  0000 R CNN
F 2 "multipackage:LED_Rectangular_W5.0mm_H2.0mm_yellow" H 12100 11650 50  0001 C CNN
F 3 "~" H 12100 11650 50  0001 C CNN
F 4 "07" H 5050 9250 50  0001 C CNN "PlacementOrder"
F 5 "07" H 5050 9250 50  0001 C CNN "SortForPlacement"
F 6 "09 Place, then check work" H 5050 9250 50  0001 C CNN "ClickToSortForPlacement"
F 7 "SSL-LX2573YD" H 12100 11650 50  0001 C CNN "Part_number"
F 8 "http://Arrow.com" H 12100 11650 50  0001 C CNN "Source"
	1    12100 11650
	0    -1   -1   0   
$EndComp
$Comp
L Device:Q_NMOS_GSD Q6
U 1 1 5CC49AA9
P 12000 12000
F 0 "Q6" H 12200 11900 50  0000 L CNN
F 1 "DMN601K-7" H 12200 11750 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23_Handsoldering" H 12200 11925 50  0001 L CIN
F 3 "~" H 12000 12000 50  0001 L CNN
F 4 "03" H 5050 9250 50  0001 C CNN "PlacementOrder"
F 5 "03" H 5050 9250 50  0001 C CNN "SortForPlacement"
F 6 "10 Place then check work.  " H 5050 9250 50  0001 C CNN "ClickToSortForPlacement"
F 7 "DMN601K-7" H 12000 12000 50  0001 C CNN "Part_number"
F 8 "http://Arrow.com" H 12000 12000 50  0001 C CNN "Source"
	1    12000 12000
	1    0    0    -1  
$EndComp
$Comp
L Device:Net-Tie_2 NT2
U 1 1 5D18EDE5
P 14850 4800
F 0 "NT2" H 14850 4981 50  0001 C CNN
F 1 "Net-Tie_2" H 14850 4890 50  0001 C CNN
F 2 "multipackage:NetTie-2_HX711_THT_Pad1.0mm" H 14850 4800 50  0001 C CNN
F 3 "~" H 14850 4800 50  0001 C CNN
F 4 "99" H 14850 4800 50  0001 C CNN "ClickToSortForPlacement"
	1    14850 4800
	1    0    0    -1  
$EndComp
$Comp
L Device:Net-Tie_2 NT3
U 1 1 5D1D0EE6
P 14700 5000
F 0 "NT3" H 14700 5181 50  0001 C CNN
F 1 "Net-Tie_2" H 14700 5090 50  0001 C CNN
F 2 "multipackage:NetTie-2_HX711_THT_Pad1.0mm" H 14700 5000 50  0001 C CNN
F 3 "~" H 14700 5000 50  0001 C CNN
F 4 "99" H 14700 5000 50  0001 C CNN "ClickToSortForPlacement"
	1    14700 5000
	1    0    0    -1  
$EndComp
$Comp
L Device:Net-Tie_2 NT4
U 1 1 5D1D1913
P 14700 5200
F 0 "NT4" H 14700 5381 50  0001 C CNN
F 1 "Net-Tie_2" H 14700 5290 50  0001 C CNN
F 2 "multipackage:NetTie-2_HX711_THT_Pad1.0mm" H 14700 5200 50  0001 C CNN
F 3 "~" H 14700 5200 50  0001 C CNN
F 4 "99" H 14700 5200 50  0001 C CNN "ClickToSortForPlacement"
	1    14700 5200
	1    0    0    -1  
$EndComp
$Comp
L Device:Net-Tie_2 NT5
U 1 1 5D1D225B
P 14850 5400
F 0 "NT5" H 14850 5581 50  0001 C CNN
F 1 "Net-Tie_2" H 14850 5490 50  0001 C CNN
F 2 "multipackage:NetTie-2_HX711_THT_Pad1.0mm" H 14850 5400 50  0001 C CNN
F 3 "~" H 14850 5400 50  0001 C CNN
F 4 "99" H 14850 5400 50  0001 C CNN "ClickToSortForPlacement"
	1    14850 5400
	1    0    0    -1  
$EndComp
$Comp
L Device:Net-Tie_2 NT6
U 1 1 5D25E3D8
P 15200 4700
F 0 "NT6" H 15200 4881 50  0001 C CNN
F 1 "Net-Tie_2" H 15200 4790 50  0001 C CNN
F 2 "multipackage:NetTie-2_HX711_THT_Pad1.0mm" H 15200 4700 50  0001 C CNN
F 3 "~" H 15200 4700 50  0001 C CNN
F 4 "99" H 15200 4700 50  0001 C CNN "ClickToSortForPlacement"
	1    15200 4700
	1    0    0    -1  
$EndComp
$Comp
L Device:Net-Tie_2 NT7
U 1 1 5D1B1DB1
P 15000 5600
F 0 "NT7" V 15046 5556 50  0001 R CNN
F 1 "Net-Tie_2" V 14955 5556 50  0001 R CNN
F 2 "multipackage:NetTie-2_HX711_THT_Pad1.0mm" H 15000 5600 50  0001 C CNN
F 3 "~" H 15000 5600 50  0001 C CNN
F 4 "99" H 15000 5600 50  0001 C CNN "ClickToSortForPlacement"
F 5 "" H 15000 5600 50  0001 C CNN "Source"
	1    15000 5600
	0    -1   -1   0   
$EndComp
$Comp
L Connector:Conn_01x02_Female J7_A7,A6
U 1 1 5CFFF071
P 15925 8725
F 0 "J7_A7,A6" V 15925 8475 50  0000 R CNN
F 1 "Conn_01x02_Female" V 15850 8550 50  0000 R CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x02_P2.54mm_Vertical" H 15925 8725 50  0001 C CNN
F 3 "~" H 15925 8725 50  0001 C CNN
F 4 "SSA-102-S-T" H 15925 8725 50  0001 C CNN "Part_number"
F 5 "99" H 15925 8725 50  0001 C CNN "ClickToSortForPlacement"
F 6 "http://Arrow.com" H 15925 8725 50  0001 C CNN "Source"
	1    15925 8725
	0    1    -1   0   
$EndComp
$Comp
L Connector:Conn_01x09_Female J6
U 1 1 5D248321
P 13375 1425
F 0 "J6" H 13350 975 50  0000 C CNN
F 1 "Conn_01x09_Female" H 13375 2050 50  0000 C CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x09_P2.54mm_Vertical" H 13375 1425 50  0001 C CNN
F 3 "~" H 13375 1425 50  0001 C CNN
F 4 "99  Optional and not ideal.  Direct solder is best." H 13375 1425 50  0001 C CNN "ClickToSortForPlacement"
F 5 "Sockets: 1 qty SL-106-T-10 optional and not ideal and may not fit pin dia.  Direct solder is normally a better option except in experimentation environments and where smaller dia pins can be found if needed." H 13375 1425 50  0001 C CNN "Part_number"
F 6 "http://Arrow.com" H 13375 1425 50  0001 C CNN "Source"
	1    13375 1425
	-1   0    0    1   
$EndComp
$Comp
L Jumper:Jumper_2_Bridged JP4
U 1 1 5D27A949
P 13775 1625
F 0 "JP4" H 13775 1575 50  0000 C CNN
F 1 "HC-05_EN/KEY" H 14250 1550 50  0000 C CNN
F 2 "multipackage:PinHeader_1x02_P2.54mm_Vertical" H 13775 1625 50  0001 C CNN
F 3 "~" H 13775 1625 50  0001 C CNN
F 4 "part of MSB-T plus part of a second TSW-150-05-T-S/4-103327-0.  ONLY used if wireless module installed" H 13775 1625 50  0001 C CNN "Part_number"
F 5 "http://Arrow.com" H 13775 1625 50  0001 C CNN "Source"
F 6 "99 ONLY used if wireless module installed" H 13775 1625 50  0001 C CNN "ClickToSortForPlacement"
	1    13775 1625
	1    0    0    -1  
$EndComp
$Comp
L Jumper:Jumper_2_Bridged JP5
U 1 1 5D29AEF4
P 14050 1125
F 0 "JP5" H 14050 1075 50  0000 C CNN
F 1 "HC-05_KEY/STATE_LED" H 14500 1200 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 14050 1125 50  0001 C CNN
F 3 "~" H 14050 1125 50  0001 C CNN
F 4 "part of MSB-T plus part of a second TSW-150-05-T-S/4-103327-0.  ONLY used if wireless module installed" H 14050 1125 50  0001 C CNN "Part_number"
F 5 "http://Arrow.com" H 14050 1125 50  0001 C CNN "Source"
F 6 "99 ONLY used if wireless module installed" H 14050 1125 50  0001 C CNN "ClickToSortForPlacement"
	1    14050 1125
	1    0    0    -1  
$EndComp
$Comp
L Jumper:SolderJumper_3_Bridged12 JP7
U 1 1 5D261B02
P 19575 1300
F 0 "JP7" V 19625 1175 50  0000 C CNN
F 1 "3.3/5" V 19475 1150 50  0000 C CNN
F 2 "Jumper:SolderJumper-3_P1.3mm_Bridged2Bar12_RoundedPad1.0x1.5mm_NumberLabels" H 19575 1300 50  0001 C CNN
F 3 "~" H 19575 1300 50  0001 C CNN
F 4 "part of MSB-T plus part of a second TSW-150-05-T-S/4-103327-0" H 19575 1300 50  0001 C CNN "Part_number"
F 5 "99" H 19575 1300 50  0001 C CNN "ClickToSortForPlacement"
	1    19575 1300
	0    1    -1   0   
$EndComp
$Comp
L Jumper:Jumper_2_Bridged JP6
U 1 1 5D363170
P 21275 4075
F 0 "JP6" H 21275 4150 50  0000 C CNN
F 1 "Remove JP6 if MCU is 3V3 but MCU board sends 5V up this pin 2" H 21650 4250 30  0000 C CNN
F 2 "multipackage:PinHeader_1x02_P2.54mm_Vertical" H 21275 4075 50  0001 C CNN
F 3 "~" H 21275 4075 50  0001 C CNN
F 4 "part of MSB-T plus part of a second TSW-150-05-T-S/4-103327-0" H 21275 4075 50  0001 C CNN "Part_number"
F 5 "http://Arrow.com" H 21275 4075 50  0001 C CNN "Source"
F 6 "04 First, determine what Vcc the MCU operates at, what voltage this GWAAMC board Vcc will be (match them unless you have the different signal line voltages figured out and do what you need to about it) and what voltage the MCU places on pin2 of ICSP1.  Leave JP6 open if MCU Vcc is 3V3 but it sends 5V to ICSP1 pin 2 - otherwise, if volts on ICSP1 pin 2  matches the Vcc this board is set for (no other case can exist), install a low profile wire short here across JP6.  The wire may used may be a trimmed lead from the future D1-3 installation step: go through the D1 install motions to trim the longest lead amount you can.  You may later replace this short with a normal height pin pair and jumper after board construction, if you need that flexibility or just want to.  This solder joint will press against ICSP1 and will too easily prevent proper seating of ICSP1 unless you hold ICSP1 firmly in its place while placing JP6." H 21275 4075 50  0001 C CNN "ClickToSortForPlacement"
	1    21275 4075
	1    0    0    -1  
$EndComp
$Comp
L Device:Q_PJFET_SDG Q2
U 1 1 5D11525B
P 8775 4350
F 0 "Q2" V 8650 4400 50  0000 L CNN
F 1 "MMBF5460 (2N5460)" V 8500 4050 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23_Handsoldering" H 8975 4450 50  0001 C CNN
F 3 "~" H 8775 4350 50  0001 C CNN
F 4 "MMBF5460" H 8775 4350 50  0001 C CNN "Part_number"
F 5 "http://Arrow.com" H 8775 4350 50  0001 C CNN "Source"
F 6 "24 Place, check work, place the diags resistors back that you may have had to move or remove using pad 1 of a MOSFET for any diag resistor to it.  Run the same diags just ran in previous step.  Remove diag resistors." H 8775 4350 50  0001 C CNN "ClickToSortForPlacement"
	1    8775 4350
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:Fiducial FID1
U 1 1 5D3E646F
P 625 600
F 0 "FID1" H 710 646 50  0000 L CNN
F 1 "Front Fiducial" H 710 555 50  0000 L CNN
F 2 "Fiducial:Fiducial_1mm_Mask3mm" H 625 600 50  0001 C CNN
F 3 "~" H 625 600 50  0001 C CNN
F 4 "99 " H 625 600 50  0001 C CNN "ClickToSortForPlacement"
F 5 "0 For clarity: [If not shown] U9-U33 must be ordered as well.  Same part number and source as U8, so order a qty 26 of U8 part number. Also, some components in this project are assigned to multiple sources, sure sure to decide where you'll buy those components from before ordering anything from anywhere so you won't end up ordering them on their own order and incurring additional costs in doing so." H 625 600 50  0001 C CNN "Source"
	1    625  600 
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:Fiducial FID2
U 1 1 5D3E7553
P 625 800
F 0 "FID2" H 710 846 50  0000 L CNN
F 1 "Front Fiducial" H 710 755 50  0000 L CNN
F 2 "Fiducial:Fiducial_1mm_Mask3mm" H 625 800 50  0001 C CNN
F 3 "~" H 625 800 50  0001 C CNN
F 4 "99 " H 625 800 50  0001 C CNN "ClickToSortForPlacement"
F 5 "0 For clarity: [If not shown] U9-U33 must be ordered as well.  Same part number and source as U8, so order a qty 26 of U8 part number. Also, some components in this project are assigned to multiple sources, sure sure to decide where you'll buy those components from before ordering anything from anywhere so you won't end up ordering them on their own order and incurring additional costs in doing so." H 625 800 50  0001 C CNN "Source"
	1    625  800 
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:Fiducial FID3
U 1 1 5D3E82BC
P 625 1000
F 0 "FID3" H 710 1046 50  0000 L CNN
F 1 "Front Fiducial" H 710 955 50  0000 L CNN
F 2 "Fiducial:Fiducial_1mm_Mask3mm" H 625 1000 50  0001 C CNN
F 3 "~" H 625 1000 50  0001 C CNN
F 4 "99 " H 625 1000 50  0001 C CNN "ClickToSortForPlacement"
F 5 "0 For clarity: [If not shown] U9-U33 must be ordered as well.  Same part number and source as U8, so order a qty 26 of U8 part number. Also, some components in this project are assigned to multiple sources, sure sure to decide where you'll buy those components from before ordering anything from anywhere so you won't end up ordering them on their own order and incurring additional costs in doing so." H 625 1000 50  0001 C CNN "Source"
	1    625  1000
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:Fiducial FID4
U 1 1 5D41677B
P 1450 600
F 0 "FID4" H 1535 646 50  0000 L CNN
F 1 "Back Fiducial" H 1535 555 50  0000 L CNN
F 2 "Fiducial:Fiducial_1mm_Mask3mm" H 1450 600 50  0001 C CNN
F 3 "~" H 1450 600 50  0001 C CNN
F 4 "99 " H 1450 600 50  0001 C CNN "ClickToSortForPlacement"
F 5 "0 For clarity: [If not shown] U9-U33 must be ordered as well.  Same part number and source as U8, so order a qty 26 of U8 part number. Also, some components in this project are assigned to multiple sources, sure sure to decide where you'll buy those components from before ordering anything from anywhere so you won't end up ordering them on their own order and incurring additional costs in doing so." H 1450 600 50  0001 C CNN "Source"
	1    1450 600 
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:Fiducial FID5
U 1 1 5D416781
P 1450 800
F 0 "FID5" H 1535 846 50  0000 L CNN
F 1 "Back Fiducial" H 1535 755 50  0000 L CNN
F 2 "Fiducial:Fiducial_1mm_Mask3mm" H 1450 800 50  0001 C CNN
F 3 "~" H 1450 800 50  0001 C CNN
F 4 "99 " H 1450 800 50  0001 C CNN "ClickToSortForPlacement"
F 5 "0 For clarity: [If not shown] U9-U33 must be ordered as well.  Same part number and source as U8, so order a qty 26 of U8 part number. Also, some components in this project are assigned to multiple sources, sure sure to decide where you'll buy those components from before ordering anything from anywhere so you won't end up ordering them on their own order and incurring additional costs in doing so." H 1450 800 50  0001 C CNN "Source"
	1    1450 800 
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:Fiducial FID6
U 1 1 5D416787
P 1450 1000
F 0 "FID6" H 1535 1046 50  0000 L CNN
F 1 "Back Fiducial" H 1535 955 50  0000 L CNN
F 2 "Fiducial:Fiducial_1mm_Mask3mm" H 1450 1000 50  0001 C CNN
F 3 "~" H 1450 1000 50  0001 C CNN
F 4 "99 " H 1450 1000 50  0001 C CNN "ClickToSortForPlacement"
F 5 "0 For clarity: [If not shown] U9-U33 must be ordered as well.  Same part number and source as U8, so order a qty 26 of U8 part number. Also, some components in this project are assigned to multiple sources, sure sure to decide where you'll buy those components from before ordering anything from anywhere so you won't end up ordering them on their own order and incurring additional costs in doing so." H 1450 1000 50  0001 C CNN "Source"
	1    1450 1000
	1    0    0    -1  
$EndComp
$Comp
L solderjumper_3_bridged12:SolderJumper_3_Bridged12 JP8
U 1 1 5D438593
P 17700 9075
F 0 "JP8" H 17700 9280 50  0000 C CNN
F 1 "SolderJumper_3_Bridged12" H 17550 9475 50  0000 C CNN
F 2 "Jumper:SolderJumper-3_P1.3mm_Bridged12_Pad1.0x1.5mm_NumberLabels" H 17700 9075 50  0001 C CNN
F 3 "~" H 17700 9075 50  0001 C CNN
F 4 "999" H 17700 9075 50  0001 C CNN "ClickToSortForPlacement"
	1    17700 9075
	-1   0    0    -1  
$EndComp
$Comp
L solderjumper_3_bridged12:SolderJumper_3_Bridged12 JP10
U 1 1 5D43B289
P 18400 8975
F 0 "JP10" H 18400 9100 50  0000 C CNN
F 1 "SolderJumper_3_Bridged12" H 17625 8975 50  0000 C CNN
F 2 "Jumper:SolderJumper-3_P1.3mm_Bridged12_Pad1.0x1.5mm_NumberLabels" H 18400 8975 50  0001 C CNN
F 3 "~" H 18400 8975 50  0001 C CNN
F 4 "999" H 18400 8975 50  0001 C CNN "ClickToSortForPlacement"
	1    18400 8975
	-1   0    0    -1  
$EndComp
$Comp
L solderjumper_3_bridged12:SolderJumper_3_Bridged12 JP11
U 1 1 5D43C8EF
P 18400 9575
F 0 "JP11" H 18400 9688 50  0000 C CNN
F 1 "SolderJumper_3_Bridged12" H 17600 9600 50  0000 C CNN
F 2 "Jumper:SolderJumper-3_P1.3mm_Bridged12_Pad1.0x1.5mm_NumberLabels" H 18400 9575 50  0001 C CNN
F 3 "~" H 18400 9575 50  0001 C CNN
F 4 "999" H 18400 9575 50  0001 C CNN "ClickToSortForPlacement"
	1    18400 9575
	-1   0    0    1   
$EndComp
$Comp
L Device:R_POT_US VR4
U 1 1 5DC8FA72
P 18400 9275
F 0 "VR4" H 18332 9229 50  0000 R CNN
F 1 "200 KΩ" H 18332 9320 50  0000 R CNN
F 2 "multipackage:Potentiometer_Bourns_PTV09A-1_Single_Vertical" H 18400 9275 50  0001 C CNN
F 3 "https://www.bourns.com/docs/Product-Datasheets/PTV09.pdf" H 18400 9275 50  0001 C CNN
F 4 "28 Don't solder, merely press against sides of holes inside them with power on and diags running.  When A0 diags are successful, power down, pull boards apart with great care, then remove J3 and attach it again with a tack solder to J3 pin 2. Power up and run A1 diags using VR2 position similarly (inserted without soldering).   When A1 diags are successful power down, then remove J2, 3, & 4, R1 and solder-bridges of JP1-3 no cuts needed, check work for inadvertent shorts and opens after" H 9440 3545 50  0001 C CNN "ClickToSortForPlacement"
F 5 "User/developer use only: PTV09A-4030U-B204 or may end in B203 or some resistance in between those.  The 4030 may be 4020 or 4015 for shorter shaft. If using the UNO SMD MCU version with an ATMEGA128P-AU (a TQFP package specifically instead of the UNO with a DIP ATMEGA128P), there are two analog input pins available at the TQFP package on the MCU board that not wired out to any connector.  One or both of these can be, if you are willing to attach tiny wires between them and VR3/4 and write the code, used as seventh and eighth analog inputs A6 & A7.  Then air-wire them or connectorize them somehow across to this extention board and buy the PCB mount vertically oriented version of PTV09 pots to get one or two more user developed, run-time analog input controls into the training board." H 18400 9275 50  0001 C CNN "Part_number"
F 6 "http://Arrow.com" H 18400 9275 50  0001 C CNN "Source"
	1    18400 9275
	-1   0    0    1   
$EndComp
$Comp
L solderjumper_3_bridged12:SolderJumper_3_Bridged12 JP9
U 1 1 5D43D9B5
P 17700 9675
F 0 "JP9" H 17700 9788 50  0000 C CNN
F 1 "SolderJumper_3_Bridged12" H 18325 9850 50  0000 C CNN
F 2 "Jumper:SolderJumper-3_P1.3mm_Bridged12_Pad1.0x1.5mm_NumberLabels" H 17700 9675 50  0001 C CNN
F 3 "~" H 17700 9675 50  0001 C CNN
F 4 "999" H 17700 9675 50  0001 C CNN "ClickToSortForPlacement"
	1    17700 9675
	-1   0    0    1   
$EndComp
$Comp
L Device:Q_PJFET_SDG Q1
U 1 1 5D3CA4B3
P 7675 4350
F 0 "Q1" V 7550 4400 50  0000 L CNN
F 1 "MMBF5460 (2N5460)" V 7400 4100 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23_Handsoldering" H 7875 4450 50  0001 C CNN
F 3 "https://www.onsemi.com/pub/Collateral/MMBF5462-D.pdf" H 7675 4350 50  0001 C CNN
F 4 "MMBF5460" H 7675 4350 50  0001 C CNN "Part_number"
F 5 "http://Arrow.com" H 7675 4350 50  0001 C CNN "Source"
F 6 "24 Place, check work, place the diags resistors back that you may have had to move or remove using pad 1 of a MOSFET for any diag resistor to it.  Run the same diags just ran in previous step.  Remove diag resistors." H 7675 4350 50  0001 C CNN "ClickToSortForPlacement"
	1    7675 4350
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small_US R4
U 1 1 5CFBF015
P 6150 4025
F 0 "R4" H 5975 4075 50  0000 L CNN
F 1 "10 KΩ" H 5825 3975 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 6150 4025 50  0001 C CNN
F 3 "~" H 6150 4025 50  0001 C CNN
F 4 "http://Arrow.com" H 6150 4025 50  0001 C CNN "Source"
F 5 "RC0603JR-1310KL" H 6150 4025 50  0001 C CNN "Part_number"
F 6 "14 Place then check work" H 6150 4025 50  0001 C CNN "ClickToSortForPlacement"
	1    6150 4025
	1    0    0    -1  
$EndComp
$Comp
L 2019-03-19_09-09-09:MCP4262-xxxE_UN U27
U 1 1 5D6AAC30
P 6950 -825
F 0 "U27" H 6825 -1200 60  0000 R CNN
F 1 "MCP4262-502E/UN" H 6875 -1300 60  0000 R CNN
F 2 "Package_SO:MSOP-10_3x3mm_P0.5mm" H 7495 -400 60  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/22059b.pdf" H 6960 -825 60  0001 C CNN
F 4 "01" H 2600 -2725 50  0001 C CNN "PlacementOrder"
F 5 "01" H 2600 -2725 50  0001 C CNN "SortForPlacement"
F 6 "15 Check corner pads for adequate bare metal: ensure the solder mask of all corner pads is scraped off.  Clean so well after tinning that no difference can be seen of the output level when powered between with and without the unpopulated flex board inserted into J9.  Then place one component at a time, checking operation with power after each one is placed. For best immunity from physical vibrations, ensure leads 5,6,7 and 8 make contact with copper trace itself rather than only to solder.  " H 2600 -2725 50  0001 C CNN "ClickToSortForPlacement"
F 7 "MCP4262-502E/UN-ND" H 6950 -825 50  0001 C CNN "Part_number"
F 8 "http://digikey.com" H 6950 -825 50  0001 C CNN "Source"
	1    6950 -825
	-1   0    0    1   
$EndComp
$Comp
L 2019-03-19_09-09-09:MCP4262-xxxE_UN U28
U 1 1 5D79DE00
P 8725 -775
F 0 "U28" H 8600 -1150 60  0000 R CNN
F 1 "MCP4262-502E/UN" H 8650 -1250 60  0000 R CNN
F 2 "Package_SO:MSOP-10_3x3mm_P0.5mm" H 9270 -350 60  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/22059b.pdf" H 8735 -775 60  0001 C CNN
F 4 "01" H 4375 -2675 50  0001 C CNN "PlacementOrder"
F 5 "01" H 4375 -2675 50  0001 C CNN "SortForPlacement"
F 6 "15 Check corner pads for adequate bare metal: ensure the solder mask of all corner pads is scraped off.  Clean so well after tinning that no difference can be seen of the output level when powered between with and without the unpopulated flex board inserted into J9.  Then place one component at a time, checking operation with power after each one is placed. For best immunity from physical vibrations, ensure leads 5,6,7 and 8 make contact with copper trace itself rather than only to solder.  " H 4375 -2675 50  0001 C CNN "ClickToSortForPlacement"
F 7 "MCP4262-502E/UN-ND" H 8725 -775 50  0001 C CNN "Part_number"
F 8 "http://digikey.com" H 8725 -775 50  0001 C CNN "Source"
	1    8725 -775
	-1   0    0    1   
$EndComp
$Comp
L 2019-03-19_09-09-09:MCP4262-xxxE_UN U29
U 1 1 5D7B7390
P 10325 -800
F 0 "U29" H 10200 -1175 60  0000 R CNN
F 1 "MCP4262-502E/UN" H 10250 -1275 60  0000 R CNN
F 2 "Package_SO:MSOP-10_3x3mm_P0.5mm" H 10870 -375 60  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/22059b.pdf" H 10335 -800 60  0001 C CNN
F 4 "01" H 5975 -2700 50  0001 C CNN "PlacementOrder"
F 5 "01" H 5975 -2700 50  0001 C CNN "SortForPlacement"
F 6 "15 Check corner pads for adequate bare metal: ensure the solder mask of all corner pads is scraped off.  Clean so well after tinning that no difference can be seen of the output level when powered between with and without the unpopulated flex board inserted into J9.  Then place one component at a time, checking operation with power after each one is placed. For best immunity from physical vibrations, ensure leads 5,6,7 and 8 make contact with copper trace itself rather than only to solder.  " H 5975 -2700 50  0001 C CNN "ClickToSortForPlacement"
F 7 "MCP4262-502E/UN-ND" H 10325 -800 50  0001 C CNN "Part_number"
F 8 "http://digikey.com" H 10325 -800 50  0001 C CNN "Source"
	1    10325 -800
	-1   0    0    1   
$EndComp
$Comp
L 2019-03-19_09-09-09:MCP4262-xxxE_UN U30
U 1 1 5D7D0E54
P 11950 -775
F 0 "U30" H 11825 -1150 60  0000 R CNN
F 1 "MCP4262-502E/UN" H 11875 -1250 60  0000 R CNN
F 2 "Package_SO:MSOP-10_3x3mm_P0.5mm" H 12495 -350 60  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/22059b.pdf" H 11960 -775 60  0001 C CNN
F 4 "01" H 7600 -2675 50  0001 C CNN "PlacementOrder"
F 5 "01" H 7600 -2675 50  0001 C CNN "SortForPlacement"
F 6 "15 Check corner pads for adequate bare metal: ensure the solder mask of all corner pads is scraped off.  Clean so well after tinning that no difference can be seen of the output level when powered between with and without the unpopulated flex board inserted into J9.  Then place one component at a time, checking operation with power after each one is placed. For best immunity from physical vibrations, ensure leads 5,6,7 and 8 make contact with copper trace itself rather than only to solder.  " H 7600 -2675 50  0001 C CNN "ClickToSortForPlacement"
F 7 "MCP4262-502E/UN-ND" H 11950 -775 50  0001 C CNN "Part_number"
F 8 "http://digikey.com" H 11950 -775 50  0001 C CNN "Source"
	1    11950 -775
	-1   0    0    1   
$EndComp
$Comp
L 2019-03-19_09-09-09:MCP4262-xxxE_UN U31
U 1 1 5D7E9C86
P 13700 -750
F 0 "U31" H 13575 -1125 60  0000 R CNN
F 1 "MCP4262-502E/UN" H 13625 -1225 60  0000 R CNN
F 2 "Package_SO:MSOP-10_3x3mm_P0.5mm" H 14245 -325 60  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/22059b.pdf" H 13710 -750 60  0001 C CNN
F 4 "01" H 9350 -2650 50  0001 C CNN "PlacementOrder"
F 5 "01" H 9350 -2650 50  0001 C CNN "SortForPlacement"
F 6 "15 Check corner pads for adequate bare metal: ensure the solder mask of all corner pads is scraped off.  Clean so well after tinning that no difference can be seen of the output level when powered between with and without the unpopulated flex board inserted into J9.  Then place one component at a time, checking operation with power after each one is placed. For best immunity from physical vibrations, ensure leads 5,6,7 and 8 make contact with copper trace itself rather than only to solder.  " H 9350 -2650 50  0001 C CNN "ClickToSortForPlacement"
F 7 "MCP4262-502E/UN-ND" H 13700 -750 50  0001 C CNN "Part_number"
F 8 "http://digikey.com" H 13700 -750 50  0001 C CNN "Source"
	1    13700 -750
	-1   0    0    1   
$EndComp
$Comp
L 2019-03-19_09-09-09:MCP4262-xxxE_UN U32
U 1 1 5D8038A3
P 15225 -750
F 0 "U32" H 15100 -1125 60  0000 R CNN
F 1 "MCP4262-502E/UN" H 15150 -1225 60  0000 R CNN
F 2 "Package_SO:MSOP-10_3x3mm_P0.5mm" H 15770 -325 60  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/22059b.pdf" H 15235 -750 60  0001 C CNN
F 4 "01" H 10875 -2650 50  0001 C CNN "PlacementOrder"
F 5 "01" H 10875 -2650 50  0001 C CNN "SortForPlacement"
F 6 "15 Check corner pads for adequate bare metal: ensure the solder mask of all corner pads is scraped off.  Clean so well after tinning that no difference can be seen of the output level when powered between with and without the unpopulated flex board inserted into J9.  Then place one component at a time, checking operation with power after each one is placed. For best immunity from physical vibrations, ensure leads 5,6,7 and 8 make contact with copper trace itself rather than only to solder.  " H 10875 -2650 50  0001 C CNN "ClickToSortForPlacement"
F 7 "MCP4262-502E/UN-ND" H 15225 -750 50  0001 C CNN "Part_number"
F 8 "http://digikey.com" H 15225 -750 50  0001 C CNN "Source"
	1    15225 -750
	-1   0    0    1   
$EndComp
$Comp
L Device:R_Small_US R17
U 1 1 5D899630
P 8050 4150
F 0 "R17" V 8150 4100 50  0000 L CNN
F 1 "15 KΩ" V 7950 4025 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 8050 4150 50  0001 C CNN
F 3 "~" H 8050 4150 50  0001 C CNN
F 4 "http://Arrow.com" H 8050 4150 50  0001 C CNN "Source"
F 5 "RNCP0603FTD15K0" H 8050 4150 50  0001 C CNN "Part_number"
F 6 "14 IF NO FOOTPRINT FOR THIS: OPTIONAL IN BOARD REV .7 AND BELOW AND WOULD HAVE TO CUT A TRACE.  Place. For best immunity from physical vibrations, ensure the ends make contact with copper trace itself rather than only to solder.   Then check work" H 8050 4150 50  0001 C CNN "ClickToSortForPlacement"
	1    8050 4150
	0    1    1    0   
$EndComp
$Comp
L 2019-03-19_09-09-09:MCP4262-xxxE_UN U21
U 1 1 5D88DEC2
P 6900 -2500
F 0 "U21" H 6775 -2875 60  0000 R CNN
F 1 "MCP4262-502E/UN" H 6825 -2975 60  0000 R CNN
F 2 "Package_SO:MSOP-10_3x3mm_P0.5mm" H 7445 -2075 60  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/22059b.pdf" H 6910 -2500 60  0001 C CNN
F 4 "01" H 2550 -4400 50  0001 C CNN "PlacementOrder"
F 5 "01" H 2550 -4400 50  0001 C CNN "SortForPlacement"
F 6 "15 Check corner pads for adequate bare metal: ensure the solder mask of all corner pads is scraped off.  Clean so well after tinning that no difference can be seen of the output level when powered between with and without the unpopulated flex board inserted into J9.  Then place one component at a time, checking operation with power after each one is placed. For best immunity from physical vibrations, ensure leads 5,6,7 and 8 make contact with copper trace itself rather than only to solder.  " H 2550 -4400 50  0001 C CNN "ClickToSortForPlacement"
F 7 "MCP4262-502E/UN-ND" H 6900 -2500 50  0001 C CNN "Part_number"
F 8 "http://digikey.com" H 6900 -2500 50  0001 C CNN "Source"
	1    6900 -2500
	-1   0    0    1   
$EndComp
$Comp
L 2019-03-19_09-09-09:MCP4262-xxxE_UN U22
U 1 1 5D88DEE1
P 8675 -2450
F 0 "U22" H 8550 -2825 60  0000 R CNN
F 1 "MCP4262-502E/UN" H 8600 -2925 60  0000 R CNN
F 2 "Package_SO:MSOP-10_3x3mm_P0.5mm" H 9220 -2025 60  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/22059b.pdf" H 8685 -2450 60  0001 C CNN
F 4 "01" H 4325 -4350 50  0001 C CNN "PlacementOrder"
F 5 "01" H 4325 -4350 50  0001 C CNN "SortForPlacement"
F 6 "15 Check corner pads for adequate bare metal: ensure the solder mask of all corner pads is scraped off.  Clean so well after tinning that no difference can be seen of the output level when powered between with and without the unpopulated flex board inserted into J9.  Then place one component at a time, checking operation with power after each one is placed. For best immunity from physical vibrations, ensure leads 5,6,7 and 8 make contact with copper trace itself rather than only to solder.  " H 4325 -4350 50  0001 C CNN "ClickToSortForPlacement"
F 7 "MCP4262-502E/UN-ND" H 8675 -2450 50  0001 C CNN "Part_number"
F 8 "http://digikey.com" H 8675 -2450 50  0001 C CNN "Source"
	1    8675 -2450
	-1   0    0    1   
$EndComp
$Comp
L 2019-03-19_09-09-09:MCP4262-xxxE_UN U23
U 1 1 5D88DF00
P 10275 -2475
F 0 "U23" H 10150 -2850 60  0000 R CNN
F 1 "MCP4262-502E/UN" H 10200 -2950 60  0000 R CNN
F 2 "Package_SO:MSOP-10_3x3mm_P0.5mm" H 10820 -2050 60  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/22059b.pdf" H 10285 -2475 60  0001 C CNN
F 4 "01" H 5925 -4375 50  0001 C CNN "PlacementOrder"
F 5 "01" H 5925 -4375 50  0001 C CNN "SortForPlacement"
F 6 "15 Check corner pads for adequate bare metal: ensure the solder mask of all corner pads is scraped off.  Clean so well after tinning that no difference can be seen of the output level when powered between with and without the unpopulated flex board inserted into J9.  Then place one component at a time, checking operation with power after each one is placed. For best immunity from physical vibrations, ensure leads 5,6,7 and 8 make contact with copper trace itself rather than only to solder.  " H 5925 -4375 50  0001 C CNN "ClickToSortForPlacement"
F 7 "MCP4262-502E/UN-ND" H 10275 -2475 50  0001 C CNN "Part_number"
F 8 "http://digikey.com" H 10275 -2475 50  0001 C CNN "Source"
	1    10275 -2475
	-1   0    0    1   
$EndComp
$Comp
L 2019-03-19_09-09-09:MCP4262-xxxE_UN U24
U 1 1 5D88DF1F
P 11900 -2450
F 0 "U24" H 11775 -2825 60  0000 R CNN
F 1 "MCP4262-502E/UN" H 11825 -2925 60  0000 R CNN
F 2 "Package_SO:MSOP-10_3x3mm_P0.5mm" H 12445 -2025 60  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/22059b.pdf" H 11910 -2450 60  0001 C CNN
F 4 "01" H 7550 -4350 50  0001 C CNN "PlacementOrder"
F 5 "01" H 7550 -4350 50  0001 C CNN "SortForPlacement"
F 6 "15 Check corner pads for adequate bare metal: ensure the solder mask of all corner pads is scraped off.  Clean so well after tinning that no difference can be seen of the output level when powered between with and without the unpopulated flex board inserted into J9.  Then place one component at a time, checking operation with power after each one is placed. For best immunity from physical vibrations, ensure leads 5,6,7 and 8 make contact with copper trace itself rather than only to solder.  " H 7550 -4350 50  0001 C CNN "ClickToSortForPlacement"
F 7 "MCP4262-502E/UN-ND" H 11900 -2450 50  0001 C CNN "Part_number"
F 8 "http://digikey.com" H 11900 -2450 50  0001 C CNN "Source"
	1    11900 -2450
	-1   0    0    1   
$EndComp
$Comp
L 2019-03-19_09-09-09:MCP4262-xxxE_UN U25
U 1 1 5D88DF3E
P 13650 -2425
F 0 "U25" H 13525 -2800 60  0000 R CNN
F 1 "MCP4262-502E/UN" H 13575 -2900 60  0000 R CNN
F 2 "Package_SO:MSOP-10_3x3mm_P0.5mm" H 14195 -2000 60  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/22059b.pdf" H 13660 -2425 60  0001 C CNN
F 4 "01" H 9300 -4325 50  0001 C CNN "PlacementOrder"
F 5 "01" H 9300 -4325 50  0001 C CNN "SortForPlacement"
F 6 "15 Check corner pads for adequate bare metal: ensure the solder mask of all corner pads is scraped off.  Clean so well after tinning that no difference can be seen of the output level when powered between with and without the unpopulated flex board inserted into J9.  Then place one component at a time, checking operation with power after each one is placed. For best immunity from physical vibrations, ensure leads 5,6,7 and 8 make contact with copper trace itself rather than only to solder.  " H 9300 -4325 50  0001 C CNN "ClickToSortForPlacement"
F 7 "MCP4262-502E/UN-ND" H 13650 -2425 50  0001 C CNN "Part_number"
F 8 "http://digikey.com" H 13650 -2425 50  0001 C CNN "Source"
	1    13650 -2425
	-1   0    0    1   
$EndComp
$Comp
L 2019-03-19_09-09-09:MCP4262-xxxE_UN U26
U 1 1 5D88DF5D
P 15175 -2425
F 0 "U26" H 15050 -2800 60  0000 R CNN
F 1 "MCP4262-502E/UN" H 15100 -2900 60  0000 R CNN
F 2 "Package_SO:MSOP-10_3x3mm_P0.5mm" H 15720 -2000 60  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/22059b.pdf" H 15185 -2425 60  0001 C CNN
F 4 "01" H 10825 -4325 50  0001 C CNN "PlacementOrder"
F 5 "01" H 10825 -4325 50  0001 C CNN "SortForPlacement"
F 6 "15 Check corner pads for adequate bare metal: ensure the solder mask of all corner pads is scraped off.  Clean so well after tinning that no difference can be seen of the output level when powered between with and without the unpopulated flex board inserted into J9.  Then place one component at a time, checking operation with power after each one is placed. For best immunity from physical vibrations, ensure leads 5,6,7 and 8 make contact with copper trace itself rather than only to solder.  " H 10825 -4325 50  0001 C CNN "ClickToSortForPlacement"
F 7 "MCP4262-502E/UN-ND" H 15175 -2425 50  0001 C CNN "Part_number"
F 8 "http://digikey.com" H 15175 -2425 50  0001 C CNN "Source"
	1    15175 -2425
	-1   0    0    1   
$EndComp
$Comp
L 2019-03-19_09-09-09:MCP4262-xxxE_UN U15
U 1 1 5D8ACEF1
P 6875 -4325
F 0 "U15" H 6750 -4700 60  0000 R CNN
F 1 "MCP4262-502E/UN" H 6800 -4800 60  0000 R CNN
F 2 "Package_SO:MSOP-10_3x3mm_P0.5mm" H 7420 -3900 60  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/22059b.pdf" H 6885 -4325 60  0001 C CNN
F 4 "01" H 2525 -6225 50  0001 C CNN "PlacementOrder"
F 5 "01" H 2525 -6225 50  0001 C CNN "SortForPlacement"
F 6 "15 Check corner pads for adequate bare metal: ensure the solder mask of all corner pads is scraped off.  Clean so well after tinning that no difference can be seen of the output level when powered between with and without the unpopulated flex board inserted into J9.  Then place one component at a time, checking operation with power after each one is placed. For best immunity from physical vibrations, ensure leads 5,6,7 and 8 make contact with copper trace itself rather than only to solder.  " H 2525 -6225 50  0001 C CNN "ClickToSortForPlacement"
F 7 "MCP4262-502E/UN-ND" H 6875 -4325 50  0001 C CNN "Part_number"
F 8 "http://digikey.com" H 6875 -4325 50  0001 C CNN "Source"
	1    6875 -4325
	-1   0    0    1   
$EndComp
$Comp
L 2019-03-19_09-09-09:MCP4262-xxxE_UN U16
U 1 1 5D8ACF10
P 8650 -4275
F 0 "U16" H 8525 -4650 60  0000 R CNN
F 1 "MCP4262-502E/UN" H 8575 -4750 60  0000 R CNN
F 2 "Package_SO:MSOP-10_3x3mm_P0.5mm" H 9195 -3850 60  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/22059b.pdf" H 8660 -4275 60  0001 C CNN
F 4 "01" H 4300 -6175 50  0001 C CNN "PlacementOrder"
F 5 "01" H 4300 -6175 50  0001 C CNN "SortForPlacement"
F 6 "15 Check corner pads for adequate bare metal: ensure the solder mask of all corner pads is scraped off.  Clean so well after tinning that no difference can be seen of the output level when powered between with and without the unpopulated flex board inserted into J9.  Then place one component at a time, checking operation with power after each one is placed. For best immunity from physical vibrations, ensure leads 5,6,7 and 8 make contact with copper trace itself rather than only to solder.  " H 4300 -6175 50  0001 C CNN "ClickToSortForPlacement"
F 7 "MCP4262-502E/UN-ND" H 8650 -4275 50  0001 C CNN "Part_number"
F 8 "http://digikey.com" H 8650 -4275 50  0001 C CNN "Source"
	1    8650 -4275
	-1   0    0    1   
$EndComp
$Comp
L 2019-03-19_09-09-09:MCP4262-xxxE_UN U17
U 1 1 5D8ACF2F
P 10250 -4300
F 0 "U17" H 10125 -4675 60  0000 R CNN
F 1 "MCP4262-502E/UN" H 10175 -4775 60  0000 R CNN
F 2 "Package_SO:MSOP-10_3x3mm_P0.5mm" H 10795 -3875 60  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/22059b.pdf" H 10260 -4300 60  0001 C CNN
F 4 "01" H 5900 -6200 50  0001 C CNN "PlacementOrder"
F 5 "01" H 5900 -6200 50  0001 C CNN "SortForPlacement"
F 6 "15 Check corner pads for adequate bare metal: ensure the solder mask of all corner pads is scraped off.  Clean so well after tinning that no difference can be seen of the output level when powered between with and without the unpopulated flex board inserted into J9.  Then place one component at a time, checking operation with power after each one is placed. For best immunity from physical vibrations, ensure leads 5,6,7 and 8 make contact with copper trace itself rather than only to solder.  " H 5900 -6200 50  0001 C CNN "ClickToSortForPlacement"
F 7 "MCP4262-502E/UN-ND" H 10250 -4300 50  0001 C CNN "Part_number"
F 8 "http://digikey.com" H 10250 -4300 50  0001 C CNN "Source"
	1    10250 -4300
	-1   0    0    1   
$EndComp
$Comp
L 2019-03-19_09-09-09:MCP4262-xxxE_UN U18
U 1 1 5D8ACF4E
P 11875 -4275
F 0 "U18" H 11750 -4650 60  0000 R CNN
F 1 "MCP4262-502E/UN" H 11800 -4750 60  0000 R CNN
F 2 "Package_SO:MSOP-10_3x3mm_P0.5mm" H 12420 -3850 60  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/22059b.pdf" H 11885 -4275 60  0001 C CNN
F 4 "01" H 7525 -6175 50  0001 C CNN "PlacementOrder"
F 5 "01" H 7525 -6175 50  0001 C CNN "SortForPlacement"
F 6 "15 Check corner pads for adequate bare metal: ensure the solder mask of all corner pads is scraped off.  Clean so well after tinning that no difference can be seen of the output level when powered between with and without the unpopulated flex board inserted into J9.  Then place one component at a time, checking operation with power after each one is placed. For best immunity from physical vibrations, ensure leads 5,6,7 and 8 make contact with copper trace itself rather than only to solder.  " H 7525 -6175 50  0001 C CNN "ClickToSortForPlacement"
F 7 "MCP4262-502E/UN-ND" H 11875 -4275 50  0001 C CNN "Part_number"
F 8 "http://digikey.com" H 11875 -4275 50  0001 C CNN "Source"
	1    11875 -4275
	-1   0    0    1   
$EndComp
$Comp
L 2019-03-19_09-09-09:MCP4262-xxxE_UN U19
U 1 1 5D8ACF6D
P 13625 -4250
F 0 "U19" H 13500 -4625 60  0000 R CNN
F 1 "MCP4262-502E/UN" H 13550 -4725 60  0000 R CNN
F 2 "Package_SO:MSOP-10_3x3mm_P0.5mm" H 14170 -3825 60  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/22059b.pdf" H 13635 -4250 60  0001 C CNN
F 4 "01" H 9275 -6150 50  0001 C CNN "PlacementOrder"
F 5 "01" H 9275 -6150 50  0001 C CNN "SortForPlacement"
F 6 "15 Check corner pads for adequate bare metal: ensure the solder mask of all corner pads is scraped off.  Clean so well after tinning that no difference can be seen of the output level when powered between with and without the unpopulated flex board inserted into J9.  Then place one component at a time, checking operation with power after each one is placed. For best immunity from physical vibrations, ensure leads 5,6,7 and 8 make contact with copper trace itself rather than only to solder.  " H 9275 -6150 50  0001 C CNN "ClickToSortForPlacement"
F 7 "MCP4262-502E/UN-ND" H 13625 -4250 50  0001 C CNN "Part_number"
F 8 "http://digikey.com" H 13625 -4250 50  0001 C CNN "Source"
	1    13625 -4250
	-1   0    0    1   
$EndComp
$Comp
L 2019-03-19_09-09-09:MCP4262-xxxE_UN U20
U 1 1 5D8ACF8C
P 15150 -4250
F 0 "U20" H 15025 -4625 60  0000 R CNN
F 1 "MCP4262-502E/UN" H 15075 -4725 60  0000 R CNN
F 2 "Package_SO:MSOP-10_3x3mm_P0.5mm" H 15695 -3825 60  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/22059b.pdf" H 15160 -4250 60  0001 C CNN
F 4 "01" H 10800 -6150 50  0001 C CNN "PlacementOrder"
F 5 "01" H 10800 -6150 50  0001 C CNN "SortForPlacement"
F 6 "15 Check corner pads for adequate bare metal: ensure the solder mask of all corner pads is scraped off.  Clean so well after tinning that no difference can be seen of the output level when powered between with and without the unpopulated flex board inserted into J9.  Then place one component at a time, checking operation with power after each one is placed. For best immunity from physical vibrations, ensure leads 5,6,7 and 8 make contact with copper trace itself rather than only to solder.  " H 10800 -6150 50  0001 C CNN "ClickToSortForPlacement"
F 7 "MCP4262-502E/UN-ND" H 15150 -4250 50  0001 C CNN "Part_number"
F 8 "http://digikey.com" H 15150 -4250 50  0001 C CNN "Source"
	1    15150 -4250
	-1   0    0    1   
$EndComp
$Comp
L 2019-03-19_09-09-09:MCP4262-xxxE_UN U9
U 1 1 5D8CCF9E
P 6850 -6150
F 0 "U9" H 6725 -6525 60  0000 R CNN
F 1 "MCP4262-502E/UN" H 6775 -6625 60  0000 R CNN
F 2 "Package_SO:MSOP-10_3x3mm_P0.5mm" H 7395 -5725 60  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/22059b.pdf" H 6860 -6150 60  0001 C CNN
F 4 "01" H 2500 -8050 50  0001 C CNN "PlacementOrder"
F 5 "01" H 2500 -8050 50  0001 C CNN "SortForPlacement"
F 6 "15 Check corner pads for adequate bare metal: ensure the solder mask of all corner pads is scraped off.  Clean so well after tinning that no difference can be seen of the output level when powered between with and without the unpopulated flex board inserted into J9.  Then place one component at a time, checking operation with power after each one is placed. For best immunity from physical vibrations, ensure leads 5,6,7 and 8 make contact with copper trace itself rather than only to solder.  " H 2500 -8050 50  0001 C CNN "ClickToSortForPlacement"
F 7 "MCP4262-502E/UN-ND" H 6850 -6150 50  0001 C CNN "Part_number"
F 8 "http://digikey.com" H 6850 -6150 50  0001 C CNN "Source"
	1    6850 -6150
	-1   0    0    1   
$EndComp
$Comp
L 2019-03-19_09-09-09:MCP4262-xxxE_UN U10
U 1 1 5D8CCFBD
P 8625 -6100
F 0 "U10" H 8500 -6475 60  0000 R CNN
F 1 "MCP4262-502E/UN" H 8550 -6575 60  0000 R CNN
F 2 "Package_SO:MSOP-10_3x3mm_P0.5mm" H 9170 -5675 60  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/22059b.pdf" H 8635 -6100 60  0001 C CNN
F 4 "01" H 4275 -8000 50  0001 C CNN "PlacementOrder"
F 5 "01" H 4275 -8000 50  0001 C CNN "SortForPlacement"
F 6 "15 Check corner pads for adequate bare metal: ensure the solder mask of all corner pads is scraped off.  Clean so well after tinning that no difference can be seen of the output level when powered between with and without the unpopulated flex board inserted into J9.  Then place one component at a time, checking operation with power after each one is placed. For best immunity from physical vibrations, ensure leads 5,6,7 and 8 make contact with copper trace itself rather than only to solder.  " H 4275 -8000 50  0001 C CNN "ClickToSortForPlacement"
F 7 "MCP4262-502E/UN-ND" H 8625 -6100 50  0001 C CNN "Part_number"
F 8 "http://digikey.com" H 8625 -6100 50  0001 C CNN "Source"
	1    8625 -6100
	-1   0    0    1   
$EndComp
$Comp
L 2019-03-19_09-09-09:MCP4262-xxxE_UN U11
U 1 1 5D8CCFDC
P 10225 -6125
F 0 "U11" H 10100 -6500 60  0000 R CNN
F 1 "MCP4262-502E/UN" H 10150 -6600 60  0000 R CNN
F 2 "Package_SO:MSOP-10_3x3mm_P0.5mm" H 10770 -5700 60  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/22059b.pdf" H 10235 -6125 60  0001 C CNN
F 4 "01" H 5875 -8025 50  0001 C CNN "PlacementOrder"
F 5 "01" H 5875 -8025 50  0001 C CNN "SortForPlacement"
F 6 "15 Check corner pads for adequate bare metal: ensure the solder mask of all corner pads is scraped off.  Clean so well after tinning that no difference can be seen of the output level when powered between with and without the unpopulated flex board inserted into J9.  Then place one component at a time, checking operation with power after each one is placed. For best immunity from physical vibrations, ensure leads 5,6,7 and 8 make contact with copper trace itself rather than only to solder.  " H 5875 -8025 50  0001 C CNN "ClickToSortForPlacement"
F 7 "MCP4262-502E/UN-ND" H 10225 -6125 50  0001 C CNN "Part_number"
F 8 "http://digikey.com" H 10225 -6125 50  0001 C CNN "Source"
	1    10225 -6125
	-1   0    0    1   
$EndComp
$Comp
L 2019-03-19_09-09-09:MCP4262-xxxE_UN U12
U 1 1 5D8CCFFB
P 11850 -6100
F 0 "U12" H 11725 -6475 60  0000 R CNN
F 1 "MCP4262-502E/UN" H 11775 -6575 60  0000 R CNN
F 2 "Package_SO:MSOP-10_3x3mm_P0.5mm" H 12395 -5675 60  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/22059b.pdf" H 11860 -6100 60  0001 C CNN
F 4 "01" H 7500 -8000 50  0001 C CNN "PlacementOrder"
F 5 "01" H 7500 -8000 50  0001 C CNN "SortForPlacement"
F 6 "15 Check corner pads for adequate bare metal: ensure the solder mask of all corner pads is scraped off.  Clean so well after tinning that no difference can be seen of the output level when powered between with and without the unpopulated flex board inserted into J9.  Then place one component at a time, checking operation with power after each one is placed. For best immunity from physical vibrations, ensure leads 5,6,7 and 8 make contact with copper trace itself rather than only to solder.  " H 7500 -8000 50  0001 C CNN "ClickToSortForPlacement"
F 7 "MCP4262-502E/UN-ND" H 11850 -6100 50  0001 C CNN "Part_number"
F 8 "http://digikey.com" H 11850 -6100 50  0001 C CNN "Source"
	1    11850 -6100
	-1   0    0    1   
$EndComp
$Comp
L 2019-03-19_09-09-09:MCP4262-xxxE_UN U13
U 1 1 5D8CD01A
P 13600 -6075
F 0 "U13" H 13475 -6450 60  0000 R CNN
F 1 "MCP4262-502E/UN" H 13525 -6550 60  0000 R CNN
F 2 "Package_SO:MSOP-10_3x3mm_P0.5mm" H 14145 -5650 60  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/22059b.pdf" H 13610 -6075 60  0001 C CNN
F 4 "01" H 9250 -7975 50  0001 C CNN "PlacementOrder"
F 5 "01" H 9250 -7975 50  0001 C CNN "SortForPlacement"
F 6 "15 Check corner pads for adequate bare metal: ensure the solder mask of all corner pads is scraped off.  Clean so well after tinning that no difference can be seen of the output level when powered between with and without the unpopulated flex board inserted into J9.  Then place one component at a time, checking operation with power after each one is placed. For best immunity from physical vibrations, ensure leads 5,6,7 and 8 make contact with copper trace itself rather than only to solder.  " H 9250 -7975 50  0001 C CNN "ClickToSortForPlacement"
F 7 "MCP4262-502E/UN-ND" H 13600 -6075 50  0001 C CNN "Part_number"
F 8 "http://digikey.com" H 13600 -6075 50  0001 C CNN "Source"
	1    13600 -6075
	-1   0    0    1   
$EndComp
$Comp
L 2019-03-19_09-09-09:MCP4262-xxxE_UN U14
U 1 1 5D8CD039
P 15125 -6075
F 0 "U14" H 15000 -6450 60  0000 R CNN
F 1 "MCP4262-502E/UN" H 15050 -6550 60  0000 R CNN
F 2 "Package_SO:MSOP-10_3x3mm_P0.5mm" H 15670 -5650 60  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/22059b.pdf" H 15135 -6075 60  0001 C CNN
F 4 "01" H 10775 -7975 50  0001 C CNN "PlacementOrder"
F 5 "01" H 10775 -7975 50  0001 C CNN "SortForPlacement"
F 6 "15 Check corner pads for adequate bare metal: ensure the solder mask of all corner pads is scraped off.  Clean so well after tinning that no difference can be seen of the output level when powered between with and without the unpopulated flex board inserted into J9.  Then place one component at a time, checking operation with power after each one is placed. For best immunity from physical vibrations, ensure leads 5,6,7 and 8 make contact with copper trace itself rather than only to solder.  " H 10775 -7975 50  0001 C CNN "ClickToSortForPlacement"
F 7 "MCP4262-502E/UN-ND" H 15125 -6075 50  0001 C CNN "Part_number"
F 8 "http://digikey.com" H 15125 -6075 50  0001 C CNN "Source"
	1    15125 -6075
	-1   0    0    1   
$EndComp
$Comp
L Regulator_Linear:MCP1700-3002E_SOT23 U1
U 1 1 5DA5755D
P 3225 5050
F 0 "U1" H 3225 5250 50  0000 C CNN
F 1 "3V LDO" H 3225 5175 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 3225 5275 50  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/20001826D.pdf" H 3225 5050 50  0001 C CNN
F 4 "http://Arrow.com" H 3225 5050 50  0001 C CNN "Source"
F 5 "18 Place then check work" H 3225 5050 50  0001 C CNN "ClickToSortForPlacement"
F 6 "MCP1700T-3002E/TT" H 3225 5050 50  0001 C CNN "Part_number"
	1    3225 5050
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C7
U 1 1 5DADD1F4
P 3575 5150
F 0 "C7" H 3450 5050 50  0000 L CNN
F 1 "1uF" H 3600 5050 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 3575 5150 50  0001 C CNN
F 3 "https://static6.arrow.com/aropdfconversion/1f443eab4acf01f089a96c9291c2d9208a40ac8/nmchc.pdf" H 3575 5150 50  0001 C CNN
F 4 "NMC0603Y5V105Z10TRPF" H 3575 5150 50  0001 C CNN "Part_number"
F 5 "http://Arrow.com" H 3575 5150 50  0001 C CNN "Source"
F 6 "09 Place, then check work" H 3575 5150 50  0001 C CNN "ClickToSortForPlacement"
	1    3575 5150
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small_US R18
U 1 1 5DB14AB4
P 3700 4950
F 0 "R18" H 3500 5000 50  0000 L CNN
F 1 "21 KΩ" H 3700 4825 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 3700 4950 50  0001 C CNN
F 3 "https://static6.arrow.com/aropdfconversion/3cece72dd289ffbadc164fbcd05f638dd7240f7b/rc_datasheet_150330.pdf.pdf" H 3700 4950 50  0001 C CNN
F 4 "http://Arrow.com" H 3700 4950 50  0001 C CNN "Source"
F 5 "RC1608F2102CS" H 3700 4950 50  0001 C CNN "Part_number"
F 6 "09 Place, then check work" H 3700 4950 50  0001 C CNN "ClickToSortForPlacement"
	1    3700 4950
	1    0    0    -1  
$EndComp
Wire Wire Line
	3750 4750 3700 4750
Wire Wire Line
	3700 4750 3700 4850
NoConn ~ 3800 4850
Wire Wire Line
	9500 4000 9500 4325
Wire Wire Line
	9500 4000 10750 4000
Text Label 8300 -4525 2    50   ~ 0
U8-Pad6
Text Label 8300 -4425 2    50   ~ 0
U8-Pad5
Text Label 6525 -4475 2    50   ~ 0
U8-Pad5
Text Label 6525 -4575 2    50   ~ 0
U8-Pad6
Text Label 6500 -6400 2    50   ~ 0
U8-Pad6
Text Label 6500 -6300 2    50   ~ 0
U8-Pad5
$Comp
L 2019-03-19_09-09-09:MCP4262-xxxE_UN U7
U 1 1 5C9A2EF5
P 9850 4575
F 0 "U7" H 10050 3675 60  0000 R CNN
F 1 "MCP4262-503E/UN" H 10450 3575 60  0000 R CNN
F 2 "Package_SO:MSOP-10_3x3mm_P0.5mm" H 10395 5000 60  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/22059b.pdf" H 9860 4575 60  0001 C CNN
F 4 "01" H 5500 2675 50  0001 C CNN "PlacementOrder"
F 5 "01" H 5500 2675 50  0001 C CNN "SortForPlacement"
F 6 "12 Check corner pads for adequate bare metal: ensure the solder mask of all corner pads is scraped off.  Place.  For best immunity from physical vibrations, ensure leads 5,6,7 and 8 make contact with copper trace itself rather than only to solder.  Temporary tack solder J2 with pin 5 only, J3 with pin 1, and J4 with pin 4 only.  Check for inadvertent shorts and opens." H 5500 2675 50  0001 C CNN "ClickToSortForPlacement"
F 7 "MCP4262-503E/UN-ND" H 9850 4575 50  0001 C CNN "Part_number"
F 8 "http://Arrow.com" H 9850 4575 50  0001 C CNN "Source"
	1    9850 4575
	-1   0    0    1   
$EndComp
Text Label 10950 4425 2    50   ~ 0
U8-Pad5
Text Label 10950 4325 2    50   ~ 0
U8-Pad6
Wire Notes Line
	9525 4025 9525 4275
$Comp
L 1-2328702-0:1-2328702-0 J9
U 1 1 5DA5E558
P 21400 5500
F 0 "J9" H 21325 4800 50  0000 L CNN
F 1 "TE_1-2328702-0" H 21000 4625 50  0000 L CNN
F 2 "multipackage:TE_1-2328702-0" H 21400 5500 50  0001 C CNN
F 3 "~" H 21400 5500 50  0001 C CNN
F 4 "1-2328702-0" H 21400 5500 50  0001 C CNN "Part_number"
F 5 "https://www.te.com/ OR http://Arrow.com (factory direct can actually be a few cents cheaper with this one!)" H 21400 5500 50  0001 C CNN "Source"
F 6 "14 Place then check work" H 21400 5500 50  0001 C CNN "ClickToSortForPlacement"
	1    21400 5500
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR0142
U 1 1 5D76262A
P 21000 6000
F 0 "#PWR0142" H 21000 5750 50  0001 C CNN
F 1 "GNDD" H 21004 5845 50  0000 C CNN
F 2 "" H 21000 6000 50  0001 C CNN
F 3 "" H 21000 6000 50  0001 C CNN
	1    21000 6000
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0143
U 1 1 5D764CDA
P 20225 5250
F 0 "#PWR0143" H 20225 5100 50  0001 C CNN
F 1 "+5V" H 20240 5423 50  0000 C CNN
F 2 "" H 20225 5250 50  0001 C CNN
F 3 "" H 20225 5250 50  0001 C CNN
	1    20225 5250
	1    0    0    -1  
$EndComp
Text Label 21000 5000 2    50   ~ 0
8
Text Label 21000 5100 2    50   ~ 0
SCK(1)
Text Label 21000 5200 2    50   ~ 0
MOSI(1)
$Comp
L power:GNDD #PWR0144
U 1 1 5D79F70A
P 20125 5550
F 0 "#PWR0144" H 20125 5300 50  0001 C CNN
F 1 "GNDD" H 20129 5395 50  0000 C CNN
F 2 "" H 20125 5550 50  0001 C CNN
F 3 "" H 20125 5550 50  0001 C CNN
	1    20125 5550
	1    0    0    -1  
$EndComp
Text Label 21000 5600 2    50   ~ 0
U8-Pad5
Text Label 21000 5900 2    50   ~ 0
U8-Pad6
Text Label 21000 5800 2    50   ~ 0
U8-Pad7
Text Label 21000 5700 2    50   ~ 0
U8-Pad8
Text Label 21000 5500 2    50   ~ 0
1st_stage_guard_trace
$Comp
L Reference_Current:REF200AU U4
U 1 1 5D0F9980
P 6150 3525
F 0 "U4" H 5775 3825 50  0000 L CNN
F 1 "REF200AU" H 5650 3725 50  0000 L CIN
F 2 "Package_SO:SOIC-8_3.9x4.9mm_P1.27mm" H 6025 3550 50  0001 R CIN
F 3 "www.ti.com/lit/ds/symlink/ref200.pdf" H 6450 3525 50  0001 C CIN
F 4 "http://Arrow.com" H 6150 3525 50  0001 C CNN "Source"
F 5 "REF200AU (Requires hermetic sealing, so will have dessicant with it that you'll need to place under SHLD1)" H 6150 3525 50  0001 C CNN "Part_number"
F 6 "26 Before opening this shipping package, perform as complete of diagnostics as possible of all circuitry under SHLD1 placed thus far: solder a shorting wire between pins 4 & 5 of U3 (mix & match with pins 1 of both Q1 and Q2) and load the Arduino with GWAAM-Sea Diagnostics 1 and run them.  Remove short between pins 4 and 5 of U3.  Then, from the bottom side of the board, solder seal any and all via holes left unsoldered located within SHLD1 footprint.  Solder seal any and all place-assist holes located within SHLD1 footprint except U3 place-assist holes.  All this should minimize risk of getting interrupted while U3 is left not heremetically sealed.  Tin SHLD1 around outside of bottom edge that will get soldered to its footprint.  Tin SHLD1 footprint on the board, leaving a very SMOOTH & FLAT surface to mate with SHLD1.  Prepare dessicant (trim pkg for edges to be bent over to fit inside SHLD1 holding like a pinch of the silica or clay granules & held in place by Kapton tape without putting pressure on other components) as soon as U3 is placed, and ensure SHLD1 is handy also.  Place U3 and perform diagnostics of U3.  After diags, solder-seal its place-assist holes.  Immediately perform next step." H 6150 3525 50  0001 C CNN "ClickToSortForPlacement"
	1    6150 3525
	1    0    0    -1  
$EndComp
Wire Wire Line
	22050 5050 22550 5050
Wire Wire Line
	22650 4725 21950 4725
Wire Wire Line
	21950 4725 21950 7800
Wire Wire Line
	22500 5500 22600 5500
Text Label 10200 4425 0    50   ~ 0
7
Text Label 11675 4425 0    50   ~ 0
8
Wire Wire Line
	20125 5550 20125 5300
Wire Wire Line
	20125 5300 21000 5300
Wire Wire Line
	20225 5400 20225 5250
Wire Wire Line
	20225 5400 21000 5400
Text Notes 50   -75  0    50   ~ 0
1 step MSB is 50000 ohms per device/256 steps per device = 195.3125 ohms = 195 ohms\n\n    5000 ohms LSB:\na single LSB device full resistance is 5000 ohms per device\n\nnumber of LSB devices to parallel together to make their full resistance value equal to 195 ohms is 5000 ohms per device/195 ohms = 25.6 devices\n\ncost = $25 + flex board a little larger size\n\n   Alternate design under consideration 1000 ohms LSB:\na single LSB device full resistance is 1000 ohms per device\n\nnumber of LSB devices to parallel together to make their full resistance value equal to 195 ohms is 1000 ohms per device/195 ohms = 5.13 devices\n\nEquivalent 2 devices/package, so 3 packages @ $6/pkg = $18 for savings of $7 or so and a much smaller flex board but with a different pinout of both the flex connector and the MCU connector from which it will consume one more digital pin.
Wire Wire Line
	1700 4800 2050 4800
Wire Wire Line
	2325 4800 2250 4800
Wire Wire Line
	2325 4800 2325 5450
$Comp
L power:GNDA #PWR0145
U 1 1 5DA6BC20
P 1700 4900
F 0 "#PWR0145" H 1700 4650 50  0001 C CNN
F 1 "GNDA" H 1705 4727 50  0000 C CNN
F 2 "" H 1700 4900 50  0001 C CNN
F 3 "" H 1700 4900 50  0001 C CNN
	1    1700 4900
	1    0    0    -1  
$EndComp
Text Notes 6650 4825 0    50   ~ 0
      > Solute >\n(aka DUT mirrored current)
Text Notes 7950 4650 1    55   ~ 0
|<Solvent<\n
Text Notes 7700 5850 1    50   ~ 0
<  Solution  <
Text Notes 8050 5800 0    50   ~ 0
<Mirrored solution<
Text Notes 9000 5600 1    50   ~ 0
< Counter-Balancing   Solvent <\n
Text Notes 5825 7600 0    70   Italic 14
NOTE THE ABOVE UNUSUAL USE OF, AND DISTINCTION BETWEEN CHEMISTRY TERMS \n"SOLUTE", "SOLVENT", AND "SOLUTION" ANALOGOUSLY APPLIED TO ELECTRICAL CURRENT
Wire Wire Line
	6200 4950 6200 12000
Connection ~ 6200 4950
Wire Notes Line
	1675 4950 2325 4950
Wire Wire Line
	20525 1500 20525 1225
Wire Notes Line
	8275 4100 8275 4750
Wire Wire Line
	7975 3950 7975 3900
Wire Notes Line
	9375 4125 9375 4450
Connection ~ 13075 6400
Wire Wire Line
	8350 3900 8350 4675
Wire Wire Line
	8150 4150 8250 4150
Wire Wire Line
	8250 4150 8250 4775
Connection ~ 6150 3225
Wire Wire Line
	14500 6400 16475 6400
Connection ~ 13575 6400
Wire Wire Line
	13575 6400 13850 6400
Wire Wire Line
	9500 5225 10975 5225
Wire Wire Line
	11675 4575 12050 4575
Wire Wire Line
	12050 4575 12050 5625
Wire Wire Line
	11675 4775 11975 4775
Wire Wire Line
	11800 4425 11800 7800
Wire Wire Line
	11800 7800 21950 7800
Wire Wire Line
	10350 4425 10350 5475
Wire Wire Line
	11725 7875 22050 7875
Wire Wire Line
	10200 4775 10200 5675
Wire Wire Line
	10250 4575 10250 5625
Wire Wire Line
	11725 5475 10350 5475
Wire Wire Line
	11725 5475 11725 7875
Wire Notes Line
	9050 3925 10975 3925
Wire Notes Line
	8900 4075 8900 4250
Wire Notes Line
	9525 5200 10850 5200
Wire Notes Line
	9425 5275 11000 5275
Wire Wire Line
	5000 5450 5000 6450
Connection ~ 5000 5450
Wire Notes Line
	9525 4025 10725 4025
Connection ~ 6400 4850
Wire Wire Line
	6150 3225 6400 3225
Wire Wire Line
	6400 3225 6400 3750
Wire Wire Line
	7475 3750 6400 3750
Connection ~ 6400 3750
Wire Wire Line
	6400 3750 6400 4850
Wire Wire Line
	6275 4750 6275 3925
Wire Wire Line
	6200 12000 9400 12000
Text Notes 6500 6250 0    65   ~ 0
        Solution Mirror\nMax current rating: \n     3 to 4 mA
Text Notes 8025 7000 0    60   ~ 0
 Signal Forming High-Z node - The signal on A0 is formed \nby the electromotively forced exit of the mirrored solute current (aka \n"twice-mirrored DUT current") by the Solution Mirror against the node's \nattached impedances.  The higher those impedances remain, the better \nsignal EMF is generated by said current, so keep this area clean and \nguarded with 3rd stage guard trace.
Text Notes 8250 6150 0    50   ~ 0
Mirrored solute, having its DC component \nremoved by the counter-balancing solvent \nstage, is transformed into the signal of interest
Text Notes 14975 3825 0    100  ~ 0
Optional \nOutboard \nADC
Wire Wire Line
	9400 4150 9400 4425
Wire Wire Line
	9400 4425 9500 4425
Wire Wire Line
	8875 4150 9400 4150
Wire Notes Line
	8900 4125 9375 4125
Wire Notes Line
	9375 4450 9575 4450
Connection ~ 7775 4650
Wire Wire Line
	12700 6350 13075 6350
Wire Wire Line
	13075 6350 13075 6400
Text Label 14600 6400 0    60   ~ 0
A1
Text Label 14050 4775 0    60   ~ 0
A0
Wire Notes Line
	12225 4175 12225 5875
Wire Notes Line
	8025 5875 12225 5875
Wire Notes Line
	7750 4475 7750 5850
Text Notes 17000 8450 0    70   ~ 0
Construction diagnostics may use one of \nthese VRs for solute dilution control or \nother purposes
Connection ~ 12050 5625
Wire Wire Line
	10250 5625 12050 5625
Wire Wire Line
	12050 5625 12050 6875
Wire Wire Line
	11975 4775 11975 5675
Connection ~ 11975 5675
Wire Wire Line
	10200 5675 11975 5675
Wire Wire Line
	11975 5675 11975 6950
Wire Wire Line
	7975 3900 8350 3900
Wire Notes Line
	7800 4075 7800 4225
Wire Notes Line
	8375 3925 8000 3925
Wire Notes Line
	8225 4125 7800 4125
Wire Notes Line
	8325 4700 9600 4700
Wire Notes Line
	8375 3875 8375 4700
Wire Notes Line
	8225 4750 9450 4750
Wire Wire Line
	8075 5850 8875 5850
Wire Notes Line
	8900 4475 8900 5850
Connection ~ 8875 5850
Wire Wire Line
	8875 5850 12250 5850
Wire Wire Line
	8875 4550 8875 5850
Wire Wire Line
	8250 4775 9400 4775
Wire Wire Line
	8350 4675 9500 4675
Text Notes 7800 5550 0    50   ~ 0
For optimal LM334 \nperformance, inject \nsolvent until solution = 2 \nor 3 µA.  Beyond that, \nsignal dilutes unnecessarily \nunless the diluted effect is \ndesired.  Solvent total is \nlimited to about 4 µA \nby R17 
Text Notes 8950 5800 0    50   ~ 0
Counter-Balancing Solvent total is limited by U4C to Solution total
Text Notes 6600 5100 0    50   ~ 0
Solute total is limited to \n750 µA by R3 + R1, and \nagain to 3.69 mA by R5
Text Notes 9050 5500 0    50   ~ 0
Sets DC \nlevel at \nA0 to \ntrack \noutboard \nADC's \nreference input \non A1.
$EndSCHEMATC