#include "custom.h"
#include <vector>
#include <iostream>
#include <fstream>
#include "rapidjson/rapidjson.h"

void save_game(std::vector<block> &blocks)
{



    std::ofstream saveGameFile;
    saveGameFile.open("savegame");

    for (block &block: blocks)
    {
        sf::Vector2f blockPos = block.getPosition();
        saveGameFile << blockPos.x << "," << blockPos.y << "," << block.bp.isDeadly << "," << block.bp.isStart << "," << block.bp.isCheckpoint << "," << block.bp.isFinish << "," << block.bp.isBreakable << "," << block.bp.textureIndex << std::endl;
    }

        saveGameFile.close();
}
