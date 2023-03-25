#include <kipr/wombat.h>
#include "movement.h"
#include "constants.h"

void drive_to_bump(int speed)
{
    create_drive_straight(speed);
    while ( (get_create_lbump() == 0) && (get_create_rbump() == 0) )
    {
    }

    create_drive_direct(0,0);
}

void forward_to_black(int speed, int port)
{	

    create_drive_straight(-speed);
    while ( analog(port) < BLACK )
    {
    }

    create_drive_straight(0);
}

void forward_to_white(int speed, int port)
{	

    create_drive_straight(-speed);
    while ( analog(port) > BLACK )
    {
    }

    create_drive_straight(0);
}

void CW_to_black(int speed, int port)
{
    create_spin_CW(speed);
    while( analog(port) < BLACK)
    {
    }
    create_spin_CW(0);
}


void backward_to_black(int speed, int port)
{	

    create_drive_straight(speed);
    while ( analog(port) < BLACK )
    {
    }

    create_drive_straight(0);
}

void CCW_to_black(int speed, int port)
{
    create_spin_CCW(speed);
    while( analog(port) < BLACK)
    {
    }
    create_spin_CCW(0);
}

void line_follow(int speed, int mm)
{

    set_create_distance(0);
	printf("dist: %d\n", get_create_distance());
   while (get_create_distance() > -mm)
   {
       //printf("dist: %d\n", get_create_distance());
       if (analog(RIGHT_LINE) > BLACK) // drift right
       {
           create_drive_direct(-speed+50, (-speed)-50 );
       }
       else if (analog(LEFT_LINE) > BLACK) // drift left
       {
           create_drive_direct((-speed)-50, -speed +50);
       }
       else
       {
           create_drive_direct(-speed, -speed);
       }
    }
    create_drive_direct(0,0);
}

void forward_to_black_align(int speed)
{

    create_drive_direct(-speed, -speed);

    while ( (analog(LEFT_LINE) < BLACK) && (analog(RIGHT_LINE) < BLACK) )
    {
        //go forward while both sensors are over white
    }
    create_drive_direct(0, 0);
    msleep(750);


    if ( analog(LEFT_LINE) > analog(RIGHT_LINE) )  // left over black
    {
        create_drive_direct(-50, 30);

        while (analog(RIGHT_LINE) < BLACK)
        {
        }
        create_drive_direct(0,0);
    }
    else
    {
        create_drive_direct(30, -50);

        while (analog(LEFT_LINE) < BLACK)
        {
        }
        create_drive_direct(0,0);
    }
    create_drive_direct(0,0);
}


/*
void line_follow(int speed, int mm)
{
    set_create_distance(0);
    set_create_total_angle(0);
    
   while (get_create_total_distance() < mm)
   {
       if (analog(LEFT_LINE) > BLACK) // drift right
       {
           create_drive_direct(-speed, (-speed)-100) );
       }
       else if (analog(RIGHT_LINE) > BLACK) // drift left
       {
           create_drive_direct((-speed)-100, -speed );
       }
       else
       {
           create_drive_direct(-speed, -speed);
       }
   }
    create_drive_direct(0
               
*/










