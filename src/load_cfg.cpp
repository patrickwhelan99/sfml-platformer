#include "../include/custom.h"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <cstring>

cfg load_cfg()
{

    cfg config;

    std::ifstream loadCfg;
    loadCfg.open("cfg/platformer.cfg");

    std::string line;
    std::string valFor;
    config.xres = 800;
    config.yres = 600;

    if (loadCfg.is_open())
    {

            while ( std::getline (loadCfg,line) )
            {
                std::istringstream stream(line);
                std::string thing;
                int counter = 0;
                    while(getline(stream, thing, '='))
                    {
                        switch (counter)
                        {
                            case 0:
                                valFor = thing;
                                break;

                            case 1:
                                    if(valFor == "xres")
                                            config.xres = atoi(thing.c_str());
                                    if(valFor == "yres")
                                            config.yres = atoi(thing.c_str());
                                    if(valFor == "gravity")
                                            config.gravity = atof(thing.c_str());
                                    if(valFor == "speed")
                                            config.speed = atof(thing.c_str());
                                    if(valFor == "maxHorizontalMovement")
                                            config.maxHorizontalMovement = atof(thing.c_str());
                                    if(valFor == "maxVerticalMovement")
                                            config.maxVerticalMovement = atof(thing.c_str());
                                    if(valFor == "terminalVelocity")
                                            config.terminalVelocity = atof(thing.c_str());
                                    if(valFor == "terminalHorizontalVelocity")
                                            config.terminalHorizontalVelocity = atof(thing.c_str());
                            break;
                        }
                    counter ++;
                    }

        }
    }
    else
        printf("Couldn't open platformer.cfg");

    return config;
}
