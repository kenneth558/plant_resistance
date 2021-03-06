//        BEFORE COMPILING THIS SKETCH you must set or confirm the following preprocessor macros appropriately for your configuration and preferences !!!
#define LM334_BRIDGES 1                                        //Number of digipot Wheatstones you have topped with LM334s each leg, (schematically wired before bare DPot bridges) but this sketch revision level not tested beyond 1.  Remove if using Wheatstone bridge with only standard or DPot resistors.  make this the number of bridges with upper resistive elements being LM334s controllable with the MCP4162-104 pots
#define DPOTS_PER_LM334_LEG 3                                  //Not yet tested for any setting except 3, so verify it before trusting fully.  Due to their significant temperature coefficient, LM334s need to be used in pairs so their tempco offsets each other's; i.e., LM334 legs are invalid unless bridged with both legs topped by a LM334
//FUTURE #define BARE_DPOT_LEG_BRIDGES                         //(after LM334 bridges in terms of pin number order) Subject to change NOT CODED FOR YET, but this makes effects of DPot settings be reversed from when LM334s are used.  Note that higher values of DPot leg resistances are expected to be required.  This could mean more DPots per leg increasing the likelihood 74LV138 decoding will be necessary.
//FUTURE #define BARE_DPOT_LEGS_UNBRIDGED                    //(after active bridges in terms of pin number order, passive bridges using manual pots might include these legs)Subject to change NOT CODED FOR YET, but this makes effects of DPot settings be reversed from when LM334s are used.  Note that higher values of DPot leg resistances are expected to be required.  This could mean more DPots per leg.
#define INBOARDS_PLOTTED 2                              //The number of consecutive analog pins to plot, beginning with PIN_A0
//#define OUTBOARDS_PLOTTED 1                             //The number of consecutive "highest-sensitivity ADC" pins to plot, beginning with A0 and, if double-ended, A1.  OUTBOARD ADC ONLY - DOES _NOT_ INCLUDE INBOARD ANALOG INPUT PINS
//#define MAGNIFICATION_FACTOR 5                                 //Activates the plotting of magnified traces in all ADC linespaces; upper limit somewhere less than 4,294,967,295. Note: you can disable displaying magnified traces altogether by not defined this macro at all. Proper use of SUPERIMPOSE_FIRST_INBOARDS_IN_PAIRS will also disable magnified traces of the first two analog inputs
#define HIGHEST_SENSI_OUTBOARD_ADC_TYPE HX711                  //Proposing that "ADS1231" covers ADS1231; could make this "ADS1232" ( ADS1232), "ADS1242" ( ADS1242), "AD779x" ( AD779x), "AD7780" ( AD7780), "HX711" (HX711), "ADS1X15" ( ADS1015 or ADS1115), "MAX112x0" (MAX112X0...) or "LTC2400" (LTC2400) but code not included in v.FREE; ONLY ONE TYPE ALLOWED
#define HIGHEST_BIT_RES_FROM_HIGHEST_SENSI_OUTBOARD_ADC 24     //All ADC values will get scaled to the single-ended aspect of this,  15 is ADS1115 single-ended, 16 for double-ended when two LM334s are used.  change to 11 for ADS1015 single-ended or 12 with two LM334s, (future: change to 24 for HX711--NO b/c there is the ADS1231 at 24 bits)
#define SAMPLE_TIMES 2                                         //To better average out artifacts we over-sample and average.  This value can be tweaked by you to ensure neutralization of power line noise or harmonics of power supplies, etc.....
//#define MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE true//Doesn't catch much - future plan is to have different levels including DEBUG in this
#define MOST_PROBLEMATIC_INTERFERENCE_FREQ 60                                                               //This is here just in case you think that you might have some interference on a known frequency.
#define DELAY_TIME_BETWEEN_SAMPLES_MS ( 1000 / MOST_PROBLEMATIC_INTERFERENCE_FREQ / SAMPLE_TIMES )          //COARSE ADJUST
#define DELAY_TIME_BETWEEN_SAMPLES_US ( ( ( 1000000 / MOST_PROBLEMATIC_INTERFERENCE_FREQ ) - ( DELAY_TIME_BETWEEN_SAMPLES_MS * SAMPLE_TIMES * 1000 ) ) / SAMPLE_TIMES ) //FINE ADJUST.  THIS GETS ADDED TO COARSE ADJUST, PRECISION = TRUNCATED PRAGMATICALLY TO uSec TO ACKNOWLEDGE SOME OVERHEAD FOR LOOPING SUPPORT CODE   // End of this part of code update
#define FIRST_ANALOG_PIN_DIGITAL_NUMBER_FOR_BOARDS_NOT_HAVING_ANALOG_PINS_DEFINED_BY_PIN_A0_TYPE_DEFINES 14 //Some boards don't have good definitions and constants for the analog pins :-(
#define PERCENT_OF_LINESPACE_MAGNIFIED_VIEW_SKIPS_WHEN_REPOSITIONED_WHEN_LINESPACE_LIMITS_GET_EXCEEDED 85   //BETWEEN 0 AND 100 indicating how much of the display region in percent to skip when magnified view trace has to get repositioned because trace would be outside region bounds; NO BOUNDS CHECKING IS PROVIDED!!!
#define ANALOG_INPUT_BITS_OF_BOARD 10                                        //Most Arduino boards are 10-bit resolution, but some can be 12 bits.  For known 12 bit boards (SAM, SAMD and TTGO XI architectures), this gets re-defined below, so generally this can be left as 10 even for those boards
#define SECONDS_THAT_A_LGT8FX8E_HARDWARE_SERIAL_NEEDS_TO_COME_UP_WORKING 9   //8 works only usually
#define HIGHEST_SENSI_PGA_GAIN_FACTOR 128                                    //For HX711 a gain of 128 gets applied to channel A. Available to you for your own use PGA=Programmable Gain Amplifier: many ADCs will correlate a gain of one with full-scale being rail-to-rail, while a gain of anything higher correlates to full-scale being in the mV range (most sensitive and most noise-susceptible).
#define MIN_WAIT_TIME_BETWEEN_PLOT_POINTS_MS 1                              //Sets a maximum speed limit, but actual speed may be further limited by other factors
#define SUPERIMPOSE_FIRST_INBOARDS_IN_PAIRS 1                                //If defined allows the rail-to-rail inboard Analog Inputs to be used to adjust digipots, but mainly causes first inboard Analog Inputs to be paired (superimposed in pairs sharing plot-line spaces) so even manual pots can be adjusted easily.
//#define PLOT_ONLY_THE_SIGNAL_LEG_OF_SUPERIMPOSED_DPOT_LEG_BRIDGE_INBOARDS  //By defining this macro comparison between signal and reference is no longer possible but it could be less confusing this way since user doesn't need to manually adjust anything with DPots and especially with AUTO_BRIDGE_BALANCING. ADVISE without AUTO_BRIDGE_BALANCING in effect, this macro probably should not be defined either. But regardless for greatest flexibility, that macro won't affect this.
//#define AUTO_BRIDGE_BALANCING                                                //increases setup time and during which the plot timing line stays high, then spikes low and high to indicate balancing complete //Turns on auto-balancing in setup(), significant time elapse for this to complete!
#define CONTINUE_PLOTTING_DURING_AUTO_BRIDGE_BALANCE true                    //Without predictive balancing, this takes too much time if true
//#define DEBUG                                                              //Don't forget that DEBUG is not formatted for Serial plotter, but might work anyway if you'd never print numbers only any DEBUG print line
#define SHOW_LINEARITY_USING_THIS_BRIDGE_INDEX 0
#define INJECT_DIAGNOSTIC_SQUARE_WAVE_ON_SIGNAL_PIN_OF_SPECIFIED_OUTBOARD_ADC 0       //For testing - wobbles digipot settings on bridge index to impose a signal into Wheatstone bridge outputs. This imposes a signal on the signal leg
#define INJECT_DIAGNOSTIC_SQUARE_WAVE_ON_REFERENCE_PIN_OF_SPECIFIED_OUTBOARD_ADC 0    //For testing - wobbles digipot settings on bridge index to impose a signal into Wheatstone bridge outputs. This imposes a signal on the reference leg
#define DIAGNOSTIC_SQUARE_WAVE_TIME_PERIOD  10
//#define LEAVE_POT_VALUES_ALONE_DURING_SETUP                                         //First run should leave this undefined to load digi pots with some values
#define BIAS_IN_ANALOG_INPUT_BITS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE_BRIDGE0 0  //This offset will be applied to all signal lines of outboard ADCs, not just the first one, until further development.  Write some code yourself to expand.  Inboard Analog Inputs of 10 bits will make much change with little values, 12 bit inboard allows more flexibility here
#ifdef BIAS_IN_ANALOG_INPUT_BITS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE_BRIDGE0
#define ADDITIONAL_BIAS_IN_LSB_DPOT_SETTING_POSITION_TO_APPLY_TO_SIGNAL_TRACE_BRIDGE0 2 //To maintain consistent effect with the above, associated macro, this gets applied inverted. This is in lieu of setting by reading the ADCs and zeroing them.
#endif
#ifdef __LGT8FX8E__
#define BAUD_TO_SERIAL 19200                                                          //This speed is what works best with WeMos XI/TTGO XI board.  Experiment as desired.
#else
#define BAUD_TO_SERIAL 115200                                                         //YOU MAY SET THIS TO THE MAXIMUM VALUE THAT YOUR CONFIGURATION WILL FUNCTION WITH (UNLESS YOU'RE USING THE WeMos XI/TTGO XI, OF COURSE)
#endif
#define DPOT_RATIO 20 /* DPOT_RATIO: System-wide MSB/LSB.  Ex.: If the LSB digipot is 200 ohms/step and the MSB digipot is 2000 ohms/step, this value will be 10. (2000/200)
                      It is only used relative to the LSB digipot, so there can only be that one digipot per leg allowed to have a smaller resistance
                      per step than other digipots on the leg. All bridge legs in the system must be built with the same ratio scheme, and must always include one and
                      only one LSB digipot, with all non-LSB digipots matching each others' resistance/step values.  This macro limits LSB settings adjustments
                      when another digipot in the leg is set to less than MAX_DPOT_SETTG, but not otherwise, allowing LSB to reach MAX_DPOT_SETTG when non-LSBs are all at MAX_DPOT_SETTG.
                      As far as MAX_DPOT_SETTG, all digipots in the system are bound by the same MAX_DPOT_SETTG value. */
//#define MINIMIZE_COMPILED_SKETCH_SIZE_LEVEL 0      somehow this does the opposite!!!   //Number 0 produces smallest sketch giving least data output functionality
//#define LOOP_COUNTER_LIMIT_THAT_TRACE_IS_ALLOWED_TO_BE_OFF_CENTER 3                   //sets how soon run-time auto-balancing kicks in when trace goes off scale

//#define SD_CARD_STORAGE_CS_PIN 4                                           //The free version does not contain the code to utilize SD card storage.  SD card storage only available in the priced ($20) sketch version.
//#define WIFI true                                                          //The free version does not contain the code to utilize wifi.  Wifi only available in the priced ($20) sketch version.  Buy online at 
//FUTURE
//FUTURE #define POT_WIPER_TO_THIS_ANALOG_INPUT_PIN_TO_ADJUST_MAGNIFICATION_FACTOR 3         //NOT the digital number //Can use a spare analog input as magnification attenuator by connecting wiper of a pot (100K or greater, please) that voltage-divides 0-5 vdc.  //Arduino only unless a dedicated ADS1115 is used
//FUTURE #define USING_DUAL_74LV138_DECODERS_FOR_DPOT_CS_LINES
//FUTURE #define TEST_STEP_UP_DOWN COMMONMODE                                // Available: SINGLESIDE COMMONMODE
//FUTURE #define BARE_DPOT_LEG_BRIDGES, BARE_DPOT_LEGS_UNBRIDGED             // Subject to change, but this makes effects of DPot settings be reversed from when LM334s are used.  Note that higher values of DPot leg resistances are expected to be required.  This could mean more DPots per leg.
//FUTURE #define BARE_DPOT_LEG_BRIDGES 1                                     // (after LM334 bridges in terms of pin number order) Subject to change NOT CODED FOR YET, but this makes effects of DPot settings be reversed from when LM334s are used.  Note that higher settingValues of DPot leg resistances are expected to be required.  This could mean more DPots per leg increasing the likelihood 74LV138 decoding will be necessary.
//FUTURE #define BARE_DPOT_LEGS_UNBRIDGED 1                                  //(If inputting to outboard ADCs these would be after active bridges in terms of pin number order, passive bridges using manual pots might include these legs)Subject to change NOT CODED FOR YET, but this makes effects of DPot settings be reversed from when LM334s are used.  Note that higher settingValues of DPot leg resistances are expected to be required.  This could mean more DPots per leg.
//FUTURE #define VERBOSITY_LEVEL                                             //To be used instead of and combines DEBUG and MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE
#define DPOTS_PER_BRIDGED_BARE_LEG 3                                         //FUTURE Not yet tested for any setting, so verify it before trusting fully
#define DPOTS_PER_UNBRIDGED_BARE_LEG 3                                       //FUTURE Not yet tested for any setting, so verify it before trusting fully
#ifdef USING_DUAL_74LV138_DECODERS_FOR_DPOT_CS_LINES                         //Arduino pins can be better utilized with higher numbers of DPots by adding 74LV138s expand the number of DPot CS pins that can be driven with a given number of Arduino pins
//!!! NOTE !!! 531 lines below this are also macros entitled similar to [NON_]LSB_DPOT_BXSIG(or REF)_PIN.  Those macros must also be set to correspond to the pins driving the CS lines of digipots
    #warning These pin numbers get specified normally, but be sure you specify the _digital_pot_CS_pins_ with the MSB set to decode them; i.e., make those pin numbers>= 128, but not these
    #define FIRST_STAGE_3_TO_8_DECODER_A0_PIN1 5                             //
    #define FIRST_STAGE_3_TO_8_DECODER_A1_PIN2 6                             //Second address pin of first stage not necessary if total DPots in the systems <= 2
    #define FIRST_STAGE_3_TO_8_DECODER_A2_PIN3 7                             //Third address pin of first stage not necessary if total DPots in the system <= 4
    //#define FIRST_STAGE_3_TO_8_DECODER_A3_PIN4 8                           //Always the same as FIRST_STAGE_3_TO_8_DECODER_ENABLE_PIN4 since both reference pin 4
    #ifndef FIRST_STAGE_3_TO_8_DECODER_A3_PIN4
        #define FIRST_STAGE_3_TO_8_DECODER_ENABLE_PIN4 8                     //Pin 4 either paralleled with final stage's pin 4 (only for up to 8 DPots) or used as a virtual A3. Pin 5 always connects to pin 4 of final stage 74LV138.
    #endif
    //#define FINAL_STAGE_3_TO_8_DECODER_A0_PIN1 5                           //Second stage not necessary if total DPots in the system <= 8
    //#define FINAL_STAGE_3_TO_8_DECODER_A1_PIN2 6                           //Second address pin of second stage not necessary if total DPots in the systems <= 16
    //#define FINAL_STAGE_3_TO_8_DECODER_A2_PIN3 7                           //Third address pin of second stage not necessary if total DPots in the systems <= 32
    //#define FINAL_STAGE_3_TO_8_DECODER_ENABLE_PIN4 9                       //This connects into both 74LV138 chips on their pins 4 with pins 6 held high. First stage gets its pin 5 signal from second stage pin 15 and second stage pin 5 gets held low. Maximum total DPots = 64
#endif                                                                       //There are two ways to use 74LV138s: if more than 16 DPots, then, in part, the final stage 74LV138 drives all previous stages 74LV138 with its output lines driving pin 4 of previous stages. Up to 16 DPots can be used by two 74LV138s in parallel with, in part, the first 74LV138's pin 4 acting as an A3 and its pin 5 connected to pin 4 of the final 74LV138

//No need to change macros below:
#define CONVERT_TWOS_COMP_TO_SINGLE_ENDED( value_read_from_the_differential_ADC, mask, xorvalue ) ((value_read_from_the_differential_ADC & mask)^xorvalue)
//A FEW OF THE OTHER MACROS (DEFINES OR RE-DEFINES) ELSEWHERE: VERSION, NON_LSB_DPOT_2_B0SIG_STARTVALUE - LSB_DPOT_B0REF_STARTVALUE, HALFHIGHEST_BIT_RES_FROM_HIGHEST_SENSI_OUTBOARD_ADC, DIFFERENTIAL, PIN_FOR_DATA_TOFROM_HIGHEST_SENSI_ADC, PIN_FOR_CLK_TO_HIGHEST_SENSI_ADC, PLOTTER_MAX_SCALE, HUNDREDTHPLOTTER_MAX_SCALE, SAMPLE_TIMES, SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE, COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG, HEIGHT_OF_A_PLOT_LINESPACE
#define COPYRIGHT_YEAR 2018
/*******************(C)  COPYRIGHT 2018 KENNETH L ANDERSON *********************

       ARDUINO ELECTRICAL RESISTANCE/CONDUCTANCE MONITORING SKETCH

  File Name          : adc_for_plant_tissue.ino
  Author             : KENNETH L ANDERSON
  Version            : v.Free
  Date               : 09-DEC-2018
  Description        : To replicate Cleve Backster's findings that he attributed to a phenomenon he called "Primary Perception".  Basically, this sketch turns an Arduino MCU and optional (recommended) ADS1115 into a nicely functional poor man's polygraph in order to learn/demonstrate telempathic gardening.
  Boards tested on   : Uno using both ADS1115 and inboard analog inputs.
                     : TTGO XI using ADS1115 in an early version
                     : Many other configurations should work fine.
                     : The ATtiny x4, ATtiny x5, ATtiny x61, ATtiny x8  not suitable at all due to not having hardware serial

  Known limitations  : Free version does not use predictive auto bridge balance resulting in painfully slow auto balance when plant conductance goes out of range
                     : No ability to accept user input from keyboard during run time due to Arduino plotter limitation
                     : Re-compile always needed to effect any changes to configuration
                     : Analog input pins being used are hard-coded to be used in pin number order and their purposes are hard-coded as well
                     : Only a single add-on ADS ADC device and only 1 or 2 differential channels on it is tested
                     : Conventional add-on high-sensitivity ADCs limit their useable common mode differential input range to merely a few millivolts with active or passive clamping
                     : Non-bridged DPot legs are only for outboard ADCs though presumeably single-ended, they are not accommodated for inboard Analog Inputs
                     : Some of these limitations will be addressed in future not-for-free versions

      Due to the many preprocessor condition checks throughout this sketch source, the IDE is unable to track bracketed constructs accurately in many places.
      What does this mean?  If you are used to relying on the IDE's highlighting of a paired bracket to help you know a bracketed construct's boundaries, you'll have to give that convenience up in places in this sketch source code.

********************************************************************************
  THE PRESENT PRODUCT WHICH IS ONLY FOR USE BY SOFTWARE- AND HARDWARE-COMPETENT 
  USERS IS INTENDED TO OFFER VARIOUS CAPABILITIES.  Because absolutely no 
  consideration is expected in return, no contract binding on me, whether offering
  suitability, reliability, functionality, safety, or other, exists.  IF YOU 
  MODIFY THIS SKETCH, I VERY SIMPLY REQUIRE that you not remove, hide, nor 
  denigrate the comments nor data output that refers to Jesus or God or their 
  words in any way.  BY USING THIS PRODUCT YOU EXPRESSLY AND TOTALLY ACCEPT FULL
  LIABILITY for any direct, indirect or consequential damages with respect to any 
  claims arising from software and/or hardware derivations of product. I make 
  absolutely no claim of my own competence, licensure, certification, experience,
  or professional standing other than being an Electronics Technician by formal 
  degree and United States FCC Radiotelephone Operators license, and a software
  developer by limited practical experience, and being formally degreed with 
  Bachelor of General Studies majoring in General Sciences
********************************************************************************

   Changelog:  30 April 2018 :  Final inboard 10 bit operation and ADS1X15 operation has been achieved.
               04 May   2018 :  Some 12 bit tweaking so that TTGO/WeMos XI, SAM and SAMD architectures compile with inboard analog inputs to computed at 12 bit even though ANALOG_INPUT_BITS_OF_BOARD is set at default.
               18 May   2018 :  Anti-aliasing code
               29 May   2018 :  Differential use of ADS1x15 to allow LM334 temperature comp to negative inputs so LM334 can be used on positive inputs
               32 May   2018 :  Added skeleton preprocessor defines for user to compatibly code their own support for a few 24-bit ADCs
               05 June  2018 :  HX711 accommodated, you'll just have to balance the bridge manually
               08 June  2018 :  Bugfix for inboard analog inputs above the first one - they didn't print before this fix
               17 June  2018 :  Corrected pointer reinitialize of analogPinArray that disabled internal Analog Input pins.  Added "while( !Serial );" for Leonardo's native USB; starting to add framework for programmable potentiometers, changed defines to allow for a separate full-scale, lower res ADC and a high res ADC for normal viewing, etc,
               18 June  2018 :  Bug fixes relative to displaying multiple traces while one or more are from inboard analog pins
               13 July  2018 :  Modified plotter timing trace to notch horizontally at range min and max for signal traces when it crosses up and down.  Incorporated digi pot adjustings in debug mode. Enabled bypass of digi pot set in setup()
               14 July  2018 :  Improved horizontal timing trace notching - made it shorter and consistent between levels
               15 July  2018 :  Allow unique digipot initializing settingValue for each pot.  Discovered HX711 input Z is way too low for use without buffers.  Regrouping....
               16 July  2018 :  Removed disparaging comments toward TTGO XI/Wemo XI because we will make the plunge to employ the AD8244 buffer as standard, resulting in those boards being eligible as any other board
               20 July  2018 :  Improved plotting with INBOARDINPARALLELWITHHIGHESTSENSI and improved 24-bit plot values
               26 July  2018 :  Corrected conversion from twos complement differential readings to proper single ended plotting
               27 July  2018 :  Discovered HX711's common-mode level sweet spot for max sensitivity, made COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG with default of half-scale
               28 July  2018 :  If using digipots with LM334s, sketch can now auto-balance during setup and target the most sensitive common-mode voltage of a selected outboard ADC...LATER REVISIONS BROKE AUTO_BRIDGE_BALANCING
               29 July  2018 :  With INBOARDINPARALLELWITHHIGHESTSENSI && AUTO_BRIDGE_BALANCING defined, plotspace now excludes the two inboard Analog Input traces, making maximum linespace available for the other more interesting traces
               30 July  2018 :  Now able continuously to run-time auto-balance at least with a single HX711 LATER REVISIONS BROKE AUTO_BRIDGE_BALANCING
               31 July  2018 :  I've noticed one sketch bug in the printing of the magnified traces in that they don't stay within bounds any more. Older sketch versions never had that problem. I'm not sure where it began, but it seems to be a memory management problem from my inital troubleshooting rather than any type of algorithm weakness. I'll work on that when I'm able...
               01 Aug   2018 :  Working on vertical positioning of the magnified traces
               23 Aug   2018 :  Fixed magnified traces in all respects; added functionality to display digipot calibration effects during calibration in setup(); started adding code to handle multiple digipot stacks that utilize dual 74VHC138/74LV138s.  Still no AUTO_BRIDGE_BALANCING
               23 Aug   2018 :  Magnification factor adjustable downward via a potentiometer if defined POT_WIPER_TO_THIS_ANALOG_INPUT_PIN_TO_ADJUST_MAGNIFICATION_FACTOR with the digital number of an inboard analog input pin.
               23 Aug   2018 :  added USING_DUAL_74LV138_DECODERS_FOR_DPOT_CS_LINES with possibly enough code (just needs testing). Allowed for any ratio of LSB pot step to MSB step with DPOT_RATIO
               11 Sep   2018 :  Back with new style of arrays useage to make bug-free coding more possible.
               20 Sep   2018 :  Auto adjust works, but only non-predictively so it is slow.  Added macro CONTINUE_PLOTTING_DURING_AUTO_BRIDGE_BALANCE thinking someone may not want display to pause during auto balance, but that is even painfully slower still.
               20 Sep   2018 :  Alpha chars added into output for future expansion beyond Arduino
               18 Oct   2018 :  Now allows dual digi pot devices: MCP42xxx by manipulating the DPotPin of the first DPot of pkg OR'ing it with 0x40 as the pin of the second DPot in the pkg
               16 Nov   2018 :  Scalability rewrite.  DO NOT USE PREDATED VERSIONS TO ADVANCE DEVELOPMENT!!!!!!!  Many changes have been made as of this date to accommodate future scalability
               17 Nov   2018 :  Functionalities restored that were present before scalability rewrite.
               28 Nov   2018 :  Begin development on SD card storage + wifi connectivity so training aid can be powered through the power connector and store the data onboard and transmit it online
               12 Dec   2018 :  Working on Predictive DPot setting, sketch is published  for the purpose of establishing code flow to best support project advancement. 
               NEXT          :  Predictive DPot setting by tracking +/- Inboard and Outboard ADC bits per +LSB bit
               NEXT          :  Allow using dual digital potentiometers (MCP42XXX) for more lower parts count than when using single pot MCP41XXX
               NEXT          :  Allow DigiPots without LM334: the direction of effect will be opposite.  New macro:
               NEXT          :  EEPROM storage of things like ADC sweet spot, initial digipot settings, etc.  Hardware configs like DPot types & ADC types & other upgradeable hardware version possiblities needs to be able to be set in the hat board rather than EEPROM
               NEXT          :  Accommodate ADS1232 &/or ADS1231
               NEXT          :  Detect hat config and version with 256 versions detection and warning to acquire more recent sketch version when versions > known are found

  TODO:  Arrange for run-time keyboard input to eliminate need to re-compile when changes are made or plotting adjustments are desired.  Will require non-Arduino IDE plotter
         Accommodate more 24-bit adcs like ADS1231
         Accommodate plant growth rate data somehow...visual/optical/height?

   These planned enhancements will be reserved for NOT-FOR-FREE sketch versions in the future

  Should you examine the sketch code you will or may notice it is in a state of transition.  Variable names and useages may be inconsistent and so forth.  That is
  because I am upgrading it with longer-term goals in mind while at the same time adding intermediate features that are easily and quickly coded.

  Planned longer-term upgrades are as follows:
  - Am currently coding for use of less than 3 and more than 3 DPots/leg
  - Am currently coding for using DPots alone, without LM334, in the bridges
  - Am currently coding for using unbridged DPots, single leg only
  - Am currently coding for faster conductance range changes when DUT conductance goes out of range
  - Not coding for other ADC types yet, but will eventually first code for multiple HX711

  These goals necessitate many smaller changes that make an uninformed observer wonder why this or that is so convoluted.  The answer in many cases is
  that I've learned not to make so many changes at a time that the sketch can acquire failures/bugs in more than one or two places because troubleshooting
  would become harder by orders of magnitude.  So the many small modifications to support the longer term goals are being added incrementally without
  breaking the sketch along the way.  Thank you for your tolerance.

  Names are created according to the following conventions:

    PREPROCESSOR_MACROS (ALL_WORDS_IN_ALL_CAPS_AND_JOINED_WITH_DELINEATORS)
    functionNames
        and
    variableNames (eachWordCapitalizedExceptFirst, words joined without delineators)
    OBJECTNAMES (ALLWORDSINALLCAPS, words joined without delineators)
    struct_names (no_capital_letters, words joined with delineators)
    StructMemberNames
        and
    GotoLabels(EachWordCapitalized, words joined without delineators)

*********************************************************************************************************************/
#if ( defined ARDUINO_attiny )
    #error The board you are compiling for does not have the serial in its hardware that this sketch as written is dependent on.  Sorry...
#elif ( defined ARDUINO_ARCH_STM32F4 )
    #error The board you are compiling for has not been accommodated with this sketch as written is dependent on.  Sorry...
#endif
#define VERSION "v.Free"
#include <math.h>
#ifdef WIFI  //The free version does not contain the code to utilize wifi.  Wifi only available in the priced ($20) sketch version.  
    #error The free version does not contain the code to utilize wifi.  Wifi only available in the priced ($20) sketch version.  Thank you for your understanding
    #include <Ethernet.h>
    #include <Phpoc.h> //This would necessitate a pricey shield
    #include <PhpocExpansion.h>
//Object gets instantiated during setup() for greatest flexibility
#endif
#ifdef SD_CARD_STORAGE_CS_PIN  //The free version does not contain the code to utilize SD card storage.  SD card storage only available in the priced ($20) sketch version.
    #error  The free version does not contain the code to utilize SD card storage.  SD card storage only available in the priced ($20) sketch version.
    #ifndef SPIINCLUDED
        #include "SPI.h" //This is the hardware implementation of SPI with CS pin addressable devices (instead of devices with unidirectional data in and data out pins needing addressed via data).  The software implementation uses shiftIn() instead and is slower but frees up otherwise-CS pins and can be used adjunctive for cases where a chip has no CS pin.  Adafruit_ADS1015 uses the shiftIn() method, so those pins are user's choice.  Not data addressable as would be in I2C
        #define SPIINCLUDED
    #endif
    #include <SD.h>
//Object gets instantiated during setup() for greatest flexibility
#endif
//global variables are declared static to prevent them from being seen by any later user-added compilation units that would try, presumeably inadvertently, through the use of the "extern" cast.  Feel free to change if not inadvertent access is helpful
#define COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG ( 1 << ( ANALOG_INPUT_BITS_OF_BOARD - 1 ) ) // Needed if HIGHEST_SENSI_OUTBOARD_ADC_TYPE has a sweet spot of max sensitivity, unlike true op-amp.  (HX711 == 306; normal op-amp, which has none == Vcc/2 == 512)
//Next, force all macros to be coherent with each other
#ifndef OUTBOARDS_PLOTTED
    #define OUTBOARDS_PLOTTED 0
#elif ( 1 > OUTBOARDS_PLOTTED + 0 ) //Evaluates to 1>+0 if the macro was defined as a blank.  Only way I know of to check for blank macros when we need a number in them
    #undef OUTBOARDS_PLOTTED
    #define OUTBOARDS_PLOTTED 0
#endif
#ifndef INBOARDS_PLOTTED
    #define INBOARDS_PLOTTED 0 //This is used for some lightly thought out formulas in any case, so it must be defined until formulas are re-written to handle null values, but that might not be desirable as it results in more confusing formulas
#elif ( 1 > INBOARDS_PLOTTED + 0 )
    #undef INBOARDS_PLOTTED
    #define INBOARDS_PLOTTED 0
#endif
#ifdef MAGNIFICATION_FACTOR
    #if ( MAGNIFICATION_FACTOR == 0 ) //This value not allowed, assume it to mean 1
        #undef MAGNIFICATION_FACTOR
        #define MAGNIFICATION_FACTOR 1
    #endif
#endif
#ifdef ADDITIONAL_BIAS_IN_LSB_DPOT_SETTING_POSITION_TO_APPLY_TO_SIGNAL_TRACE_BRIDGE0
    #if ( ADDITIONAL_BIAS_IN_LSB_DPOT_SETTING_POSITION_TO_APPLY_TO_SIGNAL_TRACE_BRIDGE0 + 1 > 1 )
    #else
        #undef ADDITIONAL_BIAS_IN_LSB_DPOT_SETTING_POSITION_TO_APPLY_TO_SIGNAL_TRACE_BRIDGE0
    #endif
#endif
#if ( OUTBOARDS_PLOTTED > 0 ) //Since so many of the ADC libraries already use OO classes, we'll set that as a pattern - instantiate prior to executing any code
    #define HALFHIGHEST_BIT_RES_FROM_HIGHEST_SENSI_OUTBOARD_ADC ( HIGHEST_BIT_RES_FROM_HIGHEST_SENSI_OUTBOARD_ADC / 2 )
    #if ( ( HALFHIGHEST_BIT_RES_FROM_HIGHEST_SENSI_OUTBOARD_ADC * 2 ) == HIGHEST_BIT_RES_FROM_HIGHEST_SENSI_OUTBOARD_ADC )
        #define DIFFERENTIAL
    #else
        #ifdef DIFFERENTIAL
            #undef DIFFERENTIAL
        #endif
    #endif
/*  The foloowing section needs further thought if to be used
    #if not ( ( ( defined MINIMIZE_COMPILED_SKETCH_SIZE_LEVEL ) && ( MINIMIZE_COMPILED_SKETCH_SIZE_LEVEL == 0 ) ) && ( ( not defined MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE ) || ( MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE == false ) ) )
        #ifdef MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE
            #undef MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE
        #endif
        #define MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE true
    #endif
*/
    #if ( HIGHEST_SENSI_OUTBOARD_ADC_TYPE == ADS1X15 ) && ( HIGHEST_BIT_RES_FROM_HIGHEST_SENSI_OUTBOARD_ADC < 17 ) && ( OUTBOARDS_PLOTTED > 0 )
        #include <Adafruit_ADS1015.h> //for systems using ADS1115/ADS1015  Data addressable I2C, shares bidirectional, open-collector data and clk only with other I2C slaves on same bus, must use the core-defined SDA/SCL pins except ESP8266 and ATtiny85 or see https://www.arduino.cc/en/reference/wire or see the Adafruit_ADS1X15-master README.md
    /*
       With Adafruit_ADS1015.h, SDA, SCL Wemos XI/TTGO XI use A4 for SDA, and A5 is SCL.
    */
        #if ( HIGHEST_BIT_RES_FROM_HIGHEST_SENSI_OUTBOARD_ADC == 15 ) || ( HIGHEST_BIT_RES_FROM_HIGHEST_SENSI_OUTBOARD_ADC == 16 )
            Adafruit_ADS1115 ads;  //For when ADS1115 is being used Data addressable I2C and shares bidirectional, open-collector data and clk only with other I2C slaves on same bus, must use the core-defined SDA/SCL pins except ESP8266 and ATtiny85 or see https://www.arduino.cc/en/reference/wire or see the Adafruit_ADS1X15-master README.md
        #else
            #if ( HIGHEST_BIT_RES_FROM_HIGHEST_SENSI_OUTBOARD_ADC == 11 ) || ( HIGHEST_BIT_RES_FROM_HIGHEST_SENSI_OUTBOARD_ADC == 12 )
                Adafruit_ADS1015 ads;  //For when ADS1015 is being used Data addressable I2C and bidirectional, open-collector data and clk only with other I2C slaves on same bus, must use the core-defined SDA/SCL pins except ESP8266 and ATtiny85 or see https://www.arduino.cc/en/reference/wire or see the Adafruit_ADS1X15-master README.md
            #else
                #error This add-on ADC resolution is not supported in this sketch version.
            #endif
        #endif
    #else
        #define PIN_FOR_DATA_TOFROM_HIGHEST_SENSI_ADC 2 //PROPRIETARY, NOT SPI Must always be dedicated in cases where it doesn't go hi-Z (as in HX711).  This won't work if an ADS1x15 or any other I2C device is also used on this pin
        #define PIN_FOR_CLK_TO_HIGHEST_SENSI_ADC 3 //PROPRIETARY, NOT SPI Must always be dedicated in cases where it doesn't go hi-Z (as in HX711).  This won't work if an ADS1x15 or any other I2C device is also used on this pin
    /*
       If ever would use an ADS1x15 along with this ADC, then see error msg below
            #ifdef ARDUINO_AVR_LEONARDO
                #if ( PIN_FOR_DATA_TOFROM_HIGHEST_SENSI_ADC == 2 ) || ( PIN_FOR_CLK_TO_HIGHEST_SENSI_ADC == 3 ) || ( PIN_FOR_CLK_TO_HIGHEST_SENSI_ADC == 2 ) || ( PIN_FOR_DATA_TOFROM_HIGHEST_SENSI_ADC == 3 )
                    #error "The pins being used for clock and data of the ADC conflict with the I2C pins used by ADS1x15.  See https://www.arduino.cc/en/reference/wire and the Adafruit_ADS1X15-master README.md.  Remove this warning once you are satisfied one way or another"
                #endif
            #endif
    */
        #if ( HIGHEST_SENSI_OUTBOARD_ADC_TYPE == HX711 ) && ( HIGHEST_BIT_RES_FROM_HIGHEST_SENSI_OUTBOARD_ADC == 24 )  //The HX711 does NOT communicate over open-collector I2C; pick your own pins for comming with it other than SS, CLK, MOSI, and MISO of SPI.  The digital interface to the HX711 is a proprietary SPI-like interface using CLK to select and Data is always lo-z (can't share either)
            #include <HX711.h>  //From https://github.com/bogde/HX711  This ADC has no CS pin so the library must use software SPI with dedicated CLK pin.  Not data selectable as would be in I2C, nor CS selectable - must be on dedicated CLK & Data lines
            HX711 hx711( PIN_FOR_DATA_TOFROM_HIGHEST_SENSI_ADC, PIN_FOR_CLK_TO_HIGHEST_SENSI_ADC ); // This library allows us to set the pins and gain here or later in a .begin().
            #undef COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG
            #define COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG 306                // If HIGHEST_SENSI_OUTBOARD_ADC_TYPE has a sweet spot of max sensitivity, unlike true op-amp.  (HX711 == 305, ranging from 1.49 to 1.507 vdc depending which scale is used to read it).  This will also be discovered and stored in EEPROM in a future revision
        #elif ( HIGHEST_SENSI_OUTBOARD_ADC_TYPE == ADS1232 ) && ( HIGHEST_BIT_RES_FROM_HIGHEST_SENSI_OUTBOARD_ADC == 24 )
        #elif ( HIGHEST_SENSI_OUTBOARD_ADC_TYPE == ADS1242 ) && ( HIGHEST_BIT_RES_FROM_HIGHEST_SENSI_OUTBOARD_ADC == 24 ) //Which 24-bit ADC is single-ended?  ADS1242 It is 23 bits hopefully
        #elif ( HIGHEST_SENSI_OUTBOARD_ADC_TYPE == AD7780 ) && ( HIGHEST_BIT_RES_FROM_HIGHEST_SENSI_OUTBOARD_ADC == 24 )
        #elif ( HIGHEST_SENSI_OUTBOARD_ADC_TYPE == AD779x ) && ( HIGHEST_BIT_RES_FROM_HIGHEST_SENSI_OUTBOARD_ADC == 24 )
        #elif ( HIGHEST_SENSI_OUTBOARD_ADC_TYPE == MAX112x0 ) && ( HIGHEST_BIT_RES_FROM_HIGHEST_SENSI_OUTBOARD_ADC == 24 )
        #elif ( HIGHEST_SENSI_OUTBOARD_ADC_TYPE == LTC2400 ) && ( HIGHEST_BIT_RES_FROM_HIGHEST_SENSI_OUTBOARD_ADC == 24 )
        #elif ( HIGHEST_SENSI_OUTBOARD_ADC_TYPE == ADS1231 ) && ( HIGHEST_BIT_RES_FROM_HIGHEST_SENSI_OUTBOARD_ADC == 24 )
        #else
            #error This add-on ADC resolution is not supported in this sketch version
        #endif
    #endif
