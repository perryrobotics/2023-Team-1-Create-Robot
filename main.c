#include <kipr/wombat.h>
#include <time.h>
#include "movement.h"
#include "sensors.h"
#include "constants.h"
#include "effectors.h"

int main()
{
 	time_t start_time;   
    printf("Hello World\n");
    printf("Attempting to connect to Create!\n");
    create_connect();
    printf("CONNECTED!!\n");
    create_full();
    enable_servos();
    set_servo_position(WS,896); // START POSITION
    //wireshark_up();
    hook_up();
    
    wait_for_light(LIGHT);
    shut_down_in(119);
    start_time = time(NULL);
    //GAME BEGINS!!


    wireshark_up(); 
    CW(150,45);
    wireshark_down();
    CW(150,45);
    forward_mm(100,85);
    msleep(2000);
    wireshark_up(); // fling it!!
    //backward_mm(100,15);
    CCW(150,100);
    //forward_mm(100,230);
    forward_to_black(100, RIGHT_LINE);
    forward_mm(150,90);
   CW_to_black(100, LEFT_LINE);

   line_follow(300,1805);
    //msleep(3000);
   CW(100,45);
    forward_mm(100,150);// INSIDE THE SCORE BOX
    backward_to_black(100, RIGHT_LINE);
    backward_mm(200,100);
    CCW(100,45);
    wireshark_down();
    forward_mm(100,120);
    CW(100,90);
    wireshark_up();
    backward_mm(100,100);
    CCW(100,60);
    wireshark_down();
    hook_up();
    // FORWARD UNTIL IT CLICKS
    create_drive_straight(-100);
    while ( digital(CLICK_SENSOR) == 0 )
    {
    }
    create_drive_straight(0);
    // DONE WITH CLICK SENSOR!!
    hook_down();
    backward_mm(100,200);
    CW(100,90);
    drive_to_bump(100);
    forward_to_black(150, LEFT_LINE);
    forward_mm(150,100);
    CW_to_black(150, LEFT_LINE);
    line_follow(300,1630);
    //msleep(14000);//waiting for ping pong balls to fall
    while ( (time(NULL) - start_time) < 64) // WAIT FOR 64 SECONDS TO GO BY!!!
    {}
    CCW(150, 150);
    wireshark_up();
    drive_to_bump(200);
    CCW(100,55);
    set_servo_position(WS, 2047);
    msleep(2000);
    
    /*
    forward_to_black(250, LEFT_LINE); //center of table
    forward_mm(250,1000);
    CW(100,100);
    forward_mm(100,500);//All poms in cybersecurity
    CW(100,100);
    
    forward_to_black(150, LEFT_LINE);
    forward_mm(150,100);
    
        forward_to_black(150, LEFT_LINE);
    forward_mm(150,200);
    
    //CW(50,100);
    

    */
    return 0;
}
