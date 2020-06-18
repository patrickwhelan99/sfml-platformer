#include "../include/custom.h"
#include <vector>

void destroy_block(std::vector<block> &sprites)
{
            if(sprites.size() > 0) //if no sprites then game crashes due to bad iterators :3
                sprites.pop_back();
}
