#include <kipr/wombat.h>
#include "movement.h"
#include "sensors.h"
#include "constants.h"
#include "effectors.h"

int main()
{
    printf("Hello World\n");
    create_connect();
    create_full();
    enable_servos();
    wireshark_up();
    hook_up();
    shut_down_in(119);
    //GAME BEGINS!!


    wireshark_up();


    
    forward_mm(200, 330); // First red pom pushed
    drive_to_bump(200);

    // go get second red pom
    forward_mm(200,81);
    CW(125, 102);// turn tpo face second box
    forward_to_black_align(200);  // OUT OF FIRST BOX
    forward_mm(200,280); 

    forward_to_black_align(150);
    forward_mm(200,270);
    forward_to_black_align(100);
    forward_mm(200,470); // push rings out of way
    backward_mm(200,200);
    CW(200, 90);
    forward_mm(250,325); // ALIGN ON PIPE
    msleep(500);
    backward_mm(200,100);
    backward_to_black(200, LEFT_LINE);

    forward_mm(200,50);
    CCW(50,102); // FACE WIRESHARK  MAY NEED ADJUSTMENT!!

    // NEW STUFF TO SLAP POMS
    backward_mm(200,75);
    wireshark_down();
    CCW(200, 15);
    forward_mm(200,200);
    CW(200,30);
    CCW(200,30);
    forward_mm(200,55);
    CW(200,45);
    wireshark_up();
    forward_to_black(100, LEFT_LINE);
    backward_to_black(100, RIGHT_LINE);
    backward_mm(100,100);
    wireshark_down();
    CCW(200,10);


    //forward_mm(200,380);  // GO FORWARD TO WIRESHARK
    create_drive_straight(-200);
    while( digital(0) == 0 )
    {
    }
    create_drive_straight(0);
    backward_mm(100,10);

    // AT THE WIRESHARK!  HOOK IT!
    hook_down();
    CCW(200, 90);
    CCW_to_black(200,LEFT_LINE);
    line_follow(150,1890);
    //CW(200,10);
    /*
    forward_to_black(300, RIGHT_LINE);
    msleep(500);
    forward_to_black(300, RIGHT_LINE);
    forward_mm(100,200);
    CCW(100,30);
    forward_to_black(100, RIGHT_LINE);
    CW_to_black(100, LEFT_LINE);
    CCW(50, 5); // correct and face the ping pongs
    forward_mm(100,410);
	msleep(7000);
    backward_mm(100,50);
    CCW(100,140);
*/
    	msleep(7000);
    backward_mm(100,50);
    CCW(100,140);
    create_disconnect();
    return 0;
}