#else
    #ifdef HIGHEST_BIT_RES_FROM_HIGHEST_SENSI_OUTBOARD_ADC
        #undef HIGHEST_BIT_RES_FROM_HIGHEST_SENSI_OUTBOARD_ADC
    #endif
    #define HIGHEST_BIT_RES_FROM_HIGHEST_SENSI_OUTBOARD_ADC ANALOG_INPUT_BITS_OF_BOARD
//    #ifdef HIGHEST_SENSI_OUTBOARD_ADC_TYPE
//        #undef HIGHEST_SENSI_OUTBOARD_ADC_TYPE //this would prevent setup from finding linearity unless outboard ADC was operating: undesireable limitation
//    #endif
    #ifdef HIGHEST_SENSI_PGA_GAIN_FACTOR
        #undef HIGHEST_SENSI_PGA_GAIN_FACTOR
    #endif
#endif
//#ifndef LOOP_COUNTER_LIMIT_THAT_TRACE_IS_ALLOWED_TO_BE_OFF_CENTER
//    #define LOOP_COUNTER_LIMIT_THAT_TRACE_IS_ALLOWED_TO_BE_OFF_CENTER 65536 //really bad idea, will crash at some point
//#endif
#ifndef BIAS_IN_ANALOG_INPUT_BITS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE_BRIDGE0
    #define BIAS_IN_ANALOG_INPUT_BITS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE_BRIDGE0 0
#endif
#if ( INBOARDS_PLOTTED > 0 )
    #ifndef NUM_ANALOG_INPUTS
        #error You are compiling for a board that requires you to manually define the define variable NUM_ANALOG_INPUTS somewhere above this line and re-compile...
    #endif
#else
    #if ( OUTBOARDS_PLOTTED == 0 )
        #error You will need to manually define at least one of the variables INBOARDS_PLOTTED or OUTBOARDS_PLOTTED where they appear in the lines above and re-compile...
If you only have the Arduino without an ADS1X15, then define INBOARDS_PLOTTED.  Otherwise, define OUTBOARDS_PLOTTED and / or both of them.
    #endif
#endif

#if defined MAGNIFICATION_FACTOR && ( ( PERCENT_OF_LINESPACE_MAGNIFIED_VIEW_SKIPS_WHEN_REPOSITIONED_WHEN_LINESPACE_LIMITS_GET_EXCEEDED > 100 ) || ( PERCENT_OF_LINESPACE_MAGNIFIED_VIEW_SKIPS_WHEN_REPOSITIONED_WHEN_LINESPACE_LIMITS_GET_EXCEEDED < 0 ) )
    #error The macro PERCENT_OF_LINESPACE_MAGNIFIED_VIEW_SKIPS_WHEN_REPOSITIONED_WHEN_LINESPACE_LIMITS_GET_EXCEEDED is out of bounds
#endif

// NOT ALL OF THE FOLLOWING INDEX_OF_INBOARDS_NOT_PLOTTED MACROS WILL BE CORRECT.  ADJUST AS NEEDED DURING DEVELOPMENT
//#error Examine carefully the following calculations:
//The following redefines likely obsolete a number of macro checks in the body of sketch but I haven't gone through to clean them up
#ifdef LM334_BRIDGES
    #if ( 1 > LM334_BRIDGES + 0 ) //This traps both a null and all negatives - they are invalid and get changed to a 1 value, not a 0 value
        #undef LM334_BRIDGES
        #define LM334_BRIDGES 1  //Make sure it contains an integer
        #warning You are specifying LM334_BRIDGES with no number: Assuming 1 for the number of input pairs that the first analog pins form to read analog signals
    #elif ( LM334_BRIDGES == 0 )
        #undef LM334_BRIDGES     //Zero value means same as undefined so undef it to minimize variations
    #endif
    #define TAKE_LEG_VOLTAGE_UP false
    #define TAKE_LEG_VOLTAGE_DOWN true
    #define TIMES_LIMIT ( 3 * DPOT_RATIO )
#endif
#if ( INBOARDS_PLOTTED < 2 ) && defined SUPERIMPOSE_FIRST_INBOARDS_IN_PAIRS
    #undef SUPERIMPOSE_FIRST_INBOARDS_IN_PAIRS
#endif
#ifdef SUPERIMPOSE_FIRST_INBOARDS_IN_PAIRS
    #if ( 1 > SUPERIMPOSE_FIRST_INBOARDS_IN_PAIRS + 0 ) //This traps both a null and all negatives - they are invalid
        #undef SUPERIMPOSE_FIRST_INBOARDS_IN_PAIRS
        #define SUPERIMPOSE_FIRST_INBOARDS_IN_PAIRS 1
        #warning You are specifying SUPERIMPOSE_FIRST_INBOARDS_IN_PAIRS with no number: Assuming just a single bridge exists
    #elif ( SUPERIMPOSE_FIRST_INBOARDS_IN_PAIRS == 0 )
        #undef SUPERIMPOSE_FIRST_INBOARDS_IN_PAIRS //Zero value means same as undefined so undef it to minimize variations
    #endif
#endif
#define LEGS_PER_DPOT_STYLE_BRIDGE ( 0 )
#define DPOT_LEGS ( 0 )
// always 0 so no macro needed: #define dPotLegMSBUsedAndAvailablesIndexLM334_LEG ( 0 )
#define DPOT_LEG_MSB_USED_AND_AVAILABLES_INDEX_BRIDGED_BARE_LEG ( 0 )
#define DPOT_LEG_MSB_USED_AND_AVAILABLES_INDEX_UNBRIDGED_BARE_LEG ( 0 )

#if ( ( defined LM334_BRIDGES ) && ( defined DPOTS_PER_LM334_LEG ) && ( LM334_BRIDGES > 0 ) && ( DPOTS_PER_LM334_LEG > 0 ) )
// Limit checking here for number of DPots this sketch can work with.  Be your own developer and expand this capability to fit your needs
    #if ( ( LM334_BRIDGES > 1 ) || ( DPOTS_PER_LM334_LEG > 3 ) )
        #error To utilize that value for LM334_BRIDGES or DPOTS_PER_LM334_LEG, you will have to develop this sketch further yourself.
    #endif
    #define DPOTS_IN_ALL_LM334_BRIDGES ( LM334_BRIDGES * DPOTS_PER_LM334_LEG * LEGS_PER_DPOT_STYLE_BRIDGE ) //For LM334-tipped bridges //For LM334-tipped bridges
    #define DPOTS_PER_LM334_BRIDGE ( DPOTS_PER_LM334_LEG * LEGS_PER_DPOT_STYLE_BRIDGE )
    #undef LEGS_PER_DPOT_STYLE_BRIDGE
    #define LEGS_PER_DPOT_STYLE_BRIDGE ( 2 )
    #define LM334_BRIDGE_LEGS ( LM334_BRIDGES * LEGS_PER_DPOT_STYLE_BRIDGE )
    #if ( DPOTS_PER_LM334_LEG > 1 )
        #undef DPOT_LEG_MSB_USED_AND_AVAILABLES_INDEX_BRIDGED_BARE_LEG //move where index is for all next styles legs
        #define DPOT_LEG_MSB_USED_AND_AVAILABLES_INDEX_BRIDGED_BARE_LEG ( 2 * LEGS_PER_DPOT_STYLE_BRIDGE * LM334_BRIDGES ) // one member for Total, one for Available for each leg
        #undef DPOT_LEG_MSB_USED_AND_AVAILABLES_INDEX_UNBRIDGED_BARE_LEG //move where index is for next style leg
        #define DPOT_LEG_MSB_USED_AND_AVAILABLES_INDEX_UNBRIDGED_BARE_LEG ( DPOT_LEG_MSB_USED_AND_AVAILABLES_INDEX_BRIDGED_BARE_LEG )
    #endif
#else
    #ifdef DPOTS_PER_LM334_LEG
        #undef DPOTS_PER_LM334_LEG
    #endif
    #define DPOTS_PER_LM334_LEG ( 0 )
    #define LM334_BRIDGES ( 0 )
    #define DPOTS_IN_ALL_LM334_BRIDGES ( 0 ) //For LM334-tipped bridges
    #define LM334_BRIDGE_LEGS ( 0 ) //For LM334-tipped bridges
#endif
#if ( ( defined BARE_DPOT_LEG_BRIDGES ) && ( defined DPOTS_PER_BRIDGED_BARE_LEG ) && ( BARE_DPOT_LEG_BRIDGES > 0 ) && ( DPOTS_PER_BRIDGED_BARE_LEG > 0 ) )
// Limit checking here for number of DPots this sketch can work with.  Be your own developer and expand this capability to fit your needs
    #if ( ( BARE_DPOT_LEG_BRIDGES > 0 ) || ( DPOTS_PER_BRIDGED_BARE_LEG > 0 ) )
        #error To utilize that value for BARE_DPOT_LEG_BRIDGES or DPOTS_PER_BRIDGED_BARE_LEG, you will have to develop this sketch version further yourself.
    #endif
    #define DPOTS_IN_ALL_BARE_LEG_BRIDGES ( BARE_DPOT_LEG_BRIDGES * DPOTS_PER_BRIDGED_BARE_LEG * LEGS_PER_DPOT_STYLE_BRIDGE ) //for bare DPot bridges
    #define DPOTS_PER_BARE_LEG_BRIDGE ( DPOTS_PER_BRIDGED_BARE_LEG * LEGS_PER_DPOT_STYLE_BRIDGE )
    #undef LEGS_PER_DPOT_STYLE_BRIDGE
    #define LEGS_PER_DPOT_STYLE_BRIDGE ( 2 )
    #define BARE_BRIDGE_LEGS ( BARE_DPOT_LEG_BRIDGES * LEGS_PER_DPOT_STYLE_BRIDGE ) //for bare DPot bridges
    #if ( DPOTS_PER_BRIDGED_BARE_LEG > 1 )
        #undef DPOT_LEG_MSB_USED_AND_AVAILABLES_INDEX_UNBRIDGED_BARE_LEG //move where index is for next style leg
        #define DPOT_LEG_MSB_USED_AND_AVAILABLES_INDEX_UNBRIDGED_BARE_LEG ( DPOT_LEG_MSB_USED_AND_AVAILABLES_INDEX_BRIDGED_BARE_LEG + ( 2 * LEGS_PER_DPOT_STYLE_BRIDGE * BARE_DPOT_LEG_BRIDGES ) ) // one member for Total, one for Available for each leg
    #endif
#else
    #ifdef DPOTS_PER_BRIDGED_BARE_LEG
        #undef DPOTS_PER_BRIDGED_BARE_LEG
    #endif
    #define BARE_DPOT_LEG_BRIDGES ( 0 )
    #define DPOTS_PER_BRIDGED_BARE_LEG ( 0 )
    #define DPOTS_IN_ALL_BARE_LEG_BRIDGES ( 0 ) //for bare DPot bridges
    #define BARE_BRIDGE_LEGS ( 0 ) //for bare DPot bridges
#endif

#if ( ( defined BARE_DPOT_LEGS_UNBRIDGED ) && ( defined DPOTS_PER_UNBRIDGED_BARE_LEG ) && ( BARE_DPOT_LEGS_UNBRIDGED > 0 ) && ( DPOTS_PER_UNBRIDGED_BARE_LEG > 0 ) )
// Limit checking here for number of DPots this sketch can work with.  Be your own developer and expand this capability to fit your needs
    #if ( ( DPOTS_IN_ALL_BARE_LEGS_UNBRIDGED > 0 ) || ( BARE_DPOT_LEGS_UNBRIDGED > 0 ) )
        #error To utilize that value for LM334_BRIDGES or DPOTS_PER_LM334_LEG, you will have to develop this sketch version further yourself.
    #endif
    #define DPOTS_IN_ALL_BARE_LEGS_UNBRIDGED ( BARE_DPOT_LEGS_UNBRIDGED * DPOTS_PER_UNBRIDGED_BARE_LEG ) //FUTURE USE for unbridged DPot control
#else
    #ifdef DPOTS_PER_UNBRIDGED_BARE_LEG
        #undef DPOTS_PER_UNBRIDGED_BARE_LEG
    #endif
    #ifdef BARE_DPOT_LEGS_UNBRIDGED
        #undef BARE_DPOT_LEGS_UNBRIDGED
    #endif
    #define DPOTS_PER_UNBRIDGED_BARE_LEG ( 0 )
    #define DPOTS_IN_ALL_BARE_LEGS_UNBRIDGED ( 0 ) //FUTURE USE for unbridged DPot control
    #define BARE_DPOT_LEGS_UNBRIDGED ( 0 )
#endif
//#if ( ( LM334_BRIDGES + BARE_DPOT_LEG_BRIDGES /*+ BARE_DPOT_LEGS_UNBRIDGED*/ ) > OUTBOARDS_PLOTTED )
//Notice that BARE_DPOT_LEGS_UNBRIDGED is a don't care to allow greatest user flexibility
//#error The number of outboard ADCs is not adequate for the total from the specified values of LM334_BRIDGES + BARE_DPOT_LEG_BRIDGES 
//#endif
#ifdef DPOT_LEGS
    #undef DPOT_LEGS
#endif
#define DPOT_LEGS ( LM334_BRIDGE_LEGS + BARE_BRIDGE_LEGS + BARE_DPOT_LEGS_UNBRIDGED )
#if ( DPOTS_IN_ALL_LM334_BRIDGES + DPOTS_IN_ALL_BARE_LEG_BRIDGES == 0 )
    #undef LEGS_PER_DPOT_STYLE_BRIDGE //Means there are no bridges with DPots in them
    #undef AUTO_BRIDGE_BALANCING
#endif
#if ( DPOT_LEGS == 0 )
//
//Here means there are no DPots in the system anywhere
//
    #undef INJECT_DIAGNOSTIC_SQUARE_WAVE_ON_SIGNAL_PIN_OF_SPECIFIED_OUTBOARD_ADC
    #undef INJECT_DIAGNOSTIC_SQUARE_WAVE_ON_REFERENCE_PIN_OF_SPECIFIED_OUTBOARD_ADC
    #undef TEST_STEP_UP_DOWN
#else
/*
  Using a Microchip MCP4162 digital potentiometer
    [http://bit.ly/iwDmnd]
    http://tronixstuff.com/tutorials > chapter 34 | CC by-sa-nc | John Boxall

    SS – digital 10 to CS of a single digital pot, not abstracted by library call, so can be any pin as determined within main function unidirectional NOT PIN 10 ON LEONARDO - IS FOUND ON LED_BUILTIN_RX (PIN 17) ONLY
    MOSI – digital 11 to inputs of all digital pots unidirectional NOT PIN 11 ON LEONARDO - IS FOUND ON 1CSP ONLY.  REQ'D IN ALL CASES.
    MISO – digital 12 to outputs of all digital pots unidirectional NOT PIN 12 ON LEONARDO - IS FOUND ON 1CSP ONLY.  REQ'D IN SD CARD. OPTIONAL WHEN DPOTS AREN'T SUPPLIED WITH 8.5-12 VDC FOR PERSISTENCE.
    SCK – digital 13 to CLK of all digital pots unidirectional NOT PIN 13 ON LEONARDO - IS FOUND ON 1CSP ONLY
    Clock speed of MCP4162 is 10 MHz max, well capable to use default Arduino speed of 4 MHz.
    EEPROM and nonvolatile settings are only available with >8.5 Vdc to <12.5Vdc applied to CS pins of MCP4162, which we don't have.
    Therefore, we have no need to read data back from digipots b/c we're storing their settings in sketch variables.

*/
    #ifndef SPIINCLUDED
        #include "SPI.h" //This is the hardware implementation of SPI with CS pin addressable devices (instead of devices with unidirectional data in and data out pins needing addressed via data).  The software implementation uses shiftIn() instead and is slower but frees up otherwise-CS pins and can be used adjunctive for cases where a chip has no CS pin.  Adafruit_ADS1015 uses the shiftIn() method, so those pins are user's choice.  Not data addressable as would be in I2C
        #define SPIINCLUDED
    #endif
    #ifdef INJECT_DIAGNOSTIC_SQUARE_WAVE_ON_SIGNAL_PIN_OF_SPECIFIED_OUTBOARD_ADC
        #if ( 1 > INJECT_DIAGNOSTIC_SQUARE_WAVE_ON_SIGNAL_PIN_OF_SPECIFIED_OUTBOARD_ADC + 0 )
            #undef INJECT_DIAGNOSTIC_SQUARE_WAVE_ON_SIGNAL_PIN_OF_SPECIFIED_OUTBOARD_ADC
            #define INJECT_DIAGNOSTIC_SQUARE_WAVE_ON_SIGNAL_PIN_OF_SPECIFIED_OUTBOARD_ADC 0 //make sure it contains a bridge index or leg for non-bridged legs, default is bridge 0
        #endif
        #if ( INJECT_DIAGNOSTIC_SQUARE_WAVE_ON_SIGNAL_PIN_OF_SPECIFIED_OUTBOARD_ADC > 0 )
            #error SINCE THIS HOLDS WHICH BRIDGE IS OF INTEREST, MULTIPLY IT BY # OF DPOTS PER BRIDGE WHERE IT IS USED BUT YOU WILL ALSO HAVE TO ADAPT THE PREPROCESSOR MACROD PREFILL PIN NUMBERS BY HAND.  PRIORITIES DO NOT ALLOW ME TO DO IT FOR YOU
        #endif
    #endif
    #ifdef INJECT_DIAGNOSTIC_SQUARE_WAVE_ON_REFERENCE_PIN_OF_SPECIFIED_OUTBOARD_ADC
        #if ( 1 > INJECT_DIAGNOSTIC_SQUARE_WAVE_ON_REFERENCE_PIN_OF_SPECIFIED_OUTBOARD_ADC + 0 )
            #undef INJECT_DIAGNOSTIC_SQUARE_WAVE_ON_REFERENCE_PIN_OF_SPECIFIED_OUTBOARD_ADC
            #define INJECT_DIAGNOSTIC_SQUARE_WAVE_ON_REFERENCE_PIN_OF_SPECIFIED_OUTBOARD_ADC 0 //make sure it contains a bridge index or leg for non-bridged legs, default is bridge 0
        #endif
        #if ( INJECT_DIAGNOSTIC_SQUARE_WAVE_ON_REFERENCE_PIN_OF_SPECIFIED_OUTBOARD_ADC > 0 )
            #error SINCE THIS HOLDS WHICH BRIDGE IS OF INTEREST, MULTIPLY IT BY # OF DPOTS PER BRIDGE WHERE IT IS USED BUT YOU WILL ALSO HAVE TO ADAPT THE PREPROCESSOR MACROD PREFILL PIN NUMBERS BY HAND.  PRIORITIES DO NOT ALLOW ME TO DO IT FOR YOU
        #endif
    #endif

    #define DPOTS ( DPOTS_IN_ALL_LM334_BRIDGES + DPOTS_IN_ALL_BARE_LEG_BRIDGES + DPOTS_IN_ALL_BARE_LEGS_UNBRIDGED )
    #define READ_AND_PLOT_IN_EACH_LAP true
    #define WORK_ON_THE_REFERENCE_LEG true
/*
      The following are globals since their contents can only be calculated at run-time and necessarily must remain accessible by every function without loss or recalculation, or are essential to the calculation of another global
      and we don't want to waste the CPU time of making them into preprocessor macros which would get calculated every single time the macro is used instead of just a single time when the DPotLeg of interest is changed
*/
    //The following variable is intended to be stored in EEPROM once calculated
    #define NUM_ELEMENTS_PER_LEG_IN_dPotLegMSBUsedAndAvailables_ARRAY 2
    static uint16_t dPotLegMSBUsedAndAvailables[ NUM_ELEMENTS_PER_LEG_IN_dPotLegMSBUsedAndAvailables_ARRAY * DPOT_LEGS ]; //This will only be needed on legs with > 1 Dpots: each leg can store totalAllMSBsThisLeg availableAllMSBsThisLeg
/*
    #define MSB_SETTINGS_TOTAL_THIS_LEG ( dPotLegMSBUsedAndAvailables[ NUM_ELEMENTS_PER_LEG_IN_dPotLegMSBUsedAndAvailables_ARRAY * dPotLeg ] )
    #define MSB_SETTINGS_AVAILABLE_THIS_LEG ( dPotLegMSBUsedAndAvailables[ ( NUM_ELEMENTS_PER_LEG_IN_dPotLegMSBUsedAndAvailables_ARRAY * dPotLeg ) + 1 ] )
    #define MSB_SETTINGS_TOTAL_THIS_REFERENCE_LEG ( dPotLegMSBUsedAndAvailables[ NUM_ELEMENTS_PER_LEG_IN_dPotLegMSBUsedAndAvailables_ARRAY * ( dPotLeg + 1 ) ] )
    #define MSB_SETTINGS_AVAILABLE_THIS_REFERENCE_LEG ( dPotLegMSBUsedAndAvailables[ ( NUM_ELEMENTS_PER_LEG_IN_dPotLegMSBUsedAndAvailables_ARRAY * ( dPotLeg + 1 ) ) + 1 ] )
*/
/*
    struct previous_readings_only_of_inboards_and_outboards
    {
      uint32_t CurrentUnmagnifiedReading;
      uint32_t PreviousUnmagnifiedReading;
      uint8_t IndexInlinespaceParametersArray;
    } typedef previous_readings_only;

    //To retrieve bridgeleg readings for non-plotting use such as reading their most recent values while adjusting DPots, you must downconvert them with >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE (shift rights).
    previous_readings_only masterReadingsArray[ INDEX_OF_OUTBOARDS + OUTBOARDS_PLOTTED ]; one per bridge, but when both legs get displayed, the magnified variable is repurposed
*/    
    typedef struct dPotBridgesDetails
    {
        uint8_t dPotsPerThisBridge;
        uint16_t mSBsGroupSize; //casted to 16 bits b/c it will be used to divide settingValue which is 16 bits
        uint8_t lSBDPotOffsetIndexThisLegSignal;
        uint8_t firstMSBIndexThisLegSignal;
        int16_t legLSBSettingUnitsTimes100PerAnalogInputUnitSignal;
        int16_t analogInputUnitsTimes100PerMSBLegSettingUnitSignal;
        int16_t dPotLegMSBUsedSignal;
        int16_t dPotLegMSBAvailablesSignal;
        uint32_t CurrentUnmagnifiedReading;
        uint32_t PreviousUnmagnifiedReading;
        uint8_t IndexInlinespaceParametersArray;
        uint8_t lSBDPotOffsetIndexThisLegReference;
        uint8_t firstMSBIndexThisLegReference;
        int16_t legLSBSettingUnitsTimes100PerAnalogInputUnitReference;
        int16_t analogInputUnitsTimes100PerMSBLegSettingUnitReference;
        int16_t dPotLegMSBUsedReference;
        int16_t dPotLegMSBAvailablesReference;
    } dPotBridgeDetail;
    dPotBridgeDetail dPotBridgeDetails[ LM334_BRIDGES + BARE_DPOT_LEG_BRIDGES + BARE_DPOT_LEGS_UNBRIDGED ];
/*
    WHY WE DON'T GLOBALLY STORE THE BRIDGE IN CONTEXT LIKE WE DO THESE OTHER VARS:
    Because sending the bridge as an argument instead is never inconvenient as
    it is always handy from where functions are called that need to know it.
    These globals are here b/c otherwise they would have to be recalculated
    multiple times within the same bridge or leg context or else clutter 
    function argument lists into too much ugliness.  Not so with bridge.
*/

    void configureFromDPotLeg( void ) //Note that the way the dPotPins array is ordered allows the following to work even with unbridged legs in the system
    { //checking whether this got executed for the signal leg when the current context is for the reference leg: indexOfThisDPotCSPinInDPotArrays < lSBDPotInLegReference ? <signal leg value> : <reference leg value>
    //If the leg has only a single DPot, the mSBsGroupSize will be one and both lSBDPotOffsetIndexThisLeg and firstMSBIndexThisLeg will equate as firstDPotInLeg in signal leg - the reference leg acts similarly.
      uint8_t dPotsPerThisLeg = ( dPotLeg < LM334_BRIDGE_LEGS ) ? \
                        DPOTS_PER_LM334_LEG : \
                        ( dPotLeg < ( LM334_BRIDGE_LEGS + BARE_BRIDGE_LEGS ) ) ? \
                          DPOTS_PER_BRIDGED_BARE_LEG : \
                          DPOTS_PER_UNBRIDGED_BARE_LEG;
      uint8_t dPotsPerThisBridge = ( dPotLeg < ( LM334_BRIDGE_LEGS + BARE_BRIDGE_LEGS ) ) ? \
                          ( dPotsPerThisLeg << 1 ) : \
                          dPotsPerThisLeg;
    
      uint8_t mSBsGroupSize = dPotsPerThisLeg - ( ( dPotsPerThisLeg > 1 ) ? 1 : 0 );
    
      uint8_t lSBDPotOffsetIndexThisLeg = ( dPotLeg < LM334_BRIDGE_LEGS ) ? \
                       ( dPotLeg * DPOTS_PER_LM334_LEG ) : \
                       ( dPotLeg < ( LM334_BRIDGE_LEGS + BARE_BRIDGE_LEGS ) ) ? \
                       ( DPOTS_IN_ALL_LM334_BRIDGES + ( ( dPotLeg - LM334_BRIDGE_LEGS ) * DPOTS_PER_BRIDGED_BARE_LEG ) ) : \
                       ( DPOTS_IN_ALL_LM334_BRIDGES + DPOTS_IN_ALL_BARE_LEG_BRIDGES + ( ( dPotLeg - ( LM334_BRIDGE_LEGS + DPOTS_IN_ALL_BARE_LEG_BRIDGES ) * DPOTS_PER_UNBRIDGED_BARE_LEG ) ) );
      uint8_tlSBDPotOffsetIndexThisLegReference = ( dPotLeg < ( LM334_BRIDGE_LEGS + BARE_BRIDGE_LEGS ) ) ? lSBDPotOffsetIndexThisLeg + dPotsPerThisLeg : lSBDPotOffsetIndexThisLeg;
    

      uint8_t firstMSBIndexThisLeg = lSBDPotOffsetIndexThisLeg + ( ( dPotsPerThisLeg > 1 ) ? 1 : 0 );
      uint8_t firstMSBIndexThisLegReference = ( dPotLeg < ( LM334_BRIDGE_LEGS + BARE_BRIDGE_LEGS ) ) ? firstMSBIndexThisLeg + dPotsPerThisLeg : firstMSBIndexThisLeg;
    }
    
    void configureFromDPotIndex()
    {
      dPotLeg = indexOfThisDPotCSPinInDPotArrays < DPOTS_IN_ALL_LM334_BRIDGES ? \
                ( indexOfThisDPotCSPinInDPotArrays / DPOTS_PER_LM334_LEG ) : \
                indexOfThisDPotCSPinInDPotArrays < DPOTS_IN_ALL_LM334_BRIDGES + DPOTS_IN_ALL_BARE_LEG_BRIDGES ? \
                ( LM334_BRIDGE_LEGS + ( ( indexOfThisDPotCSPinInDPotArrays - DPOTS_IN_ALL_LM334_BRIDGES ) / DPOTS_PER_BRIDGED_BARE_LEG ) ) : \
                LM334_BRIDGE_LEGS + BARE_BRIDGE_LEGS + ( ( indexOfThisDPotCSPinInDPotArrays - ( LM334_BRIDGE_LEGS + BARE_BRIDGE_LEGS ) ) / DPOTS_IN_ALL_BARE_LEGS_UNBRIDGED );
      configureFromDPotLeg();
    }
    
    void configureForSignalLegWithBridgeIndexIncludingNonBridgedLegs( uint8_t bridge )
    {
        whichBridgeOrOutboardADCindex = bridge;
      dPotLeg = ( whichBridgeOrOutboardADCindex < LM334_BRIDGES + BARE_DPOT_LEG_BRIDGES ) ? ( whichBridgeOrOutboardADCindex * LEGS_PER_DPOT_STYLE_BRIDGE ) :  LM334_BRIDGES + BARE_DPOT_LEG_BRIDGES + ( ( whichBridgeOrOutboardADCindex - ( LM334_BRIDGES + BARE_DPOT_LEG_BRIDGES ) ) * LEGS_PER_DPOT_STYLE_BRIDGE );
      configureFromDPotLeg();
    }
    
    void configureForReferenceLegWithBridgeIndex( uint8_t bridge )
    { //Not using configureForSignalLegWithBridgeIndexIncludingNonBridgedLegs b/c would be too wasteful of CPU
        whichBridgeOrOutboardADCindex = bridge;
      dPotLeg = ( whichBridgeOrOutboardADCindex * LEGS_PER_DPOT_STYLE_BRIDGE ) + 1;
      configureFromDPotLeg();
    }
    #define MAX_DPOT_SETTG 256 //This settingValue is 1 less than the actual number of steps b/c the lowest setting is 0 - zero indexed, but since it equates to practical zero resistance this works fine
    
    //    #if ( LM334_BRIDGES > 0 ) Just b/c this conforms to the pattern
    //When using one or two 3:8 decoders, note that these pins numbers must be greater than 127
    //Never use bit 6 of DPotPin for anything except to designate the second pot in a dual pkg
    /*
        To scale up to multiple values of digipotsperleg:
      x1   fix LSB_DPOT_B0SIG_PIN names and such
      x2   fix index order within DPotSettings and DPotPins
      >3   fix LSB_DPOT_B0SIG_STARTVALUE names and such
      4   fix DPOT_RATIO to something that will work where it is used
      5
      Never use bit 6 of DPotPin for anything except to designate the second pot in a dual pkg
    
    */
    //If a digipot is the second in a pkg, you will OR that digipot's pin number with B0100000 (add 64) like so: #define LSB_DPOT_B0SIG_PIN ( 7 + 64 ) would be for when pin 7 is the physical Arduino Digital pin
    //If you find that you don't understand that, I'd encourage you to learn the topics of converting between hexadecimal, decimal, and binary and to learn bitwise boolean operations
    #define LSB_DPOT_B0SIG_PIN 5         // Signal LSB fine adjust digital pot's CS line connected to here
//    #define LSB_DPOT_B0SIG_STARTVALUE 0 //309 52 - 54 or ( MAX_DPOT_SETTG / 2 )   //this settingValue in digipots and with 1 MOhm resistors for the LM334 loads put the LM334 output voltage at closest: with three DPots per leg
    #define LSB_DPOT_B0SIG_STARTVALUE 38 //304 52 - 54 or ( MAX_DPOT_SETTG / 2 )   //this settingValue in digipots and with 1 MOhm resistors for the LM334 loads put the LM334 output voltage at closest: with three DPots per leg
//    #define LSB_DPOT_B0SIG_STARTVALUE 83 //52 - 54 or ( MAX_DPOT_SETTG / 2 )   //this settingValue in digipots and with 1 MOhm resistors for the LM334 loads put the LM334 output voltage at closest: with three DPots per leg
    
    #if ( ( DPOTS_PER_LM334_LEG > 0 ) || ( DPOTS_PER_BRIDGED_BARE_LEG > 0 ) )
        #define LSB_DPOT_B0REF_PIN 8        // Reference LSB fine adjust digital pot's CS line connected to here
//        #define LSB_DPOT_B0REF_STARTVALUE 0 //310 or ( MAX_DPOT_SETTG / 2 )   //this settingValue in digipots and with 1 MOhm resistors for the LM334 loads put the LM334 output voltage at closest: with three DPots per leg
        #define LSB_DPOT_B0REF_STARTVALUE 50 //305 or ( MAX_DPOT_SETTG / 2 )   //this settingValue in digipots and with 1 MOhm resistors for the LM334 loads put the LM334 output voltage at closest: with three DPots per leg
//        #define LSB_DPOT_B0REF_STARTVALUE 87 //or ( MAX_DPOT_SETTG / 2 )   //this settingValue in digipots and with 1 MOhm resistors for the LM334 loads put the LM334 output voltage at closest: with three DPots per leg
    //        #define LSB_DPOT_B0REF_STARTVALUE 18 //or ( MAX_DPOT_SETTG / 2 )   //this settingValue in digipots and with 1 MOhm resistors for the LM334 loads put the LM334 output voltage at closest: with two DPots per leg
    #endif
    #if ( ( DPOTS_PER_LM334_LEG > 1 ) || ( DPOTS_PER_BRIDGED_BARE_LEG > 1 ) || ( DPOTS_PER_UNBRIDGED_BARE_LEG > 1 ) )
        #define NON_LSB_DPOT_1_B0SIG_PIN 6          // second digital pot of signal leg CS line connected to here.  coarse adjust B positive (signal) leg
//        #define NON_LSB_DPOT_1_B0SIG_STARTVALUE ( MAX_DPOT_SETTG / 4 ) //or ( MAX_DPOT_SETTG / 2 )  //this settingValue in digipots and with 1 MOhm resistors for the LM334 loads put the LM334 output voltage at closest: with two or three DPots per leg
        #define NON_LSB_DPOT_1_B0SIG_STARTVALUE 125 //or ( MAX_DPOT_SETTG / 2 )  //this settingValue in digipots and with 1 MOhm resistors for the LM334 loads put the LM334 output voltage at closest: with two or three DPots per leg
    #endif
    #if ( ( DPOTS_PER_LM334_LEG > 1 ) || ( DPOTS_PER_BRIDGED_BARE_LEG > 1 ) )
        #define NON_LSB_DPOT_1_B0REF_PIN 9          // second digital pot of reference leg CS line connected to here.  coarse adjust B negative (reference) leg
