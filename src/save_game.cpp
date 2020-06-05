#include "custom.h"
#include <vector>
#include <iostream>
#include <fstream>

void save_game(std::vector<block> &sprites)
{

    std::ofstream saveGameFile;
    saveGameFile.open("savegame");

    for (auto const& sprite: sprites)
    {
        sf::Vector2f spritePos = sprite.getPosition();
        saveGameFile << spritePos.x << "," << spritePos.y << "," << sprite.deadly << "," << sprite.startPoint << "," << sprite.savePoint << "," << sprite.finishPoint << "," << sprite.breakable << "," << sprite.texture << std::endl;
    }

        saveGameFile.close();
}
