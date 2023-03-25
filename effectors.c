#include <kipr/wombat.h>
#include "movement.h"
#include "sensors.h"
#include "constants.h"


void wireshark_up()
{
    set_servo_position(WS, WS_UP);
    msleep(750);
}

void wireshark_down()
{
    set_servo_position(WS, WS_DOWN);
    msleep(750);
}

void hook_up()
{
    set_servo_position(HOOK, HOOK_UP);
    msleep(750);
}

void hook_down()
{
    set_servo_position(HOOK, HOOK_DOWN);
    msleep(750);
}
