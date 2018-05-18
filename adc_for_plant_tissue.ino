// Before using this sketch, you must set the following appropriately for your configuration and preferences !!!
#define NUM_ANALOG_INPUTS_TO_PLOT 0 //The number of consecutive analog pins to plot, beginning with PIN_A0
#define NUM_ADS1X15_INPUTS_TO_PLOT 1 //The number of consecutive ADS1X15 pins to plot, beginning with A0
#define MULTIPLICATION_FACTOR 15 //To aid in viewing
#define HighestBitResFromADS 15 //This is ADS1115 single-ended, advertised res of 16 bit only applies to double-ended.  all ADC values will get scaled to this, change to 11 for ADS1015
#define SAMPLE_TIMES 9 //To better average out artifacts we over-sample and average.  This value can be tweaked by you to ensure neutralization of power line noise or harmonics of power supplies, etc.....

/*
* 18 May 2018 Anti-aliasing update:  This update has four parts - two definitions here and three small code patches in the sampling area of this sketch which you can locate by searching this sketch for this date
*                                    This update allows you to control the over-sampling periods.  Intent is to spread over samples out evenly for averaging over one period of the fundamental noise wavelength that you choose.
*/
                                                                                           // 18 May 2018 Anti-aliasing update: Definition next line, update is the next two lines only
#define DELAY_TIME_BETWEEN_SAMPLES_MS 0 //COARSE ADJUST  60Hz = 16.667 mS, so if you want oversample averaging to be across a 60 Hz fundamental this definition would be 16 and the next would be 667 less whatever overhead time the code takes on your board
#define DELAY_TIME_BETWEEN_SAMPLES_US 0 //FINE ADJUST.  THIS GETS ADDED TO COARSE ADJUST   // End of this part of code update

#define FIRST_ANALOG_PIN_DIGITAL_NUMBER_FOR_BOARDS_NOT_HAVING_ANALOG_PINS_DEFINED_BY_PIN_A0_TYPE_DEFINES 14 //Some boards don't have good definitions and constants for the analog pins :-(
#define REPOSITION_RATIO_OF_MAGNIFIED_VIEW_WHEN_LIMITS_GET_EXCEEDED (.6) //BETWEEN 0 AND 1 indicating how much of the display region to skip when magnified view trace has to get repositioned because trace would be outside region bounds