//        #define NON_LSB_DPOT_1_B0REF_STARTVALUE ( MAX_DPOT_SETTG / 4 ) //or ( MAX_DPOT_SETTG / 2 )   //this settingValue in digipots and with 1 MOhm resistors for the LM334 loads put the LM334 output voltage at closest: with three DPots per leg
        #define NON_LSB_DPOT_1_B0REF_STARTVALUE 125 //or ( MAX_DPOT_SETTG / 2 )   //this settingValue in digipots and with 1 MOhm resistors for the LM334 loads put the LM334 output voltage at closest: with three DPots per leg
    //        #define NON_LSB_DPOT_1_B0REF_STARTVALUE 117 //or ( MAX_DPOT_SETTG / 2 )   //this settingValue in digipots and with 1 MOhm resistors for the LM334 loads put the LM334 output voltage at closest: with two DPots per leg
    #endif
    #if ( ( DPOTS_PER_LM334_LEG > 2 ) || ( DPOTS_PER_BRIDGED_BARE_LEG > 2 ) || ( DPOTS_PER_UNBRIDGED_BARE_LEG > 2 ) )
        #define NON_LSB_DPOT_2_B0SIG_PIN 7         // third digital pot of signal leg CS line connected to here.  coarse adjust B positive (signal) leg
        #define NON_LSB_DPOT_2_B0SIG_STARTVALUE 0  //or ( MAX_DPOT_SETTG / 2 )  //this settingValue in digipots and with 1 MOhm resistors for the LM334 loads put the LM334 output voltage at closest
    #endif
    #if ( ( DPOTS_PER_LM334_LEG > 2 ) || ( DPOTS_PER_BRIDGED_BARE_LEG > 2 ) )
        #define NON_LSB_DPOT_2_B0REF_PIN 10         // third digital pot of reference leg CS line connected to here.  coarse adjust B negative (reference) leg
        #define NON_LSB_DPOT_2_B0REF_STARTVALUE 0  //or ( MAX_DPOT_SETTG / 2 )   //this settingValue in digipots and with 1 MOhm resistors for the LM334 loads put the LM334 output voltage at closest
    #endif
    
    #if ( ( defined ARDUINO_AVR_LEONARDO ) \
        && ( NON_LSB_DPOT_2_B0SIG_PIN == 2 || NON_LSB_DPOT_2_B0SIG_PIN == 3 \
        || NON_LSB_DPOT_1_B0SIG_PIN == 2 || NON_LSB_DPOT_1_B0SIG_PIN == 3 \
        || LSB_DPOT_B0SIG_PIN == 2 || LSB_DPOT_B0SIG_PIN == 3 \
        || NON_LSB_DPOT_2_B0REF_PIN == 2 || NON_LSB_DPOT_2_B0REF_PIN == 3 \
        || NON_LSB_DPOT_1_B0REF_PIN == 2 || NON_LSB_DPOT_1_B0REF_PIN == 3 \
        || LSB_DPOT_B0REF_PIN == 2 || LSB_DPOT_B0REF_PIN == 3 \
        ) )
    //        #if ( LM334_BRIDGES + BARE_DPOT_LEG_BRIDGES > 1 )
    //            #if ( LM334_BRIDGES + BARE_DPOT_LEG_BRIDGES > 2 )
    //                #if ( LM334_BRIDGES + BARE_DPOT_LEG_BRIDGES > 3 )
    //                    #if ( LM334_BRIDGES + BARE_DPOT_LEG_BRIDGES > 4 )
    //                        #if ( LM334_BRIDGES + BARE_DPOT_LEG_BRIDGES > 5 )
    //                            #if ( LM334_BRIDGES + BARE_DPOT_LEG_BRIDGES > 6 )
    //                            #endif
    //                        #endif
    //                    #endif
    //                #endif
    //            #endif
    //        #endif //Expand this if sketch expands
    //    )//This style of compiler preprocessor nested definition doesn't really work.  It is here to show the desired concept
    
        #error "The pins being used for clock and data of the ADC conflict with the I2C pins used by ADS1x15.  See https://www.arduino.cc/en/reference/wire and the Adafruit_ADS1X15-master README.md.  Remove this warning once you are satisfied one way or another"
    #endif
    static uint8_t dPotPins[ DPOTS ]; //If I could just figure out how to fill this array here it would sure make for less code clutter
    static uint16_t dPotSettings[ DPOTS ];
    /* EEPROM and nonvolatile settings are only available with >8.5, <12.5 Vdc applied to CS pins of MCP4162, which we don't have with mere Arduino: */
    #define MATCHING_TO_SIGNAL_LEG true
#endif

#if ( ARDUINO_ARCH_XI || ARDUINO_ARCH_SAM || ARDUINO_ARCH_SAMD ) //These are the boards known to have 12 bit analog inputs
#ifdef ANALOG_INPUT_BITS_OF_BOARD
#undef ANALOG_INPUT_BITS_OF_BOARD
#endif
#define ANALOG_INPUT_BITS_OF_BOARD 12  //These boards have 12 bit
#endif

#if ( OUTBOARDS_PLOTTED > 0 )
#define SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE ( HIGHEST_BIT_RES_FROM_HIGHEST_SENSI_OUTBOARD_ADC - ANALOG_INPUT_BITS_OF_BOARD )
#else
#define SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE 0
#endif

/*
  DEFINING INDEX_OF_INBOARDS_NOT_SUPERIMPOSED:
*/

#if defined SUPERIMPOSE_FIRST_INBOARDS_IN_PAIRS \
    && ( SUPERIMPOSE_FIRST_INBOARDS_IN_PAIRS > 0 )
#if ( ( ( SUPERIMPOSE_FIRST_INBOARDS_IN_PAIRS * LEGS_PER_DPOT_STYLE_BRIDGE ) < INBOARDS_PLOTTED ) && ( defined LEGS_PER_DPOT_STYLE_BRIDGE ) ) //use the smaller of the two possibilities
#define INDEX_OF_INBOARDS_NOT_SUPERIMPOSED ( SUPERIMPOSE_FIRST_INBOARDS_IN_PAIRS * LEGS_PER_DPOT_STYLE_BRIDGE )
#else
#define INDEX_OF_INBOARDS_NOT_SUPERIMPOSED INBOARDS_PLOTTED
#endif

#else
#define INDEX_OF_INBOARDS_NOT_SUPERIMPOSED 0
#endif

/*
  DEFINING INDEX_OF_INBOARDS_NOT_PLOTTED:
*/

#define INDEX_OF_INBOARDS_NOT_PLOTTED INBOARDS_PLOTTED

/*
  DEFINING INDEX_OF_OUTBOARDS:
*/
#if ( DPOT_LEGS > INBOARDS_PLOTTED )
#define INDEX_OF_OUTBOARDS DPOT_LEGS
#else
#define INDEX_OF_OUTBOARDS INBOARDS_PLOTTED
#endif

struct linespace_bounds_and_magnify_trace_offsets
{
  uint32_t ZeroOfThisPlotLinespace;
  uint32_t HighLimitOfThisPlotLinespace;
  uint32_t LastSignalPinPlotPoint;
  uint32_t LastReferencePinPlotPointOrLastMagnifiedPlotPoint;
#ifdef MAGNIFICATION_FACTOR
  uint32_t MagnifyAdjustment;
#endif
} typedef linespace_bounds_and_magnify_trace_offsets;

/*
  DEFINING NUMBER_OF_LINESPACES:
*/

#define NUMBER_OF_LINESPACES ( INBOARDS_PLOTTED + OUTBOARDS_PLOTTED - ( INDEX_OF_INBOARDS_NOT_SUPERIMPOSED / 2 ) ) //Each superimposed pair reduces total linespaces by one from total of plotted
linespace_bounds_and_magnify_trace_offsets linespaceParameters[ NUMBER_OF_LINESPACES ]; // INDEX_OF_INBOARDS_NOT_SUPERIMPOSED, being the start index for the not superimposed part of the array is also actually the number of superimposed inboards

static bool graphLine = false;
static uint32_t thisReadingTemp;
static long millisStart;
uint16_t plotterLoops;
#ifdef DEBUG
static char szFull[ ] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, \
                         0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
                        };
#endif
#define HEIGHT_OF_A_PLOT_LINESPACE ( ( uint32_t )pow( 2, HIGHEST_BIT_RES_FROM_HIGHEST_SENSI_OUTBOARD_ADC ) ) //casting as uint32_t allows calculations properly
#define PLOTTER_MAX_SCALE ( ( uint32_t )( HEIGHT_OF_A_PLOT_LINESPACE * NUMBER_OF_LINESPACES ) )
#define HALF_HEIGHT_OF_A_PLOT_LINESPACE ( HEIGHT_OF_A_PLOT_LINESPACE >> 1 )

#if ( ( defined AUTO_BRIDGE_BALANCING ) && ( defined DIFFERENTIAL ) )
#define HALF_HEIGHT_INBOARD_SCALE_OF_A_PLOT_LINESPACE ( pow( 2, ANALOG_INPUT_BITS_OF_BOARD - 1 ) )
static uint16_t counterForTraceOutOfRangeTooLong[ OUTBOARDS_PLOTTED ]; //Main intent is for DIFFERENTIAL input ADCs. This is also used to prevent infinite loop with AUTO_BRIDGE_BALANCING
#endif
#define HUNDREDTH_PLOTTER_MAX_SCALE ( PLOTTER_MAX_SCALE / 100 );
#ifndef SAMPLE_TIMES
#define SAMPLE_TIMES 1
#elif ( 1 > SAMPLE_TIMES + 0 )
#undef SAMPLE_TIMES
#define SAMPLE_TIMES 1
#endif
/*  development notes to self:
  Is SUPERIMPOSE_FIRST_INBOARDS_IN_PAIRS (1, 2, 3, etc. ) ever needed?

  AUTO_BRIDGE_BALANCING means both initial setup & ongoing adjustment: initial adjustment means setting pots to EEPROM settings or defines settings and for
  sweet spot ADCs it fines tunes during setup and re-stores that in EEPROM

  defined AUTO_BRIDGE_BALANCING should only be allowed to be the case
    with OUTBOARDS_PLOTTED > 0
    and LM334_BRIDGES (?inboard pairs 1, 2, 3, etc. or ADDONs n... ) //Besides being used for auto-balancing, these could be used just to allow a wider range of plant tissue conductance.
    and SUPERIMPOSE_FIRST_INBOARDS_IN_PAIRS (but is this moot?).  The alternative
    to this condition in isolation from bridge balancing is just adjusting to plant resistance instead of

  Bridge balancing should not be needed with those ADCs that need a sweet spot to work.  That sweet spot could be hard wired or manual pot adjusted and only
  bridge LEG adjusting should get done????
  With those ADCs, the digipots should be able to be put in serial and assigned to
  Except that the tempco of the LM334 will then all be on only one leg, thus not able to be balanced out to cancel out, so never mind....
  Possibilities:
  AUTO...BALANCING is invalid w/o ...POTS and ...PARALLELed > 0
  not LM334_BRIDGES - invalidates AUTO...BALANCING
                                  - if inputs are ...PARALLELed > 0 and ...ADDONs exist and INBOARDS > 0, it is for manual pot manipulations while viewing
                                    traces

  So: - define ...PARALLELed = 0 if it is undefined
    - undefine USING...POTS if USING...POTS == 0 or if ...INBOARD == 0 and not AUTO...BALANCING and #defined LEAVE_POT_VALUES_ALONE_DURING_SETUP and #not defined DEBUG, the digipots may be useful in debug then re-compile but why would they need to be
    - undefine AUTO...BALANCING if not USING...POTS, or if not ...ADDONs, or if ...PARALLELed == 0
    - define ...PARALLELed = 0 if ...ADDONs == 0, or if not AUTO...BALANCING and ...INBOARD == 0 while USING...POTS

*/
void readAndPlotFromAllADCsInAndOutboard( uint32_t, bool = false );

static uint8_t* analogPinArray = 0; //Initializing to 0 allows functions that would use it to know whether valid or not
#if ( ( defined DPOT_LEGS ) && ( DPOT_LEGS > 0 ) )

    void printDPotSettings()
    {
    #if ( ( not defined MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE ) || ( MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE == false ) )
      for( uint8_t dPotLeg = 0; dPotLeg < DPOT_LEGS; dPotLeg++ )
      {
        Serial.print( F( "LegUnit<" ) );
        Serial.print( dPotLeg );
        Serial.print( F( ">, dPotsPerThisLeg=<" ) );
        uint8_t dPotsPerThisLeg = ( dPotLeg < LM334_BRIDGE_LEGS ) ? \
                                  DPOTS_PER_LM334_LEG : \
                                  ( dPotLeg < ( LM334_BRIDGE_LEGS + BARE_BRIDGE_LEGS ) ? \
                                    DPOTS_PER_BRIDGED_BARE_LEG : DPOTS_PER_UNBRIDGED_BARE_LEG );
        Serial.print( dPotsPerThisLeg );
        Serial.print( F( ">" ) );
        for( uint8_t dPotUnit = 0; dPotUnit < dPotsPerThisLeg; dPotUnit++ )
        { //DPOTS_PER_LM334_LEG.
          Serial.print( F( ", dPotUnit=<" ) );
          Serial.print( dPotUnit );
          Serial.print( F( "> dPotPin=<" ) );
          Serial.print( dPotPins[ ( dPotLeg < LM334_BRIDGE_LEGS ) ? \
                                  ( ( dPotLeg * DPOTS_PER_LM334_LEG ) + dPotUnit ) : \
                                  ( dPotLeg < ( LM334_BRIDGE_LEGS + BARE_BRIDGE_LEGS ) ) ? \
                                  ( ( ( LM334_BRIDGE_LEGS * LEGS_PER_DPOT_STYLE_BRIDGE ) + ( dPotLeg * DPOTS_PER_BRIDGED_BARE_LEG ) ) + dPotUnit ) : \
                                  ( ( ( LM334_BRIDGE_LEGS + DPOTS_PER_BRIDGED_BARE_LEG ) * LEGS_PER_DPOT_STYLE_BRIDGE ) + ( dPotLeg * DPOTS_PER_UNBRIDGED_BARE_LEG ) + dPotUnit ) ] );
    
          Serial.print( F( ">" ) );
    
          bool signalTrueReferenceFalse = ( dPotLeg < ( LM334_BRIDGE_LEGS + BARE_BRIDGE_LEGS ) ) ? \
                                          ( ( dPotLeg % 2 == 0 ) ? true : false ) : \
                                          true;
    
          if( signalTrueReferenceFalse )
            Serial.print( F( ", signal " ) );
          else
            Serial.print( F( ", reference " ) );
          //Until the LSB/MSB conversion is complete, this is backwards:
          if( dPotUnit == 0 )
            Serial.print( F( "LSB " ) );
          else
            Serial.print( F( "MSB " ) );
          Serial.print( F( "setting=<" ) );
          Serial.print( dPotSettings[ ( dPotLeg < LM334_BRIDGE_LEGS ) ? \
                                      ( ( dPotLeg * DPOTS_PER_LM334_LEG ) + dPotUnit ) : \
                                      ( dPotLeg < ( LM334_BRIDGE_LEGS + BARE_BRIDGE_LEGS ) ) ? \
                                      ( ( ( LM334_BRIDGE_LEGS * LEGS_PER_DPOT_STYLE_BRIDGE ) + ( dPotLeg * DPOTS_PER_BRIDGED_BARE_LEG ) ) + dPotUnit ) : \
                                      ( ( ( LM334_BRIDGE_LEGS + DPOTS_PER_BRIDGED_BARE_LEG ) * LEGS_PER_DPOT_STYLE_BRIDGE ) + ( dPotLeg * DPOTS_PER_UNBRIDGED_BARE_LEG ) + dPotUnit ) ] );
          if( dPotUnit == 0 || dPotUnit == dPotsPerThisLeg )
          {
            Serial.print( F( ">, " ) );
            if( signalTrueReferenceFalse )
              Serial.print( F( "signal" ) );
            else
              Serial.print( F( "reference" ) );
          }
          else Serial.print( F( "> " ) );
          Serial.print( F( "> dPotUnit=<" ) );
          Serial.print( dPotUnit );
          Serial.print( F( "> " ) );
        }
      }
    #else
        ;
    #endif        
    }
    
    int16_t writeSettingToAsingleDPot( uint8_t, uint16_t );
    void setDPotOrMSBGroupValue( uint8_t indexOfThisDPotCSPinInDPotArrays, /*always will either be 1st or last DPot in leg, is currently coming in at one high from setDPotLegMidPoint()*/ \
                                 uint16_t settingValue /*16 bits to allow cumulative settingValue of msb group to about 250 DPots in the group*/ )
    {
    #if ( ( not defined MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE ) || ( MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE == false ) )
      Serial.print( F( "Just entered setDPotOrMSBGroupValue, " ) );
    #endif
        bool thisIsReferenceWhenConfigureWasForSignal;
    #if ( ( not defined MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE ) || ( MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE == false ) )
      if( !analogPinArray )
      {
        Serial.print( F( "indexOfThisDPotCSPinInDPotArrays=<" ) );
        Serial.print( indexOfThisDPotCSPinInDPotArrays );
        Serial.print( F( ">, lSBDPotOffsetIndexThisLeg=<" ) );
        Serial.print( lSBDPotOffsetIndexThisLeg );
        Serial.print( F( "> " ) );
      }
      else
      { //This part happens later the pin lookup table gets populated
    #endif
        Serial.print( F( "indexOfThisDPotCSPinInDPotArrays=<" ) );
        Serial.print( indexOfThisDPotCSPinInDPotArrays );
        Serial.print( F( "lSBDPotOffsetIndexThisLeg=<" ) );
        Serial.print( lSBDPotOffsetIndexThisLeg );
        Serial.print( F( "> " ) );

        thisIsReferenceWhenConfigureWasForSignal = ( indexOfThisDPotCSPinInDPotArrays >= ( lSBDPotOffsetIndexThisLeg + dPotsPerThisLeg ) );

    #if ( ( not defined MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE ) || ( MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE == false ) )
        if( analogPinArray )
        {
            Serial.print( F( " which is pin #<" ) );
            Serial.print( dPotPins[ indexOfThisDPotCSPinInDPotArrays ] );
            Serial.print( F( "> " ) );
        }
    #endif
        uint8_t mSBDPot;
        if( indexOfThisDPotCSPinInDPotArrays == ( thisIsReferenceWhenConfigureWasForSignal ? lSBDPotOffsetIndexThisLegReference : lSBDPotOffsetIndexThisLeg ) )
    {
        Serial.print( F( "Line <879>" ) );
          goto AfterMSBCombining;
    }
    #if ( ( not defined MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE ) || ( MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE == false ) )
        Serial.print( F( "about to get set to<" ) );
        Serial.print( settingValue );
        Serial.print( F( "> Line <885>" ) );
    #endif
        //Make agnostic to which MSB was spec'd:
        mSBDPot = thisIsReferenceWhenConfigureWasForSignal ? firstMSBIndexThisLegReference : firstMSBIndexThisLeg;
        Serial.print( F( ", thisIsReferenceWhenConfigureWasForSignal=<" ) );
        Serial.print( thisIsReferenceWhenConfigureWasForSignal );
        Serial.print( F( "> mSBDPot=<" ) );
        Serial.print( mSBDPot );
        Serial.print( F( "> Line <892>" ) );
        for( uint8_t counter = 0; counter < mSBsGroupSize - 1; counter++ )
        { //This will fix all but last one which will need to correct for rounding errors
          writeSettingToAsingleDPot( mSBDPot, ( settingValue / mSBsGroupSize ) );
          mSBDPot++;
        }
        //capture level
        int16_t settingsDiff = writeSettingToAsingleDPot( mSBDPot,  settingValue - ( ( ( uint16_t/*force possible rounding errors to re-appear here to compensate for them*/)( settingValue / mSBsGroupSize ) ) * ( mSBsGroupSize - 1 ) ) ); //correct for rounding errors
        if( settingsDiff )
        {
            ;//TODO: finish this thought
        }
        ( thisIsReferenceWhenConfigureWasForSignal ? MSB_SETTINGS_TOTAL_THIS_REFERENCE_LEG : MSB_SETTINGS_TOTAL_THIS_LEG ) = settingValue; //This makes individual MSB settings not accessible for modifying after analogPinArray is assigned unless you save it's setting, make it zero momentarily while this functions is called
        ( thisIsReferenceWhenConfigureWasForSignal ? MSB_SETTINGS_AVAILABLE_THIS_REFERENCE_LEG : MSB_SETTINGS_AVAILABLE_THIS_LEG ) = ( mSBsGroupSize * MAX_DPOT_SETTG ) - settingValue;
        Serial.flush();
        return;
    #if ( ( not defined MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE ) || ( MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE == false ) )
      }
    #endif
AfterMSBCombining:
      //LSB pins get fastracked to here
      if( settingValue > MAX_DPOT_SETTG ) settingValue = MAX_DPOT_SETTG;
      else if( settingValue < 0 ) settingValue = 0;
      if( analogPinArray )
      {
    #if ( ( not defined MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE ) || ( MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE == false ) )
        Serial.print( F( "> which is pin #<" ) );
        Serial.print( dPotPins[ indexOfThisDPotCSPinInDPotArrays ] );
        Serial.print( F( "> dPotSettings[" ) );
        Serial.print( analogPinArray ? dPotPins[ indexOfThisDPotCSPinInDPotArrays ] : indexOfThisDPotCSPinInDPotArrays );
        Serial.print( F( "] about to get set to<" ) );
        Serial.print( settingValue );
        Serial.print( F( ">, " ) );
    #endif
        dPotSettings[ indexOfThisDPotCSPinInDPotArrays ] = settingValue < MAX_DPOT_SETTG ? settingValue : MAX_DPOT_SETTG; //make to accommodate MSB groups
        settingValue = dPotSettings[ indexOfThisDPotCSPinInDPotArrays ]; //setting settingValue but it's existence is only until end of function (transient)
      }
    #if ( ( not defined MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE ) || ( MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE == false ) )
      else
        Serial.print( F( ">" ) );
    #endif
    Serial.print( F( "Line <926>" ) );
      writeSettingToAsingleDPot( indexOfThisDPotCSPinInDPotArrays, settingValue );
      Serial.flush();
      restoreFromBaks();
    }
    
    int16_t writeSettingToAsingleDPot( uint8_t indexOfThisDPotCSPinInDPotArrays, uint16_t settingValue )
    {
    #ifdef USING_DUAL_74LV138_DECODERS_FOR_DPOT_CS_LINES
          //This is not tested, it is just a first proposed step to give capability for many ADCs
          if( ( analogPinArray ? dPotPins[ indexOfThisDPotCSPinInDPotArrays ] : indexOfThisDPotCSPinInDPotArrays ) >= 128 )
          { //Pins numbered below 128 are normal digital inboard pins
            //Pins numbered above 127 are outboard pins provided through the dual 74LV138 decoding circuitry
            //The two 74LV138 each have three enable pins but we only use one.
            //It would require 7 pins to address the two devices simultaneously.
            //Use 'em since we have 'em...it'll save a part for latch
            digitalWrite( FIRST_STAGE_3_TO_8_DECODER_A0_PIN1,  ( analogPinArray ? dPotPins[ indexOfThisDPotCSPinInDPotArrays ] : indexOfThisDPotCSPinInDPotArrays ) & B1 );  //These address bits are always necessary
        #ifdef FIRST_STAGE_3_TO_8_DECODER_A1_PIN2
            digitalWrite( FIRST_STAGE_3_TO_8_DECODER_A1_PIN2,  ( analogPinArray ? dPotPins[ indexOfThisDPotCSPinInDPotArrays ] : indexOfThisDPotCSPinInDPotArrays ) & B10 ); //These address bits are always necessary
        #endif
        #ifdef FIRST_STAGE_3_TO_8_DECODER_A2_PIN3
            digitalWrite( FIRST_STAGE_3_TO_8_DECODER_A2_PIN3,  ( analogPinArray ? dPotPins[ indexOfThisDPotCSPinInDPotArrays ] : indexOfThisDPotCSPinInDPotArrays ) & B100 ); //These address bits are always necessary
        #endif
        #ifdef FIRST_STAGE_3_TO_8_DECODER_A3_PIN4
            digitalWrite( FIRST_STAGE_3_TO_8_DECODER_A3_PIN4,  ( analogPinArray ? dPotPins[ indexOfThisDPotCSPinInDPotArrays ] : indexOfThisDPotCSPinInDPotArrays ) & B1000 ); //These address bits are always necessary
        #endif
        #ifdef FINAL_STAGE_3_TO_8_DECODER_A0_PIN1
            digitalWrite( FINAL_STAGE_3_TO_8_DECODER_A0_PIN1, ( analogPinArray ? dPotPins[ indexOfThisDPotCSPinInDPotArrays ] : indexOfThisDPotCSPinInDPotArrays ) & B1000 ); //This decoder might not be present
        #endif
        #ifdef FINAL_STAGE_3_TO_8_DECODER_A1_PIN2
            digitalWrite( FINAL_STAGE_3_TO_8_DECODER_A1_PIN2, ( analogPinArray ? dPotPins[ indexOfThisDPotCSPinInDPotArrays ] : indexOfThisDPotCSPinInDPotArrays ) & B10000 ); //This decoder might not be present
        #endif
        #ifdef FINAL_STAGE_3_TO_8_DECODER_A2_PIN3
            digitalWrite( FINAL_STAGE_3_TO_8_DECODER_A2_PIN3, ( analogPinArray ? dPotPins[ indexOfThisDPotCSPinInDPotArrays ] : indexOfThisDPotCSPinInDPotArrays ) & B100000 );  //This decoder might not be present
        #endif
            //bit B1000000 is reserved for virtualizing the second DPot in a dual DPot pkg MCP42xxx
            //Never have bit 6 set in elements of dPotPins[ indexOfThisDPotCSPinInDPotArrays ] for anything except to designate the second pot in a dual pkg MCP42xxx
        #ifdef FINAL_STAGE_3_TO_8_DECODER_ENABLE_PIN4
            digitalWrite( FINAL_STAGE_3_TO_8_DECODER_ENABLE_PIN4, LOW ); // In prep for next instruction.
        #endif
        #ifdef FIRST_STAGE_3_TO_8_DECODER_ENABLE_PIN4
            digitalWrite( FIRST_STAGE_3_TO_8_DECODER_ENABLE_PIN4, LOW ); // In prep for next instruction.
        #endif
          }
    #endif
      digitalWrite( ( analogPinArray ? dPotPins[ indexOfThisDPotCSPinInDPotArrays ] : indexOfThisDPotCSPinInDPotArrays ) & 0x3FF, LOW );
      SPI.transfer( ( settingValue & 0x100 ) ? ( ( analogPinArray ? dPotPins[ indexOfThisDPotCSPinInDPotArrays ] : \
                    indexOfThisDPotCSPinInDPotArrays ) & 0x400 ? 0x11 : 1 ) : \
                    ( ( analogPinArray ? dPotPins[ indexOfThisDPotCSPinInDPotArrays ] : \
                        indexOfThisDPotCSPinInDPotArrays ) & 0x400 ? 0x10 : 0 ) ); //This is the way we allow dual dpot devices MCP42xxx
      SPI.transfer( settingValue & 0xFF ); // send settingValue (0~255)
      /**********************************************************************************************************************************************************
        When dual pots are employed (MCP42XXX) this is the way to control the second DPOT in the pkg:  the first digi pot of a pkg is addressed with true pin number,
        the second digipot in the pkg is addressed by adding 64 to the physical pin number driving the pkg, creating a virtual pin number for that second DPot of the pkg
              SPI.transfer( ( settingValue & 0x100 ) ? 0x11 : 0x10 ); //NOTE THE LEADING 1 HERE THAT DOESN'T APPEAR FOR MCP41XXX - it's part of the 0x10
              SPI.transfer( settingValue & 0xff ); // send settingValue (0~255)
    
        In order to utilize this method, both dual pots share a single physical CS (dPotPins[ indexOfThisDPotCSPinInDPotArrays ]) pin (remember ones above 127 pin numbers are connected via 3-to-8 decoders)
        but virtually the second DPot's physical dPotPins[ indexOfThisDPotCSPinInDPotArrays ] must be OR'd with 0x40 (adding 64) in this sketch.  Note that two different schemes of dual DPot can exist:
        duals shared on same leg and duals shared across legs.  By adhering to the afore-described pin numbering methodology, either scheme or both mixed
        throughout the system will work fine.  Note that if any boards have actual physical pins numbered above 64, those cannot be used for DPotPins without sketch
        modification to accommodate it.
    
      ***********************************************************************************************************************************************************/
      digitalWrite( ( analogPinArray ? dPotPins[ indexOfThisDPotCSPinInDPotArrays ] : indexOfThisDPotCSPinInDPotArrays ) & 0x3FF, HIGH );
    #ifdef USING_DUAL_74LV138_DECODERS_FOR_DPOT_CS_LINES
        #ifdef FINAL_STAGE_3_TO_8_DECODER_ENABLE_PIN4
            digitalWrite( FINAL_STAGE_3_TO_8_DECODER_ENABLE_PIN4, HIGH );
        #endif
        #ifdef FIRST_STAGE_3_TO_8_DECODER_ENABLE_PIN4
            digitalWrite( FIRST_STAGE_3_TO_8_DECODER_ENABLE_PIN4, HIGH );
        #endif
    #endif
//    #if ( ( not defined MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE ) || ( MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE == false ) )
        Serial.print( F( "Pin <" ) );
        if( analogPinArray ) 
        {
            Serial.print( dPotPins[ indexOfThisDPotCSPinInDPotArrays ] );
        }
        else
        {
            Serial.print( indexOfThisDPotCSPinInDPotArrays );
        }
        Serial.print( F( "> got set to <" ) );
        Serial.print( settingValue );
        Serial.print( F( "> " ) );
//    #endif
    uint16_t settingPrevious = dPotSettings[ indexOfThisDPotCSPinInDPotArrays ];
      if( analogPinArray ) 
      {
        dPotSettings[ indexOfThisDPotCSPinInDPotArrays ] = settingValue;
    #if ( ( not defined MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE ) || ( MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE == false ) )
          Serial.print( F( "and settings saved to dPotSettings[" ) );
            Serial.print( indexOfThisDPotCSPinInDPotArrays );
          Serial.print( F( "] " ) );
    #endif
      }
      Serial.flush();
      if( analogPinArray ) return ( dPotSettings[ indexOfThisDPotCSPinInDPotArrays ] - settingPrevious );
      return 0;
    }
    void offsetDPotOrMSBGroupValue( uint8_t indexOfThisDPotCSPinInDPotArrays, int16_t offsetValue )
    { //configureFrom...() and configureFor...() must already be ran 
    #if ( ( not defined MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE ) || ( MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE == false ) )
      Serial.print( F( " Entering offsetDPotOrMSBGroupValue=<" ) );
      Serial.print( indexOfThisDPotCSPinInDPotArrays );
      Serial.print( F( "> for pin<" ) );
      Serial.print( dPotPins[ indexOfThisDPotCSPinInDPotArrays ] );
      Serial.print( F( ">, offsetValue<" ) );
      Serial.print( offsetValue );
      Serial.print( F( "> " ) );
    #endif
    #ifdef DEBUG
      //        offsetValue *= 10;  //A magnifier for troubleshooting
      while( !Serial );
      Serial.print( F( "Line 775 offsetValue=" ) );
      Serial.print( offsetValue );
      Serial.print( F( " for Digi pot on pin " ) );
    #endif
//#error The next instruction is part of the problem
        bool thisIsReferenceWhenConfigureWasForSignal = !( indexOfThisDPotCSPinInDPotArrays < lSBDPotOffsetIndexThisLegReference );
      Serial.print( F( ">, thisIsReferenceWhenConfigureWasForSignal<" ) );
      Serial.print( thisIsReferenceWhenConfigureWasForSignal );
      if( indexOfThisDPotCSPinInDPotArrays == ( thisIsReferenceWhenConfigureWasForSignal ? lSBDPotOffsetIndexThisLegReference : lSBDPotOffsetIndexThisLeg ) )
      {


        
        
//A truncate error below makes a 1 out of what should equate to 0
//#error Fix "offsetValue<3266>"
        int16_t borrowOrCarryNeededToPreventBreakingLimitDividedByDPOT_RATIO = ( \
        ( offsetValue < 0 ) ? \
            0 - ( ( ( signed )abs( min( ( offsetValue + ( signed )dPotSettings[ indexOfThisDPotCSPinInDPotArrays ]), 0 ) ) + ( signed )DPOT_RATIO - 1 ) / ( signed )DPOT_RATIO ) : \
        ( ( ( ( signed )offsetValue + dPotSettings[ indexOfThisDPotCSPinInDPotArrays ] ) - ( signed )MAX_DPOT_SETTG ) / ( signed )DPOT_RATIO ) );
        
//should be a borrow, not a carry anyway: if will go negative, borrow beyond amount needed: ( offsetValue < 0 ) ? ( offsetValue + ( signed )dPotSettings[ indexOfThisDPotCSPinInDPotArrays ]) / ( signed )DPOT_RATIO : ( ( ( ( signed )offsetValue+dPotSettings[ indexOfThisDPotCSPinInDPotArrays ] ) - ( signed )MAX_DPOT_SETTG ) / ( signed )DPOT_RATIO ) );

        //recursive call for borrow/carry against the MSB group
//#error This is where we are: carrying should only happen when lsb setting would go over MAX_DPOT_SETTG, borrowing only when would go under zero
      Serial.print( F( ">, making a recursive call with borrowOrCarryNeededToPreventBreakingLimitDividedByDPOT_RATIO=<" ) );
      Serial.print( borrowOrCarryNeededToPreventBreakingLimitDividedByDPOT_RATIO );
      Serial.print( F( ">, ( offsetValue + ( signed )dPotSettings[ indexOfThisDPotCSPinInDPotArrays ] )=<" ) );
      Serial.print( ( offsetValue + ( signed )dPotSettings[ indexOfThisDPotCSPinInDPotArrays ] ) );
      Serial.print( F( ">, offsetValue=<" ) );
      Serial.print( offsetValue );
      Serial.print( F( ">, min( ( offsetValue + ( signed )dPotSettings[ indexOfThisDPotCSPinInDPotArrays ]), <0> )=<" ) );
      Serial.print( min( ( offsetValue + ( signed )dPotSettings[ indexOfThisDPotCSPinInDPotArrays ] ), 0 ) );
      Serial.print( F( ">, ( signed )DPOT_RATIO - <1> )=<" ) );
      Serial.print( ( signed )DPOT_RATIO - 1 );
      Serial.print( F( ">, <0> - ( ( ( signed )abs( min( ( offsetValue + ( signed )dPotSettings[ indexOfThisDPotCSPinInDPotArrays ] ), <0> ) ) + ( signed )DPOT_RATIO - <1> ) / ( signed )DPOT_RATIO )=<" ) );
      Serial.print( 0 - ( ( ( signed )abs( min( ( offsetValue + ( signed )dPotSettings[ indexOfThisDPotCSPinInDPotArrays ] ), 0 ) ) + ( signed )DPOT_RATIO - 1 ) / ( signed )DPOT_RATIO ) );
      Serial.print( F( ">, ( ( ( signed )offsetValue + dPotSettings[ indexOfThisDPotCSPinInDPotArrays ] ) - ( signed )MAX_DPOT_SETTG )=<" ) );
      Serial.print( ( ( ( signed )offsetValue + dPotSettings[ indexOfThisDPotCSPinInDPotArrays ] ) - ( signed )MAX_DPOT_SETTG ) );
      Serial.print( F( ">, ( ( ( signed )offsetValue + dPotSettings[ indexOfThisDPotCSPinInDPotArrays ] ) - ( signed )MAX_DPOT_SETTG ) / ( signed )DPOT_RATIO )=<" ) );
      Serial.print( ( ( ( signed )offsetValue + dPotSettings[ indexOfThisDPotCSPinInDPotArrays ] ) - ( signed )MAX_DPOT_SETTG ) / ( signed )DPOT_RATIO );
//      Serial.print( F( ">, offsetValue=<" ) );
//      Serial.print( offsetValue );



      if( borrowOrCarryNeededToPreventBreakingLimitDividedByDPOT_RATIO ) offsetDPotOrMSBGroupValue( thisIsReferenceWhenConfigureWasForSignal ? dPotsPerThisLeg + firstMSBIndexThisLeg : firstMSBIndexThisLeg, borrowOrCarryNeededToPreventBreakingLimitDividedByDPOT_RATIO );
      Serial.print( F( "back after recursive call " ) );
        offsetValue -= ( signed )borrowOrCarryNeededToPreventBreakingLimitDividedByDPOT_RATIO * ( signed )DPOT_RATIO;
        if( !offsetValue ) return;
      Serial.print( F( ", offsetValue now<" ) );//offsetValue now<220>
      Serial.print( offsetValue );
      }
      //Sanity check on offset amount being requested:
    
      Serial.print( F( ">, lSBDPotOffsetIndexThisLeg<" ) );
      Serial.print( lSBDPotOffsetIndexThisLeg );
      Serial.print( F( ">, MSB_SETTINGS_TOTAL_THIS_LEG<" ) );
      Serial.print( MSB_SETTINGS_TOTAL_THIS_LEG );
      Serial.print( F( ">, MSB_SETTINGS_AVAILABLE_THIS_LEG<" ) );
      Serial.print( MSB_SETTINGS_AVAILABLE_THIS_LEG );
      Serial.print( F( ">, dPotSettings[ indexOfThisDPotCSPinInDPotArrays ]<" ) );
      Serial.print( dPotSettings[ indexOfThisDPotCSPinInDPotArrays ] );
      Serial.print( F( "> " ) );
    
    if( ( offsetValue < 0 ) && ( ( 0 - offsetValue ) > ( ( indexOfThisDPotCSPinInDPotArrays == ( thisIsReferenceWhenConfigureWasForSignal ? lSBDPotOffsetIndexThisLegReference : lSBDPotOffsetIndexThisLeg ) ? dPotSettings[ indexOfThisDPotCSPinInDPotArrays ] : ( thisIsReferenceWhenConfigureWasForSignal ? MSB_SETTINGS_TOTAL_THIS_REFERENCE_LEG : MSB_SETTINGS_TOTAL_THIS_LEG ) ) ) ) || \
        ( ( offsetValue > 0 ) && ( offsetValue > ( ( indexOfThisDPotCSPinInDPotArrays == ( thisIsReferenceWhenConfigureWasForSignal ? lSBDPotOffsetIndexThisLegReference : lSBDPotOffsetIndexThisLeg ) ? ( offsetValue > ( MAX_DPOT_SETTG - dPotSettings[ indexOfThisDPotCSPinInDPotArrays ] ) ) : ( thisIsReferenceWhenConfigureWasForSignal ? MSB_SETTINGS_AVAILABLE_THIS_REFERENCE_LEG : MSB_SETTINGS_AVAILABLE_THIS_LEG ) ) ) ) ) )
    { //Beyond limit being asked for.  This location is where to add carrying/borrowing feature
        Serial.print( F( "Beyond limit, limiting offset request of <" ) );
        Serial.print( offsetValue );
        Serial.print( F( "> to <" ) );
    
        if( offsetValue < 0 )
        {
            if( indexOfThisDPotCSPinInDPotArrays == ( thisIsReferenceWhenConfigureWasForSignal ? lSBDPotOffsetIndexThisLegReference : lSBDPotOffsetIndexThisLeg ) ) //( ( indexOfThisDPotCSPinInDPotArrays == ( thisIsReferenceWhenConfigureWasForSignal ? lSBDPotOffsetIndexThisLegReference : lSBDPotOffsetIndexThisLeg ) ? dPotSettings[ indexOfThisDPotCSPinInDPotArrays ] 
                offsetValue = 0 - ( signed )dPotSettings[ indexOfThisDPotCSPinInDPotArrays ];/*a negative LSB value equaling zero minus the current setting*/
            else // : ( thisIsReferenceWhenConfigureWasForSignal ? MSB_SETTINGS_TOTAL_THIS_REFERENCE_LEG : MSB_SETTINGS_TOTAL_THIS_LEG ) ) ) ) )
                offsetValue = 0 - ( signed )( thisIsReferenceWhenConfigureWasForSignal ? ( signed )MSB_SETTINGS_TOTAL_THIS_REFERENCE_LEG : ( signed )MSB_SETTINGS_TOTAL_THIS_LEG );/*a negative MSB value equaling zero minus the current total*/
        }
        else //if( ( offsetValue < 0 ) && ( offsetValue > ( ( indexOfThisDPotCSPinInDPotArrays == ( thisIsReferenceWhenConfigureWasForSignal ? lSBDPotOffsetIndexThisLegReference : lSBDPotOffsetIndexThisLeg ) ? ( offsetValue > ( MAX_DPOT_SETTG - dPotSettings[ indexOfThisDPotCSPinInDPotArrays ] ) ) : ( thisIsReferenceWhenConfigureWasForSignal ? MSB_SETTINGS_AVAILABLE_THIS_REFERENCE_LEG : MSB_SETTINGS_AVAILABLE_THIS_LEG ) ) ) ) )
            if( indexOfThisDPotCSPinInDPotArrays == ( thisIsReferenceWhenConfigureWasForSignal ? lSBDPotOffsetIndexThisLegReference : lSBDPotOffsetIndexThisLeg ) ) //( ( indexOfThisDPotCSPinInDPotArrays == ( thisIsReferenceWhenConfigureWasForSignal ? lSBDPotOffsetIndexThisLegReference : lSBDPotOffsetIndexThisLeg ) ? dPotSettings[ indexOfThisDPotCSPinInDPotArrays ] 
                offsetValue = dPotSettings[ indexOfThisDPotCSPinInDPotArrays ];/*a negative LSB value equaling the current setting*/
            else // : ( thisIsReferenceWhenConfigureWasForSignal ? MSB_SETTINGS_TOTAL_THIS_REFERENCE_LEG : MSB_SETTINGS_TOTAL_THIS_LEG ) ) ) ) )
                offsetValue = thisIsReferenceWhenConfigureWasForSignal ? MSB_SETTINGS_AVAILABLE_THIS_REFERENCE_LEG : MSB_SETTINGS_AVAILABLE_THIS_LEG;/*a positive MSB value equaling the current available*/
    
        Serial.print( offsetValue );
        Serial.print( F( ">." ) );
      }//Sanity enforcement complete
    
    if( indexOfThisDPotCSPinInDPotArrays == \
    ( thisIsReferenceWhenConfigureWasForSignal ? \
    lSBDPotOffsetIndexThisLegReference : lSBDPotOffsetIndexThisLeg ) )
        offsetValue += dPotSettings[ indexOfThisDPotCSPinInDPotArrays ];
    else
        offsetValue += MSB_SETTINGS_TOTAL_THIS_LEG;
    #ifdef DEBUG
      while( !Serial );
      Serial.print( dPotPins[ indexOfThisDPotCSPinInDPotArrays ] );
      Serial.print( F( " getting " ) );
      Serial.print( offsetValue );
    #endif
      //setDPotOrMSBGroupValue( const uint8_t DPotPin, uint16_t settingValue ) or writeSettingToAsingleDPot()
      setDPotOrMSBGroupValue( indexOfThisDPotCSPinInDPotArrays, ( uint16_t )offsetValue );
    }
    static int32_t startMSBSettingForCalculatingSettingUnitsPerAnalogInputUnit = 0;
    static int16_t startLSBSettingForCalculatingSettingUnitsPerAnalogInputUnit = 0; //signed b/c we need to do subtraction with it and save sign
    int16_t bestOfFour( uint8_t ); //signed b/c we need to do subtraction with it and save sign
    #define MOST_ACCURATE true  //This belongs with the following function declare
    int16_t bestGuessAnalogInputReading( uint8_t = dPotLeg, bool = !MOST_ACCURATE, bool = true ); //signed b/c we need to do subtraction with it and save sign
    #define TARGET_LEVEL_DUMMY_VALUE 0
    #define USE_OPPOSING_LEGS_LEVEL_AS_TARGET_LEVEL true
    static bool thisIsTheMSBPass;
    static int16_t settingStepSize, endLevel, incomingInboardAnalogLevel, targetLevel; //signed b/c we need to do subtraction with it and save sign
    #define END_LEVEL_VALID true
