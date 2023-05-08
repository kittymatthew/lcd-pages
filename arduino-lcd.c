#include "lcd-pages.h"

void arduinoSetup(LCDDisplay display, LCDControls controls)
{
    int type = INPUT;
    if (controls.inputType == IN_PULLUP) { type = INPUT_PULLUP; }

    pinMode(controls.back, INPUT);
    pinMode(controls.left, INPUT);
    pinMode(controls.right, INPUT);
    pinMode(controls.ok, INPUT);

    pinMode(display.data5, OUTPUT);
    pinMode(display.data6, OUTPUT);
    pinMode(display.data7, OUTPUT);
    pinMode(display.data8, OUTPUT);
}