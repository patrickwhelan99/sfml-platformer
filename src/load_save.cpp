#include "../include/block.h"
#include "../include/gameState.h"
#include <fstream>
#include <SFML/Graphics.hpp>

void load_save(gameState &gs)
{
    std::ifstream is("save_games/1");
    if(!is.good() || !is.is_open())
    {
        std::cerr << "Error opening file!\n";
        return;
    }
    cereal::XMLInputArchive inArchive( is );

    inArchive(gs.blocks);

    for(block &b : gs.blocks)
    {
        b.setTexture(gs.textures->at(b.bp.textureIndex));
        printf("Block loaded!\n");
    }

    printf("%i Blocks loaded!\n", gs.blocks.size());

}
