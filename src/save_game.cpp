#include "../include/custom.h"
#include "../include/walker.h"

#include <fstream>
#include <string>
#include <cereal/archives/xml.hpp>
#include <cereal/types/vector.hpp>

void save_game(std::vector<block> &blocks, std::vector<std::shared_ptr<Entity>> entities)
{
    std::ofstream os("save_games/1");
    cereal::XMLOutputArchive archive( os );
    archive( cereal::make_nvp("blocks", blocks) );
    archive(entities);
}
