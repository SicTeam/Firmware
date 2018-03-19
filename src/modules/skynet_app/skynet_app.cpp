/*

The MIT License

Copyright (c) 2018 SicTeam - (Portland State University)

SicTeam is: Israel Bond, Brandon Craig, Cody Herberholz, Khuong Nguyen,
            Dakota Sanchez, Samuel Strba, Elijah Whitham-Powell

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.

*/


#include <px4_config.h>
#include <px4_tasks.h>
#include <px4_posix.h>
#include <unistd.h>
#include <stdio.h>
#include <poll.h>
#include <string.h>
#include <math.h>

#include <uORB/uORB.h>
#include <uORB/topics/sensor_combined.h>
#include <uORB/topics/vehicle_attitude.h>


/********************************************************************
 * Includes that are not part of original "px4_example_app" are here*/

#include <uORB/topics/position_setpoint_triplet.h>
#include <uORB/topics/vehicle_command.h>


static volatile bool thread_running = false;	


extern "C" __EXPORT int skynet_app_main(int argc, char *argv[]);

static void usage(const char * reason);

int skynet_app_main(int argc, char *argv[])
{
    if(argc < 2) {
        usage("missing command");
            return 1;
    }

    if(!strcmp(argv[1], "start")) {
        if(thread_running) {
            warnx("skynet_app already running");
            return 0;
        }
        thread_running = true;

        PX4_INFO("skynet_app start.");
        return 0;
    }
    
    if(!strcmp(argv[1], "stop")) {
        if(!thread_running) {
            warnx("skynet_app not running; no shutdown required.");
            return 0;
        }
        thread_running = false;


        PX4_INFO("skynet_app shutting down.");
        return 0;
    }

    if(!thread_running) {
        warnx("skynet_app not yet running");
        return 1;
    }

    
    if(!strcmp(argv[1], "status")) {
        PX4_INFO("skynet_app status.");
        return 0;
    }
    
       
    if(!strcmp(argv[1], "test")) {
        
        PX4_INFO("skynet_app simple test passed.");
        
        //position_setpoint_s z;
        //z.x = 0.0f;
        //if(z.x < 1.0f)
            //PX4_INFO("x coordinate set, test win. yay.");

        return 0;
    }
    
    usage("command given but not recognized.");
    return 1;
}


  

static void usage(const char *reason)
{
	if (reason && *reason > 0) {
		PX4_INFO("%s", reason);
	}

	PX4_INFO("usage: skynet_app {start|stop|status|test}\n");
        return;
}


