//#error Next step: reconcile setDPotLegMidPoint() with dPotLegSetpointing()

    void theNewSettingStepSizeInLSBUnits( bool endLevelValid = END_LEVEL_VALID )
    { //endLevel might not be valid yet or might cause division by zero
//What about limits like this:        settingStepSize = ( settingStepSize < 0 ) ? 0 - ( signed )MSB_SETTINGS_TOTAL_THIS_LEG : MSB_SETTINGS_AVAILABLE_THIS_LEG;
        if( endLevelValid && ( ( signed )( ( signed )endLevel - ( signed )incomingInboardAnalogLevel ) ) ) //so we don't divide by the wrong value or by zero in here
        {/*HOPING THIS INSTRUCTION UP HERE FIRST WORKS BUT I SUSPECT IT WON'T
            */
            legLSBSettingUnitsTimes100PerAnalogInputUnit[ dPotLeg ] = ( int32_t )( ( signed )100 * ( ( ( signed )( ( signed )DPOT_RATIO * ( signed ) MSB_SETTINGS_TOTAL_THIS_LEG ) + ( signed )dPotSettings[ lSBDPotOffsetIndexThisLeg ] ) - ( ( signed )DPOT_RATIO * ( signed )startMSBSettingForCalculatingSettingUnitsPerAnalogInputUnit + startLSBSettingForCalculatingSettingUnitsPerAnalogInputUnit ) ) / ( signed )( ( signed )endLevel - ( signed )incomingInboardAnalogLevel ) );
            Serial.print( F( "Entered theNewSettingStepSizeInLSBUnits() with level difference=<" ) );
            Serial.print( ( ( signed )endLevel - ( signed )incomingInboardAnalogLevel ) );
            Serial.print( F( "> and step difference=<" ) );
            Serial.print( ( ( signed )( ( signed )DPOT_RATIO * ( signed ) MSB_SETTINGS_TOTAL_THIS_LEG ) + ( signed )dPotSettings[ lSBDPotOffsetIndexThisLeg ] ) - ( ( signed )DPOT_RATIO * ( signed )startMSBSettingForCalculatingSettingUnitsPerAnalogInputUnit + startLSBSettingForCalculatingSettingUnitsPerAnalogInputUnit ) );
            Serial.print( F( "> and calculated from ( ( signed )DPOT_RATIO * ( signed ) MSB_SETTINGS_TOTAL_THIS_LEG ) + ( signed )dPotSettings[ lSBDPotOffsetIndexThisLeg ] ) =<" ) );
            Serial.print( ( signed )( ( signed )DPOT_RATIO * ( signed ) MSB_SETTINGS_TOTAL_THIS_LEG ) + ( signed )dPotSettings[ lSBDPotOffsetIndexThisLeg ] );
//            Serial.print( F( ">, =<" ) );
//            Serial.print(  );
            Serial.print( F( "> legLSBSettingUnitsTimes100PerAnalogInputUnit=<" ) );
            Serial.print( legLSBSettingUnitsTimes100PerAnalogInputUnit[ dPotLeg ] );
            Serial.print( F( ">. Calculated settingStepSize=<" ) );
            settingStepSize = ( ( signed )( ( signed )endLevel - ( signed )targetLevel ) * legLSBSettingUnitsTimes100PerAnalogInputUnit[ dPotLeg ] ) / 100;
            Serial.print( settingStepSize );
            Serial.print( F( "> divd by DPOT_RATIO=<" ) );
            Serial.print( ( ( ( signed )( ( signed )endLevel - ( signed )targetLevel ) * legLSBSettingUnitsTimes100PerAnalogInputUnit[ dPotLeg ] ) / 100 ) / ( signed )DPOT_RATIO );
            Serial.print( F( ">. " ) );
        }
        else
        {
            settingStepSize = ( ( dPotLeg < LM334_BRIDGE_LEGS ) ? \
                ( signed )( ( signed )incomingInboardAnalogLevel - ( signed )targetLevel ) : \
                ( signed )( ( signed )targetLevel - ( signed )incomingInboardAnalogLevel ) ) / ( signed )2;
        //The following lines are the key to predictive leg setting
            if( thisIsTheMSBPass )
            {
                settingStepSize = ( ( dPotLeg < LM334_BRIDGE_LEGS ) ? \
                    ( signed )( ( signed )incomingInboardAnalogLevel - ( signed )targetLevel ) : \
                    ( signed )( ( signed )targetLevel - ( signed )incomingInboardAnalogLevel ) ) / ( signed )2;
            }
            else
                settingStepSize = ( ( dPotLeg < LM334_BRIDGE_LEGS ) ? \
                    ( signed )( ( signed )incomingInboardAnalogLevel - ( signed )targetLevel ) : \
                    ( signed )( ( signed )targetLevel - ( signed )incomingInboardAnalogLevel ) ) / ( signed )2;
        }
        Serial.print( F( "Calculated or not settingStepSize=<" ) );
        Serial.print( settingStepSize );
        Serial.print( F( ">. " ) );
//        analogInputUnitsTimes100PerMSBLegSettingUnit[ dPotLeg ] = ( 100 * ( signed )( endLevel - incomingInboardAnalogLevel ) ) / ( signed )( startMSBSettingForCalculatingSettingUnitsPerAnalogInputUnit - MSB_SETTINGS_TOTAL_THIS_LEG );
    //not good yet        legLSBSettingUnitsTimes100PerAnalogInputUnit[ dPotLeg ] = ( 100 * ( signed )( endLevel - incomingBestGuessAnalogInputreading ) ) / ( signed )( startLSBSettingForCalculatingSettingUnitsPerAnalogInputUnit - dPotSettings[ lSBDPotOffsetIndexThisLeg ] );
    //DON'T ALLOW A new STEP SIZE CHANGE to less THAN 1/6 of current IF TARGET HASN'T BEEN ACQUIRED: FROM 20 CAN ONLY GO DOWN TO 3 or -3
    }
    #define REFERENCE_LEG_LEVEL_IS_HIGH 1
    #define REFERENCE_LEG_LEVEL_IS_OPTIMAL 0
    #define REFERENCE_LEG_LEVEL_IS_LOW -1
    static int8_t referenceLegLevelFromLastSettingIt[ LM334_BRIDGE_LEGS + BARE_BRIDGE_LEGS ];
    int16_t dPotLegSetpointing( bool readAndPlotInEachLap = !READ_AND_PLOT_IN_EACH_LAP, bool useOpposingLegLevelAsTargetLevel = !USE_OPPOSING_LEGS_LEVEL_AS_TARGET_LEVEL )
    { //returns the resulting single-try reading of the leg, making it negative if the direction to target level changed?   int16_t value = bestOfFour( dPotLeg )
        thisIsTheMSBPass = true;
        bool originalDirectionToTargetLevel, directionToTargetLevel;
        int16_t startSettings, startLevel;
        int16_t newStepSize, oldStepSizeDivdBy6;
        if( useOpposingLegLevelAsTargetLevel && ( dPotLeg < ( LM334_BRIDGE_LEGS + BARE_BRIDGE_LEGS ) ) )
            targetLevel = bestGuessAnalogInputReading( dPotLeg + ( ( dPotLeg % 2 ) ? -1 : 1 ), MOST_ACCURATE );
        if( incomingInboardAnalogLevel == targetLevel && bestGuessAnalogInputReading( dPotLeg, MOST_ACCURATE ) == targetLevel ) return true; //if already there
        startMSBSettingForCalculatingSettingUnitsPerAnalogInputUnit = MSB_SETTINGS_TOTAL_THIS_LEG;
        startLSBSettingForCalculatingSettingUnitsPerAnalogInputUnit = dPotSettings[ lSBDPotOffsetIndexThisLeg ];

CalculateNewStepSize:
        theNewSettingStepSizeInLSBUnits( !END_LEVEL_VALID );
//        settingStepSize = analogInputUnitsTimes100PerMSBLegSettingUnit[ dPotLeg ] ? \
//            ( 100 * ( signed )( targetLevel - incomingInboardAnalogLevel ) ) / analogInputUnitsTimes100PerMSBLegSettingUnit[ dPotLeg ] : \
//             theNewSettingStepSizeInLSBUnits();
//#error Next step: reconcile aqll the different stepsize calculations, then the borrow/carry problem
        endLevel = incomingInboardAnalogLevel;
        bool firstPass;
        Serial.print( F( "Entered dPotLegSetpointing(" ) );
        Serial.print( dPotLeg );
        Serial.print( F( ") with incomingInboardAnalogLevel=<" ) );
        Serial.print( incomingInboardAnalogLevel );
        Serial.print( F( ">, targetLevel=<" ) );
        Serial.print( targetLevel );
        Serial.print( F( ">, settingStepSize=<" ) );
        Serial.print( settingStepSize );
        Serial.print( F( ">, readAndPlotInEachLap=<" ) );
        Serial.print( readAndPlotInEachLap );
        Serial.print( F( ">, useOpposingLegLevelAsTargetLevel=<" ) );
        Serial.print( useOpposingLegLevelAsTargetLevel );
        Serial.print( F( ">, analogInputUnitsTimes100PerMSBLegSettingUnit[ dPotLeg ]=<" ) );
        Serial.print( analogInputUnitsTimes100PerMSBLegSettingUnit[ dPotLeg ] );
        Serial.print( F( ">, ( 100 * ( signed )( targetLevel - incomingInboardAnalogLevel ) ) / ( analogInputUnitsTimes100PerMSBLegSettingUnit[ dPotLeg ] )=<" ) );
        Serial.print( ( 100 * ( signed )( ( signed )targetLevel - ( signed )incomingInboardAnalogLevel ) ) / ( analogInputUnitsTimes100PerMSBLegSettingUnit[ dPotLeg ] ) );
        Serial.print( F( ">, ( dPotLeg < LM334_BRIDGE_LEGS )=<" ) );
        Serial.print( ( dPotLeg < LM334_BRIDGE_LEGS ) );
        Serial.print( F( ">, ( targetLevel > incomingInboardAnalogLevel )=<" ) );
        Serial.print( ( targetLevel > incomingInboardAnalogLevel ) );
        Serial.print( F( ">, ( targetLevel - incomingInboardAnalogLevel ) / -2=<" ) );
        Serial.print( ( signed )( ( signed )targetLevel - ( signed )incomingInboardAnalogLevel ) / -2 );
        Serial.print( F( ">, ( incomingInboardAnalogLevel - targetLevel ) / 2=<" ) );
        Serial.print( ( signed )( ( signed )incomingInboardAnalogLevel - ( signed )targetLevel ) / ( signed )2 );
        Serial.print( F( "> " ) );
        do //has to be able to loop b/c the legLSBSettingUnitsTimes100PerAnalogInputUnit[ dPotLeg ] might be way off or not set
        { //checked reference leg
            firstPass = true;
            do //has to be able to loop b/c the legLSBSettingUnitsTimes100PerAnalogInputUnit[ dPotLeg ] might be way off or not set
            { //checked reference leg
                if( thisIsTheMSBPass )
                {
                    if( ( signed )( ( settingStepSize < 0 ) ? MSB_SETTINGS_TOTAL_THIS_LEG : MSB_SETTINGS_AVAILABLE_THIS_LEG ) < abs( settingStepSize ) )
                    {
                        theNewSettingStepSizeInLSBUnits();
                        if( !( settingStepSize / ( signed )DPOT_RATIO ) ) 
                            break;
                    }
                }
                else if( masterReadingsArray[ dPotLeg ].CurrentUnmagnifiedReading >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE == targetLevel )
                {
                    break; //This will go outside the MSB loop for the second time and we shouldn't need to come back
                }
                else
                {
//                    if( masterReadingsArray[ dPotLeg ].CurrentUnmagnifiedReading >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE > targetLevel )
//                    {//making sure stepsize polarity is positive for dPotLeg < ( LM334_BRIDGE_LEGS + BARE_BRIDGE_LEGS ), negative otherwise
                        theNewSettingStepSizeInLSBUnits();
//                        settingStepSize = ( dPotLeg < ( LM334_BRIDGE_LEGS + BARE_BRIDGE_LEGS ) ) ? \
//                        ( signed )( ( signed )( masterReadingsArray[ dPotLeg ].CurrentUnmagnifiedReading >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE ) - ( signed )targetLevel ) : \
//                        ( signed )( ( signed )targetLevel - ( signed )( masterReadingsArray[ dPotLeg ].CurrentUnmagnifiedReading >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE ) );
//                    }
//                    else
//                    {//making sure stepsize polarity is negative for dPotLeg < ( LM334_BRIDGE_LEGS + BARE_BRIDGE_LEGS ), positive otherwise
//                        settingStepSize = ( dPotLeg >= ( LM334_BRIDGE_LEGS + BARE_BRIDGE_LEGS ) ) ? \
//                        ( signed )( ( signed )( masterReadingsArray[ dPotLeg ].CurrentUnmagnifiedReading >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE ) - ( signed )targetLevel ) :
//                        ( signed )( ( signed )targetLevel - ( signed )( masterReadingsArray[ dPotLeg ].CurrentUnmagnifiedReading >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE ) );
//                    }
                }

                if( !thisIsTheMSBPass && ( signed )( ( settingStepSize < 0 ) ?  dPotSettings[ lSBDPotOffsetIndexThisLeg ] : MAX_DPOT_SETTG - dPotSettings[ lSBDPotOffsetIndexThisLeg ] ) < abs( settingStepSize ) )
                {
                        theNewSettingStepSizeInLSBUnits();
//                    settingStepSize = ( settingStepSize < 0 ) ? \
//                    0 - ( signed )dPotSettings[ lSBDPotOffsetIndexThisLeg ] : \
//                    dPotSettings[ lSBDPotOffsetIndexThisLeg ];
                }

                startLevel = endLevel;
                if( thisIsTheMSBPass && !( settingStepSize / ( signed )DPOT_RATIO ) )/*need to advance to LSB level*/ break;
                offsetDPotOrMSBGroupValue( thisIsTheMSBPass ? firstMSBIndexThisLeg : lSBDPotOffsetIndexThisLeg, ( thisIsTheMSBPass ) ? ( settingStepSize / ( signed )DPOT_RATIO ) : settingStepSize ); //Force correct polarity  TODO fix so polarity is correct without this extra force
                if( !thisIsTheMSBPass || readAndPlotInEachLap ) 
                {
                    readAndPlotFromAllADCsInAndOutboard( PLOTTER_MAX_SCALE ); //
                    endLevel = masterReadingsArray[ dPotLeg ].CurrentUnmagnifiedReading >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE;
                    Serial.print( F( "> new value this leg=<" ) );
                    Serial.print( masterReadingsArray[ dPotLeg ].CurrentUnmagnifiedReading >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE );
                    Serial.print( F( "> endLevel=<" ) );
                    Serial.print( endLevel );
                    Serial.print( F( "> " ) );
                }
                else
                    endLevel = bestOfFour( dPotLeg );

                if( endLevel == targetLevel ) break;
//                newStepSize = ;//theNewSettingStepSizeInLSBUnits(); We have preliminarily set things up to need an intermediate variable newStepSize.  Now to fix that

/*
                ( signed )( ( ( signed )targetLevel - ( signed )endLevel ) * settingStepSize ) / ( signed )( ( signed )endLevel - ( signed )startLevel );
*/
/*
                    ( dPotLeg < LM334_BRIDGE_LEGS ) ? \
                        ( ( signed )( ( signed )targetLevel - ( signed )incomingInboardAnalogLevel ) / -2 ) : 
                        ( ( signed )( ( signed )targetLevel - ( signed )incomingInboardAnalogLevel ) / ( signed )2 );
*/
//                Serial.print( F( "> Line <1211> initial new settingStepSize=<" ) );
//                Serial.print( newStepSize );
                oldStepSizeDivdBy6 = abs( ( signed )settingStepSize / ( signed )6 );
                theNewSettingStepSizeInLSBUnits();
                if( oldStepSizeDivdBy6 >  abs( ( signed )settingStepSize ) ) //abs( newStepSize ) ) //Ex.: first pass step size = 4, next pass step size is 0 but target voltage not reached
                {
                    if( !settingStepSize )
                    {
                        firstPass = false;
                    }
                    settingStepSize = max( 1, oldStepSizeDivdBy6 ); //but inact an additional fix to ensure step polarity is appropriate and allow that 1
                    if( ( ( targetLevel > endLevel ) && ( dPotLeg < LM334_BRIDGE_LEGS ) ? ( settingStepSize > 0 ) : ( settingStepSize < 0 ) ) || ( targetLevel < endLevel && ( ( dPotLeg < LM334_BRIDGE_LEGS ) ? ( settingStepSize < 0 ) : ( settingStepSize > 0 ) ) ) ) //This depends on whether lm334 or bare !!!!!!!!!!!! It forces polarity compliance
                        settingStepSize = 0 - settingStepSize;
                }
                Serial.print( F( "> Line <1331> new settingStepSize=<" ) );
                Serial.print( settingStepSize );
                Serial.print( F( ">" ) );
                if( !settingStepSize )       //
                    break;               //  Why are we using an intermediate variable? Probably to allow a second calculation on the value being used for :::: purpose of knowing effect on stepsPerLevelUnit so that we could check to ensure > old ( stepsize / 6 )
                if( useOpposingLegLevelAsTargetLevel && ( dPotLeg < ( LM334_BRIDGE_LEGS + BARE_BRIDGE_LEGS ) ) )
                    targetLevel = bestGuessAnalogInputReading( dPotLeg + ( ( dPotLeg % 2 ) ? -1 : 1 ), MOST_ACCURATE );
            }  while( endLevel != targetLevel );
            if( !thisIsTheMSBPass ) break; //this is the second time outside first do loop
            thisIsTheMSBPass = false;
            Serial.print( F( "Changing to LSB steps." ) );
            readAndPlotFromAllADCsInAndOutboard( PLOTTER_MAX_SCALE ); //delay some time to settle and take another reading for highest accuracy's sake
            if( useOpposingLegLevelAsTargetLevel && ( dPotLeg < ( LM334_BRIDGE_LEGS + BARE_BRIDGE_LEGS ) ) )
            {
                targetLevel = masterReadingsArray[ dPotLeg + ( ( dPotLeg % 2 ) ? -1 : 1 ) ].CurrentUnmagnifiedReading >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE;
                Serial.print( F( "> Line <1239> adjusted targetLevel=<" ) );
                Serial.print( targetLevel );
                Serial.print( F( "> " ) );
            }
        }while( ( masterReadingsArray[ dPotLeg ].CurrentUnmagnifiedReading >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE ) != targetLevel );

//Definition of oscillating: an invalid stepsize has been calculated or endLevel is not approaching targetLevel and !firstPass
        Serial.print( F( "> Line <1210> dPotLeg=<" ) );
        Serial.print( dPotLeg );
        Serial.print( F( "> Line <1212> incomingInboardAnalogLevel=<" ) );
        Serial.print( incomingInboardAnalogLevel );
        Serial.print( F( "Line <1214> targetLevel=<" ) );
        Serial.print( targetLevel );
        Serial.print( F( "> Line <1216> startLevel=<" ) );
        Serial.print( startLevel );
        Serial.print( F( "> Line <1218> endLevel=<" ) );
        Serial.print( endLevel );
        Serial.print( F( "> Line <1220> newStepSize=<" ) );
        Serial.print( newStepSize );
        Serial.print( F( "> Line <1222> settingStepSize=<" ) );
        Serial.print( settingStepSize );
        Serial.print( F( "> legLSBSettingUnitsTimes100PerAnalogInputUnit[ dPotLeg ]=<" ) );
        referenceLegLevelFromLastSettingIt[ dPotLeg / 2 /*equates to bridge index from either leg index*/ ] = ( ( masterReadingsArray[ dPotLeg ].CurrentUnmagnifiedReading >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE ) == COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG ) ? REFERENCE_LEG_LEVEL_IS_OPTIMAL : ( ( masterReadingsArray[ dPotLeg ].CurrentUnmagnifiedReading >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE ) > COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG ) ? \
        REFERENCE_LEG_LEVEL_IS_HIGH : REFERENCE_LEG_LEVEL_IS_LOW;
        return ( originalDirectionToTargetLevel ? ( bestGuessAnalogInputReading( dPotLeg, MOST_ACCURATE ) >= targetLevel ) : ( bestGuessAnalogInputReading( dPotLeg, MOST_ACCURATE ) < targetLevel ) );
    }

    bool stepAdjustDPotsForThisLeg( bool = TAKE_LEG_VOLTAGE_DOWN, bool = false ); //default direction will be positive

    #if ( ( defined AUTO_BRIDGE_BALANCING ) && ( defined DIFFERENTIAL ) )
    bool highestLevelDifferentialBridgeSetpointing( uint8_t OutboardADCindex = whichBridgeOrOutboardADCindex, uint8_t limit = 200/*This value is arbitrary right now*/ )
    {
        counterForTraceOutOfRangeTooLong[ OutboardADCindex ] == 0;
      //Need to insert bounds checking for if signal leg level has not attained very near to reference leg level
      //If midpoint is overshot, stops as if we achieved it
        while( oneReadingFromThisOutboardADC( OutboardADCindex ) > HALF_HEIGHT_OF_A_PLOT_LINESPACE ) //This cannot work for setting the reference leg b/c the signal leg may be out of range!
        {
            if( counterForTraceOutOfRangeTooLong[ OutboardADCindex ]++ > limit ) break; //Limited to prevent endless looping here
            stepAdjustDPotsForThisLeg( TAKE_LEG_VOLTAGE_DOWN );
            Serial.print( F( "Line <1539>" ) );
            readAndPlotFromAllADCsInAndOutboard( PLOTTER_MAX_SCALE, true ); // I would think the operator would appreciate seeing something like this during calibration
        }
        while( oneReadingFromThisOutboardADC( OutboardADCindex ) < HALF_HEIGHT_OF_A_PLOT_LINESPACE )
        {
            if( counterForTraceOutOfRangeTooLong[ OutboardADCindex ]++ > limit ) break; //Limited to prevent endless looping here
            stepAdjustDPotsForThisLeg( !TAKE_LEG_VOLTAGE_DOWN );
            Serial.print( F( "Line <1401>" ) );
            readAndPlotFromAllADCsInAndOutboard( PLOTTER_MAX_SCALE, true ); // I would think the operator would appreciate seeing something like this during calibration
        }
        if( counterForTraceOutOfRangeTooLong[ OutboardADCindex ] > limit ) 
            return false;
        counterForTraceOutOfRangeTooLong[ OutboardADCindex ] == 0;
    }
    #endif

    #define JUST_QUERYING_WHETHER_SETTINGS_ARE_MAXED_OUT true
    bool stepAdjustDPotsForThisLeg( bool voltsDown, bool justQueryingWhetherSettingsAreMaxedOut ) //default direction will be positive
    { // This returns answer to query or effectively increments or decrements LSB digipot setting just once and returns whether direction to targetLevel stayed the same
    //return false if still needs to take in the same direction
      Serial.print( F( "Going " ) );
      if( voltsDown )
        Serial.print( F( "down" ) );
      else
        Serial.print( F( "up" ) );
      Serial.print( F( " in stepAdjustDPotsForThisLeg=<" ) );
      Serial.print( dPotLeg );
      Serial.print( F( "> targetLevel=<" ) );
      Serial.print( targetLevel );
      Serial.print( F( "> lSBDPotOffsetIndexThisLeg=<" ) );
      Serial.print( lSBDPotOffsetIndexThisLeg );
      Serial.print( F( "> MSBpotPin=<" ) );
      Serial.print( dPotPins[ firstMSBIndexThisLeg ] );
      Serial.print( F( "> DPOTS_PER_LM334_LEG=<" ) );
      Serial.print( DPOTS_PER_LM334_LEG );
        if( dPotSettings[ lSBDPotOffsetIndexThisLeg ] > MAX_DPOT_SETTG )
        { //This is an invalid condition - put the setting at half scale
            setDPotOrMSBGroupValue( lSBDPotOffsetIndexThisLeg, MAX_DPOT_SETTG >> 1 ); 
          return false;
        }
        uint8_t oneAboveLastDPotIndexThisLeg = lSBDPotOffsetIndexThisLeg + dPotsPerThisLeg;
      if( justQueryingWhetherSettingsAreMaxedOut )
      { //returning false means failure of digipot settings that they are either maxed high or minimized zeroes whichever one was queried
        for( uint8_t dPotIndexThisLeg = lSBDPotOffsetIndexThisLeg; dPotIndexThisLeg < oneAboveLastDPotIndexThisLeg; dPotIndexThisLeg++ )
          if( dPotSettings[ dPotIndexThisLeg ] != dPotSettings[ lSBDPotOffsetIndexThisLeg ] ) return true;
      }
      if( analogPinArray )
      {
        Serial.print( F( "> dPotLeg=<" ) );
        Serial.print( dPotLeg );
      }
      Serial.print( F( ">" ) );
      //The following construct acts whether justQuerying... or not
      if( voltsDown ) //This means querying whether the settings are maxed high and the voltage will be minimium low
      {
        Serial.print( F( "Line <1066> " ) );
        if( ( dPotSettings[ lSBDPotOffsetIndexThisLeg ] >= MAX_DPOT_SETTG ) && ( MSB_SETTINGS_AVAILABLE_THIS_LEG == 0 ) )
          return false;
      }
      else
      {
        if( ( dPotSettings[ lSBDPotOffsetIndexThisLeg ] == 0 ) && ( MSB_SETTINGS_TOTAL_THIS_LEG == 0 ) )
          return false;
      }
      if( justQueryingWhetherSettingsAreMaxedOut ) return true;
    #ifdef DEBUG
      Serial.print( F( " on " ) );
      Serial.print( firstMSBIndexThisLeg );
    #endif
      //        Serial.print( F( " going " ) );
      //        Serial.print( voltsDown ? "down ": "up ");
    #ifdef DEBUG
      Serial.println();
    #endif
      Serial.print( F( "Line <1097> " ) );
    #if ( ( not defined MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE ) || ( MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE == false ) )
        for( uint8_t dPotIndexThisLeg = lSBDPotOffsetIndexThisLeg; dPotIndexThisLeg < oneAboveLastDPotIndexThisLeg; dPotIndexThisLeg++ )
      {
        Serial.print( F( " Entering dPotSettings[" ) );
        Serial.print( dPotPins[ dPotIndexThisLeg ] );
        Serial.print( F( "]=<" ) );
        Serial.print( dPotSettings[ dPotIndexThisLeg ] );
        Serial.print( F( ">" ) );
      }
    #endif

    if( dPotsPerThisLeg > 1 )
    {
        if( !voltsDown ) //Positive direction == true
        { //being told to decrement so the voltage goes up and we already know we have margin somewhere for one step
            Serial.print( F( " Entered with voltsDown as false " ) ); //Was hoping
            if( ( int16_t )dPotSettings[ lSBDPotOffsetIndexThisLeg ] == 0 ) //This catches dPotSettings[ lSBDPotOffsetIndexThisLeg ] having or about to have a value lower than 0.  So we cycle it up
            { 
                setDPotOrMSBGroupValue( lSBDPotOffsetIndexThisLeg, DPOT_RATIO - 1 ); //We do it this way so we normally only deal with a single carry or borrow
                setDPotOrMSBGroupValue( firstMSBIndexThisLeg, MSB_SETTINGS_TOTAL_THIS_LEG - 1 );
            }
            else
            {
                setDPotOrMSBGroupValue( lSBDPotOffsetIndexThisLeg, --( dPotSettings[ lSBDPotOffsetIndexThisLeg ] ) );
            }
#if ( ( not defined MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE ) || ( MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE == false ) )
            Serial.print( F( " called setDPotOrMSBGroupValue on MID and MSB DPotSettings[" ) );
#endif
        }
        else
        {
            Serial.print( F( " Entered with voltsDown as true " ) );
//Being told to increment so the voltage goes down
            if( ( int16_t )( dPotSettings[ lSBDPotOffsetIndexThisLeg ] == MAX_DPOT_SETTG ) && ( MSB_SETTINGS_AVAILABLE_THIS_LEG > 0 ) )
            {
                setDPotOrMSBGroupValue( lSBDPotOffsetIndexThisLeg, MAX_DPOT_SETTG + 1 - DPOT_RATIO ); //We do it this way so we normally only deal with a single carry or borrow
                setDPotOrMSBGroupValue( firstMSBIndexThisLeg, MSB_SETTINGS_TOTAL_THIS_LEG + 1 );
            }
            else
            {
                setDPotOrMSBGroupValue( lSBDPotOffsetIndexThisLeg, ++( dPotSettings[ lSBDPotOffsetIndexThisLeg ] ) );
            }
        }
    }
    else
    {
        if( !voltsDown ) //Positive direction == true
        {
            dPotSettings[ lSBDPotOffsetIndexThisLeg ] -= ( dPotSettings[ lSBDPotOffsetIndexThisLeg ] == 0 ) ? 0 : 1;
            setDPotOrMSBGroupValue( lSBDPotOffsetIndexThisLeg, dPotSettings[ lSBDPotOffsetIndexThisLeg ] );
        }
        else
        {
            dPotSettings[ lSBDPotOffsetIndexThisLeg ] += ( dPotSettings[ lSBDPotOffsetIndexThisLeg ] == MAX_DPOT_SETTG ) ? 0 : 1;
            setDPotOrMSBGroupValue( lSBDPotOffsetIndexThisLeg, dPotSettings[ lSBDPotOffsetIndexThisLeg ] );
        }
    }
    
    #if ( ( not defined MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE ) || ( MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE == false ) )
                Serial.print( F( " MSB group set to <" ) );
                Serial.print( MSB_SETTINGS_TOTAL_THIS_LEG );
                Serial.print( F( ">, LSB set pos to <" ) );
                Serial.print( dPotSettings[ lSBDPotOffsetIndexThisLeg ] );
                Serial.print( F( ">." ) );
    #endif//return false if still needs to take in the same direction
                Serial.print( F( "Line <1519> targetLevel=<" ) );
                Serial.print( targetLevel );
                Serial.print( F( ">." ) );
    if( !targetLevel ) return true;
        Serial.print( F( "Line <1526>" ) );
        return ( voltsDown ? ( bestGuessAnalogInputReading( dPotLeg, MOST_ACCURATE ) <= targetLevel ) : ( bestGuessAnalogInputReading( dPotLeg, MOST_ACCURATE ) >= targetLevel ) );
    } //End of bool stepAdjustDPotsForThisLeg()
    uint32_t oneReadingFromThisOutboardADC( uint8_t );
    bool setDPotLegMidPoint( uint8_t/* bridge*/, bool /*thisIsReferenceLegOfBridge*/, bool = !READ_AND_PLOT_IN_EACH_LAP, /* = !READ_AND_PLOT_IN_EACH_LAP,*/ bool /*useOpposingLegLevelAsTargetLevel*/ = !USE_OPPOSING_LEGS_LEVEL_AS_TARGET_LEVEL ); //All this does without the third argument is set the reference leg to COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG.
    bool adjustBridgeOutputPositive( uint8_t bridge = whichBridgeOrOutboardADCindex ) //TODO: make this function faster through predictive step sizes
    { //If all pots are maxed (positive leg to positive and negative leg to negative) return false
/*
We need to come up with a state variable to know whether the reference leg level is optimal, supra-optimal or sub-optimal.
*/
    #if ( ( not defined MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE ) || ( MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE == false ) )
      while( !Serial );
      Serial.print( F( " Entered adjustBridgeOutputPositive " ) );
      Serial.print( F( " EABOP " ) );
      Serial.print( F( "with bridge=<" ) );
      Serial.print( bridge );
      Serial.print( F( ">." ) );
    #endif
/*
    lower reference leg voltage if it is higher than commonmode... level until it reaches commonmode...,
    during the routine of lowering it, set the state of the level to supra-optimal until it reaches optimal level
    then raise signal leg voltage until can't raise it any more,
    then resume to lower reference leg until can't lower it any more
*/

  //?to read values from analog pins: use IndexInlinespaceParametersArray and add one (reference) or not (signal)?
  // If all are maxed out, return false to signify reference leg maxed negative, signal leg maxed positive


    configureForSignalLegWithBridgeIndexIncludingNonBridgedLegs( bridge );

  if( !stepAdjustDPotsForThisLeg( !TAKE_LEG_VOLTAGE_DOWN, JUST_QUERYING_WHETHER_SETTINGS_ARE_MAXED_OUT ) ) //This only CHECKS to see if there is any settings headroom to take the bridge up signal leg first.  Does this do a recursive call?  That would be horrible!
  {
    Serial.print( F( "Line <1581>." ) );
    configureForReferenceLegWithBridgeIndex( bridge );
    Serial.print( F( "Line <1583>." ) );
    if( !stepAdjustDPotsForThisLeg( TAKE_LEG_VOLTAGE_DOWN, JUST_QUERYING_WHETHER_SETTINGS_ARE_MAXED_OUT ) ) //This only CHECKS to see if there is any settings headroom to take the bridge up reference leg now.  Does this do a recursive call?  That would be horrible!
    { 
        Serial.print( F( "Line <1583>." ) );
    #if ( ( not defined MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE ) || ( MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE == false ) )
        while( !Serial );
        Serial.print( F( " Leaving adjustBridgeOutputPositive unable to change" ) );
        Serial.print( F( " LABOP " ) );
        Serial.print( F( "with bridge=" ) );
        Serial.print( bridge );
        Serial.print( F( ",." ) );
    #endif
        return false;
    }
    Serial.print( F( "Line <1411> targetLevel=<" ) );
  }
    Serial.print( F( "Line <1413>. Settings not maxed out and will allow raising the bridge output level." ) );
  //int16_t bestOfFour( uint8_t dPotLegOrIndexedInboardAnalogInput = 0 )

  if( bridge < LM334_BRIDGES + BARE_DPOT_LEG_BRIDGES )
    { //These are all the bridged so there is a reference leg in these
        configureForReferenceLegWithBridgeIndex( bridge );

//bool setDPotLegMidPoint( uint8_t bridge, bool thisIsReferenceLegOfBridge, bool readAndPlotInEachLap, /* = !READ_AND_PLOT_IN_EACH_LAP,*/ bool useOpposingLegLevelAsTargetLevel = !USE_OPPOSING_LEGS_LEVEL_AS_TARGET_LEVEL ) //All this does without the third argument is set the reference leg to COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG.
//#error read the following and finish development with it in the interest of coming up with a state variable to know whether the reference leg level is optimal, supra-optimal or sub-optimal.
//Need to account for why wouldn't reference leg be able to be lowered to optimal.  It will be able to be but the question is 
//    whether the signal leg can be raised to COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG - BIAS_IN_ANALOG_INPUT_BITS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE_BRIDGE0

//    Essentially, manipulate signal level while reference level sits at COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG 
//    until it maxes out, then resort to manipulating reference level with the signal level maxed either high or low, so when bridge out needs to
//    go up check if referenceLegLevelFromLastSettingIt[ bridge ] == REFERENCE_LEG_LEVEL_IS_OPTIMAL
        incomingInboardAnalogLevel = bestOfFour( dPotLeg );

        if( !setDPotLegMidPoint( bridge, WORK_ON_THE_REFERENCE_LEG ) && ( incomingInboardAnalogLevel /*this is still reference leg*/ > COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG  ) )
            referenceLegLevelFromLastSettingIt[ bridge ] = REFERENCE_LEG_LEVEL_IS_HIGH;
            if( ( bestOfFour( dPotLeg + 1 ) + BIAS_IN_ANALOG_INPUT_BITS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE_BRIDGE0 < incomingInboardAnalogLevel ) )
            {
                return false;
            }
    }

    configureForSignalLegWithBridgeIndexIncludingNonBridgedLegs( bridge );
    incomingInboardAnalogLevel = bestOfFour( dPotLeg );
    targetLevel = COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG; 
 while( !dPotLegSetpointing() )
  {
                Serial.print( F( " raising the signal leg settings since the reference leg voltage is optimal " ) );
                Serial.print( F( " ltslsstrlvio " ) );
                Serial.flush();
/*
     if( bestOfFour( dPotLeg ) < COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG )
     {
       if( !stepAdjustDPotsForThisLeg( !TAKE_LEG_VOLTAGE_DOWN ) )
        {
            if( bridge < LM334_BRIDGES + BARE_DPOT_LEG_BRIDGES )                
                break; 
            else return false; //these bridges are actually unbridged legs so they have no reference leg to keep trying with
        }
     }
     else
     {
        perfectlyBalanceBridgeByTweakingSignalLeg();
         break;
     }
*/
    #if defined CONTINUE_PLOTTING_DURING_AUTO_BRIDGE_BALANCE && CONTINUE_PLOTTING_DURING_AUTO_BRIDGE_BALANCE
        readAndPlotFromAllADCsInAndOutboard( graphLine ? 0 : PLOTTER_MAX_SCALE );
    #endif
    }

      while( oneReadingFromThisOutboardADC( bridge ) < ( HALF_HEIGHT_OF_A_PLOT_LINESPACE ) )
      {
                    Serial.print( F( " raising the reference leg settings since the signal leg settings are maxed low " ) );
                    Serial.print( F( " rtrlsstslsaml " ) );
                    Serial.flush();
        if( !stepAdjustDPotsForThisLeg( !TAKE_LEG_VOLTAGE_DOWN ) )
        {
        #if ( ( not defined MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE ) || ( MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE == false ) )
              while( !Serial );
              Serial.print( F( " Leaving adjustBridgeOutputPositive maxed out" ) );
              Serial.print( F( " LABOP " ) );
              Serial.print( F( "with bridge=" ) );
              Serial.print( bridge );
              Serial.print( F( ",." ) );
        #endif
          return false;
        }
        #if defined CONTINUE_PLOTTING_DURING_AUTO_BRIDGE_BALANCE && CONTINUE_PLOTTING_DURING_AUTO_BRIDGE_BALANCE
            readAndPlotFromAllADCsInAndOutboard( graphLine ? 0 : PLOTTER_MAX_SCALE );
        #endif
      }
    
    #if ( ( not defined MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE ) || ( MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE == false ) )
      while( !Serial );
      Serial.print( F( " Leaving adjustBridgeOutputPositive successful change" ) );
      Serial.print( F( " LABOP " ) );
      Serial.print( F( "with bridge=" ) );
      Serial.print( bridge );
      Serial.print( F( ",." ) );
    #endif
    }

    bool adjustBridgeOutputNegative( uint8_t bridge )
    { //If all pots are maxed (positive leg to negative and negative leg to positive) return false
      configureForSignalLegWithBridgeIndexIncludingNonBridgedLegs( bridge );
    #if ( ( not defined MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE ) || ( MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE == false ) )
      while( !Serial );
      Serial.print( F( " Entered adjustBridgeOutputNegative " ) );
      Serial.print( F( " EABON " ) );
      Serial.print( F( "with bridge=" ) );
      Serial.print( bridge );
      Serial.print( F( ",." ) );
    #endif
      if( !stepAdjustDPotsForThisLeg( TAKE_LEG_VOLTAGE_DOWN, JUST_QUERYING_WHETHER_SETTINGS_ARE_MAXED_OUT ) )
      {
        configureForReferenceLegWithBridgeIndex( bridge );
           if( !stepAdjustDPotsForThisLeg( !TAKE_LEG_VOLTAGE_DOWN, JUST_QUERYING_WHETHER_SETTINGS_ARE_MAXED_OUT ) )
          {
    #if ( ( not defined MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE ) || ( MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE == false ) )
        while( !Serial );
        Serial.print( F( " Leaving adjustBridgeOutputNegative unable to change" ) );
        Serial.print( F( " LABON " ) );
        Serial.print( F( "with bridge=" ) );
        Serial.print( bridge );
        Serial.print( F( ",." ) );
    #endif
        return false; //checks if reference leg is maxed to highest voltage already
      }
      }
      if( bridge < LM334_BRIDGES + BARE_DPOT_LEG_BRIDGES )
        {
                configureForReferenceLegWithBridgeIndex( bridge );
    
      while( bestOfFour( dPotLeg ) > COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG )
      {
                            Serial.print( F( " making sure reference voltage is not too high " ) );
                if( !stepAdjustDPotsForThisLeg( !TAKE_LEG_VOLTAGE_DOWN ) ) break;
    #if defined CONTINUE_PLOTTING_DURING_AUTO_BRIDGE_BALANCE && CONTINUE_PLOTTING_DURING_AUTO_BRIDGE_BALANCE
        readAndPlotFromAllADCsInAndOutboard( graphLine ? 0 : PLOTTER_MAX_SCALE );
    #endif
              }
              while( bestOfFour( dPotLeg ) < COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG )
              {
                            Serial.print( F( " raising the reference leg since that voltage is lower than optimal " ) );
                            Serial.print( F( " rtrlsstvilto " ) );
                            Serial.flush();
                if( !stepAdjustDPotsForThisLeg( !TAKE_LEG_VOLTAGE_DOWN ) ) break;
            #if defined CONTINUE_PLOTTING_DURING_AUTO_BRIDGE_BALANCE && CONTINUE_PLOTTING_DURING_AUTO_BRIDGE_BALANCE
                readAndPlotFromAllADCsInAndOutboard( graphLine ? 0 : PLOTTER_MAX_SCALE );
            #endif
              }
        }
     configureForSignalLegWithBridgeIndexIncludingNonBridgedLegs( bridge );
     while( bestOfFour( dPotLeg ) > COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG )
      {
                    Serial.print( F( " raising the signal leg settings since the reference leg voltage is optimal " ) );
                    Serial.print( F( " ltslsstrlvio " ) );
                    Serial.flush();
                if( !stepAdjustDPotsForThisLeg( TAKE_LEG_VOLTAGE_DOWN ) )
                {
                    if( bridge < LM334_BRIDGES + BARE_DPOT_LEG_BRIDGES )                
                        break; 
                    else return false; //these bridges are actually unbridged legs so they have no reference leg to keep trying with
                }
    #if defined CONTINUE_PLOTTING_DURING_AUTO_BRIDGE_BALANCE && CONTINUE_PLOTTING_DURING_AUTO_BRIDGE_BALANCE
        readAndPlotFromAllADCsInAndOutboard( graphLine ? 0 : PLOTTER_MAX_SCALE );
    #endif
      } //must determine here if success b/c leg may be not bridged
         configureForReferenceLegWithBridgeIndex( bridge );
      while( oneReadingFromThisOutboardADC( bridge ) > ( HALF_HEIGHT_OF_A_PLOT_LINESPACE ) )
      {
                    Serial.print( F( " raising the reference leg settings since the signal leg settings are maxed low " ) );
                    Serial.print( F( " rtrlsstslsaml " ) );
                    Serial.flush();
        if( !stepAdjustDPotsForThisLeg( TAKE_LEG_VOLTAGE_DOWN ) )
        {
    #if ( ( not defined MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE ) || ( MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE == false ) )
          while( !Serial );
          Serial.print( F( " Leaving adjustBridgeOutputPositive maxed out" ) );
          Serial.print( F( " LABOP " ) );
          Serial.print( F( "with bridge=" ) );
          Serial.print( bridge );
          Serial.print( F( ",." ) );
    #endif
          return false;
        }
    #if defined CONTINUE_PLOTTING_DURING_AUTO_BRIDGE_BALANCE && CONTINUE_PLOTTING_DURING_AUTO_BRIDGE_BALANCE
        readAndPlotFromAllADCsInAndOutboard( graphLine ? 0 : PLOTTER_MAX_SCALE );
    #endif
      }
        
    #if ( ( not defined MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE ) || ( MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE == false ) )
      while( !Serial );
      Serial.print( F( " Leaving adjustBridgeOutputPositive successful change" ) );
      Serial.print( F( " LABOP " ) );
      Serial.print( F( "with bridge=" ) );
      Serial.print( bridge );
      Serial.print( F( ",." ) );
    #endif
    }