//#define DEBUG //Don't forget that DEBUG is not formatted for Serial plotter so plotter can't work when you put the compiler in DEBUG
#define AnalogInputBitsOfBoard 10 //Most Arduino boards are 10-bit resolution, but some can be 12 bits.  For known 12 bit boards (SAM, SAMD and TTGO XI architectures), this gets re-defined below, so generally this can be left as 10 even for those boards
#define SECONDS_THAT_A_LGT8FX8E_HARDWARE_SERIAL_NEEDS_TO_COME_UP_WORKING 9 //8 works only usually
/*******************(C)  COPYRIGHT 2018 KENNETH L ANDERSON *********************
* 
*      ARDUINO ELECTRICAL RESISTANCE/CONDUCTANCE MONITORING SKETCH 
*      
* File Name          : adc_for_plant_tissue.ino
* Author             : KENNETH L ANDERSON
* Version            : v.Free
* Date               : 18-May-2018.  Versions you may have downloaded dated prior to 30 April should be replaced with 30 April 2018 or one more recent.  Revisions more recent than 30 April 2018 do not affect you if your 30 April sketch compiles and plots any inboard analog input pins.  No changes have been made to ADS1X15 operation nor 10-bit operation since 30 April 2018
* Description        : To replicate Cleve Backster's findings that he named "Primary Perception".  Basically, this sketch turns an Arduino MCU and optional (recommended) ADS1115 into a nicely functional poor man's polygraph.
* Boards tested on   : Uno using both ADS1115 and inboard analog inputs.  
*                    : TTGO XI using ADS1115.  
*                    : Many other configurations should work fine.  
*                    : Sadly, TTGO XI 12-bit analog inputs are unsuitable due to their irremoveable pullup conductance.  
*                    : The ATTINY85 is not suitable at all due to not having hardware serial
* 
* Known limitations  : No ability to accept user input from keyboard during run time
*                    : Re-compile is needed for any changes to configuration
*                    : Analog input pins being used MUST be the first available analog inputs
*                    : Some of these limitations will be addressed in future not-for-free versions
*                    
********************************************************************************
* THE PRESENT PRODUCT WHICH IS ONLY FOR USE BY SOFTWARE- AND HARDWARE-COMPETENT USERS
* IS INTENDED TO OFFER VARIOUS CAPABILITIES.  BECAUSE ABSOLUTELY NO CONSIDERATION 
* IS EXPECTED IN RETURN, NO CONTRACT, WHETHER OFFERING SUITABILITY, RELIABILITY, 
* FUNCTIONALITY, SAFETY, OR OTHER, EXISTS.  BY USING THIS PRODUCT YOU EXPRESSLY AND
* TOTALLY ACCEPT FULL LIABILITY FOR ANY DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES 
* WITH RESPECT TO ANY CLAIMS ARISING FROM SOFTWARE AND/OR HARDWARE DERIVATIONS OF PRODUCT.
* I MAKE ABSOLUTELY NO CLAIM OF MY OWN COMPETENCE, LICENSURE, CERTIFICATION, EXPERIENCE,
* OR PROFESSIONAL STANDING OTHER THAN BEING AN ELECTRONICS TECHNICIAN BY FORMAL 
* DEGREE AND UNITED STATES FCC RADIOTELEPHONE OPERATORS LICENSE, AND 
* A SOFTWARE DEVELOPER BY LIMITED PRACTICAL EXPERIENCE, AND BEING FORMALLY
* DEGREED WITH BACHELOR OF GENERAL STUDIES MAJORED IN GENERAL SCIENCES
********************************************************************************
*
* TODO:  Arrange for run-time keyboard input to eliminate need to re-compile when changes are made or plotting adjustments are desired
*        Use an LM334 to prevent power supply noise from plotting (i.e., convert from resistance to conductance)  5 VOLT DEVICES ONLY.   A toroid-based noise suppression coil might be needed.
*        Use digital potentiometer (MCP41XXX or MCP42XXX) for more automated balancing of the two serial resistances.  The charge pump noise generated by the x9c series rules them out.
* 
*  These planned enhancements will be reserved for NOT-FOR-FREE sketch versions in the future
*  
*  Changelog:  30 April 2018 :  Final inboard 10 bit operation and ADS1X15 operation has been achieved.  Future work on free version will be for 12 bit boards only
*              04 May   2018 :  Some 12 bit tweaking so that TTGO/WeMos XI, SAM and SAMD architectures compile with inboard analog inputs to computed at 12 bit even though AnalogInputBitsOfBoard is set at default.
*              08 May   2018 :  Made able to use X9C with LM334
* 
*********************************************************************************************************************/
#define VERSION "v.NOT_Free"

#include <math.h>
#if ( NUM_ADS1X15_INPUTS_TO_PLOT > 0 )
        #include "SPI.h"
/*
*
*  SDA, SCL Wemos XI/TTGO XI are terribly mislabeled in slkscreen on the board!  Use A4 for SDA, and A5 is SCL.
*/
    #include <Adafruit_ADS1015.h>//for systems using ADS1115/ADS1015
    #if ( HighestBitResFromADS == 15 )
        Adafruit_ADS1115 ads;  //For when ADS1115 is being used
    #else
        #if ( HighestBitResFromADS == 11 )
            Adafruit_ADS1015 ads;  //For when ADS1015 is being used
        #else
This ADS resolution is not supported in this sketch version.
        #endif
    #endif
#endif
#if ( NUM_ANALOG_INPUTS_TO_PLOT > 0 )
    #ifndef NUM_ANALOG_INPUTS
Sorry, but you will have to manually define the variable NUM_ANALOG_INPUTS somewhere above this line and re-compile...
    #endif
