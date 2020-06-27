#include "../include/block.h"
#include "../include/gameState.h"
#include "../include/walker.h"

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

    inArchive(gs.entities);

    for(std::shared_ptr<Entity> &e : gs.entities)
    {
        if(!e)
        {
            printf("ERROR: FAILED TO LOAD ENTITY!\n");
            return;
        }

        printf("%i\n", e->textureIndex);

        e->setTexture(gs.textures->at(e->textureIndex));
        if(std::dynamic_pointer_cast<Player>(e))
        {
            gs.player.reset();
            gs.player = std::dynamic_pointer_cast<Player>(e);
            printf("Player loaded!\n");
        }
        else if(std::dynamic_pointer_cast<walker>(e))
            printf("Walker loaded!\n");
        else
            printf("Entity loaded!\n");

    }

}
