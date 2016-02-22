#include "custom.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <cstring>

void load_save(std::vector<block> &newVector, std::vector<sf::Texture> &textures, sf::Vector2f &levelStart, sf::Vector2f &levelFinish)
{
    std::string line;
    std::string xStr;
    std::string yStr;
    std::string deadlyStr;
    std::string startStr;
    std::string saveStr;
    std::string finishStr;
    std::string breakableStr;
    std::string textureStr;

    std::ifstream loadSave;
    loadSave.open("savegame");


    if (loadSave.is_open())
    {

            while ( std::getline (loadSave,line) )
            {
                std::istringstream stream(line);
                std::string thing;
                int counter = 0;
                    while(getline(stream, thing, ','))
                    {
                        switch (counter)
                        {
                            case 0:
                                xStr = thing;
                                break;

                            case 1:
                                yStr = thing;
                                break;

                            case 2:
                                deadlyStr = thing;
                                break;

                            case 3:
                                startStr = thing;
                                break;

                            case 4:
                                saveStr = thing;
                                break;

                            case 5:
                                finishStr = thing;
                                break;

                            case 6:
                                breakableStr = thing;
                                break;

                            case 7:
                                textureStr = thing;
                                break;

                        }

                    counter ++;
                    }

                sf::Vector2f blockPos = {atof(xStr.c_str()), atof(yStr.c_str())};
                bool deadly = atoi(deadlyStr.c_str());
                bool startPoint = atoi(startStr.c_str());
                bool savePoint = atoi(saveStr.c_str());
                bool finishPoint = atoi(finishStr.c_str());
                bool breakable = atoi(breakableStr.c_str());
                int texture = atoi(textureStr.c_str());


                if(startPoint)
                {
                    sf::Vector2f tempLevelStart = blockPos;
                    tempLevelStart.y -= 50;
                    levelStart = tempLevelStart;
                }

                if(finishPoint)
                    levelFinish = blockPos;



                block newBlock;
                newBlock.setPosition(blockPos);
                newBlock.deadly = deadly;
                newBlock.startPoint = startPoint;
                newBlock.savePoint = savePoint;
                newBlock.finishPoint = finishPoint;
                newBlock.breakable = breakable;
                newBlock.texture = texture;
                newBlock.setTexture(textures.at(texture));

                /*
                if (deadly)
                    newBlock.setTexture(textures.at(2));
                else
                    newBlock.setTexture(textures.at(1));
                */
                newVector.push_back(newBlock);

            }


        loadSave.close();
    }

}
