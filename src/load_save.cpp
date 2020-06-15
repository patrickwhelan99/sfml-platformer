#include "block.h"
#include "gameState.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#include <SFML/Graphics.hpp>

void load_save(gameState &gs)
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

                blockProperties bp;

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
                bp.isDeadly = atoi(deadlyStr.c_str());
                bp.isStart = atoi(startStr.c_str());
                bp.isCheckpoint = atoi(saveStr.c_str());
                bp.isFinish = atoi(finishStr.c_str());
                bp.isBreakable = atoi(breakableStr.c_str());
                bp.textureIndex = atoi(textureStr.c_str());


                if(bp.isStart)
                {
                    gs.lp.levelStart = sf::Vector2f(blockPos.x, blockPos.y - 150);
                    gs.lp.currentCheckpoint = sf::Vector2f(blockPos.x, blockPos.y - 150);
                }

                if(bp.isCheckpoint)
                {
                    gs.lp.currentCheckpoint = sf::Vector2f(blockPos.x, blockPos.y - 150);
                }

                if(bp.isFinish)
                {
                    gs.lp.levelEnd = sf::Vector2f(blockPos.x, blockPos.y - 150);
                }

                block newBlock(bp, gs.textures->at(bp.textureIndex), blockPos);
                gs.blocks.push_back(newBlock);

            }


        loadSave.close();
    }

}