#else
    #if ( NUM_ADS1X15_INPUTS_TO_PLOT == 0 )
You'll need to manually define at least one of the variables NUM_ANALOG_INPUTS_TO_PLOT or NUM_ADS1X15_INPUTS_TO_PLOT where they appear in the lines above and re-compile...
If you only have the Arduino without an ADS1X15, then define NUM_ANALOG_INPUTS_TO_PLOT.  Otherwise, define NUM_ADS1X15_INPUTS_TO_PLOT and/or both of them.
    #endif
#endif

/*
 * 
 * The following pin defines are for the WeMos XI/TTGO XI board only
 * Change per your board layout
 * 
 */

uint8_t *A_PIN_ARRAY;
struct magnify_adjustment_and_display_zero
{
    unsigned long magnify_adjustment;
    unsigned long zero_of_this_plotline;
    unsigned long high_limit_of_this_plotline;
} typedef magnify_adjustment_and_display_zero;

magnify_adjustment_and_display_zero screen_offsets[ NUM_ADS1X15_INPUTS_TO_PLOT + NUM_ANALOG_INPUTS_TO_PLOT ];
bool graphline = false;
unsigned long value, valueTemp;
#define PlotterMaxScale ( ( ( unsigned long )pow( 2, HighestBitResFromADS ) ) * ( unsigned long )( NUM_ADS1X15_INPUTS_TO_PLOT + NUM_ANALOG_INPUTS_TO_PLOT ) )
#define HundredthPlotterMaxScale ( PlotterMaxScale / 100 );


