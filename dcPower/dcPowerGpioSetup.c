//###########################################################################
// FILE:	Example_2806xGpioSetup.c
// TITLE:	GPIO Setup Example
//###########################################################################
#include    <header.h>
#include    <extern.h>

void ePwmPortOff()
{
    EALLOW;
    GpioCtrlRegs.GPAMUX1.bit.GPIO0  = 0;  // GPIO0 = PWM1A
    GpioCtrlRegs.GPAMUX1.bit.GPIO1  = 0;  // GPIO1 = PWM1B
    GpioCtrlRegs.GPAMUX1.bit.GPIO2  = 0;  // GPIO2 = PWM2A
    GpioCtrlRegs.GPAMUX1.bit.GPIO3  = 0;  // GPIO3 = PWM2B

    GpioCtrlRegs.GPADIR.bit.GPIO0   = 1;  // GPIO0 = Output
    GpioCtrlRegs.GPADIR.bit.GPIO1   = 1;  // GPIO1 = Output
    GpioCtrlRegs.GPADIR.bit.GPIO2   = 1;  // GPIO2 = Output
    GpioCtrlRegs.GPADIR.bit.GPIO3   = 1;  // GPIO3 = Output

    GpioDataRegs.GPACLEAR.bit.GPIO0 = 1;  // Set Output
    GpioDataRegs.GPACLEAR.bit.GPIO1 = 1;  // Set Output
    GpioDataRegs.GPACLEAR.bit.GPIO2 = 1;  // Set Output
    GpioDataRegs.GPACLEAR.bit.GPIO3 = 1;  // Set Output
    EDIS;
}

void ePwmEnable()
{
    EALLOW;
    GpioCtrlRegs.GPAMUX1.bit.GPIO0  = 1;            // GPIO0    = PWM1A
    GpioCtrlRegs.GPAMUX1.bit.GPIO1  = 1;            // GPIO1    = PWM1B
    GpioCtrlRegs.GPAMUX1.bit.GPIO2  = 1;            // GPIO2    = PWM2A
    GpioCtrlRegs.GPAMUX1.bit.GPIO3  = 1;            // GPIO3    = PWM2B
    EDIS;
}