#endif //Ending section for DPots legs more than zero

void replotLastValuesForAllTraces( bool actuals = false )                  //If we don't execute the following construct, the signal traces will lag behind the graphLine
{ //1st pin bad coming in
#ifdef DEBUG
  while( !Serial ) ;
  Serial.println( F( "Entering replotLastValuesForAllTraces" ) );
#endif
  while( !Serial ) ;
#if ( ( not defined MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE ) || ( MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE == false ) )
  Serial.print( F( " reprinting most recent plotline values: " ) );
#else
  Serial.print( F( " " ) );
#endif
  for( uint8_t linespaceParametersIndex = 0; linespaceParametersIndex < NUMBER_OF_LINESPACES; linespaceParametersIndex++ )
  {
#ifdef DEBUG
    while( !Serial ) ;
    Serial.print( F( "linespaceParametersIndex = " ) );
    Serial.print( linespaceParametersIndex );
    Serial.print( F( ", LastSignalPinPlotPoint = " ) );
    Serial.print( linespaceParameters[ linespaceParametersIndex ].LastSignalPinPlotPoint );
    Serial.print( F( ", ZeroOfThisPlotLinespace = " ) );
    Serial.print( linespaceParameters[ linespaceParametersIndex ].ZeroOfThisPlotLinespace );
    Serial.print( F( ", INDEX_OF_INBOARDS_NOT_SUPERIMPOSED = " ) );
    Serial.println( INDEX_OF_INBOARDS_NOT_SUPERIMPOSED );
#endif
    Serial.print( actuals ? linespaceParameters[ linespaceParametersIndex ].LastSignalPinPlotPoint + linespaceParameters[ linespaceParametersIndex ].ZeroOfThisPlotLinespace : 0 ); //I think this looks better than the line above
    Serial.print( F( " " ) );
    // INDEX_OF_INBOARDS_NOT_SUPERIMPOSED actually equals the number of InboardSuperimposed that exist
    if( linespaceParametersIndex < INDEX_OF_INBOARDS_NOT_SUPERIMPOSED / 2 ) //The same as comparing masterReadingsArrayIndex < INDEX_OF_INBOARDS_NOT_SUPERIMPOSED
    {
#if not defined PLOT_ONLY_THE_SIGNAL_LEG_OF_SUPERIMPOSED_DPOT_LEG_BRIDGE_INBOARDS
#ifdef DEBUG
      while( !Serial ) ;
      Serial.print( F( ", LastReferencePinPlotPointOrLastMagnifiedPlotPoint = " ) );
      Serial.println( linespaceParameters[ linespaceParametersIndex ].LastReferencePinPlotPointOrLastMagnifiedPlotPoint );
#endif
      Serial.print( actuals ? linespaceParameters[ linespaceParametersIndex ].LastReferencePinPlotPointOrLastMagnifiedPlotPoint + linespaceParameters[ linespaceParametersIndex ].ZeroOfThisPlotLinespace : 0 ); //I think this looks better than the line above
      Serial.print( F( " " ) );
#endif
      continue;
    }
    else //skip the following if the above was true
    {
      ;
#ifdef MAGNIFICATION_FACTOR
      Serial.print( actuals ? linespaceParameters[ linespaceParametersIndex ].LastReferencePinPlotPointOrLastMagnifiedPlotPoint + linespaceParameters[ linespaceParametersIndex ].ZeroOfThisPlotLinespace : 0 ); //I think this looks better than the line above
      Serial.print( F( " " ) );
#endif
    }
  }
  Serial.println();
#ifdef DEBUG
  while( !Serial ) ;
  Serial.println( F( "Leaving replotLastValuesForAllTraces" ) );
#endif
}
//

void plotTimingLineGoingUp( bool tracesAlreadyInitializedToValidReadings = true )
{ //doesn't work in loop() when there is more than one linespace: it runs one too many indices?
#ifdef DEBUG
  while( !Serial ) ;
  Serial.println( F( "Entering plotTimingLineGoingUp" ) );
#endif
  while( !Serial ); // wait for serial port to connect. Needed for Leonardo's native USB
  for( uint8_t linespaceParametersIndex = NUMBER_OF_LINESPACES - 1; linespaceParametersIndex != 255; linespaceParametersIndex-- )
  {
    /*
            if( linespaceParametersIndex > 1 ) //plot only double instances until the last one
            {
                Serial.println(); //temporary for debugging
                Serial.print( linespaceParameters[ linespaceParametersIndex - 1 ].HighLimitOfThisPlotLinespace );
                Serial.print( F( " " ) );//?
                #ifdef DEBUG
                    while( !Serial ) ;
                    Serial.println();
                    Serial.println( F( "Line 815" ) );
                #endif
                if( tracesAlreadyInitializedToValidReadings )
                    replotLastValuesForAllTraces( tracesAlreadyInitializedToValidReadings );
                else
                    Serial.println();
                #ifdef DEBUG
                    while( !Serial ) ;
                    Serial.println();
                    Serial.println( F( "Line 820" ) );
                #endif
            }
    */
#if ( ( not defined MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE ) || ( MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE == false ) )
    Serial.print( F( " timing line zero of this linespace: " ) );
#else
    Serial.print( F( " " ) );
#endif
    Serial.print( linespaceParameters[ linespaceParametersIndex ].ZeroOfThisPlotLinespace );
    replotLastValuesForAllTraces( true );
#if ( ( not defined MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE ) || ( MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE == false ) )
    Serial.print( F( " timing line zero of this linespace: " ) );
#else
    Serial.print( F( " " ) );
#endif
    Serial.print( linespaceParameters[ linespaceParametersIndex ].HighLimitOfThisPlotLinespace );
    replotLastValuesForAllTraces( true );
    //        Serial.print( linespaceParameters[ linespaceParametersIndex - 1 ].HighLimitOfThisPlotLinespace );
    Serial.print( F( " " ) );//?
#ifdef DEBUG
    while( !Serial ) ;
    Serial.println();
    Serial.print( F( "Line 826 linespaceParametersIndex - 1 =" ) );
    Serial.println( linespaceParametersIndex - 1 );
#endif
    //        if( tracesAlreadyInitializedToValidReadings ) replotLastValuesForAllTraces( tracesAlreadyInitializedToValidReadings );
    //        else Serial.println();
#ifdef DEBUG
    while( !Serial ) ;
    Serial.println();
    Serial.print( F( "Line 832, linespaceParametersIndex - 1 =" ) );
    Serial.println( linespaceParametersIndex - 1 );
#endif
  }
#ifdef DEBUG
  while( !Serial ) ;
  Serial.println( F( "Leaving plotTimingLineGoingUp" ) );
#endif
}

int16_t bestOfFour( uint8_t dPotLegOrIndexedInboardAnalogInput = 0 ) //returns an INBOARD Analog Input pin reading, dPotLegOrIndexedInboardAnalogInput is also equal to bridge leg indices
{ //remove from consideration the max and min, then return avg of remaining two  //Re-suse some variables not otherwise in use right now
    uint16_t value1, value2, value3, value4;
    do
    {
//        delay( 2 );
        value1 = analogRead( *( analogPinArray + dPotLegOrIndexedInboardAnalogInput ) );
//        delay( 12 );
        value2 = analogRead( *( analogPinArray + dPotLegOrIndexedInboardAnalogInput ) );
//        delay( 6 );
        value3 = analogRead( *( analogPinArray + dPotLegOrIndexedInboardAnalogInput ) );
//        delay( 20 );
        value4 = analogRead( *( analogPinArray + dPotLegOrIndexedInboardAnalogInput ) );
    }while( !( ( ( value1 == value2 ) && ( value1 == value3 ) ) || \
    ( ( value1 == value3 ) && ( value1 == value4 ) ) || \
    ( ( value2 == value3 ) && ( value2 == value4 ) ) || \
    ( ( value1 == value2 ) && ( value1 == value4 ) ) ) );//( finalValue != value ) && ( finalValue != value1 ) && ( finalValue != value2 ) && ( finalValue != value3 ) );
    
  return ( ( value1 + value2 + value3 + value4 - ( max( max( max( value1, value2 ), value3 ), value4 ) + min( min( min( value1, value2 ), value3 ), value4 ) ) ) >> 1 );
}

#if ( ( defined DPOT_LEGS ) && ( DPOT_LEGS > 0 ) )
    int16_t bestGuessAnalogInputReading( uint8_t dPotLegOrIndexedInboardAnalogInput, bool mostAccurate, bool usingGlobalValueOfDPotLegForAnalogPinArrayIndex )
    {
        dPotLegOrIndexedInboardAnalogInput = ( ( dPotLegOrIndexedInboardAnalogInput > 0 ) || ( !usingGlobalValueOfDPotLegForAnalogPinArrayIndex ) ) ? dPotLegOrIndexedInboardAnalogInput : dPotLeg;
        uint16_t value;
        unsigned long runningTotal = 0;
        uint8_t times = 0;
        for( ; times < 4; times++ )
        {
            value = bestOfFour( dPotLegOrIndexedInboardAnalogInput );
            runningTotal += value;
        }
        if( mostAccurate )
        {
            for( ; times < 8; times++ )
            {
                value = bestOfFour( dPotLegOrIndexedInboardAnalogInput );
                runningTotal += value;
            }
        }
        else if( ( ( runningTotal / times ) * times ) > runningTotal + ( times >> 1 ) ) //do the truncatings make a runningTotal recreation too high?
            return ( runningTotal / times ) - 1;
        else if( ( ( runningTotal / times ) * times ) < runningTotal - ( ( times >> 1 ) + 1 ) ) //do the truncatings make a runningTotal recreation too low?
            return ( runningTotal / times ) + 1;
        return ( runningTotal / times );
    }
    
    bool setDPotLegMidPoint( uint8_t bridge, bool thisIsReferenceLegOfBridge, bool readAndPlotInEachLap, bool useOpposingLegLevelAsTargetLevel )
    {
//        uint16_t targetLevel; made to be global
        if( thisIsReferenceLegOfBridge ) 
        {
            configureForReferenceLegWithBridgeIndex( bridge );
        }
        else
        {
            configureForSignalLegWithBridgeIndexIncludingNonBridgedLegs( bridge );
        }        
        targetLevel = \
        ( thisIsReferenceLegOfBridge \
        ? \
        ( useOpposingLegLevelAsTargetLevel \
        ? ( bestGuessAnalogInputReading( dPotLeg - 1, MOST_ACCURATE ) - BIAS_IN_ANALOG_INPUT_BITS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE_BRIDGE0 ) \
        : COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG ) \
        : \
        ( ( bridge < LM334_BRIDGES + BARE_DPOT_LEG_BRIDGES ) ? ( bestGuessAnalogInputReading( dPotLeg + 1, MOST_ACCURATE ) + BIAS_IN_ANALOG_INPUT_BITS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE_BRIDGE0 ) : ( 1 << ( ANALOG_INPUT_BITS_OF_BOARD - 1 ) ) ) );

        incomingInboardAnalogLevel = bestOfFour( dPotLeg ); targetLevel = COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG; 

        dPotLegSetpointing( READ_AND_PLOT_IN_EACH_LAP, useOpposingLegLevelAsTargetLevel );

        return true;
    }
