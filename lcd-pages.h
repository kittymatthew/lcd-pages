#ifndef lcd-pages
#define lcd-pages

#define __ARDUINO

#include "platform.h"

// Supported page types
#define PT_SPLASH 0
#define PT_MENU 1
#define PT_OPTION 2
#define PT_ACTION 3

// Input pullup or normal constants
#define IN_NORMAL 0
#define IN_PULLUP 1

// Typedefs
typedef short PIN;
typedef void* CALLBACK;

// Structure that holds information about a physical LCD display
typedef struct LCDDisplay
{
    // The display's pins
    PIN chipEnable;
    PIN registerSelect;
    PIN data5;
    PIN data6;
    PIN data7;
    PIN data8;

    // The rows and columns capable of being used
    int rows;
    int columns;
} LCDDisplay;

// Structure that holds information about an LCD's control scheme
typedef struct LCDControls
{
    // The pins of the control inputs
    PIN back;
    PIN left;
    PIN right;
    PIN ok;

    // Does the input need to be pulled up internally?
    int inputType;
} LCDControls;

// Structure that represents a page
typedef struct LCDPage
{
    int type; // Screen type
    int splashTime; // Time to wait if it is a splash screen

    // Text to display
    char* upperText;
    char* lowerText;

    // The next and previous pages
    LCDPage* rightPage;
    LCDPage* leftPage;

    // The callback method to call if this is an action screen
    CALLBACK action;
} LCDPage;

#endif 