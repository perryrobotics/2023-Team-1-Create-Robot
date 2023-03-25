#include <kipr/wombat.h>


void backward_mm(int speed, int mm)
{
    set_create_distance(0);
    create_drive_direct(speed, speed);
    
    while(get_create_distance() < mm)
    {
        msleep(25);
    }
    create_drive_straight(0);
}
void forward_mm(int speed, int mm)
{
    set_create_distance(0);
    create_drive_direct(-speed, -speed);
    
    while(get_create_distance() > -mm)
    {
        msleep(25);
    }
    create_drive_straight(0);
}

void CCW(int speed, int angle)
{
    set_create_total_angle(0);
    create_spin_CCW(speed);
    while(get_create_total_angle() < angle)
    {
        msleep(25);
    }
    
    create_spin_CCW(0);
}
void CW(int speed, int angle)
{
    set_create_total_angle(0);
    create_spin_CW(speed);
    while(get_create_total_angle() > -angle)
    {
        msleep(25);
    }
    
    create_spin_CW(0);
}
