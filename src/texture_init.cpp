#include "custom.h"
#include <string>
#include <cstring>
#include <iostream>
#include <dirent.h>

void texture_init(std::vector<sf::Texture> &textures)
{
    DIR *dir;
    struct dirent *ent;
    dir = opendir("textures");
    if (dir != NULL)
    {
        while ((ent = readdir (dir)) != NULL)
        {
            std::string fileName = ent->d_name;
            if(!(fileName == ".") && !(fileName == "..") && !(fileName == "Character") && !(fileName == "anims"))
            {
                std::string tang = "textures/";
                std::string texStr = tang + ent->d_name;
                sf::Texture newTexture;
                newTexture.loadFromFile(texStr);
                textures.push_back(newTexture);
            }
        }
        closedir(dir);
    }
    else
    {
        printf("Failed to read directory %i", EXIT_FAILURE);
    }

}