void InitGpio(void)
{
    EALLOW;
//--- pwm 0, 1, 2, 3
    GpioCtrlRegs.GPAPUD.bit.GPIO0 = 0;   // Enable pullup on GPIO0
    GpioCtrlRegs.GPAPUD.bit.GPIO1 = 0;   // Enable pullup on GPIO1
    GpioCtrlRegs.GPAPUD.bit.GPIO2 = 0;   // Enable pullup on GPIO2
    GpioCtrlRegs.GPAPUD.bit.GPIO3 = 0;   // Enable pullup on GPIO3
    GpioCtrlRegs.GPAMUX1.bit.GPIO0 = 1;  // GPIO0 = PWM1A
    GpioCtrlRegs.GPAMUX1.bit.GPIO1 = 1;  // GPIO1 = PWM1B
    GpioCtrlRegs.GPAMUX1.bit.GPIO2 = 1;  // GPIO2 = PWM2A
    GpioCtrlRegs.GPAMUX1.bit.GPIO3 = 1;  // GPIO3 = PWM2B

//--- open output 4,5,6
    GpioCtrlRegs.GPAPUD.bit.GPIO4 = 0;   // Enable pullup on GPIO4
    GpioCtrlRegs.GPAPUD.bit.GPIO5 = 0;   // Enable pullup on GPIO5
    GpioCtrlRegs.GPAPUD.bit.GPIO6 = 0;   // DB-pulse
    GpioCtrlRegs.GPAMUX1.bit.GPIO4 = 0;  // GPIO
    GpioCtrlRegs.GPAMUX1.bit.GPIO5 = 0;  // GPIO
    GpioCtrlRegs.GPAMUX1.bit.GPIO6 = 0;  //--- GPIO6 = PWM4A
    GpioCtrlRegs.GPADIR.bit.GPIO4 = 1;   //--- GPIO7 = output
    GpioCtrlRegs.GPADIR.bit.GPIO5 = 1;   //--- GPIO7 = output
    GpioCtrlRegs.GPADIR.bit.GPIO6 = 1;   //--- GPIO7 = output

//--- gpio7 gate enable
    GpioCtrlRegs.GPAPUD.bit.GPIO7 = 0;   // Enable pullup
    GpioDataRegs.GPASET.bit.GPIO7 = 1;   // Load output latch
    GpioCtrlRegs.GPAMUX1.bit.GPIO7 = 0;  // gateEnable
    GpioCtrlRegs.GPADIR.bit.GPIO7 = 1;   //--- GPIO7 = output
//--- gpio8 tlp181 ext_out
    GpioCtrlRegs.GPAPUD.bit.GPIO8 = 0;   // Enable pullup on GPIO8
    GpioDataRegs.GPASET.bit.GPIO8 = 1;   // Load output latch
    GpioCtrlRegs.GPAMUX1.bit.GPIO8 = 0;  // signal2
    GpioCtrlRegs.GPADIR.bit.GPIO8 = 1;   //--- GPIO8 = output
//--- gpio9 open output
    GpioCtrlRegs.GPAPUD.bit.GPIO9 = 0;   // Enable pullup on GPIO9
    GpioDataRegs.GPASET.bit.GPIO9 = 1;   // Load output latch
    GpioCtrlRegs.GPAMUX1.bit.GPIO9 = 0;  // reserved
    GpioCtrlRegs.GPADIR.bit.GPIO9 = 1;   //--- GPIO9 = output
//---gpio10 mainRelayOn
    GpioCtrlRegs.GPAPUD.bit.GPIO10 = 0;  // Enable pullup on GPIO10
    GpioDataRegs.GPACLEAR.bit.GPIO10= 1; // output clear
    GpioCtrlRegs.GPAMUX1.bit.GPIO10 = 0; //--- mainRelayOn
    GpioCtrlRegs.GPADIR.bit.GPIO10 = 1;  // GPIO10 = output
//---gpio11 relayTripOut
    GpioCtrlRegs.GPAPUD.bit.GPIO11 = 0;  // Enable pullup on GPIO11
    GpioDataRegs.GPACLEAR.bit.GPIO11= 1; // output clear
    GpioCtrlRegs.GPAMUX1.bit.GPIO11 = 0; //--- relayTripOut
    GpioCtrlRegs.GPADIR.bit.GPIO11 = 1;  // GPIO11 = output
//--- gpio12 startInput
    GpioCtrlRegs.GPAPUD.bit.GPIO12 = 0;   // Enable pullup on GPIO12
    GpioCtrlRegs.GPAQSEL1.bit.GPIO12 = 3; // asynch input
    GpioCtrlRegs.GPAMUX1.bit.GPIO12 = 0;  //--- startInput
    GpioCtrlRegs.GPADIR.bit.GPIO12 = 0;   // GPIO12 = Input

//--- gpio13,14,15,16 openOutput
    GpioCtrlRegs.GPAPUD.bit.GPIO13  = 0;  // Enable pullup on GPIO13
    GpioDataRegs.GPACLEAR.bit.GPIO13= 1;  // output clear
    GpioCtrlRegs.GPAMUX1.bit.GPIO13 = 0;  // GPIO13 = TZ1
    GpioCtrlRegs.GPADIR.bit.GPIO13  = 1;  // GPIO13 = output

    GpioCtrlRegs.GPAPUD.bit.GPIO14  = 0;   // Enable pullup
    GpioDataRegs.GPACLEAR.bit.GPIO14= 1; // output clear
    GpioCtrlRegs.GPAMUX1.bit.GPIO14 = 0;   // gpio
    GpioCtrlRegs.GPADIR.bit.GPIO14  = 1;   // output

    GpioCtrlRegs.GPAPUD.bit.GPIO15  = 0; // Enable pullup
    GpioDataRegs.GPACLEAR.bit.GPIO15= 1; // output clear
    GpioCtrlRegs.GPAMUX1.bit.GPIO15 = 0; // gpio
    GpioCtrlRegs.GPADIR.bit.GPIO15  = 1; // output

    GpioCtrlRegs.GPAPUD.bit.GPIO16  = 0; // Enable pullup
    GpioDataRegs.GPACLEAR.bit.GPIO16= 1; // output clear
    GpioCtrlRegs.GPAMUX2.bit.GPIO16 = 0; // gpio
    GpioCtrlRegs.GPADIR.bit.GPIO16  = 1; // output

//--- gpio17 output epWriteProtect
    GpioCtrlRegs.GPAPUD.bit.GPIO17  = 0;  // Enable pullup
    GpioDataRegs.GPASET.bit.GPIO17  = 1;  // write protected, output high
    GpioCtrlRegs.GPAMUX2.bit.GPIO17 = 0;  //
    GpioCtrlRegs.GPADIR.bit.GPIO17  = 1;  // output

//--- gpio18 high side IGBT fault pwm0, button1
    GpioCtrlRegs.GPAPUD.bit.GPIO18 = 0;   // Enable pullup
    GpioCtrlRegs.GPAQSEL2.bit.GPIO18 = 3; //
    GpioCtrlRegs.GPAMUX2.bit.GPIO18 = 0;  //
    GpioCtrlRegs.GPADIR.bit.GPIO18 = 0;   // Input
//--- gpio19 low side IGBT fault pwm1 button2
    GpioCtrlRegs.GPAPUD.bit.GPIO19 = 0;   // Enable pullup
    GpioCtrlRegs.GPAQSEL2.bit.GPIO19 = 3; //
    GpioCtrlRegs.GPAMUX2.bit.GPIO19 = 0;  //
    GpioCtrlRegs.GPADIR.bit.GPIO19 = 0;   // Input
//--- gpio26 button3 high side IGBT fault pwm2
    GpioCtrlRegs.GPAPUD.bit.GPIO26 = 0;   // Enable pullup
    GpioCtrlRegs.GPAQSEL2.bit.GPIO26 = 3; //
    GpioCtrlRegs.GPAMUX2.bit.GPIO26 = 0;  //
    GpioCtrlRegs.GPADIR.bit.GPIO26 = 0;   // Input
//--- gpio27 button4 low side IGBT fault pwm3
    GpioCtrlRegs.GPAPUD.bit.GPIO27 = 0;   // Enable pullup
    GpioCtrlRegs.GPAQSEL2.bit.GPIO27 = 3; //
    GpioCtrlRegs.GPAMUX2.bit.GPIO27 = 0;  //
    GpioCtrlRegs.GPADIR.bit.GPIO27 = 0;   // Input

//--- gpio 20,21,22,23,24,25, (-26,-27),28,29,30,31
    GpioCtrlRegs.GPAPUD.bit.GPIO20  = 0;  // Enable pullup on GPIO20
    GpioDataRegs.GPACLEAR.bit.GPIO20= 1;  // output clear
    GpioCtrlRegs.GPAMUX2.bit.GPIO20 = 0;  // GPIO20
    GpioCtrlRegs.GPADIR.bit.GPIO20  = 1;  // output

    GpioCtrlRegs.GPAPUD.bit.GPIO21  = 0;  // Enable pullup on GPIO21
    GpioDataRegs.GPACLEAR.bit.GPIO21= 1;  // output clear
    GpioCtrlRegs.GPAMUX2.bit.GPIO21 = 0;  // GPIO21
    GpioCtrlRegs.GPADIR.bit.GPIO21  = 1;  // output

    GpioCtrlRegs.GPAPUD.bit.GPIO22  = 0;  // Enable pullup on GPIO22
    GpioDataRegs.GPACLEAR.bit.GPIO22= 1;  // output clear
    GpioCtrlRegs.GPAMUX2.bit.GPIO22 = 0;  // GPIO22
    GpioCtrlRegs.GPADIR.bit.GPIO22  = 1;  // output

    GpioCtrlRegs.GPAPUD.bit.GPIO23  = 0;  // Enable pullup on GPIO23
    GpioDataRegs.GPACLEAR.bit.GPIO23= 1;  // output clear
    GpioCtrlRegs.GPAMUX2.bit.GPIO23 = 0;  // GPIO23
    GpioCtrlRegs.GPADIR.bit.GPIO23  = 1;  // output

    GpioCtrlRegs.GPAPUD.bit.GPIO24  = 0;  // Enable pullup on GPIO24
    GpioDataRegs.GPACLEAR.bit.GPIO24= 1;  // output clear
    GpioCtrlRegs.GPAMUX2.bit.GPIO24 = 0;  // GPIO24
    GpioCtrlRegs.GPADIR.bit.GPIO24  = 1;  // output

    GpioCtrlRegs.GPAPUD.bit.GPIO25  = 0;  // Enable pullup on GPIO25
    GpioDataRegs.GPACLEAR.bit.GPIO25= 1;  // output clear
    GpioCtrlRegs.GPAMUX2.bit.GPIO25 = 0;  // GPIO25
    GpioCtrlRegs.GPADIR.bit.GPIO25  = 1;  // output
//--- 26,27 igbt fault
    GpioCtrlRegs.GPAPUD.bit.GPIO28  = 0;  // Enable pullup on GPIO28
    GpioDataRegs.GPACLEAR.bit.GPIO28= 1;  // output clear
    GpioCtrlRegs.GPAMUX2.bit.GPIO28 = 0;  // GPIO28
    GpioCtrlRegs.GPADIR.bit.GPIO28  = 1;  // output

    GpioCtrlRegs.GPAPUD.bit.GPIO29  = 0;  // Enable pullup on GPIO29
    GpioDataRegs.GPACLEAR.bit.GPIO29= 1;  // output clear
    GpioCtrlRegs.GPAMUX2.bit.GPIO29 = 0;  // GPIO29
    GpioCtrlRegs.GPADIR.bit.GPIO29  = 1;  // output
//--- pin 30 reserved
    GpioCtrlRegs.GPAPUD.bit.GPIO30 = 0;  // Enable pullup
    GpioDataRegs.GPACLEAR.bit.GPIO30= 1; // output clear
    GpioCtrlRegs.GPAMUX2.bit.GPIO30 = 0; // gpio
    GpioCtrlRegs.GPADIR.bit.GPIO30 = 1;  // output
//--- pin 31 reserved
    GpioCtrlRegs.GPAPUD.bit.GPIO31 = 0;  // Enable pullup
    GpioDataRegs.GPACLEAR.bit.GPIO31= 1; // output clear
    GpioCtrlRegs.GPAMUX2.bit.GPIO31 = 0; // gpio
    GpioCtrlRegs.GPADIR.bit.GPIO31 = 1;  // output

//--- Enable I2C-A on GPIO32 - GPIO33
    GpioCtrlRegs.GPBPUD.bit.GPIO32 = 0;   // Enable pullup on GPIO32
    GpioCtrlRegs.GPBMUX1.bit.GPIO32 = 1;  // GPIO32 = SDAA
    GpioCtrlRegs.GPBQSEL1.bit.GPIO33 = 3; // Asynch input
    GpioCtrlRegs.GPBPUD.bit.GPIO33 = 0;   // Enable pullup on GPIO33
    GpioCtrlRegs.GPBQSEL1.bit.GPIO33 = 3; // Asynch input
    GpioCtrlRegs.GPBMUX1.bit.GPIO33 = 1;  // GPIO33 = SCLA

//--- gpio34 reserved
    GpioCtrlRegs.GPBPUD.bit.GPIO34 = 0;  // Enable pullup on GPIO34
    GpioDataRegs.GPBCLEAR.bit.GPIO34= 1; // output clear
    GpioCtrlRegs.GPBMUX1.bit.GPIO34 = 0; // GPIO34 = GPIO34
    GpioCtrlRegs.GPBDIR.bit.GPIO34 = 1;  // GPIO34 = input

//--- gpio39~58 open output reserved
    GpioCtrlRegs.GPBPUD.bit.GPIO39 = 0;  // pullup
    GpioDataRegs.GPBCLEAR.bit.GPIO39= 1; // output clear
    GpioCtrlRegs.GPBMUX1.bit.GPIO39 = 0; // GPIO34 = GPIO34
    GpioCtrlRegs.GPBDIR.bit.GPIO39 = 1;  // GPIO34 = input

    GpioCtrlRegs.GPBPUD.bit.GPIO40 = 0;  // enable pullup
    GpioDataRegs.GPBCLEAR.bit.GPIO40= 1; // output low
    GpioCtrlRegs.GPBMUX1.bit.GPIO40 = 0; // gpio
    GpioCtrlRegs.GPBDIR.bit.GPIO40 = 1;  // output

    GpioCtrlRegs.GPBPUD.bit.GPIO41 = 0;  // enable pullup
    GpioDataRegs.GPBCLEAR.bit.GPIO41= 1; // output low
    GpioCtrlRegs.GPBMUX1.bit.GPIO41 = 0; // gpio
    GpioCtrlRegs.GPBDIR.bit.GPIO41 = 1;  // output

    GpioCtrlRegs.GPBPUD.bit.GPIO42 = 0;  // enable pullup
    GpioDataRegs.GPBCLEAR.bit.GPIO42= 1; // output low
    GpioCtrlRegs.GPBMUX1.bit.GPIO42 = 0; // gpio
    GpioCtrlRegs.GPBDIR.bit.GPIO42 = 1;  // output

    GpioCtrlRegs.GPBPUD.bit.GPIO43 = 0;  // enable pullup
    GpioDataRegs.GPBCLEAR.bit.GPIO43= 1; // output low
    GpioCtrlRegs.GPBMUX1.bit.GPIO43 = 0; // gpio
    GpioCtrlRegs.GPBDIR.bit.GPIO43 = 1;  // output

    GpioCtrlRegs.GPBPUD.bit.GPIO44 = 0;  // enable pullup
    GpioDataRegs.GPBCLEAR.bit.GPIO44= 1; // output low
    GpioCtrlRegs.GPBMUX1.bit.GPIO44 = 0; // gpio
    GpioCtrlRegs.GPBDIR.bit.GPIO44 = 1;  // output

    GpioCtrlRegs.GPBPUD.bit.GPIO50 = 0;  // enable pullup
    GpioDataRegs.GPBCLEAR.bit.GPIO50= 1; // output low
    GpioCtrlRegs.GPBMUX2.bit.GPIO50 = 0; // gpio
    GpioCtrlRegs.GPBDIR.bit.GPIO50 = 1;  // output

    GpioCtrlRegs.GPBPUD.bit.GPIO51 = 0;  // enable pullup
    GpioDataRegs.GPBCLEAR.bit.GPIO51= 1; // output low
    GpioCtrlRegs.GPBMUX2.bit.GPIO51 = 0; // gpio
    GpioCtrlRegs.GPBDIR.bit.GPIO51 = 1;  // output

    GpioCtrlRegs.GPBPUD.bit.GPIO52 = 0;  // enable pullup
    GpioDataRegs.GPBCLEAR.bit.GPIO52= 1; // output low
    GpioCtrlRegs.GPBMUX2.bit.GPIO52 = 0; // gpio
    GpioCtrlRegs.GPBDIR.bit.GPIO52 = 1;  // output

    GpioCtrlRegs.GPBPUD.bit.GPIO53 = 0;  // enable pullup
    GpioDataRegs.GPBCLEAR.bit.GPIO53= 1; // output low
    GpioCtrlRegs.GPBMUX2.bit.GPIO53 = 0; // gpio
    GpioCtrlRegs.GPBDIR.bit.GPIO53 = 1;  // output

    GpioCtrlRegs.GPBPUD.bit.GPIO54 = 0;  // enable pullup
    GpioDataRegs.GPBCLEAR.bit.GPIO54= 1; // output low
    GpioCtrlRegs.GPBMUX2.bit.GPIO54 = 0; // gpio
    GpioCtrlRegs.GPBDIR.bit.GPIO54 = 1;  // output

    GpioCtrlRegs.GPBPUD.bit.GPIO55 = 0;  // pullup
    GpioDataRegs.GPBCLEAR.bit.GPIO55= 1; // output clear
    GpioCtrlRegs.GPBMUX2.bit.GPIO55 = 0; //
    GpioCtrlRegs.GPBDIR.bit.GPIO55 = 1;  // output

    GpioCtrlRegs.GPBPUD.bit.GPIO56 = 0;  // pullup
    GpioDataRegs.GPBCLEAR.bit.GPIO56= 1; // output clear
    GpioCtrlRegs.GPBMUX2.bit.GPIO56 = 0; //
    GpioCtrlRegs.GPBDIR.bit.GPIO56 = 1;  // output

    GpioCtrlRegs.GPBPUD.bit.GPIO57 = 0;  // pullup
    GpioDataRegs.GPBCLEAR.bit.GPIO57= 1; // output clear
    GpioCtrlRegs.GPBMUX2.bit.GPIO57 = 0; //
    GpioCtrlRegs.GPBDIR.bit.GPIO57 = 1;  // output

    GpioCtrlRegs.GPBPUD.bit.GPIO58 = 0;  // pullup
    GpioDataRegs.GPBCLEAR.bit.GPIO58= 1; // output clear
    GpioCtrlRegs.GPBMUX2.bit.GPIO58 = 0; //
    GpioCtrlRegs.GPBDIR.bit.GPIO58 = 1;  // output
    EDIS;
}

//
// End of File
//