#endif
/*
  global vars needed here b/c their value is shared so much between functions
*/
static uint32_t tracespaceToSkipWhenRepositioning, negativeTracespaceToSkipWhenRepositioning;
/*
  #if ( INBOARDS_PLOTTED > 0 )
    linespace_bounds_magnify_trace_offsets_and_previous_readings linespaceParametersInboard[ INBOARDS_PLOTTED ];
  #endif
  #if defined LM334_BRIDGES && defined SUPERIMPOSE_FIRST_INBOARDS_IN_PAIRS && ( INBOARDS_PLOTTED < LM334_BRIDGES * LEGS_PER_DPOT_STYLE_BRIDGE )
    previous_readings_only DigipotLeg[ ( LM334_BRIDGES * LEGS_PER_DPOT_STYLE_BRIDGE ) - INBOARDS_PLOTTED ];
  #endif
  #if ( OUTBOARDS_PLOTTED > 0 )
    linespace_bounds_magnify_trace_offsets_and_previous_readings linespaceParametersOutboard[ OUTBOARDS_PLOTTED ];
  #endif

  How are LastSignalPinPlotPoint and PreviousUnmagnifiedReading differently used?

  linespaceParameters[ masterReadingsArray[ masterReadingsArrayIndex ].IndexInlinespaceParametersArray ].LastSignalPinPlotPoint = masterReadingsArray[ masterReadingsArrayIndex ].CurrentUnmagnifiedReading;

*/
static bool duringDPotAdjusting = false;
void plotTheNormalAndMagnifiedSignals( uint8_t masterReadingsArrayIndex ) //linespaceParameters[] has Two indices/elements per every non-magnified trace ifdef MAGNIFICATION_FACTOR, otherwise one per
{
#ifdef DEBUG
  while( !Serial );
  Serial.print( F( "Line <1319> masterReadingsArrayIndex=<" ) );
  Serial.print( masterReadingsArrayIndex );
  Serial.print( F( ">." ) );
#endif
  while( !Serial ); // wait for serial port to connect. Needed for Leonardo's native USB
#if ( ( not defined MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE ) || ( MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE == false ) )
  Serial.print( F( "unmagnified value:" ) );
#endif
  Serial.print( F( " " ) );
  if( ( masterReadingsArrayIndex < INDEX_OF_INBOARDS_NOT_SUPERIMPOSED ) && !( masterReadingsArrayIndex % 2 ) ) //This is the case for those ADCs that have just had their
    // current readings refreshed immediately prior to the
    // execution of this function, so use the stored readings.
    //Note also that the standard linespace is designed large
    // enough to always accommodate plotting the full unmagnified reading
  { //this case and the case of masterReadingsArrayIndex < INDEX_OF_OUTBOARDS but not including the case of masterReadingsArrayIndex < INBOARDS_PLOTTED
    // needs to return some values
    linespaceParameters[ masterReadingsArray[ masterReadingsArrayIndex ].IndexInlinespaceParametersArray ].LastSignalPinPlotPoint = masterReadingsArray[ masterReadingsArrayIndex ].CurrentUnmagnifiedReading;
    Serial.print( masterReadingsArray[ masterReadingsArrayIndex ].CurrentUnmagnifiedReading + linespaceParameters[ masterReadingsArray[ masterReadingsArrayIndex ].IndexInlinespaceParametersArray ].ZeroOfThisPlotLinespace ); //This is color one of pair
#if ( ( not defined MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE ) || ( MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE == false ) )
    Serial.print( F( " Unadjusted value=<" ) );
    Serial.print( masterReadingsArray[ masterReadingsArrayIndex ].CurrentUnmagnifiedReading );
    Serial.print( F( ">, scaled to inboard analog input resolution:<" ) );
    Serial.print( masterReadingsArray[ masterReadingsArrayIndex ].CurrentUnmagnifiedReading >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE );
    Serial.print( F( ">" ) );
#endif
#ifdef DEBUG
    Serial.println();
    Serial.print( F( "Line <1289> signal" ) );
#endif
#ifdef MAGNIFICATION_FACTOR
    goto AfterTheMagnifiedPlotted;
#endif
  }
  else if( masterReadingsArrayIndex < INDEX_OF_INBOARDS_NOT_SUPERIMPOSED ) //This is still the case for those ADCs that have just had their current readings refreshed
    // immediately prior to the execution of this function, so use the stored readings.
    //Note also that the standard linespace is designed large enough to always accommodate plotting
    // the full unmagnified reading
  {
    linespaceParameters[ masterReadingsArray[ masterReadingsArrayIndex ].IndexInlinespaceParametersArray ].LastReferencePinPlotPointOrLastMagnifiedPlotPoint = masterReadingsArray[ masterReadingsArrayIndex ].CurrentUnmagnifiedReading;
#if not defined PLOT_ONLY_THE_SIGNAL_LEG_OF_SUPERIMPOSED_DPOT_LEG_BRIDGE_INBOARDS
    Serial.print( masterReadingsArray[ masterReadingsArrayIndex ].CurrentUnmagnifiedReading + linespaceParameters[ masterReadingsArray[ masterReadingsArrayIndex ].IndexInlinespaceParametersArray ].ZeroOfThisPlotLinespace ); //This is color two of pair
#if ( ( not defined MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE ) || ( MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE == false ) )
    Serial.print( F( " Unadjusted value=<" ) );
    Serial.print( masterReadingsArray[ masterReadingsArrayIndex ].CurrentUnmagnifiedReading );
    Serial.print( F( ">, scaled to inboard analog input resolution:<" ) );
    Serial.print( masterReadingsArray[ masterReadingsArrayIndex ].CurrentUnmagnifiedReading >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE );
    Serial.print( F( ">" ) );
#endif
#endif
#ifdef DEBUG
    Serial.println();
    Serial.println( F( "Line 1298 reference" ) );
#endif
#ifdef MAGNIFICATION_FACTOR
    Serial.print( F( " " ) );
    goto AfterTheMagnifiedPlotted; // B/c this range is superimposed traces, no magnified plot is indicated
#endif
  }
  /*
      else if( masterReadingsArrayIndex < INBOARDS_PLOTTED )
      {
          linespaceParameters[ masterReadingsArray[ masterReadingsArrayIndex ].IndexInlinespaceParametersArray ].LastSignalPinPlotPoint = masterReadingsArray[ masterReadingsArrayIndex ].CurrentUnmagnifiedReading;
          Serial.print( masterReadingsArray[ masterReadingsArrayIndex ].CurrentUnmagnifiedReading + linespaceParameters[ masterReadingsArray[ masterReadingsArrayIndex ].IndexInlinespaceParametersArray ].ZeroOfThisPlotLinespace ); //This is color one
          #ifdef DEBUG
              Serial.println();
              Serial.println( F( "Line 1277 " ) );
          #endif
      }
  */
  else //non-superimposed inboards and all outboards
  {
    linespaceParameters[ masterReadingsArray[ masterReadingsArrayIndex ].IndexInlinespaceParametersArray ].LastSignalPinPlotPoint = masterReadingsArray[ masterReadingsArrayIndex ].CurrentUnmagnifiedReading;
    Serial.print( masterReadingsArray[ masterReadingsArrayIndex ].CurrentUnmagnifiedReading + linespaceParameters[ masterReadingsArray[ masterReadingsArrayIndex ].IndexInlinespaceParametersArray ].ZeroOfThisPlotLinespace ); //This is color one
#if ( ( not defined MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE ) || ( MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE == false ) )
    Serial.print( F( " Unadjusted value=<" ) );
    Serial.print( masterReadingsArray[ masterReadingsArrayIndex ].CurrentUnmagnifiedReading );
    Serial.print( F( ">, scaled to inboard analog input resolution:<" ) );
    Serial.print( masterReadingsArray[ masterReadingsArrayIndex ].CurrentUnmagnifiedReading >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE );
    Serial.print( F( ">" ) );
#endif
#ifdef DEBUG
    Serial.println();
    Serial.println( F( "Line 1285 " ) );
#endif
  }
#ifdef DEBUG
  Serial.print( F( "Line 1368 masterReadingsArrayIndex = " ) );
  Serial.print( masterReadingsArrayIndex );
  Serial.print( F( ", CurrentUnmagnifiedReading = " ) );
  Serial.print( masterReadingsArray[ masterReadingsArrayIndex ].CurrentUnmagnifiedReading );
  Serial.print( F( ", IndexInlinespaceParametersArray = " ) );
  Serial.print( masterReadingsArray[ masterReadingsArrayIndex ].IndexInlinespaceParametersArray );
  Serial.print( F( ", ZeroOfThisPlotLinespace = " ) );
  Serial.println( linespaceParameters[ masterReadingsArray[ masterReadingsArrayIndex ].IndexInlinespaceParametersArray ].ZeroOfThisPlotLinespace );
#endif
  Serial.print( F( " " ) );
#ifdef MAGNIFICATION_FACTOR
  uint32_t thisPlotPoint;
  /*
    SUPERIMPOSE_FIRST_INBOARDS_IN_PAIRS will be one for every pair to superimpose on each other
    INBOARDS_PLOTTED are paired times SUPERIMPOSE_FIRST_INBOARDS_IN_PAIRS, then singled
    OUTBOARDS_PLOTTED is taken at face value
  */
#if defined SUPERIMPOSE_FIRST_INBOARDS_IN_PAIRS
  if( masterReadingsArrayIndex < INDEX_OF_INBOARDS_NOT_SUPERIMPOSED ) goto AfterTheMagnifiedPlotted; //if this is one of the two parallel traces, skip the magnified view
#endif

  //Next lines plot a magnified version.  First, MagnifyAdjustment is determined
  //Next we multiply the difference between PreviousUnmagnifiedReading and this one, and see if it would take the trace out of bounds
  //Derive the next plot point for the case of current CurrentUnmagnifiedReading being less than or equal to the last UnmagnifiedReading
    if( duringDPotAdjusting )
        thisPlotPoint = linespaceParameters[ masterReadingsArray[ masterReadingsArrayIndex ].IndexInlinespaceParametersArray ].LastReferencePinPlotPointOrLastMagnifiedPlotPoint;
    else if( masterReadingsArray[ masterReadingsArrayIndex ].CurrentUnmagnifiedReading > masterReadingsArray[ masterReadingsArrayIndex ].PreviousUnmagnifiedReading ) //new plot point is higher than previous
    {
#ifdef POT_WIPER_TO_THIS_ANALOG_INPUT_PIN_TO_ADJUST_MAGNIFICATION_FACTOR
        thisPlotPoint = linespaceParameters[ masterReadingsArray[ masterReadingsArrayIndex ].IndexInlinespaceParametersArray ].LastReferencePinPlotPointOrLastMagnifiedPlotPoint + ( ( masterReadingsArray[ masterReadingsArrayIndex ].CurrentUnmagnifiedReading - masterReadingsArray[ masterReadingsArrayIndex ].PreviousUnmagnifiedReading ) * ( uint32_t )( ( analogRead( POT_WIPER_TO_THIS_ANALOG_INPUT_PIN_TO_ADJUST_MAGNIFICATION_FACTOR ) / pow( 2, ANALOG_INPUT_BITS_OF_BOARD ) ) * MAGNIFICATION_FACTOR );//new reading was not lower, so correct new plot point
#else
        thisPlotPoint = linespaceParameters[ masterReadingsArray[ masterReadingsArrayIndex ].IndexInlinespaceParametersArray ].LastReferencePinPlotPointOrLastMagnifiedPlotPoint + ( ( masterReadingsArray[ masterReadingsArrayIndex ].CurrentUnmagnifiedReading - masterReadingsArray[ masterReadingsArrayIndex ].PreviousUnmagnifiedReading ) * MAGNIFICATION_FACTOR );//new reading was not lower, so correct new plot point
#endif
        if( thisPlotPoint > HEIGHT_OF_A_PLOT_LINESPACE ) //new plot point is higher than upper limit
            thisPlotPoint = tracespaceToSkipWhenRepositioning;
    }
#ifdef POT_WIPER_TO_THIS_ANALOG_INPUT_PIN_TO_ADJUST_MAGNIFICATION_FACTOR //Arduino only unless a dedicated ADS1115 is used
    else if( ( masterReadingsArray[ masterReadingsArrayIndex ].PreviousUnmagnifiedReading - masterReadingsArray[ masterReadingsArrayIndex ].CurrentUnmagnifiedReading ) * ( uint32_t )( ( analogRead( POT_WIPER_TO_THIS_ANALOG_INPUT_PIN_TO_ADJUST_MAGNIFICATION_FACTOR ) / pow( 2, ANALOG_INPUT_BITS_OF_BOARD ) ) * MAGNIFICATION_FACTOR ) > linespaceParameters[ masterReadingsArray[ masterReadingsArrayIndex ].IndexInlinespaceParametersArray ].LastReferencePinPlotPointOrLastMagnifiedPlotPoint )
#else
    else if( ( masterReadingsArray[ masterReadingsArrayIndex ].PreviousUnmagnifiedReading - masterReadingsArray[ masterReadingsArrayIndex ].CurrentUnmagnifiedReading ) * MAGNIFICATION_FACTOR > linespaceParameters[ masterReadingsArray[ masterReadingsArrayIndex ].IndexInlinespaceParametersArray ].LastReferencePinPlotPointOrLastMagnifiedPlotPoint )
#endif
        thisPlotPoint = negativeTracespaceToSkipWhenRepositioning;
    else
#ifdef POT_WIPER_TO_THIS_ANALOG_INPUT_PIN_TO_ADJUST_MAGNIFICATION_FACTOR
        thisPlotPoint = linespaceParameters[ masterReadingsArray[ masterReadingsArrayIndex ].IndexInlinespaceParametersArray ].LastReferencePinPlotPointOrLastMagnifiedPlotPoint  - ( ( masterReadingsArray[ masterReadingsArrayIndex ].PreviousUnmagnifiedReading - masterReadingsArray[ masterReadingsArrayIndex ].CurrentUnmagnifiedReading ) * ( uint32_t )( ( analogRead( POT_WIPER_TO_THIS_ANALOG_INPUT_PIN_TO_ADJUST_MAGNIFICATION_FACTOR ) / pow( 2, ANALOG_INPUT_BITS_OF_BOARD ) ) * MAGNIFICATION_FACTOR );//new reading was lower but not too much, so correct new plot point
#else
        thisPlotPoint = linespaceParameters[ masterReadingsArray[ masterReadingsArrayIndex ].IndexInlinespaceParametersArray ].LastReferencePinPlotPointOrLastMagnifiedPlotPoint - ( ( masterReadingsArray[ masterReadingsArrayIndex ].PreviousUnmagnifiedReading - masterReadingsArray[ masterReadingsArrayIndex ].CurrentUnmagnifiedReading ) * MAGNIFICATION_FACTOR );//new reading was lower but not too much, so correct new plot point
#endif
        linespaceParameters[ masterReadingsArray[ masterReadingsArrayIndex ].IndexInlinespaceParametersArray ].LastReferencePinPlotPointOrLastMagnifiedPlotPoint = thisPlotPoint;
#if ( ( not defined MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE ) || ( MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE == false ) )
        Serial.print( F( " magnified value: " ) );
#else
        Serial.print( F( " " ) );
#endif
        Serial.print( linespaceParameters[ masterReadingsArray[ masterReadingsArrayIndex ].IndexInlinespaceParametersArray ].ZeroOfThisPlotLinespace + linespaceParameters[ masterReadingsArray[ masterReadingsArrayIndex ].IndexInlinespaceParametersArray ].LastReferencePinPlotPointOrLastMagnifiedPlotPoint );
        Serial.print( F( " " ) );
#if ( ( not defined MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE ) || ( MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE == false ) )
        Serial.print( F( "Unadjusted value=<" ) );
        Serial.print( linespaceParameters[ masterReadingsArray[ masterReadingsArrayIndex ].IndexInlinespaceParametersArray ].LastReferencePinPlotPointOrLastMagnifiedPlotPoint );
        Serial.print( F( ">, scaled to inboard analog input resolution:<" ) );
        Serial.print( linespaceParameters[ masterReadingsArray[ masterReadingsArrayIndex ].IndexInlinespaceParametersArray ].LastReferencePinPlotPointOrLastMagnifiedPlotPoint >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE );
        Serial.print( F( "> " ) );
#endif
#ifdef DEBUG
        Serial.println();
        Serial.println( F( "Line 1356 " ) );
        Serial.println();
#endif
AfterTheMagnifiedPlotted:
#endif
        masterReadingsArray[ masterReadingsArrayIndex ].PreviousUnmagnifiedReading = masterReadingsArray[ masterReadingsArrayIndex ].CurrentUnmagnifiedReading;
#ifdef DEBUG
        Serial.println();
#endif
#ifdef AUTO_BRIDGE_BALANCING
#ifdef MAGNIFICATION_FACTOR
        if( masterReadingsArrayIndex < INDEX_OF_OUTBOARDS ) return; /*TRY TO REMEMBER HOW I INTENDED TO USE THIS RETURN VALUE bestGuessAnalogInputReading( 1 + ( ( masterReadingsArray[ masterReadingsArrayIndex ].IndexInlinespaceParametersArray ) * LEGS_PER_DPOT_STYLE_BRIDGE ) + BIAS_IN_ANALOG_INPUT_BITS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE_BRIDGE0 - bestGuessAnalogInputReading( ( ( masterReadingsArray[ masterReadingsArrayIndex ].IndexInlinespaceParametersArray ) - 2 ) * LEGS_PER_DPOT_STYLE_BRIDGE ) );*/
#else
        if( masterReadingsArrayIndex >= INBOARDS_PLOTTED ) return;/*TRY TO REMEMBER HOW I INTENDED TO USE THIS RETURN VALUE bestGuessAnalogInputReading( 1 + ( masterReadingsArray[ masterReadingsArrayIndex ].IndexInlinespaceParametersArray ) ) + BIAS_IN_ANALOG_INPUT_BITS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE_BRIDGE0 - bestGuessAnalogInputReading( ( ( masterReadingsArray[ masterReadingsArrayIndex ].IndexInlinespaceParametersArray ) - 2 ) * LEGS_PER_DPOT_STYLE_BRIDGE );*/
#endif
                    //bestGuessAnalogInputReading index argument is a bridge...which doesn't exist except with the outboard ADCs
#endif
        return;//only saving the reading, don't plot.  These are just LM334 non-plotted bridges
}

#if defined ( INJECT_DIAGNOSTIC_SQUARE_WAVE_ON_SIGNAL_PIN_OF_SPECIFIED_OUTBOARD_ADC ) || defined ( INJECT_DIAGNOSTIC_SQUARE_WAVE_ON_REFERENCE_PIN_OF_SPECIFIED_OUTBOARD_ADC )
static bool potSquareWaveHighLevel = true;
static uint8_t diagnostSquareWavePlotCycleLoops = 0;
#define DIAGNOSTIC_SQUARE_WAVE_AMPLITUDE 1
void diagnostSquareWave( void )
{ //Adjust active code to amplitude of diagnostSquareWave you need at the moment
    diagnostSquareWavePlotCycleLoops = ( diagnostSquareWavePlotCycleLoops + 1 ) % DIAGNOSTIC_SQUARE_WAVE_TIME_PERIOD;
#ifdef DEBUG
    while( !Serial ); // wait for serial port to connect. Needed for Leonardo's native USB
    Serial.print( F( "Line 2203, diagnostSquareWavePlotCycleLoops = " ) );
    Serial.println( diagnostSquareWavePlotCycleLoops );
#endif
    if( diagnostSquareWavePlotCycleLoops == 0 )
    {
    uint8_t* analogPinArrayTemp = analogPinArray;
    analogPinArray = 0; //the setDPotOrMSBGroupValue functions check this for whether to consider their first argument as a real pin number or as an index to pin number within  analogPinArray[] for auto-carry/borrow (which we don't want right here until it gets perfected)
    //TODO: change all this to simple call to offsetDPotOrMSBGroupValue() and allow change of which ADC
    #ifdef INJECT_DIAGNOSTIC_SQUARE_WAVE_ON_SIGNAL_PIN_OF_SPECIFIED_OUTBOARD_ADC  //SINCE THIS HOLDS WHICH BRIDGE IS OF INTEREST, MULTIPLY IT BY # OF DPOTS PER BRIDGE BUT YOU'LL ALSO HAVE TO ADAPT THE PREPROCESSOR MACRO'D PIN NUMBERS BY HAND
        #ifdef NON_LSB_DPOT_1_B0SIG_PIN
        while( dPotSettings[ 0 ] < DIAGNOSTIC_SQUARE_WAVE_AMPLITUDE ) //then we need to borrow one unit from msb group and add DPOT_RATIO to this
        {
            setDPotOrMSBGroupValue( NON_LSB_DPOT_1_B0SIG_PIN, dPotSettings[ 1 ] - 1 ); dPotSettings[ 1 ]--;
            setDPotOrMSBGroupValue( LSB_DPOT_B0SIG_PIN, dPotSettings[ 0 ] + DPOT_RATIO ); dPotSettings[ 0 ] += DPOT_RATIO;
        }
        #endif
        setDPotOrMSBGroupValue( LSB_DPOT_B0SIG_PIN, dPotSettings[ 0 ] + ( potSquareWaveHighLevel ? DIAGNOSTIC_SQUARE_WAVE_AMPLITUDE : ( 0 - DIAGNOSTIC_SQUARE_WAVE_AMPLITUDE ) ) ); dPotSettings[ 0 ] += ( potSquareWaveHighLevel ? DIAGNOSTIC_SQUARE_WAVE_AMPLITUDE : ( 0 - DIAGNOSTIC_SQUARE_WAVE_AMPLITUDE ) );
    #endif //trap the above if setting tries to go below zero.  goes down first diagnostSquareWave tick
    
    #ifdef INJECT_DIAGNOSTIC_SQUARE_WAVE_ON_REFERENCE_PIN_OF_SPECIFIED_OUTBOARD_ADC
        #ifdef NON_LSB_DPOT_1_B0REF_PIN
        while( dPotSettings[ ( DPOTS_IN_ALL_LM334_BRIDGES > 0 ) ? DPOTS_PER_LM334_LEG : ( DPOTS_IN_ALL_BARE_LEG_BRIDGES > 0 ) ? DPOTS_PER_BRIDGED_BARE_LEG : DPOTS_PER_UNBRIDGED_BARE_LEG ] < DIAGNOSTIC_SQUARE_WAVE_AMPLITUDE )
        {
            setDPotOrMSBGroupValue( NON_LSB_DPOT_1_B0REF_PIN, dPotSettings[ ( ( DPOTS_IN_ALL_LM334_BRIDGES > 0 ) ? DPOTS_PER_LM334_LEG : ( DPOTS_IN_ALL_BARE_LEG_BRIDGES > 0 ) ? DPOTS_PER_BRIDGED_BARE_LEG : DPOTS_PER_UNBRIDGED_BARE_LEG ) + 1 ] - 1 ); dPotSettings[ ( ( DPOTS_IN_ALL_LM334_BRIDGES > 0 ) ? DPOTS_PER_LM334_LEG : ( DPOTS_IN_ALL_BARE_LEG_BRIDGES > 0 ) ? DPOTS_PER_BRIDGED_BARE_LEG : DPOTS_PER_UNBRIDGED_BARE_LEG ) + 1 ]--;
            setDPotOrMSBGroupValue( LSB_DPOT_B0REF_PIN, dPotSettings[ ( DPOTS_IN_ALL_LM334_BRIDGES > 0 ) ? DPOTS_PER_LM334_LEG : ( DPOTS_IN_ALL_BARE_LEG_BRIDGES > 0 ) ? DPOTS_PER_BRIDGED_BARE_LEG : DPOTS_PER_UNBRIDGED_BARE_LEG ] + DPOT_RATIO ); dPotSettings[ ( DPOTS_IN_ALL_LM334_BRIDGES > 0 ) ? DPOTS_PER_LM334_LEG : ( DPOTS_IN_ALL_BARE_LEG_BRIDGES > 0 ) ? DPOTS_PER_BRIDGED_BARE_LEG : DPOTS_PER_UNBRIDGED_BARE_LEG ] += DPOT_RATIO;
        }
        #endif 
        setDPotOrMSBGroupValue( LSB_DPOT_B0REF_PIN, dPotSettings[ ( DPOTS_IN_ALL_LM334_BRIDGES > 0 ) ? DPOTS_PER_LM334_LEG : ( DPOTS_IN_ALL_BARE_LEG_BRIDGES > 0 ) ? DPOTS_PER_BRIDGED_BARE_LEG : DPOTS_PER_UNBRIDGED_BARE_LEG ] + ( !potSquareWaveHighLevel ? DIAGNOSTIC_SQUARE_WAVE_AMPLITUDE : ( 0 - DIAGNOSTIC_SQUARE_WAVE_AMPLITUDE ) ) ); dPotSettings[ ( DPOTS_IN_ALL_LM334_BRIDGES > 0 ) ? DPOTS_PER_LM334_LEG : ( DPOTS_IN_ALL_BARE_LEG_BRIDGES > 0 ) ? DPOTS_PER_BRIDGED_BARE_LEG : DPOTS_PER_UNBRIDGED_BARE_LEG ] += ( !potSquareWaveHighLevel ? DIAGNOSTIC_SQUARE_WAVE_AMPLITUDE : ( 0 - DIAGNOSTIC_SQUARE_WAVE_AMPLITUDE ) );
    #endif //trap the above if setting tries to go below zero
    
    analogPinArray = analogPinArrayTemp; //restore proper value
      potSquareWaveHighLevel = !potSquareWaveHighLevel;
    }
}
#endif

//#ifdef AUTO_BRIDGE_BALANCING
//    static uint16_t counterForTraceOutOfRangeTooLong[ OUTBOARDS_PLOTTED ]; //This is to prevent infinite loop with AUTO_BRIDGE_BALANCING
//#endif

uint32_t oneReadingFromThisOutboardADC( uint8_t whichOutboardADCindex )
{
#if ( HIGHEST_BIT_RES_FROM_HIGHEST_SENSI_OUTBOARD_ADC == 11 ) || ( HIGHEST_BIT_RES_FROM_HIGHEST_SENSI_OUTBOARD_ADC == 15 )
  thisReadingTemp = ads.readADC_SingleEnded( whichOutboardADCindex );
  while( thisReadingTemp > HEIGHT_OF_A_PLOT_LINESPACE ) thisReadingTemp = ads.readADC_SingleEnded( whichOutboardADCindex );
  return thisReadingTemp;
#else
#ifdef DIFFERENTIAL
#if ( HIGHEST_BIT_RES_FROM_HIGHEST_SENSI_OUTBOARD_ADC < 17 )
  return CONVERT_TWOS_COMP_TO_SINGLE_ENDED( ( whichOutboardADCindex == 1 ) ? ads.readADC_Differential_2_3() : ads.readADC_Differential_0_1(), HEIGHT_OF_A_PLOT_LINESPACE - 1, HALF_HEIGHT_OF_A_PLOT_LINESPACE /*0x8000*/ );
#else
#if ( HIGHEST_SENSI_OUTBOARD_ADC_TYPE == HX711 )
  //                                            hx711.power_up();
  return CONVERT_TWOS_COMP_TO_SINGLE_ENDED( hx711.read(), HEIGHT_OF_A_PLOT_LINESPACE - 1/*mask of significant bits 24 or 32, etc*/, HEIGHT_OF_A_PLOT_LINESPACE >> 1 /*0x800000 which bit is sign bit*/ );
  //                                            thisReadingTemp = 0xFFFFFF; //hx711.read_average( 9 );
  //                                            hx711.power_down();
#else
#if ( HIGHEST_SENSI_OUTBOARD_ADC_TYPE == ADS1232 )
#else
#if ( HIGHEST_SENSI_OUTBOARD_ADC_TYPE == ADS1242 )
#else
#if ( HIGHEST_SENSI_OUTBOARD_ADC_TYPE == AD7780 )
#else
#if ( HIGHEST_SENSI_OUTBOARD_ADC_TYPE == AD779x )
#else
#if ( HIGHEST_SENSI_OUTBOARD_ADC_TYPE == MAX211x0 )
#else
#if ( HIGHEST_SENSI_OUTBOARD_ADC_TYPE == LTC2400 )
#else
#if ( HIGHEST_SENSI_OUTBOARD_ADC_TYPE == ADS1231 )
#else
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
}

void readAndPlotFromAllADCsInAndOutboard( uint32_t timingLineLevel, bool duringSetup )
{
#if defined ( INJECT_DIAGNOSTIC_SQUARE_WAVE_ON_SIGNAL_PIN_OF_SPECIFIED_OUTBOARD_ADC ) || defined ( INJECT_DIAGNOSTIC_SQUARE_WAVE_ON_REFERENCE_PIN_OF_SPECIFIED_OUTBOARD_ADC )
    diagnostSquareWave();
#endif
#if ( ( not defined MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE ) || ( MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE == false ) )
  Serial.print( F( " timing line value:" ) );
#endif
  Serial.print( F( " " ) );
  Serial.print( timingLineLevel );
  Serial.print( F( " " ) );
  for( uint8_t inboardPinIndex = 0; inboardPinIndex < INDEX_OF_OUTBOARDS; inboardPinIndex++ )
  {
#ifdef DEBUG
    while( !Serial ); // wait for serial port to connect. Needed for Leonardo's native USB
    //                    Serial.print( F( "analogPinArray = " ) );
    //                    Serial.println( (unsigned long)analogPinArray );
    Serial.print( F( "Reading pin " ) );
    Serial.print( *( analogPinArray + inboardPinIndex ) );
    Serial.print( F( ", level appearing as " ) );
    Serial.print( analogRead( *( analogPinArray + inboardPinIndex ) ) );
    if( inboardPinIndex == 0 )
    {
      Serial.print( F( ", SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE " ) );
      Serial.println( SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE );
    }
    else Serial.println();
#endif
    masterReadingsArray[ inboardPinIndex ].CurrentUnmagnifiedReading = analogRead( *( analogPinArray + inboardPinIndex ) );
#ifdef DEBUG
    while( !Serial ); // wait for serial port to connect. Needed for Leonardo's native USB
    Serial.print( F( "Value was " ) );
    Serial.print( masterReadingsArray[ inboardPinIndex ].CurrentUnmagnifiedReading );
#endif

    for( uint8_t sampleTimes = 1; sampleTimes < SAMPLE_TIMES; sampleTimes++ )
    {
#if ( defined DELAY_TIME_BETWEEN_SAMPLES_MS ) && ( DELAY_TIME_BETWEEN_SAMPLES_MS > 0 )
      delay( DELAY_TIME_BETWEEN_SAMPLES_MS );
#endif
#if ( defined DELAY_TIME_BETWEEN_SAMPLES_US ) && ( DELAY_TIME_BETWEEN_SAMPLES_US > 0 )
      delayMicroseconds( DELAY_TIME_BETWEEN_SAMPLES_US );
#endif
      masterReadingsArray[ inboardPinIndex ].CurrentUnmagnifiedReading += analogRead( *( analogPinArray + inboardPinIndex ) );
    }
#ifdef DEBUG
    while( !Serial ); // wait for serial port to connect. Needed for Leonardo's native USB
    Serial.print( F( ".  Done reading pin " ) );
    Serial.print( *( analogPinArray + inboardPinIndex ) );
    Serial.print( F( ", " ) );
    Serial.print( SAMPLE_TIMES );
    Serial.print( F( " times, total CurrentUnmagnifiedReading now " ) );
    Serial.print( masterReadingsArray[ inboardPinIndex ].CurrentUnmagnifiedReading );
    Serial.print( F( " which should average to " ) );
    Serial.print( masterReadingsArray[ inboardPinIndex ].CurrentUnmagnifiedReading / SAMPLE_TIMES );
    Serial.println( F( ", now plotting one inboard analog input with magnified version offset for proper positioning:" ) );
#endif
    masterReadingsArray[ inboardPinIndex ].CurrentUnmagnifiedReading /= SAMPLE_TIMES;
    masterReadingsArray[ inboardPinIndex ].CurrentUnmagnifiedReading <<= SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE;
  }

#if ( INBOARDS_PLOTTED > 0 ) //plot the inboard analogs first and above from readings in masterReadingsArray
  for( uint8_t inboardPinIndex = 0; inboardPinIndex < INBOARDS_PLOTTED; inboardPinIndex++ )
  { //PLOT_ONLY_THE_SIGNAL_LEG_OF_SUPERIMPOSED_DPOT_LEG_BRIDGE_INBOARDS
    plotTheNormalAndMagnifiedSignals( inboardPinIndex ); // What was I thinking comment: "not permissible to plot the paired/superimposed traces except with odd indices below INDEX_OF_INBOARDS_NOT_SUPERIMPOSED" ?
#ifdef DEBUG                                         // Maybe a single array element holds both reference and signal plots?
    Serial.println();
#endif
  }
#endif

#if ( OUTBOARDS_PLOTTED > 0 )
  for( uint8_t whichOutboardADCindex = 0; whichOutboardADCindex < OUTBOARDS_PLOTTED; whichOutboardADCindex++ )
  {
#if defined LEGS_PER_DPOT_STYLE_BRIDGE
Start_of_addon_ADC_acquisition:
    bool overscaleIsUnfixable = false;
    while( true ) //comes back to here if CurrentUnmagnifiedReading overscales
    {
#endif
        masterReadingsArray[ INDEX_OF_OUTBOARDS + whichOutboardADCindex ].CurrentUnmagnifiedReading = oneReadingFromThisOutboardADC( whichOutboardADCindex );
    #ifdef DEBUG                                         // Maybe a single array element holds both reference and signal plots?
        Serial.print( F( "Read outboard ADC and put reading into masterReadingsArray position " ) );
        Serial.print( INDEX_OF_OUTBOARDS + whichOutboardADCindex );
        Serial.print( F( ", it being " ) );
        Serial.println( masterReadingsArray[ INDEX_OF_OUTBOARDS + whichOutboardADCindex ].CurrentUnmagnifiedReading );
    #endif
#if defined LEGS_PER_DPOT_STYLE_BRIDGE
      break;
    }
#endif
#if ( defined SAMPLE_TIMES ) && ( SAMPLE_TIMES > 0 )
    for( uint8_t sampleTimes = 1; sampleTimes < SAMPLE_TIMES; sampleTimes++ )
    {
 #if ( defined DELAY_TIME_BETWEEN_SAMPLES_MS ) && ( DELAY_TIME_BETWEEN_SAMPLES_MS > 0 )
      delay( DELAY_TIME_BETWEEN_SAMPLES_MS );
 #endif
 #if ( defined DELAY_TIME_BETWEEN_SAMPLES_US ) && ( DELAY_TIME_BETWEEN_SAMPLES_US > 0 )
      delayMicroseconds( DELAY_TIME_BETWEEN_SAMPLES_US );
 #endif
      masterReadingsArray[ INDEX_OF_OUTBOARDS + whichOutboardADCindex ].CurrentUnmagnifiedReading += oneReadingFromThisOutboardADC( whichOutboardADCindex );
#ifdef DEBUG                                         // Maybe a single array element holds both reference and signal plots?
        Serial.print( F( "Read ADC again, now accumulation divided out is " ) );
    Serial.println( masterReadingsArray[ INDEX_OF_OUTBOARDS + whichOutboardADCindex ].CurrentUnmagnifiedReading / ( sampleTimes + 1 ) );
#endif
    }
    masterReadingsArray[ INDEX_OF_OUTBOARDS + whichOutboardADCindex ].CurrentUnmagnifiedReading /= SAMPLE_TIMES;
#endif
    masterReadingsArray[ INDEX_OF_OUTBOARDS + whichOutboardADCindex ].CurrentUnmagnifiedReading = ( masterReadingsArray[ INDEX_OF_OUTBOARDS + whichOutboardADCindex ].CurrentUnmagnifiedReading < HEIGHT_OF_A_PLOT_LINESPACE ) ? masterReadingsArray[ INDEX_OF_OUTBOARDS + whichOutboardADCindex ].CurrentUnmagnifiedReading : HEIGHT_OF_A_PLOT_LINESPACE;
#ifdef DEBUG
    while( !Serial ); // wait for serial port to connect. Needed for Leonardo's native USB
    Serial.print( F( "Line 1687 INDEX_OF_OUTBOARDS = " ) );
    Serial.print( INDEX_OF_OUTBOARDS );
    Serial.print( F( ", whichOutboardADCindex = " ) );
    Serial.println( whichOutboardADCindex );
    Serial.print( F( ", INDEX_OF_OUTBOARDS + whichOutboardADCindex = " ) );
    Serial.println( INDEX_OF_OUTBOARDS + whichOutboardADCindex );
#endif
    plotTheNormalAndMagnifiedSignals( INDEX_OF_OUTBOARDS + whichOutboardADCindex );
  }
#endif
  Serial.println();
}

void blinkMorseCode( char* symbol, uint8_t chars )
{
#ifndef LED_BUILTIN
    #define LED_BUILTIN 13
#endif
    uint16_t dotLength = 95;
    uint16_t symbolSpace = dotLength;
    uint16_t dashLength = dotLength * 4;
    uint16_t letterSpace = dashLength;
    uint16_t wordSpace = ( dotLength * 7 ) - symbolSpace;
    uint16_t messageSpace = wordSpace * 3;
    uint8_t symbolIndex = 0;
    for( uint8_t charIndex = 0; charIndex < chars; charIndex++ )
    {
        for( ; symbol[ symbolIndex ]; symbolIndex++ )
        {
            digitalWrite( LED_BUILTIN, HIGH );
            delay( symbol[ symbolIndex ] == '-' ? dashLength : dotLength );
            digitalWrite( LED_BUILTIN, LOW );
            delay( symbolSpace );
        }
        symbolIndex++;
        digitalWrite( LED_BUILTIN, LOW );
        delay( letterSpace );
    }
}
#if ( DPOT_LEGS > 0 )
void fixMSB_SETTINGSarraysAndMayDistribute( bool mayDistribute = ( bool )analogPinArray )
{
    Serial.print( F( "Entered inside fixMSB_SETTINGSarraysAndMayDistribute()," ) );
  for( dPotLeg = 0; dPotLeg < DPOT_LEGS; dPotLeg++ )
  {
    Serial.print( F( " calling configureFromDPotLeg for leg<" ) );
    configureFromDPotLeg( ); //Req'd before using MSB_SETTINGS_ macros if dPotLeg ever changes in this scope
    Serial.print( dPotLeg );
    Serial.print( F( "> " ) );

//#if not ( ( defined MINIMIZE_COMPILED_SKETCH_SIZE_LEVEL ) && ( MINIMIZE_COMPILED_SKETCH_SIZE_LEVEL == 0 ) )
    Serial.print( F( ". inside fixMSB_SETTINGSarraysAndMayDistribute(), Prefilling Used and Availables for leg<" ) );
    Serial.print( dPotLeg );
    Serial.print( F( "> firstMSBIndexThisLeg=<" ) );
    Serial.print( firstMSBIndexThisLeg );
    Serial.print( F( ">." ) );
    
//#endif
    MSB_SETTINGS_TOTAL_THIS_LEG = 0;
    MSB_SETTINGS_AVAILABLE_THIS_LEG = 0;
    if( dPotsPerThisLeg != dPotsPerThisBridge )
    {
        MSB_SETTINGS_TOTAL_THIS_REFERENCE_LEG = 0;
        MSB_SETTINGS_AVAILABLE_THIS_REFERENCE_LEG = 0;
    }
    //prefill MSB_SETTINGS_TOTAL_THIS_LEG and MSB_SETTINGS_AVAILABLE_THIS_LEG
    for( uint8_t mSBDPot = 0; mSBDPot < mSBsGroupSize; mSBDPot++ )
    { //This loop and its followup instruction merely conforms the afore-cleared two struct elements to reality
        if( dPotsPerThisLeg != dPotsPerThisBridge ) //if this is a bridge
        {
            MSB_SETTINGS_TOTAL_THIS_REFERENCE_LEG += dPotSettings[ firstMSBIndexThisLegReference + mSBDPot ];
        }
        MSB_SETTINGS_TOTAL_THIS_LEG += dPotSettings[ firstMSBIndexThisLeg + mSBDPot ];
        Serial.print( F( "total this MSB group=<" ) );
        Serial.print( MSB_SETTINGS_TOTAL_THIS_LEG );
        Serial.print( F( "> " ) );
    }
    if( dPotsPerThisLeg != dPotsPerThisBridge )
    {
        MSB_SETTINGS_AVAILABLE_THIS_REFERENCE_LEG = ( mSBsGroupSize * MAX_DPOT_SETTG ) - MSB_SETTINGS_TOTAL_THIS_REFERENCE_LEG;
    }
    MSB_SETTINGS_AVAILABLE_THIS_LEG = ( mSBsGroupSize * MAX_DPOT_SETTG ) - MSB_SETTINGS_TOTAL_THIS_LEG;

    Serial.print( F( "Next line distributes MSB DPot settings evenly amongst entire MSB group DPots, so should only be used once per leg and not on LSB DPots. dPotLeg=<" ) );
    Serial.print( dPotLeg );
    Serial.print( F( ">." ) );
    if( mayDistribute )
    {
    //Next lines corrupt dPotLeg and probably firstMSBIndexThisLeg and firstMSBIndexThisLegReference
//TODO: find out why and avoid this damage control code so the problem doesn't happen elsewhere
        setDPotOrMSBGroupValue( firstMSBIndexThisLeg, MSB_SETTINGS_TOTAL_THIS_LEG );
        setDPotOrMSBGroupValue( firstMSBIndexThisLegReference, MSB_SETTINGS_TOTAL_THIS_REFERENCE_LEG ); //This line changes dPotLeg and needs to not do that FIXME
    }
//#if not ( ( defined MINIMIZE_COMPILED_SKETCH_SIZE_LEVEL ) && ( MINIMIZE_COMPILED_SKETCH_SIZE_LEVEL == 0 ) )
    Serial.print( F( "exitted from setDPotOrMSBGroupValue DPOT_LEGS=<" ) );
    Serial.print( DPOT_LEGS );
    Serial.print( F( "> leg<" ) );
    Serial.print( dPotLeg );
    Serial.print( F( "> " ) );
    readAndPlotFromAllADCsInAndOutboard( graphLine ? 0 : PLOTTER_MAX_SCALE );    
  }
//#endif
    Serial.print( F( "Exitting fixMSB_SETTINGSarraysAndMayDistribute()." ) );
}
#endif

void setup()
{
#ifdef WIFI
    //Start wifi here.  If using wifi, _local_ SD card storage becomes critical, so smaller RAM devices become unsuitable
#endif
  Serial.begin( BAUD_TO_SERIAL );
  millisStart = millis();
  while( !Serial && ( millis() - millisStart < 8000 ) ); //Leonardo needs this check
#if ( ANALOG_INPUT_BITS_OF_BOARD != 10 )
        analogReadResolution( ANALOG_INPUT_BITS_OF_BOARD );   //This may very well not be necessary
#endif
#ifdef __LGT8FX8E__
  //    analogReadResolution( 12 );  //I believe this is not necessary
  delay( SECONDS_THAT_A_LGT8FX8E_HARDWARE_SERIAL_NEEDS_TO_COME_UP_WORKING * 1000 );  // Needed by this board for serial to work
  Serial.println( F( "DEBUG is defined." ) );
#endif
#if not ( ( defined MINIMIZE_COMPILED_SKETCH_SIZE_LEVEL ) && ( MINIMIZE_COMPILED_SKETCH_SIZE_LEVEL == 0 ) )
  while( !Serial && ( millis() - millisStart < 8000 ) );
  if( Serial )
  {
      Serial.println( F( VERSION ) );
      Serial.println( F( "Thank you for your interest in learning GWAAM-Sea to cooperate with God" ) );
      Serial.println( F( "bringing His kingdom to earth and His will to be done here as it is in heaven." ) );
      Serial.println( F( "There is no doubt He will eventually answer that prayer of ours...and very, very soon." ) );
      Serial.println();
      Serial.println( F( "This product is normally run in the Serial Plotter, not the Serial Monitor." ) );
      Serial.println( F( "Unless you're interested in this text only output, close this Serial Monitor" ) );
      Serial.println( F( "and open the Serial Plotter instead." ) );
      Serial.println();
      Serial.print( F( "(C)" ) );
      Serial.print( COPYRIGHT_YEAR ); /*To prevent this numeric from becoming part of a plotline we must have a non whitespace character adjacent.  Don't try to whitespace-wrap this numeric or it will affect plotting*/
      Serial.println( F( ", Kenneth L. Anderson, Electronics Technician, BT, BGS, MCSE, RDH (ret'd)  d/b/a A Reviving Civility" ) );
      Serial.println();
  }
#endif
#if ( DPOTS > 0 )
  SPI.begin(); //The CS pin gets specified in the SPI.transfer( CS_pin ) instruction
  SPI.setBitOrder( MSBFIRST );
#endif
#ifdef USING_DUAL_74LV138_DECODERS_FOR_DPOT_CS_LINES
        digitalWrite( FIRST_STAGE_3_TO_8_DECODER_A0_PIN1, HIGH );
    #ifdef FIRST_STAGE_3_TO_8_DECODER_A1_PIN2
        digitalWrite( FIRST_STAGE_3_TO_8_DECODER_A1_PIN2, HIGH );
    #endif 
    #ifdef FIRST_STAGE_3_TO_8_DECODER_A2_PIN3
        digitalWrite( FIRST_STAGE_3_TO_8_DECODER_A2_PIN3, HIGH );
    #endif
    #ifdef FIRST_STAGE_3_TO_8_DECODER_A3_PIN4
        digitalWrite( FIRST_STAGE_3_TO_8_DECODER_A3_PIN4, HIGH );
    #endif
    #ifdef FIRST_STAGE_3_TO_8_DECODER_ENABLE_PIN4
        digitalWrite( FIRST_STAGE_3_TO_8_DECODER_ENABLE_PIN4, HIGH );
    #endif
    #ifdef FINAL_STAGE_3_TO_8_DECODER_A0_PIN1
        digitalWrite( FINAL_STAGE_3_TO_8_DECODER_A0_PIN1, HIGH );
    #endif
    #ifdef FINAL_STAGE_3_TO_8_DECODER_A1_PIN2
        digitalWrite( FINAL_STAGE_3_TO_8_DECODER_A1_PIN2, HIGH );
    #endif
    #ifdef FINAL_STAGE_3_TO_8_DECODER_A2_PIN3
        digitalWrite( FINAL_STAGE_3_TO_8_DECODER_A2_PIN3, HIGH );
    #endif
    #ifdef FINAL_STAGE_3_TO_8_DECODER_ENABLE_PIN4
        digitalWrite( FINAL_STAGE_3_TO_8_DECODER_ENABLE_PIN4, HIGH );
    #endif
#endif
#ifdef LM334_BRIDGES   //This is important to put this first so LM334 get some resistance, but not super important b/c they default to half-setting at power-up, so the only time they MIGHT need this is when the ckt was just merely reset after a previous session that left them setting at zero resistance, but hey...
#if ( LM334_BRIDGES == 1 )
  digitalWrite( SS, HIGH ); //Not needed by slave devices but rather by this board to make it configure itself to be master
  pinMode( SS, OUTPUT );
  for( uint8_t LM334Bridge = 0; LM334Bridge < LM334_BRIDGES; LM334Bridge++ )
  { //This is not scaleable beyond a single LM334_bridge of pots as far as pins, anyway, but at least it will initialize the LM334 digipot arrays to protect the LM334s.  To get valid settingValues beyond the first LM334_bridge, assign them non-looped below this loop for additional LM334_bridges
    dPotPins[ 0 + LM334Bridge ] = LSB_DPOT_B0SIG_PIN;
    dPotSettings[ 0 + LM334Bridge ] = LSB_DPOT_B0SIG_STARTVALUE;  // Storing a copy of the digi pot settingValues in sketch makes it possible to eliminate the MISO pin connection to the data out pins of all digi pots, besides the digi pots data out may not conform strictly to SPI since the MCP41X1 version has one bidirectional data pin
#if not ( ( defined MINIMIZE_COMPILED_SKETCH_SIZE_LEVEL ) && ( MINIMIZE_COMPILED_SKETCH_SIZE_LEVEL == 0 ) )
    Serial.print( F( " Index=<" ) );
    Serial.print( LM334Bridge );
    Serial.print( F( "> pin=<" ) );
    Serial.print( dPotPins[ 0 + LM334Bridge ] );
    Serial.print( F( "> " ) );
#endif
    pinMode( dPotPins[ 0 + LM334Bridge ], OUTPUT );
    digitalWrite( dPotPins[ 0 + LM334Bridge ], HIGH );
    dPotPins[ DPOTS_PER_LM334_LEG + 0 + LM334Bridge ] = LSB_DPOT_B0REF_PIN;
    dPotSettings[ DPOTS_PER_LM334_LEG + 0 + LM334Bridge ] = LSB_DPOT_B0REF_STARTVALUE;
#if not ( ( defined MINIMIZE_COMPILED_SKETCH_SIZE_LEVEL ) && ( MINIMIZE_COMPILED_SKETCH_SIZE_LEVEL == 0 ) )
    Serial.print( F( " Index=<" ) );
    Serial.print( DPOTS_PER_LM334_LEG + 0 + LM334Bridge );
    Serial.print( F( "> pin=<" ) );
    Serial.print( dPotPins[ DPOTS_PER_LM334_LEG + 0 + LM334Bridge ] );
    Serial.print( F( "> " ) );
#endif
    pinMode( dPotPins[ 0 + DPOTS_PER_LM334_LEG + LM334Bridge ], OUTPUT );
    digitalWrite( dPotPins[ 0 + DPOTS_PER_LM334_LEG + LM334Bridge ], HIGH );
#if ( DPOTS_PER_LM334_LEG > 1 )
    dPotPins[ 1 + LM334Bridge ] = NON_LSB_DPOT_1_B0SIG_PIN;
    dPotSettings[ 1 + LM334Bridge ] = NON_LSB_DPOT_1_B0SIG_STARTVALUE;
#if not ( ( defined MINIMIZE_COMPILED_SKETCH_SIZE_LEVEL ) && ( MINIMIZE_COMPILED_SKETCH_SIZE_LEVEL == 0 ) )
    Serial.print( F( " Index=<" ) );
    Serial.print( 1 + LM334Bridge );
    Serial.print( F( "> pin=<" ) );
    Serial.print( dPotPins[ 1 + LM334Bridge ] );
    Serial.print( F( "> " ) );
#endif
    pinMode( dPotPins[ 1 + LM334Bridge ], OUTPUT );
    digitalWrite( dPotPins[ 1 + LM334Bridge ], HIGH );
    dPotPins[ DPOTS_PER_LM334_LEG + 1 + LM334Bridge ] = NON_LSB_DPOT_1_B0REF_PIN;
    dPotSettings[ DPOTS_PER_LM334_LEG + 1 + LM334Bridge ] = NON_LSB_DPOT_1_B0REF_STARTVALUE;
#if not ( ( defined MINIMIZE_COMPILED_SKETCH_SIZE_LEVEL ) && ( MINIMIZE_COMPILED_SKETCH_SIZE_LEVEL == 0 ) )
    Serial.print( F( " Index=<" ) );
    Serial.print( DPOTS_PER_LM334_LEG + 1 + LM334Bridge );
    Serial.print( F( "> pin=<" ) );
    Serial.print( dPotPins[ DPOTS_PER_LM334_LEG + 1 + LM334Bridge ] );
    Serial.print( F( "> " ) );
#endif
    pinMode( dPotPins[ 1 + DPOTS_PER_LM334_LEG + LM334Bridge ], OUTPUT );
    digitalWrite( dPotPins[ 1 + DPOTS_PER_LM334_LEG + LM334Bridge ], HIGH );
#if ( DPOTS_PER_LM334_LEG > 2 )
    dPotPins[ 2 + LM334Bridge ] = NON_LSB_DPOT_2_B0SIG_PIN;
    dPotSettings[ 2 + LM334Bridge ] = NON_LSB_DPOT_2_B0SIG_STARTVALUE;
#if not ( ( defined MINIMIZE_COMPILED_SKETCH_SIZE_LEVEL ) && ( MINIMIZE_COMPILED_SKETCH_SIZE_LEVEL == 0 ) )
    Serial.print( F( " Index=<" ) );
    Serial.print( 2 + LM334Bridge );
    Serial.print( F( "> pin=<" ) );
    Serial.print( dPotPins[ 2 + LM334Bridge ] );
    Serial.print( F( "> " ) );
#endif
    pinMode( dPotPins[ 2 + LM334Bridge ], OUTPUT );
    digitalWrite( dPotPins[ 2 + LM334Bridge ], HIGH );
    dPotPins[ DPOTS_PER_LM334_LEG + 2 + LM334Bridge ] = NON_LSB_DPOT_2_B0REF_PIN;
    dPotSettings[ DPOTS_PER_LM334_LEG + 2 + LM334Bridge ] = NON_LSB_DPOT_2_B0REF_STARTVALUE;
#if not ( ( defined MINIMIZE_COMPILED_SKETCH_SIZE_LEVEL ) && ( MINIMIZE_COMPILED_SKETCH_SIZE_LEVEL == 0 ) )
    Serial.print( F( " Index=<" ) );
    Serial.print( DPOTS_PER_LM334_LEG + 2 + LM334Bridge );
    Serial.print( F( "> pin=<" ) );
    Serial.print( dPotPins[ DPOTS_PER_LM334_LEG + 2 + LM334Bridge ] );
    Serial.print( F( "> " ) );
#endif
#endif
#endif
   pinMode( dPotPins[ 2 + DPOTS_PER_LM334_LEG + LM334Bridge ], OUTPUT );
    digitalWrite( dPotPins[ 2 + DPOTS_PER_LM334_LEG + LM334Bridge ], HIGH );
    //  The way this is built makes the DPots get initialized in reverse order from intuitive
  }
  //To increase capacity, follow the naming pattern above
#if not ( ( defined MINIMIZE_COMPILED_SKETCH_SIZE_LEVEL ) && ( MINIMIZE_COMPILED_SKETCH_SIZE_LEVEL == 0 ) )
  Serial.print( F( "DPot arrays filled " ) );
#endif
#ifndef LEAVE_POT_VALUES_ALONE_DURING_SETUP 
    for( uint8_t dPotIndex = 0; dPotIndex < DPOTS; dPotIndex++) //THIS ASSUMES THE ABOVE CONSTRUCT FILLS BOTH ARRAYS COMPLETELY
    {
#ifdef NUM_DIGITAL_PINS
      if( ( dPotSettings[ dPotIndex ] > MAX_DPOT_SETTG ) || ( dPotPins[ dPotIndex ] > NUM_DIGITAL_PINS ) ) break;  //The protection against arrays not fully set up
#else
      if( dPotSettings[ dPotIndex ] > MAX_DPOT_SETTG ) break;  //The protection against arrays not fully set up
#endif
        writeSettingToAsingleDPot( dPotPins[ dPotIndex ], dPotSettings[ dPotIndex ] );  //b/c the analog pin array not set up, this needs pin numbers like this, not pin indexes
    }
#if not ( ( defined MINIMIZE_COMPILED_SKETCH_SIZE_LEVEL ) && ( MINIMIZE_COMPILED_SKETCH_SIZE_LEVEL == 0 ) )
  Serial.print( F( "DPot pins set up " ) );
#endif
#endif
#elif ( LM334_BRIDGES > 1 )
#error This sketch is not entirely able to handle multiple digipot bridges at this revision level
#endif
#endif
  millisStart = millis();
#if defined LEGS_PER_DPOT_STYLE_BRIDGE
#ifdef DEBUG
  while( !Serial && ( millis() - millisStart < 8000 ) );
  Serial.println( F( "Digi pots set up" ) );
#endif
#endif
#if ( OUTBOARDS_PLOTTED > 0 )
#if !( ARDUINO_ARCH_SAM || ARDUINO_ARCH_SAMD )
  analogReference( DEFAULT ); //This is the voltage level of max bit value on analog input
#else
  analogReference( AR_DEFAULT ); //
#endif
#endif
#ifdef DEBUG
  while( !Serial && ( millis() - millisStart < 8000 ) );
  Serial.print( F( "Starting setup with SDA & SCL & SCK & A4 & A5 & INDEX_OF_OUTBOARDS = " ) );
  Serial.print( SDA );
  Serial.print( F( " & " ) );
  Serial.print( SCL );
  Serial.print( F( " & " ) );
  Serial.print( SCK );
  Serial.print( F( " & " ) );
  Serial.print( A4 );
  Serial.print( F( " & " ) );
  Serial.print( A5 );
  Serial.print( F( " & " ) );
  Serial.println( INDEX_OF_OUTBOARDS );
#ifdef SUPERIMPOSE_FIRST_INBOARDS_IN_PAIRS
  Serial.print( F( "SUPERIMPOSE_FIRST_INBOARDS_IN_PAIRS " ) );
  Serial.println( SUPERIMPOSE_FIRST_INBOARDS_IN_PAIRS );
#else
  Serial.println( F( "SUPERIMPOSE_FIRST_INBOARDS_IN_PAIRS not defined" ) );
#endif
  Serial.print( F( "OUTBOARDS_PLOTTED " ) );
  Serial.println( OUTBOARDS_PLOTTED );
#ifdef LM334_BRIDGES
  Serial.print( F( "LM334_BRIDGES " ) );
  Serial.println( LM334_BRIDGES );
#else
  Serial.println( F( "LM334_BRIDGES not defined" ) );
#endif
#ifdef AUTO_BRIDGE_BALANCING
  Serial.println( F( "AUTO_BRIDGE_BALANCING defined" ) );
#else
  Serial.println( F( "AUTO_BRIDGE_BALANCING not defined" ) );
#endif
  Serial.print( F( "INDEX_OF_INBOARDS_NOT_SUPERIMPOSED " ) );
  Serial.println( INDEX_OF_INBOARDS_NOT_SUPERIMPOSED );
  Serial.print( F( "INDEX_OF_INBOARDS_NOT_PLOTTED " ) );
  Serial.println( INDEX_OF_INBOARDS_NOT_PLOTTED );
  Serial.print( F( "INDEX_OF_OUTBOARDS " ) );
  Serial.println( INDEX_OF_OUTBOARDS );
  Serial.print( F( "NUMBER_OF_LINESPACES " ) );
  Serial.println( NUMBER_OF_LINESPACES );
#endif
  //#ifndef ARDUINO_AVR_DIGISPARKPRO
  //    analogReadResolution( ADC_RES_BIT );
  //#endif
#if ( OUTBOARDS_PLOTTED > 0 )
#if ( HIGHEST_BIT_RES_FROM_HIGHEST_SENSI_OUTBOARD_ADC < 17 )
  //   ads.setGain( GAIN_TWOTHIRDS );  // 2/3x gain +/- 6.144V  1 bit = 3mV      0.1875mV (default)  //The extra ones are here for reference
  ads.setGain( GAIN_ONE );        // 1x gain   +/- 4.096V  1 bit = 2mV      0.125mV  //This allows a simple power rail excitation supply to voltage divider
  //   ads.setGain( GAIN_TWO );        // 2x gain   +/- 2.048V  1 bit = 1mV      0.0625mV
  //   ads.setGain( GAIN_FOUR );       // 4x gain   +/- 1.024V  1 bit = 0.5mV    0.03125mV
  //   ads.setGain( GAIN_EIGHT );      // 8x gain   +/- 0.512V  1 bit = 0.25mV   0.015625mV
  //   ads.setGain( GAIN_SIXTEEN );    // 16x gain  +/- 0.256V  1 bit = 0.125mV  0.0078125mV
  ads.begin();
#else
#if ( HIGHEST_SENSI_OUTBOARD_ADC_TYPE == HX711 )
  /*
    #if defined LEGS_PER_DPOT_STYLE_BRIDGE
        #define MCP4162_POT_BRIDGE_DEPENDENT_ADCS_PRESENT OUTBOARDS_PLOTTED
        #ifdef SUPERIMPOSE_FIRST_INBOARDS_IN_PAIRS
            #define RAIL_TO_RAIL_OR_OTHERWISE_NOT_DIGIPOT_BRIDGE_DEPENDENT_ADCS_PRESENT INBOARDS_PLOTTED
        #endif
    #else
        #define MCP4162_POT_BRIDGE_DEPENDENT_ADCS_PRESENT 0
        #define ( OUTBOARDS_PLOTTED + RAIL_TO_RAIL_OR_OTHERWISE_NOT_DIGIPOT_BRIDGE_DEPENDENT_ADCS_PRESENT INBOARDS_PLOTTED )
    #endif
  */
#ifdef DEBUG
  millisStart = millis();
  while( !Serial && ( millis() - millisStart < 8000 ) );
  //                    Serial.print( F( "MCP4162_POT_BRIDGE_DEPENDENT_ADCS_PRESENT " ) );
  //                    Serial.println( MCP4162_POT_BRIDGE_DEPENDENT_ADCS_PRESENT );
  //                    Serial.print( F( "RAIL_TO_RAIL_OR_OTHERWISE_NOT_DIGIPOT_BRIDGE_DEPENDENT_ADCS_PRESENT " ) );
  //                    Serial.println( RAIL_TO_RAIL_OR_OTHERWISE_NOT_DIGIPOT_BRIDGE_DEPENDENT_ADCS_PRESENT );
#if not ( ( defined MINIMIZE_COMPILED_SKETCH_SIZE_LEVEL ) && ( MINIMIZE_COMPILED_SKETCH_SIZE_LEVEL == 0 ) )
  Serial.print( F( "Initializing HX711..." ) );
#endif
#endif
  /*
     With the library being used, the .begin() method is not needed if the HX711 was declared earlier prior to setup().  The reason I'm doing it here is simply to suggest some measure of future consistency across all ADCs since other ADC libraries may not allow one or the other...
  */
  hx711.begin( PIN_FOR_DATA_TOFROM_HIGHEST_SENSI_ADC, PIN_FOR_CLK_TO_HIGHEST_SENSI_ADC, HIGHEST_SENSI_PGA_GAIN_FACTOR );  // if the third parameter is ommited the default gain value 128 & channel A is used by the library
#ifdef DEBUG
  millisStart = millis();
  while( !Serial && ( millis() - millisStart < 8000 ) ); //We limit the time to wait for serial ready
#if not ( ( defined MINIMIZE_COMPILED_SKETCH_SIZE_LEVEL ) && ( MINIMIZE_COMPILED_SKETCH_SIZE_LEVEL == 0 ) )
  Serial.println( F( "done initializing HX711." ) );
#endif
#endif
#else
#if ( HIGHEST_SENSI_OUTBOARD_ADC_TYPE == ADS1232 )
#else
#if ( HIGHEST_SENSI_OUTBOARD_ADC_TYPE == ADS1242 )
#else
#if ( HIGHEST_SENSI_OUTBOARD_ADC_TYPE == AD7780 )
#else
#if ( HIGHEST_SENSI_OUTBOARD_ADC_TYPE == AD779x )
#else
#if ( HIGHEST_SENSI_OUTBOARD_ADC_TYPE == MAX112x0 )
#else
#if ( HIGHEST_SENSI_OUTBOARD_ADC_TYPE == LTC2400 )
#else
#if ( HIGHEST_SENSI_OUTBOARD_ADC_TYPE == ADS1231 )
#else
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif

#ifdef MAGNIFICATION_FACTOR
  tracespaceToSkipWhenRepositioning = ( HEIGHT_OF_A_PLOT_LINESPACE * PERCENT_OF_LINESPACE_MAGNIFIED_VIEW_SKIPS_WHEN_REPOSITIONED_WHEN_LINESPACE_LIMITS_GET_EXCEEDED ) / 100;
  negativeTracespaceToSkipWhenRepositioning = HEIGHT_OF_A_PLOT_LINESPACE - ( HEIGHT_OF_A_PLOT_LINESPACE * PERCENT_OF_LINESPACE_MAGNIFIED_VIEW_SKIPS_WHEN_REPOSITIONED_WHEN_LINESPACE_LIMITS_GET_EXCEEDED ) / 100;
#endif
  //    if( OUTBOARDS_PLOTTED + INBOARDS_PLOTTED > 1 ) linespaceParameters[ 0 ].ZeroOfThisPlotLinespace = PLOTTER_MAX_SCALE - HEIGHT_OF_A_PLOT_LINESPACE;

#ifdef DEBUG
  while( !Serial );
#if not ( ( defined MINIMIZE_COMPILED_SKETCH_SIZE_LEVEL ) && ( MINIMIZE_COMPILED_SKETCH_SIZE_LEVEL == 0 ) )
  Serial.println( F( "The following numbers count up to the highest index of linespaces to be displayed:" ) );
#endif
#endif
  // INDEX_OF_INBOARDS_NOT_SUPERIMPOSED actually equals the number of InboardSuperimposed exist
  for( uint8_t linespacesIndex = 0; linespacesIndex < NUMBER_OF_LINESPACES; linespacesIndex++ )
  {
    uint8_t masterReadingsArrayIndex;
    if( linespacesIndex == 0 ) masterReadingsArrayIndex = 0;
    if( ( masterReadingsArrayIndex == INDEX_OF_INBOARDS_NOT_PLOTTED ) && ( masterReadingsArrayIndex < INDEX_OF_OUTBOARDS ) )
      //        {
      masterReadingsArrayIndex = INDEX_OF_OUTBOARDS; //whatever members are not plotted get skipped
    //            linespacesIndex--; //ensure this linepsace doesn't get skipped
    //            continue;
    //        }
#ifdef DEBUG
    while( !Serial );
    Serial.print( F( ", Line 1852 linespacesIndex = " ) );
    Serial.print( linespacesIndex );
    Serial.print( F( ", Line 1854 masterReadingsArrayIndex = " ) );
    Serial.print( masterReadingsArrayIndex );
    Serial.print( F( " " ) );
#endif
#ifndef COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG
#define COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG HALF_HEIGHT_OF_A_PLOT_LINESPACE
#endif
    linespaceParameters[ linespacesIndex ].HighLimitOfThisPlotLinespace = ( NUMBER_OF_LINESPACES - linespacesIndex ) * HEIGHT_OF_A_PLOT_LINESPACE;
    linespaceParameters[ linespacesIndex ].ZeroOfThisPlotLinespace = linespaceParameters[ linespacesIndex ].HighLimitOfThisPlotLinespace - HEIGHT_OF_A_PLOT_LINESPACE;
    linespaceParameters[ linespacesIndex ].LastSignalPinPlotPoint = HALF_HEIGHT_OF_A_PLOT_LINESPACE;
    linespaceParameters[ linespacesIndex ].LastReferencePinPlotPointOrLastMagnifiedPlotPoint = HALF_HEIGHT_OF_A_PLOT_LINESPACE;
    masterReadingsArray[ masterReadingsArrayIndex ].PreviousUnmagnifiedReading = masterReadingsArrayIndex < INDEX_OF_OUTBOARDS ? COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG : HALF_HEIGHT_OF_A_PLOT_LINESPACE;
    masterReadingsArray[ masterReadingsArrayIndex ].CurrentUnmagnifiedReading = masterReadingsArrayIndex < INDEX_OF_OUTBOARDS ? COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG : HALF_HEIGHT_OF_A_PLOT_LINESPACE;
    masterReadingsArray[ masterReadingsArrayIndex ].IndexInlinespaceParametersArray = linespacesIndex;
    //                  Note that INDEX_OF_INBOARDS_NOT_SUPERIMPOSED is an index for masterReadingsArray and actually is equal to the number of InboardSuperimposed that exist
    if( linespacesIndex < INDEX_OF_INBOARDS_NOT_SUPERIMPOSED / 2 ) //The two arrays correlate 1:2 until INDEX_OF_INBOARDS_NOT_SUPERIMPOSED
    {
      masterReadingsArray[ masterReadingsArrayIndex + 1 ].PreviousUnmagnifiedReading = COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG;
      masterReadingsArray[ masterReadingsArrayIndex + 1 ].CurrentUnmagnifiedReading = COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG;
      masterReadingsArray[ masterReadingsArrayIndex + 1 ].IndexInlinespaceParametersArray = linespacesIndex;
    }
#ifdef MAGNIFICATION_FACTOR
    else
      linespaceParameters[ linespacesIndex ].MagnifyAdjustment = 0;
#endif
#ifdef DEBUG
    while( !Serial );
    //        Serial.println();
    Serial.print( F( "linespaceParameters[ " ) );
    Serial.print( linespacesIndex );
    Serial.print( F( " ].HighLimitOfThisPlotLinespace == " ) );
    Serial.print( linespaceParameters[ linespacesIndex ].HighLimitOfThisPlotLinespace );
    Serial.print( F( ", ZeroOfThisPlotLinespace == " ) );
    Serial.print( linespaceParameters[ linespacesIndex ].ZeroOfThisPlotLinespace );
    Serial.print( F( ", LastReferencePinPlotPointOrLastMagnifiedPlotPoint == " ) );
    Serial.print( linespaceParameters[ linespacesIndex ].LastReferencePinPlotPointOrLastMagnifiedPlotPoint );
    Serial.print( F( ", PreviousUnmagnifiedReading == " ) );
    Serial.print( masterReadingsArray[ masterReadingsArrayIndex ].PreviousUnmagnifiedReading );
    Serial.print( F( ", CurrentUnmagnifiedReading == " ) );
    Serial.print( masterReadingsArray[ masterReadingsArrayIndex ].CurrentUnmagnifiedReading );
    Serial.print( F( ", IndexInlinespaceParametersArray == " ) );
    Serial.print( masterReadingsArray[ masterReadingsArrayIndex ].IndexInlinespaceParametersArray );
    if( linespacesIndex < INDEX_OF_INBOARDS_NOT_SUPERIMPOSED / 2 )
    {
      Serial.print( F( ", + 1 PreviousUnmagnifiedReading == " ) );
      Serial.print( masterReadingsArray[ masterReadingsArrayIndex + 1 ].PreviousUnmagnifiedReading );
      Serial.print( F( ", + 1 CurrentUnmagnifiedReading == " ) );
      Serial.print( masterReadingsArray[ masterReadingsArrayIndex + 1 ].CurrentUnmagnifiedReading );
      Serial.print( F( ", + 1 IndexInlinespaceParametersArray == " ) );
      Serial.print( masterReadingsArray[ masterReadingsArrayIndex + 1 ].IndexInlinespaceParametersArray );
    }
    Serial.println();
#endif
    masterReadingsArrayIndex++;
    if( linespacesIndex < INDEX_OF_INBOARDS_NOT_SUPERIMPOSED / 2 ) masterReadingsArrayIndex++; //skip the one we had to take care of in this linepsace iteration
  }
#if not ( ( defined MINIMIZE_COMPILED_SKETCH_SIZE_LEVEL ) && ( MINIMIZE_COMPILED_SKETCH_SIZE_LEVEL == 0 ) )
  Serial.print( F( "Plotting rising timing line: " ) );
#endif
  plotTimingLineGoingUp( false ); //The false makes all traces originate at global zero.  It seems to look better that way
  //no calls using analogPinArray can be made prior to now.
  //Next the pin translation table is allocated and filled the Analog Input pins needed
#if not ( ( defined MINIMIZE_COMPILED_SKETCH_SIZE_LEVEL ) && ( MINIMIZE_COMPILED_SKETCH_SIZE_LEVEL == 0 ) )
  Serial.print( F( "malloc'd [" ) );
#endif
#if ( LM334_BRIDGE_LEGS + BARE_BRIDGE_LEGS + BARE_DPOT_LEGS_UNBRIDGED + INBOARDS_PLOTTED > 0 )
  analogPinArray = ( uint8_t * )malloc( max( INBOARDS_PLOTTED, LM334_BRIDGE_LEGS + BARE_BRIDGE_LEGS + BARE_DPOT_LEGS_UNBRIDGED ) );
#if not ( ( defined MINIMIZE_COMPILED_SKETCH_SIZE_LEVEL ) && ( MINIMIZE_COMPILED_SKETCH_SIZE_LEVEL == 0 ) )
  Serial.print( max( INBOARDS_PLOTTED, LM334_BRIDGE_LEGS + BARE_BRIDGE_LEGS + BARE_DPOT_LEGS_UNBRIDGED ) );
#endif
#else
#if not ( ( defined MINIMIZE_COMPILED_SKETCH_SIZE_LEVEL ) && ( MINIMIZE_COMPILED_SKETCH_SIZE_LEVEL == 0 ) )
  Serial.print( 0 );
#endif
#endif
  Serial.println( F( "] bytes ram for the inboard Analog Input pins needed" ) );
#if ( INBOARDS_PLOTTED > 0 ) || ( defined DPOTS )
  //Hereafter is the pattern.  If you have more analog pins, add them according to the pattern.
#ifdef NUM_ANALOG_INPUTS
#ifdef PIN_A0
  for( uint8_t i = 0; i < max( INBOARDS_PLOTTED, LM334_BRIDGE_LEGS + BARE_BRIDGE_LEGS + BARE_DPOT_LEGS_UNBRIDGED ); i++ )
  {
    if( i == 0 )
      *( analogPinArray + i ) = PIN_A0;
#ifdef PIN_A1
    else if( i == 1 )
      *( analogPinArray + i ) = PIN_A1;
#ifdef PIN_A2
    else if( i == 2 )
      *( analogPinArray + i ) = PIN_A2;
#ifdef PIN_A3
    else if( i == 3 )
      *( analogPinArray + i ) = PIN_A3;
#ifdef PIN_A4
    else if( i == 4 )
      *( analogPinArray + i ) = PIN_A4;
#ifdef PIN_A5
    else if( i == 5 )
      *( analogPinArray + i ) = PIN_A5;
#ifdef PIN_A6
    else if( i == 6 )
      *( analogPinArray + i ) = PIN_A6;
#ifdef PIN_A7
    else if( i == 7 )
      *( analogPinArray + i ) = PIN_A7;
#ifdef PIN_A8
    else if( i == 8 )
      *( analogPinArray + i ) = PIN_A8;
#ifdef PIN_A9
    else if( i == 9 )
      *( analogPinArray + i ) = PIN_A9;
#ifdef PIN_A10
    else if( i == 10 )
      *( analogPinArray + i ) = PIN_A10;
#ifdef PIN_A11
    else if( i == 11 )
      *( analogPinArray + i ) = PIN_A11;
#ifdef PIN_A12
    else if( i == 12 )
      *( analogPinArray + i ) = PIN_A12;
#ifdef PIN_A13
    else if( i == 13 )
      *( analogPinArray + i ) = PIN_A13;
#ifdef PIN_A14
    else if( i == 14 )
      *( analogPinArray + i ) = PIN_A14;
#ifdef PIN_A15
    else if( i == 15 )
      *( analogPinArray + i ) = PIN_A15;
#ifdef PIN_A16
    else if( i == 16 )
      *( analogPinArray + i ) = PIN_A16;
#ifdef PIN_A17
    else if( i == 17 )
      *( analogPinArray + i ) = PIN_A17;
#ifdef PIN_A18
    else if( i == 18 )
      *( analogPinArray + i ) = PIN_A18;
#ifdef PIN_A19
    else if( i == 19 )
      *( analogPinArray + i ) = PIN_A19;
#ifdef PIN_A20
    else if( i == 20 )
      *( analogPinArray + i ) = PIN_A20;
#ifdef PIN_A21
    else if( i == 21 )
      *( analogPinArray + i ) = PIN_A21;
#ifdef PIN_A22
    else if( i == 22 )
      *( analogPinArray + i ) = PIN_A22;
#endif //end of PIN_A22 check
#endif //end of PIN_A21 check
#endif //end of PIN_A20 check
#endif //end of PIN_A19 check
#endif //end of PIN_A18 check
#endif //end of PIN_A17 check
#endif //end of PIN_A16 check
#endif //end of PIN_A15 check
#endif //end of PIN_A14 check
#endif //end of PIN_A13 check
#endif //end of PIN_A12 check
#endif //end of PIN_A11 check
#endif //end of PIN_A10 check
#endif //end of PIN_A9 check
#endif //end of PIN_A8 check
#endif //end of PIN_A7 check
#endif //end of PIN_A6 check
#endif //end of PIN_A5 check
#endif //end of PIN_A4 check
#endif //end of PIN_A3 check
#endif //end of PIN_A2 check
#endif //end of PIN_A1 check
  }
#else
  //Some boards don't have good definitions and constants for the analog pins, TTGO XI, for example :-(
#ifdef DEBUG
  while( !Serial ); // wait for serial port to connect. Needed for Leonardo's native USB
  Serial.println( F( "Creating analog pin definitions" ) );
#endif
  for( uint8_t i = 0; i < max( INBOARDS_PLOTTED, LM334_BRIDGE_LEGS + BARE_BRIDGE_LEGS + BARE_DPOT_LEGS_UNBRIDGED ); i++ )
    *( analogPinArray + i ) = i + FIRST_ANALOG_PIN_DIGITAL_NUMBER_FOR_BOARDS_NOT_HAVING_ANALOG_PINS_DEFINED_BY_PIN_A0_TYPE_DEFINES;
#endif //end of PIN_A0 check
#endif
#endif
  while( !Serial /*|| sdcard is online*/); // wait for serial port to connect. Needed for Leonardo's native USB
#ifdef DEBUG
  Serial.println( F( "DEBUG is defined." ) );
  for( uint8_t i = 0; i < max( INBOARDS_PLOTTED, LM334_BRIDGE_LEGS + BARE_BRIDGE_LEGS + BARE_DPOT_LEGS_UNBRIDGED ); i++ )
  {
        Serial.print( F( " analogPinArray[" ) );
        Serial.print( i );
        Serial.print( F( "]=<" ) );
        Serial.print( *( analogPinArray + i ) );
        Serial.print( F( ">" ) );
  }
  for( uint8_t i = 0; i < DPOTS; i++ )
  {
        Serial.print( F( " dPotPins[" ) );
        Serial.print( i );
        Serial.print( F( "]=<" ) );
        Serial.print( *( dPotPins + i ) );
        Serial.print( F( ">" ) );
  }
#endif
//static uint32_t legLSBSettingUnitsTimes100PerAnalogInputUnit[ DPOT_LEGS ];
#if ( DPOTS_IN_ALL_LM334_BRIDGES + DPOTS_IN_ALL_BARE_LEG_BRIDGES + DPOTS_IN_ALL_BARE_LEGS_UNBRIDGED > 0 )
    for( uint8_t legIndex = 0; legIndex < DPOT_LEGS; legIndex++ )
    {
        legLSBSettingUnitsTimes100PerAnalogInputUnit[ legIndex ] = 0; //Will have to remain this way until EEPROM is untilized  //TODO: start with the EEPROM stored legLSBSettingUnitsTimes100PerAnalogInputUnit
        analogInputUnitsTimes100PerMSBLegSettingUnit[ legIndex ] = 0; //Will have to remain this way until EEPROM is untilized  //TODO: start with the EEPROM stored legLSBSettingUnitsTimes100PerAnalogInputUnit
    }
#endif
#ifdef SD_CARD_STORAGE_CS_PIN
    #define SDCARD_FILE_NAME "gwaamc.dat"
   if( !SD.begin( SD_CARD_STORAGE_CS_PIN ) )
   {
    #if not ( ( defined MINIMIZE_COMPILED_SKETCH_SIZE_LEVEL ) && ( MINIMIZE_COMPILED_SKETCH_SIZE_LEVEL == 0 ) )
            Serial.print( F( "Failed SD card initialize code=<" ) );
            Serial.print( SD.begin( SD_CARD_STORAGE_CS_PIN ) );
    #endif
    SDCardFailMsg:
    #if not ( ( defined MINIMIZE_COMPILED_SKETCH_SIZE_LEVEL ) && ( MINIMIZE_COMPILED_SKETCH_SIZE_LEVEL == 0 ) )
            Serial.print( F( ">. Disable definition of SD_CARD_STORAGE_CS_PIN and re-compile or fix the SD card problem" ) );
            Serial.flush();
    #endif
            pinMode( LED_BUILTIN, OUTPUT );
            while( true ) //Ends execution
            {
                const char msg[] = { '.', '.', '.', 0,/*S*/\
                              '-', '.', '.', 0,       /*D*/\
                              0,\
                              '-', '.', '-', '.', 0,  /*C*/\
                              '.', '-', 0,            /*A*/\
                              '.', '-', '.', 0,       /*R*/\
                              '-', '.', '.', 0 };     /*D*/
                blinkMorseCode( msg, 7 );
                delay( 900 ); //without the delays we would have to substitute some no-op semicolons
            } //Ends execution here
       }
       File sdcardFile = SD.open( SDCARD_FILE_NAME, FILE_WRITE );
        if( !sdcardFile )
       {
    #if not ( ( defined MINIMIZE_COMPILED_SKETCH_SIZE_LEVEL ) && ( MINIMIZE_COMPILED_SKETCH_SIZE_LEVEL == 0 ) )
            Serial.print( F( "Failed SD card file " ) );
            Serial.print( F( SDCARD_FILE_NAME ) );
            Serial.print( F( " returned error code from open for write attempt=<" ) );
            Serial.print( SD.open( SDCARD_FILE_NAME, FILE_WRITE ) );
    #endif
                goto SDCardFailMsg;
       }
       sdcardFile.close();
#endif
#if ( not defined __LGT8FX8E__ ) && ( defined DEBUG )
  Serial.print( F( "   Operator convenience delay so operator can prepare as needed..." ) );
  delay( 5000 );
#endif
#ifdef DEBUG
  Serial.println();
  Serial.println( F( "Done delaying for operator convenience or hardware init " ) );
  Serial.println( F( "Some running parameters:" ) );
  Serial.print( F( "analogPinArray=<" ) );
  Serial.print( (unsigned long)analogPinArray );
    Serial.println( F( ">" ) );
#if defined LEGS_PER_DPOT_STYLE_BRIDGE && defined SUPERIMPOSE_FIRST_INBOARDS_IN_PAIRS && ( INBOARDS_PLOTTED < DPOT_LEGS )
  for( uint8_t i = 0; i < DPOT_LEGS; i++ )
#else
  for( uint8_t i = 0; i < INBOARDS_PLOTTED; i++ )
#endif
    {
        Serial.print( F( "<" ) );
        Serial.print( *( analogPinArray + i ) );
        Serial.println( F( ">" ) );
    
      Serial.print( F( "PLOTTER_MAX_SCALE=<" ) );
      Serial.print( PLOTTER_MAX_SCALE );
      Serial.print( F( "> legLSBSettingUnitsTimes100PerAnalogInputUnit[ i ]=<" ) );
      Serial.print( legLSBSettingUnitsTimes100PerAnalogInputUnit[ i ] );
      Serial.print( F( "> and ( uint32_t )( OUTBOARDS_PLOTTED + INBOARDS_PLOTTED )=<" ) );
      Serial.print( ( uint32_t )( OUTBOARDS_PLOTTED + INBOARDS_PLOTTED ) );
        Serial.println( F( ">" ) );
    }
  

  //add other prints here to your liking
  Serial.print( F( "End of " ) );
#endif //end of DEBUG
  //Start of DPot MSB group settings storing for each DPot leg

#if ( DPOT_LEGS > 0 )
#if not ( ( defined MINIMIZE_COMPILED_SKETCH_SIZE_LEVEL ) && ( MINIMIZE_COMPILED_SKETCH_SIZE_LEVEL == 0 ) )
  Serial.print( F( "Entering prefill construct DPOT_LEGS=<" ) );
    Serial.print( DPOT_LEGS );
    Serial.print( F( "> DPOTS_PER_BRIDGED_BARE_LEG=<" ) );
    Serial.print( DPOTS_PER_BRIDGED_BARE_LEG );
    Serial.print( F( "> " ) );
#endif
  Serial.print( F( "Line<3109> Next line only fixes one specific leg, needs two fixed" ) );
    fixMSB_SETTINGSarraysAndMayDistribute();
  Serial.print( F( "Line<3111>" ) );
#endif
#if ( ( defined AUTO_BRIDGE_BALANCING ) && ( defined DIFFERENTIAL ) && ( defined LOOP_COUNTER_LIMIT_THAT_TRACE_IS_ALLOWED_TO_BE_OFF_CENTER ) )
  for( uint8_t bridgeIndex = 0; bridgeIndex < OUTBOARDS_PLOTTED; bridgeIndex++ )
    counterForTraceOutOfRangeTooLong[ bridgeIndex ] = 0;
#endif
//TODO: Retrieve legLSBSettingUnitsPerAnalogInputUnit from EEPROM but verify EEPROM code number first 
#ifdef DEBUG
  Serial.println( F( "initial setup.  Entering calibration setup." ) );
#else
    Serial.println();
#endif
#if not ( ( defined MINIMIZE_COMPILED_SKETCH_SIZE_LEVEL ) && ( MINIMIZE_COMPILED_SKETCH_SIZE_LEVEL == 0 ) )
  while( !Serial ); // wait for serial port to connect. Needed for Leonardo's native USB
  printDPotSettings();
  Serial.print( F( " Setting up LM334 and bare digipot bridge legs after prefill. " ) );
#endif
Serial.print( F( " DPOTS_IN_ALL_LM334_BRIDGES=<" ) );
Serial.print( DPOTS_IN_ALL_LM334_BRIDGES );
Serial.print( F( ">, DPOTS_IN_ALL_BARE_LEG_BRIDGES=<" ) );
Serial.print( DPOTS_IN_ALL_BARE_LEG_BRIDGES );
Serial.print( F( ">, DPOTS_IN_ALL_BARE_LEGS_UNBRIDGED=<" ) );
Serial.print( DPOTS_IN_ALL_BARE_LEGS_UNBRIDGED );
Serial.print( F( ">, LM334_BRIDGES=<" ) );
Serial.print( LM334_BRIDGES );
Serial.print( F( ">, BARE_DPOT_LEG_BRIDGES=<" ) );
Serial.print( BARE_DPOT_LEG_BRIDGES );
Serial.print( F( ">, BARE_DPOT_LEGS_UNBRIDGED=<" ) );
Serial.print( BARE_DPOT_LEGS_UNBRIDGED );
Serial.print( F( ">. " ) );

#if ( DPOTS_IN_ALL_LM334_BRIDGES + DPOTS_IN_ALL_BARE_LEG_BRIDGES + DPOTS_IN_ALL_BARE_LEGS_UNBRIDGED > 0 )
    for( uint8_t legIndex = 0; legIndex < DPOT_LEGS; legIndex++ )
    {
        Serial.print( F( " legLSBSettingUnitsTimes100PerAnalogInputUnit[" ) );
        Serial.print( legIndex );
        Serial.print( F( "]=<" ) );
        Serial.print( legLSBSettingUnitsTimes100PerAnalogInputUnit[ legIndex ] );
        Serial.print( F( ">. " ) );
    }
#endif

#if defined AUTO_BRIDGE_BALANCING && not defined LEAVE_POT_VALUES_ALONE_DURING_SETUP
  for( uint8_t bridge = 0; bridge < LM334_BRIDGES + BARE_DPOT_LEG_BRIDGES; bridge++ )
  { //while( oneReadingFromThisOutboardADC( bridge ) > HALF_HEIGHT_OF_A_PLOT_LINESPACE )
//NO NEED for this setDPotLegMidPoint DOES IT BASED ON THE SECOND ARG:    configureForReferenceLegWithBridgeIndex( uint8_t bridge );
#if not ( ( defined MINIMIZE_COMPILED_SKETCH_SIZE_LEVEL ) && ( MINIMIZE_COMPILED_SKETCH_SIZE_LEVEL == 0 ) )
    while( !Serial ); // wait for serial port to connect. Needed for Leonardo's native USB
    Serial.print( F( "Calling setDPotLegMidPoint() for Legs of bridge <" ) );
    Serial.print( bridge );
    Serial.print( F( ">, reference leg first:" ) );
#endif
//BIAS_IN_ANALOG_INPUT_BITS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE_BRIDGE0
//ADDITIONAL_BIAS_IN_LSB_DPOT_SETTING_POSITION_TO_APPLY_TO_SIGNAL_TRACE_BRIDGE0 0 //To maintain consistent effect with the above, associated macro, this gets applied inverted. This is in lieu of setting by reading the ADCs and zeroing them.

    uint32_t analogLegLevel;
    duringDPotAdjusting = true;
    delay( 20 );
    analogLegLevel = bestGuessAnalogInputReading( ( bridge * 2 ) + 1, MOST_ACCURATE );
    referenceLegLevelFromLastSettingIt[ bridge ] = ( analogLegLevel == COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG ) ? REFERENCE_LEG_LEVEL_IS_OPTIMAL : ( analogLegLevel > COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG ) ? \
    REFERENCE_LEG_LEVEL_IS_HIGH : REFERENCE_LEG_LEVEL_IS_LOW;
    if( referenceLegLevelFromLastSettingIt[ bridge ] != REFERENCE_LEG_LEVEL_IS_OPTIMAL ) //Context is reference leg
    {
        Serial.print( F( "REFERENCE_LEG_LEVEL_IS<" ) );
        Serial.print( analogLegLevel );
        Serial.print( F( ">. " ) );
        setDPotLegMidPoint( bridge, WORK_ON_THE_REFERENCE_LEG, READ_AND_PLOT_IN_EACH_LAP ); // ) //while false, the entire bridge is being zeroed into the desired balance
    }
    else
        Serial.print( F( "REFERENCE_LEG_LEVEL_IS_OPTIMAL. " ) );
    delay( 4 );
    analogLegLevel = bestGuessAnalogInputReading( bridge * 2, MOST_ACCURATE );
    if( analogLegLevel != COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG + BIAS_IN_ANALOG_INPUT_BITS_TO_APPLY_TO_SIGNAL_LEG_TO_CENTER_THE_TRACE_BRIDGE0 ) //Context is signal leg
    {
        Serial.print( F( "SIGNAL_LEG_LEVEL_IS<" ) );
        Serial.print( analogLegLevel );
        Serial.print( F( ">. " ) );
        setDPotLegMidPoint( bridge, !WORK_ON_THE_REFERENCE_LEG, READ_AND_PLOT_IN_EACH_LAP, USE_OPPOSING_LEGS_LEVEL_AS_TARGET_LEVEL ); // ) //while false, the entire bridge is being zeroed into the desired balance
    }
    else
        Serial.print( F( "SIGNAL_LEG_LEVEL_IS_OPTIMAL. " ) );
    configureForSignalLegWithBridgeIndexIncludingNonBridgedLegs( bridge );
#if ( defined ADDITIONAL_BIAS_IN_LSB_DPOT_SETTING_POSITION_TO_APPLY_TO_SIGNAL_TRACE_BRIDGE0 ) && ( ADDITIONAL_BIAS_IN_LSB_DPOT_SETTING_POSITION_TO_APPLY_TO_SIGNAL_TRACE_BRIDGE0 > 0 )
    offsetDPotOrMSBGroupValue( lSBDPotOffsetIndexThisLeg, ADDITIONAL_BIAS_IN_LSB_DPOT_SETTING_POSITION_TO_APPLY_TO_SIGNAL_TRACE_BRIDGE0 );
#endif
/*
#ifdef DIFFERENTIAL
      if( counterForTraceOutOfRangeTooLong[ bridge ]++ > 80 ) break; //Limited to prevent endless looping here
#endif
    }
    */
#if not ( ( defined MINIMIZE_COMPILED_SKETCH_SIZE_LEVEL ) && ( MINIMIZE_COMPILED_SKETCH_SIZE_LEVEL == 0 ) )
    Serial.print( F( "Finished calling setDPotLegMidPoint() both legs of bridge." ) );
#endif
#if ( ( defined AUTO_BRIDGE_BALANCING ) && ( defined DIFFERENTIAL ) )
    uint32_t readingOfADC = oneReadingFromThisOutboardADC( bridge );
    if( ( readingOfADC > 0 ) && ( readingOfADC < HEIGHT_OF_A_PLOT_LINESPACE - 1 ) )
    {
        int16_t retryLimit = 200;
        if( !highestLevelDifferentialBridgeSetpointing( bridge, retryLimit ) )
        {
            Serial.print( F( "Unable to balance bridge<" ) );
            Serial.print( bridge );
            Serial.print( F( ">: intent was that it now be within<" ) );
            Serial.print( retryLimit );
            Serial.print( F( "> LSB DPot setting from center point. Might you have an LSB DPot whose value needs more retries than that?" ) );
        }
    }
    else
    {
        Serial.print( F( "Error level from bridge<" ) );
        Serial.print( bridge );
        Serial.print( F( ": intent was that it now be reading within its range." ) );
    }
#endif
#if ( DPOTS_IN_ALL_LM334_BRIDGES + DPOTS_IN_ALL_BARE_LEG_BRIDGES + DPOTS_IN_ALL_BARE_LEGS_UNBRIDGED > 0 )
#if ( ( defined AUTO_BRIDGE_BALANCING ) && ( defined DIFFERENTIAL ) && ( defined LOOP_COUNTER_LIMIT_THAT_TRACE_IS_ALLOWED_TO_BE_OFF_CENTER ) )
    counterForTraceOutOfRangeTooLong[ bridge ] = 0;  //size of this array is OUTBOARDS_PLOTTED, so there is one member per bridge but needs to be one per dpot bridge plus one per non-bridged dpot leg.  Assume both are the same for now
#endif
//    while( !setDPotLegMidPoint( bridge, !WORK_ON_THE_REFERENCE_LEG, READ_AND_PLOT_IN_EACH_LAP ) ); // == false ) //while false, the entire bridge is being zeroed into the desired balance
/*
#ifdef DIFFERENTIAL
      if( counterForTraceOutOfRangeTooLong[ bridge ]++ > 80 ) break; //Limited to prevent endless looping here
#endif
    }
    */

#if ( ( defined AUTO_BRIDGE_BALANCING ) && ( defined DIFFERENTIAL ) && ( defined LOOP_COUNTER_LIMIT_THAT_TRACE_IS_ALLOWED_TO_BE_OFF_CENTER ) )
    counterForTraceOutOfRangeTooLong[ bridge ] = 0;  //size of this array is OUTBOARDS_PLOTTED, so there is one member per bridge but needs to be one per dpot bridge plus one per non-bridged dpot leg.  Assume both are the same for now
#endif
  }
  for( uint8_t bareUnbridgedLeg = LM334_BRIDGES + BARE_DPOT_LEG_BRIDGES; bareUnbridgedLeg < LM334_BRIDGES + BARE_DPOT_LEG_BRIDGES + BARE_DPOT_LEGS_UNBRIDGED; bareUnbridgedLeg++ )
  {
    setDPotLegMidPoint( bareUnbridgedLeg, !WORK_ON_THE_REFERENCE_LEG, !READ_AND_PLOT_IN_EACH_LAP ); 
  }
#endif
//#if not ( ( defined MINIMIZE_COMPILED_SKETCH_SIZE_LEVEL ) && ( MINIMIZE_COMPILED_SKETCH_SIZE_LEVEL == 0 ) )
  while( !Serial ); // wait for serial port to connect. Needed for Leonardo's native USB
  Serial.println( F( " done setting up digipot bridge legs, now take very first readings since powering on: " ) );
//#endif

  readAndPlotFromAllADCsInAndOutboard( 0, true ); //Fills the arrays with valid values

  //Now could turn on diagnostSquareWave and fine tune to find the common mode voltage to realize greatest gain of the outboard ADC BUT it's not that important!
  //    #else
  //        #ifdef DEBUG
  //            Serial.println( F( "setup." ) );
  //        #endif
#endif //End of auto-balancing aspect of setup()

#if not ( ( defined MINIMIZE_COMPILED_SKETCH_SIZE_LEVEL ) && ( MINIMIZE_COMPILED_SKETCH_SIZE_LEVEL == 0 ) )
  for( uint8_t csIndex = 0; csIndex < DPOTS; csIndex++ )
  {
    Serial.print( F( "dPotSettings[" ) );
    Serial.print( dPotPins[ csIndex ] );
    Serial.print( F( "]=<" ) );
    Serial.print( dPotSettings[ csIndex ] );
    if( csIndex < DPOTS - 1 )
      Serial.print( F( ">,. " ) );
    else
      Serial.print( F( ">,. " ) );
  }
#if ( ( defined SHOW_LINEARITY_USING_THIS_BRIDGE_INDEX ) && (not defined LEAVE_POT_VALUES_ALONE_DURING_SETUP ) )
    Serial.print( F( "Line<3290>Starting linearity diags." ) );
    uint8_t* analogPinArrayTemp = analogPinArray;
#if ( 0 < SHOW_LINEARITY_USING_THIS_BRIDGE_INDEX + 0 )
    configureForSignalLegWithBridgeIndexIncludingNonBridgedLegs( SHOW_LINEARITY_USING_THIS_BRIDGE_INDEX );
#else   
    configureForSignalLegWithBridgeIndexIncludingNonBridgedLegs( 0 );
#endif
    uint16_t lSBSettings[ 2 ];
    lSBSettings[ 0 ] = dPotSettings[ lSBDPotOffsetIndexThisLeg /*LSB of signal leg*/];
    setDPotOrMSBGroupValue( lSBDPotOffsetIndexThisLeg, 0 );           //effect signal leg settings
    lSBSettings[ 1 ] = dPotSettings[ lSBDPotOffsetIndexThisLegReference /*LSB of reference leg*/];
#if ( defined INJECT_DIAGNOSTIC_SQUARE_WAVE_ON_SIGNAL_PIN_OF_SPECIFIED_OUTBOARD_ADC ) || ( defined INJECT_DIAGNOSTIC_SQUARE_WAVE_ON_REFERENCE_PIN_OF_SPECIFIED_OUTBOARD_ADC ) //to avoid a carry or borrow being generated
    setDPotOrMSBGroupValue( lSBDPotOffsetIndexThisLegReference, 1 );  //effect reference leg settings        
#else
    setDPotOrMSBGroupValue( lSBDPotOffsetIndexThisLegReference, 0 );  //effect reference leg settings        
#endif
    uint32_t mSBStartSettingForLinearityTest = 0;
    uint32_t mSBGroupSettings[ 2 ];
    mSBGroupSettings[ 0 ] = MSB_SETTINGS_TOTAL_THIS_LEG;                //store signal leg settings
    mSBGroupSettings[ 1 ] = MSB_SETTINGS_TOTAL_THIS_REFERENCE_LEG;       //store reference leg settings
    analogPinArray = 0; //Doing this prevents the MSB settings from getting distributed throughout the entire MSB group
    uint32_t maxMSBSetting = 200;//MSB_SETTINGS_AVAILABLE_THIS_LEG;
    setDPotOrMSBGroupValue( dPotPins[ firstMSBIndexThisLeg ], mSBStartSettingForLinearityTest );
    dPotSettings[ firstMSBIndexThisLeg ] = mSBStartSettingForLinearityTest;
    setDPotOrMSBGroupValue( dPotPins[ firstMSBIndexThisLegReference ], mSBStartSettingForLinearityTest );
    dPotSettings[ firstMSBIndexThisLegReference ] = mSBStartSettingForLinearityTest;
    for( uint16_t whichMSBindex = 1; whichMSBindex < mSBsGroupSize; whichMSBindex++ )
    {
        setDPotOrMSBGroupValue( dPotPins[ firstMSBIndexThisLeg + whichMSBindex ], 0 );
        dPotSettings[ firstMSBIndexThisLeg ] = 0;
        setDPotOrMSBGroupValue( dPotPins[ firstMSBIndexThisLegReference + whichMSBindex ], 0 );
        dPotSettings[ firstMSBIndexThisLegReference ] = 0;
    }
  Serial.print( F( "Line<3304> Next line only fixes one specific leg, needs two fixed " ) );
    fixMSB_SETTINGSarraysAndMayDistribute();
  Serial.print( F( "Line<3306>" ) );

    
    
    uint16_t j = mSBStartSettingForLinearityTest;
    for( uint16_t whichMSBindex = 0; whichMSBindex < mSBsGroupSize; whichMSBindex++ )
    {
        for( ; j <= MAX_DPOT_SETTG; j++ )
        {
            Serial.print( F( " Line <3278> linearity dPot settings:" ) );
            Serial.print( F( " MSB_SETTINGS_TOTAL_THIS_LEG=<" ) );
            Serial.print( MSB_SETTINGS_TOTAL_THIS_LEG );
            Serial.print( F( "> MSB_SETTINGS_TOTAL_THIS_REFERENCE_LEG=<" ) );
            Serial.print( MSB_SETTINGS_TOTAL_THIS_REFERENCE_LEG );
            Serial.print( F( ">, " ) );


            setDPotOrMSBGroupValue( dPotPins[ firstMSBIndexThisLeg + whichMSBindex ], j );        
            dPotSettings[ firstMSBIndexThisLeg + whichMSBindex ] = j;        
            setDPotOrMSBGroupValue( dPotPins[ firstMSBIndexThisLegReference + whichMSBindex ], j );        
            dPotSettings[ firstMSBIndexThisLegReference + whichMSBindex ] = j;        
            fixMSB_SETTINGSarraysAndMayDistribute( false );
            readAndPlotFromAllADCsInAndOutboard( graphLine ? 0 : PLOTTER_MAX_SCALE );
//            settingStepSize, endLevel, incomingInboardAnalogLevel, targetLevel
//            ( masterReadingsArray[ dPotLeg ].CurrentUnmagnifiedReading >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE )
#ifdef COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG
        //compare leg reading to COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG and capture the first reading making it go lower
            if( !startMSBSettingForCalculatingSettingUnitsPerAnalogInputUnit )
            {
    #if( ( defined HIGHEST_SENSI_OUTBOARD_ADC_TYPE ) && ( HIGHEST_SENSI_OUTBOARD_ADC_TYPE == HX711 ) ) //Notice we don't care if it is actually operating
                if( ( ( dPotLeg < ( LM334_BRIDGE_LEGS + BARE_BRIDGE_LEGS ) ) && \
                ( masterReadingsArray[ dPotLeg ].CurrentUnmagnifiedReading >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE ) < 306 ) || \
                ( ( dPotLeg >= ( LM334_BRIDGE_LEGS + BARE_BRIDGE_LEGS ) ) && \
                ( ( masterReadingsArray[ dPotLeg ].CurrentUnmagnifiedReading >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE ) > 306 ) ) )
    #else
                if( ( ( dPotLeg < ( LM334_BRIDGE_LEGS + BARE_BRIDGE_LEGS ) ) && \
                ( masterReadingsArray[ dPotLeg ].CurrentUnmagnifiedReading >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE ) < COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG ) || \
                ( ( dPotLeg >= ( LM334_BRIDGE_LEGS + BARE_BRIDGE_LEGS ) ) && \
                ( ( masterReadingsArray[ dPotLeg ].CurrentUnmagnifiedReading >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE ) > COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG ) ) )
    #endif
                {
//Save this setting to calculate settingSteps/levelUnits ratios
                    startMSBSettingForCalculatingSettingUnitsPerAnalogInputUnit = MSB_SETTINGS_TOTAL_THIS_LEG;
                    Serial.print( F( "first msb setting to hit desired CM level=<" ) );
                    Serial.print( j );
                    Serial.print( F( "> dPotLeg=<" ) );
                    Serial.print( dPotLeg );
                    Serial.print( F( "> ( masterReadingsArray[ dPotLeg ].CurrentUnmagnifiedReading >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE )=<" ) );
                    Serial.print( ( masterReadingsArray[ dPotLeg ].CurrentUnmagnifiedReading >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE ) );
                    Serial.print( F( "> startMSBSettingForCalculatingSettingUnitsPerAnalogInputUnit=<" ) );
                    Serial.print( startMSBSettingForCalculatingSettingUnitsPerAnalogInputUnit );
                    Serial.print( F( "> MSB_SETTINGS_TOTAL_THIS_LEG=<" ) );
                    Serial.print( MSB_SETTINGS_TOTAL_THIS_LEG );
                    Serial.print( F( "> MSB_SETTINGS_TOTAL_THIS_REFERENCE_LEG=<" ) );
                    Serial.print( MSB_SETTINGS_TOTAL_THIS_REFERENCE_LEG );
                    Serial.print( F( ">, " ) );
//#error Seems like it reaches here too soon
                    break;
            }
    #endif
            Serial.print( F( " Line <3298> linearity dPot settings:" ) );
            for( uint8_t dpotIndex = lSBDPotOffsetIndexThisLeg; dpotIndex < lSBDPotOffsetIndexThisLeg + dPotsPerThisBridge; dpotIndex++)
            {
                Serial.print( F( "dpotIndex<" ) );
                Serial.print( dpotIndex );
                Serial.print( F( ">=<" ) );
                Serial.print( dPotSettings[ dpotIndex ] );
                Serial.print( F( ">, " ) );
            }
        }
#ifdef COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG
        if( startMSBSettingForCalculatingSettingUnitsPerAnalogInputUnit ) break;
        j = 1;
    }
    }
    
    if( !startMSBSettingForCalculatingSettingUnitsPerAnalogInputUnit )
    { //else keep these msbsettings
#endif
        analogPinArray = analogPinArrayTemp; //Goes back to normal: Doing this will cause any subsequent setDPotOrMSBGroupValue() on  firstMSBIndexThisLeg... to distribute settings throughout the entire MSB group
        setDPotOrMSBGroupValue( firstMSBIndexThisLegReference, mSBGroupSettings[ 1 ] );       //reference leg first in case unbridged
        setDPotOrMSBGroupValue( firstMSBIndexThisLeg, mSBGroupSettings[ 0 ] );                //signal leg
#ifdef COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG
    }
    else
    {
       setDPotOrMSBGroupValue( dPotPins[ firstMSBIndexThisLegReference ], ( startMSBSettingForCalculatingSettingUnitsPerAnalogInputUnit - ( ( MAX_DPOT_SETTG / DPOT_RATIO ) / 4 ) ) ); //Division by 4 will place the expected lsb pinpointing in the upper range so as to best minimize the effect of the inconsistent by one starting point
       setDPotOrMSBGroupValue( dPotPins[ firstMSBIndexThisLeg ], ( startMSBSettingForCalculatingSettingUnitsPerAnalogInputUnit - ( ( MAX_DPOT_SETTG / DPOT_RATIO ) / 4 ) ) ); //Division by 4 will place the expected lsb pinpointing in the upper range so as to best minimize the effect of the inconsistent by one starting point
//Save this analogLevel to calculate settingSteps/levelUnits ratios
        delay( 20 ); //Let level settle
        readAndPlotFromAllADCsInAndOutboard( graphLine ? 0 : PLOTTER_MAX_SCALE );
        incomingInboardAnalogLevel = masterReadingsArray[ dPotLeg ].CurrentUnmagnifiedReading >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE;
        analogPinArray = analogPinArrayTemp; //Goes back to normal: Doing this will cause any subsequent setDPotOrMSBGroupValue() on  firstMSBIndexThisLeg... to distribute settings throughout the entire MSB group
    }
#endif
//Done stepping MSB group

    Serial.print( F( " MSB_SETTINGS_TOTAL_THIS_LEG=<" ) );
    Serial.print( MSB_SETTINGS_TOTAL_THIS_LEG );
    Serial.print( F( "> MSB_SETTINGS_TOTAL_THIS_REFERENCE_LEG=<" ) );
    Serial.print( MSB_SETTINGS_TOTAL_THIS_REFERENCE_LEG );
    Serial.print( F( ">, " ) );

//Proceed to step up on LSB

#if ( defined INJECT_DIAGNOSTIC_SQUARE_WAVE_ON_SIGNAL_PIN_OF_SPECIFIED_OUTBOARD_ADC ) || ( defined INJECT_DIAGNOSTIC_SQUARE_WAVE_ON_REFERENCE_PIN_OF_SPECIFIED_OUTBOARD_ADC ) //to avoid a carry or borrow being generated
    for( uint16_t i = 1; i < MAX_DPOT_SETTG - 1; i++ ) //allow margin for square wave to decrement and increment
#else
    for( uint16_t i = 0; i < MAX_DPOT_SETTG; i++ )
#endif
    {
//#if ( ( defined ADDITIONAL_BIAS_IN_LSB_DPOT_SETTING_POSITION_TO_APPLY_TO_SIGNAL_TRACE_BRIDGE0 ) && ( ADDITIONAL_BIAS_IN_LSB_DPOT_SETTING_POSITION_TO_APPLY_TO_SIGNAL_TRACE_BRIDGE0 != 0 ) )
//        setDPotOrMSBGroupValue( lSBDPotOffsetIndexThisLeg, i + ADDITIONAL_BIAS_IN_LSB_DPOT_SETTING_POSITION_TO_APPLY_TO_SIGNAL_TRACE_BRIDGE0 ); //
//#else
        setDPotOrMSBGroupValue( lSBDPotOffsetIndexThisLeg, i );
//#endif
        setDPotOrMSBGroupValue( lSBDPotOffsetIndexThisLegReference, i );
        readAndPlotFromAllADCsInAndOutboard( graphLine ? 0 : PLOTTER_MAX_SCALE );
#ifdef COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG
    if( startMSBSettingForCalculatingSettingUnitsPerAnalogInputUnit )
    {
#if( ( defined HIGHEST_SENSI_OUTBOARD_ADC_TYPE ) && ( HIGHEST_SENSI_OUTBOARD_ADC_TYPE == HX711 ) )
        if( ( ( masterReadingsArray[ dPotLeg ].CurrentUnmagnifiedReading >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE ) == 306 ) && \
        !startLSBSettingForCalculatingSettingUnitsPerAnalogInputUnit )
#else
        if( ( ( masterReadingsArray[ dPotLeg ].CurrentUnmagnifiedReading >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE ) == COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG ) && \
        !startLSBSettingForCalculatingSettingUnitsPerAnalogInputUnit )
#endif
        {
            startLSBSettingForCalculatingSettingUnitsPerAnalogInputUnit = i; //Stores this first find to be later averaged with first miss
            startMSBSettingForCalculatingSettingUnitsPerAnalogInputUnit = 0; //Stops this check
        }
    }
    else if( startLSBSettingForCalculatingSettingUnitsPerAnalogInputUnit )
    {
#if( ( defined HIGHEST_SENSI_OUTBOARD_ADC_TYPE ) && ( HIGHEST_SENSI_OUTBOARD_ADC_TYPE == HX711 ) )
        if( ( masterReadingsArray[ dPotLeg ].CurrentUnmagnifiedReading >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE ) != 306 )
#else
        if( ( masterReadingsArray[ dPotLeg ].CurrentUnmagnifiedReading >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE ) != COMMON_MODE_LEVEL_FOR_MAX_GAIN_AS_READ_RAW_BY_INBOARD_ANALOG )
#endif
        {
#if ( 0 < SHOW_LINEARITY_USING_THIS_BRIDGE_INDEX + 0 )
            legLSBSettingUnitsTimes100PerAnalogInputUnit[ ( SHOW_LINEARITY_USING_THIS_BRIDGE_INDEX * 2 ) - \
            ( ( dPotLeg < ( LM334_BRIDGE_LEGS + BARE_BRIDGE_LEGS ) ) ? 0 : ( dPotLeg - ( LM334_BRIDGE_LEGS + BARE_BRIDGE_LEGS ) ) ) ] = \
            ( 100 * ( ( dPotSettings[ lSBDPotOffsetIndexThisLeg ] - startLSBSettingForCalculatingSettingUnitsPerAnalogInputUnit ) / 2 ) ) / ( incomingInboardAnalogLevel - ( masterReadingsArray[ dPotLeg ].CurrentUnmagnifiedReading >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE ) );
#else
            legLSBSettingUnitsTimes100PerAnalogInputUnit[ 0 ] = ( 100 * ( ( dPotSettings[ lSBDPotOffsetIndexThisLeg ] - startLSBSettingForCalculatingSettingUnitsPerAnalogInputUnit ) / 2 ) ) / ( incomingInboardAnalogLevel - ( masterReadingsArray[ dPotLeg ].CurrentUnmagnifiedReading >> SCALE_FACTOR_TO_PROMOTE_LOW_RES_ADC_TO_SAME_SCALE ) );
#endif
            Serial.print( F( "startLSBSettingForCalculatingSettingUnitsPerAnalogInputUnit=<" ) );
            Serial.print( startLSBSettingForCalculatingSettingUnitsPerAnalogInputUnit );
            Serial.print( F( "> MSB_SETTINGS_TOTAL_THIS_LEG=<" ) );
            Serial.print( MSB_SETTINGS_TOTAL_THIS_LEG );
            Serial.print( F( "> MSB_SETTINGS_TOTAL_THIS_REFERENCE_LEG=<" ) );
            Serial.print( MSB_SETTINGS_TOTAL_THIS_REFERENCE_LEG );
            Serial.print( F( ">, " ) );

            startLSBSettingForCalculatingSettingUnitsPerAnalogInputUnit = 0; //do only after calculating all ratios
        }
    }
#endif
          Serial.print( F( " Line <3321> linearity dPot settings:" ) );
          for( uint8_t dpotIndex = lSBDPotOffsetIndexThisLeg; dpotIndex < lSBDPotOffsetIndexThisLeg + dPotsPerThisBridge; dpotIndex++)
          {
                Serial.print( F( "dpotIndex<" ) );
                Serial.print( dpotIndex );
                Serial.print( F( ">=<" ) );
                Serial.print( dPotSettings[ dpotIndex ] );
                Serial.print( F( ">, " ) );
          }
    }
//Next, reset all of them back to their stored settings
    setDPotOrMSBGroupValue( lSBDPotOffsetIndexThisLeg, lSBSettings[ 0 ] );           //signal leg
    setDPotOrMSBGroupValue( lSBDPotOffsetIndexThisLegReference, lSBSettings[ 1 ] );  //reference leg         

    readAndPlotFromAllADCsInAndOutboard( graphLine ? 0 : PLOTTER_MAX_SCALE );
#endif
  while( !Serial ); // wait for serial port to connect. Needed for Leonardo's native USB
  Serial.print( F( " End of setup() " ) );
#endif
duringDPotAdjusting = false;
}

void loop()
{
#if ( ( not defined MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE ) || ( MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE == false ) )
#if ( DPOTS_IN_ALL_LM334_BRIDGES + DPOTS_IN_ALL_BARE_LEG_BRIDGES + DPOTS_IN_ALL_BARE_LEGS_UNBRIDGED > 0 )
  for( uint8_t csIndex = 0; csIndex < DPOTS; csIndex++ )
  {
    Serial.print( F( "dPotSettings[" ) );
    Serial.print( dPotPins[ csIndex ] );
    Serial.print( F( "]=" ) );
    Serial.print( dPotSettings[ csIndex ] );
    if( csIndex < DPOTS - 1 )
      Serial.print( F( ",. " ) );
    else
      Serial.print( F( ",. " ) );
  }
#endif
#endif
  for( plotterLoops = 0; plotterLoops < 500 / 3; plotterLoops++ )
  {
    millisStart = millis();
    //        if( graphLine ) thisReadingTemp = 0;
    //        else thisReadingTemp = PLOTTER_MAX_SCALE;
    //        Serial.print( thisReadingTemp ); //This was originally last printed in the group.  It needs to be first instead so the line can be "notched" horizontally without needing to reprint all values.
    //        Serial.print( F( " " ) );
    //        readAndPlotFromAllADCsInAndOutboard( thisReadingTemp );
    readAndPlotFromAllADCsInAndOutboard( graphLine ? 0 : PLOTTER_MAX_SCALE );
#ifdef AUTO_BRIDGE_BALANCING //Unsure of how to relate this macro and macro DIFFERENTIAL
    for( uint8_t whichOutboardADCindex = 0; whichOutboardADCindex < OUTBOARDS_PLOTTED; whichOutboardADCindex++ )
    {
      if( masterReadingsArray[ INDEX_OF_OUTBOARDS + whichOutboardADCindex ].CurrentUnmagnifiedReading >= HEIGHT_OF_A_PLOT_LINESPACE - 1 ) //means signal leg is higher
      { ;
#if ( ( not defined MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE ) || ( MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE == false ) )
        Serial.print( F( " reading maxed out " ) );
#endif
#if ( defined DIFFERENTIAL ) && ( defined LOOP_COUNTER_LIMIT_THAT_TRACE_IS_ALLOWED_TO_BE_OFF_CENTER )
        if( --counterForTraceOutOfRangeTooLong[ whichOutboardADCindex ] < -LOOP_COUNTER_LIMIT_THAT_TRACE_IS_ALLOWED_TO_BE_OFF_CENTER )
        {
          //Process: raise reference leg if it is lower than commonmode... level until it reaches commonmode..., then lower signal leg until can't lower it any more, then resume to raise reference leg until can't raise it any more
          //                setSignalBridgeLegInput( whichOutboardADCindex ); // Instead maybe use AdjustBridgeOutput ative( bridge );
#if ( ( not defined MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE ) || ( MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE == false ) )
          Serial.print( F( "for longer than allowed " ) );
#endif
            configureForSignalLegWithBridgeIndexIncludingNonBridgedLegs( whichOutboardADCindex );
          adjustBridgeOutputNegative( whichOutboardADCindex );
          plotterLoops = 0;
        }
#endif
      }
      else if( masterReadingsArray[ INDEX_OF_OUTBOARDS + whichOutboardADCindex ].CurrentUnmagnifiedReading == 0 ) //means reference leg is higher
      { ;
#if ( ( not defined MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE ) || ( MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE == false ) )
        Serial.print( F( " reading zeroed out " ) );
#endif
#if ( defined DIFFERENTIAL ) && ( defined LOOP_COUNTER_LIMIT_THAT_TRACE_IS_ALLOWED_TO_BE_OFF_CENTER )
        if( ++counterForTraceOutOfRangeTooLong[ whichOutboardADCindex ] > LOOP_COUNTER_LIMIT_THAT_TRACE_IS_ALLOWED_TO_BE_OFF_CENTER )
        {
          //Process: lower reference leg if it is higher than commonmode... level until it reaches commonmode..., then raise signal leg until can't raise it any more, then resume to lower reference leg until can't lower it any more
          //                setSignalBridgeLegInput( whichOutboardADCindex ); // Instead maybe use AdjustBridgeOutput ative( bridge );
#if ( ( not defined MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE ) || ( MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE == false ) )
          Serial.print( F( "for longer than allowed " ) );
#endif
            configureForSignalLegWithBridgeIndexIncludingNonBridgedLegs( whichOutboardADCindex );
          adjustBridgeOutputPositive( whichOutboardADCindex );
          plotterLoops = 0;
        }
#endif
      }
#ifdef DIFFERENTIAL
      else
      {
        counterForTraceOutOfRangeTooLong[ whichOutboardADCindex ] = 0;
      }
#endif
    }
#endif
    //        Serial.println();
    /* The following commented code can be used for keyboard input */
#ifdef DEBUG
            char nextChar;
            nextChar = 0;
            while( Serial.available() )
            {
      //            pinMode( LED_BUILTIN, OUTPUT );                // These lines for blinking the LED are here if you want the LED to blink when data is rec'd
      //            digitalWrite( LED_BUILTIN, HIGH );             // These lines for blinking the LED are here if you want the LED to blink when data is rec'd
                nextChar = (char)Serial.read();
                if( nextChar != 0xD && nextChar != 0xA )
                {
                    szFull[ strlen( szFull ) + 1 ] = 0;
                    szFull[ strlen( szFull ) ] = nextChar;
                }
                else
                {
                    if( Serial.available() ) Serial.read();
                    nextChar = 0;
                }
            }
      //        digitalWrite( LED_BUILTIN, LOW );                  // These lines for blinking the LED are here if you want the LED to blink when data is rec'd
            if( !( szFull[ 0 ] == 0 || nextChar != 0 ) )        //The way this and while loop is set up allows reception of lines with no endings but at a timing cost of one loop()
            {
                #ifdef DEBUG
                    while( !Serial ); // wait for serial port to connect. Needed for Leonardo's native USB
                    Serial.print( F( "Received " ) );
                    Serial.println( szFull );
                #endif
        #if defined LEGS_PER_DPOT_STYLE_BRIDGE
                uint8_t DIGITAL_POT_;
                int offset_integer;
                if( szFull[ 1 ] == 'D' || szFull[ 1 ] == 'd' ) szFull[ 1 ] = '-';
                else if( szFull[ 1 ] == 'U' || szFull[ 1 ] == 'u' ) szFull[ 1 ] = '+';
                if( szFull[ 1 ] == '-' )
                {
                    if( szFull[ 2 ] == 0 )
                        offset_integer = -1;
                    else
                        offset_integer = 0 - atoi( &szFull[ 2 ] );
                }
                else if( szFull[ 1 ] == '+' )
                {
                    if( szFull[ 2 ] == 0 )
                        offset_integer = 1;
                    else
                        offset_integer = atoi( &szFull[ 2 ] );
                }
                else goto NoPotChange;
                if( offset_integer > MAX_DPOT_SETTG || offset_integer < 0 - MAX_DPOT_SETTG ) goto NoPotChange;
                if( szFull[ 0 ] == '1' ) DIGITAL_POT_ = dPotPins[ 0 ];
                else if( szFull[ 0 ] == '2' ) DIGITAL_POT_ = dPotPins[ 1 ];
                else if( szFull[ 0 ] == '3' ) DIGITAL_POT_ = dPotPins[ 2 ];
                else if( szFull[ 0 ] == '4' ) DIGITAL_POT_ = dPotPins[ 3 ];
                else if( szFull[ 0 ] == '5' ) DIGITAL_POT_ = dPotPins[ 4 ];
                else if( szFull[ 0 ] == '6' ) DIGITAL_POT_ = dPotPins[ 5 ];
                else goto NoPotChange;
                indexOfThisDPotCSPinInDPotArrays = atoi( &szFull[ 0 ] ) - 1;
                configureFromDPotIndex();
                offsetDPotOrMSBGroupValue( DIGITAL_POT_, offset_integer ); //configureFrom...() and configureFor...() must already be ran
                Serial.print( F( "Dpot " ) );
                Serial.print( DIGITAL_POT_ );
                Serial.print( F( " now set to " ) );
                Serial.println( dPotSettings[ atoi( &szFull[ 0 ] ) ] );
      NoPotChange:
        #endif
                szFull[ 0 ] = 0;
//                #ifdef DEBUG
                    while( !Serial ); // wait for serial port to connect. Needed for Leonardo's native USB
                    Serial.println();
//                #endif
            }
#endif
/*    */
#if defined ( TEST_STEP_UP_DOWN )
    for( uint8_t bridge = 0; bridge < LM334_BRIDGES; bridge++ )
    {
#if ( TEST_STEP_UP_DOWN == SINGLESIDE )
      if( potstepdirection )
      { //adjustBridgeOutputPositive until maxed
        if( !adjustBridgeOutputPositive( bridge ) )
        {
          potstepdirection = false;
          adjustBridgeOutputNegative( bridge );
        }
      }
      else
      {
        if( !adjustBridgeOutputNegative( bridge ) )
        {
          potstepdirection = true;
          adjustBridgeOutputPositive( bridge );
        }
      }
#elif ( TEST_STEP_UP_DOWN == COMMONMODE )
      AdjustWholeBridgeCommonmode( bridge );
#else
      ; //I had a reason for this to be here but I don't recall it while I'm adding this comment.  May be future location for some code or maybe it makes code less susceptible to development bugs for the time being?
#endif
    }
#endif
    for( uint8_t dPotIndex = 0; dPotIndex < DPOTS; dPotIndex++) //THIS ASSUMES THE ABOVE CONSTRUCT FILLS BOTH ARRAYS COMPLETELY
    {
#ifdef NUM_DIGITAL_PINS
      if( ( dPotSettings[ dPotIndex ] > MAX_DPOT_SETTG ) || ( dPotPins[ dPotIndex ] > NUM_DIGITAL_PINS ) ) break;  //The protection against arrays not fully set up
#else
      if( dPotSettings[ dPotIndex ] > MAX_DPOT_SETTG ) break;  //The protection against arrays not fully set up
#endif
        writeSettingToAsingleDPot( dPotPins[ dPotIndex ], dPotSettings[ dPotIndex ] );  //b/c the analog pin array not set up, this needs pin numbers like this, not pin indexes
    }
    while( millis() - millisStart < MIN_WAIT_TIME_BETWEEN_PLOT_POINTS_MS )
    { //acquire and process not-plotted readings of inboard analog pins that get used for digipot auto-balancing FUTURE TODO
      ;//or just wait.
    }
  }
  while( !Serial ); // wait for serial port to connect. Needed for Leonardo's native USB
  if( !graphLine )
  { //going down
    for( uint8_t linespaceParametersIndex = 0; linespaceParametersIndex < NUMBER_OF_LINESPACES; linespaceParametersIndex++ )
    {
#if ( ( not defined MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE ) || ( MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE == false ) )
      Serial.print( F( " upper bounds of this linespace" ) );
#endif
      Serial.print( F( " " ) );
      Serial.print( linespaceParameters[ linespaceParametersIndex ].HighLimitOfThisPlotLinespace );
      replotLastValuesForAllTraces( true );
#if ( ( not defined MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE ) || ( MINIMIZE_COMMUNICATIONS_CLUTTER_FOR_HIGHER_MAX_SPEED_ONLY_COMPATIBLE_FOR_OFFICIAL_ARDUINO_IDE == false ) )
      Serial.print( F( " lower bounds of this linespace " ) );
#endif
      Serial.print( F( " " ) );
      Serial.print( linespaceParameters[ linespaceParametersIndex ].ZeroOfThisPlotLinespace );
      replotLastValuesForAllTraces( true );
    }
  }
  else
    plotTimingLineGoingUp();

  graphLine = !graphLine; // graphLine started as false, so it becomes true here on the first complementing of it
}