void setup() 
{
#if ( NUM_ADS1X15_INPUTS_TO_PLOT > 0 ) 
    #if !( ARDUINO_ARCH_SAM || ARDUINO_ARCH_SAMD )
        analogReference( DEFAULT ); //This is the voltage level of max bit value on analog input
    #else
        analogReference( AR_DEFAULT ); //
    #endif
#endif    
//#ifdef __LGT8FX8E__
    Serial.begin( 19200 );//This speed is what works best with WeMos XI/TTGO XI board.
//#else
//    Serial.begin( 57600 );//Is there any reason for this higher speed?  I don't think so, but feel free to put this code back into action if you want to.
//#endif
//#ifndef ARDUINO_AVR_DIGISPARKPRO
//    analogReadResolution( ADC_RES_BIT );
//#endif
#if ( NUM_ADS1X15_INPUTS_TO_PLOT > 0 )
//   ads.setGain(GAIN_TWOTHIRDS);  // 2/3x gain +/- 6.144V  1 bit = 3mV      0.1875mV (default)
   ads.setGain(GAIN_ONE);        // 1x gain   +/- 4.096V  1 bit = 2mV      0.125mV  //This allows a simple power rail excitation supply to voltage divider
//   ads.setGain(GAIN_TWO);        // 2x gain   +/- 2.048V  1 bit = 1mV      0.0625mV
//   ads.setGain(GAIN_FOUR);       // 4x gain   +/- 1.024V  1 bit = 0.5mV    0.03125mV
//   ads.setGain(GAIN_EIGHT);      // 8x gain   +/- 0.512V  1 bit = 0.25mV   0.015625mV
//   ads.setGain(GAIN_SIXTEEN);    // 16x gain  +/- 0.256V  1 bit = 0.125mV  0.0078125mV
    ads.begin();
#endif

#ifdef __LGT8FX8E__
    delay( SECONDS_THAT_A_LGT8FX8E_HARDWARE_SERIAL_NEEDS_TO_COME_UP_WORKING * 1000 );  // Needed by this board for serial to work
//    analogReadResolution( 12 );  //not necessary
#endif
#if ( ARDUINO_ARCH_XI || ARDUINO_ARCH_SAM || ARDUINO_ARCH_SAMD ) //These are the boards known to have 12 bit analog inputs
    #ifdef AnalogInputBitsOfBoard
        #undef AnalogInputBitsOfBoard
    #endif
    #define AnalogInputBitsOfBoard 12  //These boards have 12 bit
#endif

#define BitsToShiftInboardADCValues ( HighestBitResFromADS - AnalogInputBitsOfBoard )

    for( uint8_t i = 0; i < NUM_ADS1X15_INPUTS_TO_PLOT + NUM_ANALOG_INPUTS_TO_PLOT; i++ )
    {
        screen_offsets[ i ].magnify_adjustment = 0;
//where i > NUM_ANALOG_INPUTS_TO_PLOT results in 
        screen_offsets[ i ].high_limit_of_this_plotline = ( unsigned long )pow( 2, HighestBitResFromADS ) * ( i > NUM_ANALOG_INPUTS_TO_PLOT ? ( ( unsigned long )( NUM_ADS1X15_INPUTS_TO_PLOT - i ) ) : ( ( unsigned long )( NUM_ANALOG_INPUTS_TO_PLOT - i ) + ( unsigned long )NUM_ADS1X15_INPUTS_TO_PLOT ) );
        screen_offsets[ i ].zero_of_this_plotline = ( unsigned long )pow( 2, HighestBitResFromADS ) * ( i > NUM_ANALOG_INPUTS_TO_PLOT ? ( ( unsigned long )( NUM_ADS1X15_INPUTS_TO_PLOT - ( i + 1 ) ) ) : ( unsigned long )( NUM_ANALOG_INPUTS_TO_PLOT - ( i + 1 ) ) + ( unsigned long )NUM_ADS1X15_INPUTS_TO_PLOT );
    }
    while ( !Serial ); // wait for serial port to connect. Needed for Leonardo's native USB
    for( uint8_t i = 0; i < NUM_ANALOG_INPUTS_TO_PLOT + NUM_ADS1X15_INPUTS_TO_PLOT; i++ )
    {
        Serial.print( 0 );
        Serial.print( F( " " ) );
        Serial.print( 0 );
        Serial.print( F( " " ) );
    }
//    Serial.println( F( "0" ) );
    Serial.println( PlotterMaxScale );
#if ( NUM_ANALOG_INPUTS_TO_PLOT > 0 )
    uint8_t *A_PIN_ARRAY = (uint8_t *)malloc( NUM_ANALOG_INPUTS );

//Herafter is the pattern.  If you have more analog pins, add them according to the pattern.
#ifdef NUM_ANALOG_INPUTS
#ifdef PIN_A0
    for( uint8_t i = 0; i < NUM_ANALOG_INPUTS_TO_PLOT; i++ )
    {
        if( i == 0 )
            A_PIN_ARRAY[ i ] = PIN_A0;
#ifdef DEBUG  //This is to demonstrate the purpose of DEBUG
    Serial.println( A_PIN_ARRAY[ i ] );
#endif
#ifdef A1
        else if( i == 1 )
            A_PIN_ARRAY[ i ] = PIN_A1;
#ifdef A2
        else if( i == 2 )
            A_PIN_ARRAY[ i ] = PIN_A2;
#ifdef PIN_A3
        else if( i == 3 )
            A_PIN_ARRAY[ i ] = PIN_3;
#ifdef PIN_A4
        else if( i == 4 )
            A_PIN_ARRAY[ i ] = PIN_A4;
#ifdef PIN_A5
        else if( i == 5 )
            A_PIN_ARRAY[ i ] = PIN_A5;
#ifdef PIN_A6
        else if( i == 6 )
            A_PIN_ARRAY[ i ] = PIN_A6;
#ifdef PIN_A7
        else if( i == 7 )
            A_PIN_ARRAY[ i ] = PIN_A7;
#ifdef PIN_A8
        else if( i == 8 )
            A_PIN_ARRAY[ i ] = PIN_A8;
#ifdef PIN_A9
        else if( i == 9 )
            A_PIN_ARRAY[ i ] = PIN_A9;
#ifdef PIN_A10
        else if( i == 10 )
            A_PIN_ARRAY[ i ] = PIN_A10;
#ifdef PIN_A11
        else if( i == 11 )
            A_PIN_ARRAY[ i ] = PIN_A11;
#ifdef PIN_A12
        else if( i == 12 )
            A_PIN_ARRAY[ i ] = PIN_A12;
#ifdef PIN_A13
        else if( i == 13 )
            A_PIN_ARRAY[ i ] = PIN_A13;
#ifdef PIN_A14
        else if( i == 14 )
            A_PIN_ARRAY[ i ] = PIN_A14;
#ifdef PIN_A15
        else if( i == 15 )
            A_PIN_ARRAY[ i ] = PIN_A15;
#ifdef PIN_A16
        else if( i == 16 )
            A_PIN_ARRAY[ i ] = PIN_A16;
#ifdef PIN_A17
        else if( i == 17 )
            A_PIN_ARRAY[ i ] = PIN_A17;
#ifdef PIN_A18
        else if( i == 18 )
            A_PIN_ARRAY[ i ] = PIN_A18;
#ifdef PIN_A19
        else if( i == 19 )
            A_PIN_ARRAY[ i ] = PIN_A19;
#ifdef PIN_A20
        else if( i == 20 )
            A_PIN_ARRAY[ i ] = PIN_A20;
#ifdef PIN_A21
        else if( i == 21 )
            A_PIN_ARRAY[ i ] = PIN_A21;
#ifdef PIN_A22
        else if( i == 22 )
            A_PIN_ARRAY[ i ] = PIN_A22;
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
//Some boards don't have good definitions and constants for the analog pins :-(
    #ifdef DEBUG
            Serial.println( F( "Creating analog pin definitions" ) );
    #endif
    for( uint8_t i = 0; i < NUM_ANALOG_INPUTS_TO_PLOT; i++ )
        A_PIN_ARRAY[ i ] = i + FIRST_ANALOG_PIN_DIGITAL_NUMBER_FOR_BOARDS_NOT_HAVING_ANALOG_PINS_DEFINED_BY_PIN_A0_TYPE_DEFINES;
#endif //end of PIN_A0 check
#endif
#endif
#ifdef DEBUG
        for( uint8_t i = 0; i < NUM_ANALOG_INPUTS_TO_PLOT; i++ )
            Serial.println( A_PIN_ARRAY[ i ] );
        Serial.println( F( "End of setup" ) );
#endif
}

void plot_the_normal_and_magnified_signals( uint8_t i )
{
    value = ( uint16_t )( value / SAMPLE_TIMES );
    Serial.print( value + screen_offsets[ i ].zero_of_this_plotline ); //This is color one
    
    //Next lines plot a magnified version.  First, magnify_adjustment is determined
    Serial.print( F( " " ) );
    
    value *= MULTIPLICATION_FACTOR;

    if( screen_offsets[ i ].magnify_adjustment + screen_offsets[ i ].zero_of_this_plotline > value )
        screen_offsets[ i ].magnify_adjustment = value - screen_offsets[ i ].zero_of_this_plotline - ( ( screen_offsets[ i ].high_limit_of_this_plotline - screen_offsets[ i ].zero_of_this_plotline ) * REPOSITION_RATIO_OF_MAGNIFIED_VIEW_WHEN_LIMITS_GET_EXCEEDED ) ;

    if( screen_offsets[ i ].magnify_adjustment + screen_offsets[ i ].high_limit_of_this_plotline < value )
        screen_offsets[ i ].magnify_adjustment = value - screen_offsets[ i ].high_limit_of_this_plotline + ( ( screen_offsets[ i ].high_limit_of_this_plotline - screen_offsets[ i ].zero_of_this_plotline ) * REPOSITION_RATIO_OF_MAGNIFIED_VIEW_WHEN_LIMITS_GET_EXCEEDED ) ;
        
        //Plot it now
    Serial.print( value - screen_offsets[ i ].magnify_adjustment ); //This is color two or four
    Serial.print( F( " " ) );
}

void loop() 
{    
    for( uint16_t plotter_loops = 0; plotter_loops < 500 / 3; plotter_loops++ ) 
    {
#if ( NUM_ANALOG_INPUTS_TO_PLOT > 0 ) //plot the inboard analogs first and above
        for( uint8_t i = 0; i < NUM_ANALOG_INPUTS_TO_PLOT; i++ )
        {            
            value = analogRead( 14 ) << BitsToShiftInboardADCValues;
//            value = analogRead( *( A_PIN_ARRAY + i ) ) << BitsToShiftInboardADCValues;

            for( uint8_t sampletimes = 1; sampletimes < SAMPLE_TIMES; sampletimes++ )
                  value += ( analogRead( 14 ) << BitsToShiftInboardADCValues );
//                  value += ( analogRead( *( A_PIN_ARRAY + i ) ) << BitsToShiftInboardADCValues );
            plot_the_normal_and_magnified_signals( i );
        }
#endif

#if ( NUM_ADS1X15_INPUTS_TO_PLOT > 0 )
        for( uint8_t i = 0; i < NUM_ADS1X15_INPUTS_TO_PLOT; i++ )
        {
            value = ads.readADC_SingleEnded( i );
            while( value > pow( 2, HighestBitResFromADS ) )
            {
                value = ads.readADC_SingleEnded( i );
            }
/*
* 18 May 2018 Anti-aliasing update:  This update has four parts - one code line below, two code parts shorlty below that, and the two definitions in the definitions area of this sketch which you can locate by searching this sketch for this date
*/
                                                                                           // 18 May 2018 Anti-aliasing update: Code update next one line
#if ( defined SAMPLE_TIMES ) && ( SAMPLE_TIMES > 0 )                                       //End of this part of code update
            for( uint8_t sampletimes = 1; sampletimes < SAMPLE_TIMES; sampletimes++ )
            {
/*
* 18 May 2018 Anti-aliasing update:  This update has four parts - one code part nearby above this, these code lines here, one code part nearby below that, and the two definitions in the definitions area of this sketch which you can locate by searching this sketch for this date
*/
                                                                                           // 18 May 2018 Anti-aliasing update: Code update next six lines
#if ( defined DELAY_TIME_BETWEEN_SAMPLES_MS ) && ( DELAY_TIME_BETWEEN_SAMPLES_MS > 0 )
                delay( DELAY_TIME_BETWEEN_SAMPLES_MS );
#endif
#if ( defined DELAY_TIME_BETWEEN_SAMPLES_US ) && ( DELAY_TIME_BETWEEN_SAMPLES_US > 0 )
                delayMicroseconds( DELAY_TIME_BETWEEN_SAMPLES_US );
#endif                                                                                     //End of this part of code update
                valueTemp = ads.readADC_SingleEnded( i );
                while( valueTemp > pow( 2, HighestBitResFromADS ) ) valueTemp = ads.readADC_SingleEnded( i );
                value += valueTemp;
            }
/*
* 18 May 2018 Anti-aliasing update:  This update has four parts - two code parts nearby above this, one code line here and the two definitions in the definitions area of this sketch which you can locate by searching this sketch for this date
*/
                                                                                           // 18 May 2018 Anti-aliasing update: Code update next one line
#endif                                                                                     //End of this part of code update
            plot_the_normal_and_magnified_signals( i + NUM_ANALOG_INPUTS_TO_PLOT );
        }
#endif
        if( graphline ) valueTemp = 0;
        else valueTemp = PlotterMaxScale;
        Serial.println( valueTemp );
#if ( 12 * ( NUM_ANALOG_INPUTS_TO_PLOT + NUM_ADS1X15_INPUTS_TO_PLOT ) < 110  )
    #define DELAY_TIME ( 110 - ( 12 * ( NUM_ANALOG_INPUTS_TO_PLOT + NUM_ADS1X15_INPUTS_TO_PLOT ) ) )
        delay( DELAY_TIME );
#endif
    }
    graphline = !graphline;
}
