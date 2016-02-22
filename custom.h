#include <SFML/Graphics.hpp>
#include <vector>
#ifndef CUSTOM_H_INCLUDED
#define CUSTOM_H_INCLUDED

class block : public sf::Sprite
{
    public:
        block();
        virtual ~block();
        bool deadly = false;
        bool startPoint = false;
        bool savePoint = false;
        bool finishPoint = false;
        bool breakable = false;
        int texture;
    protected:
    private:
};



void update_view(sf::RenderWindow &app, sf::View &camera, std::vector<block> sprites, sf::Sprite player);
sf::View create_camera(sf::Sprite player);
sf::Vector2f movement(sf::Sprite &player, std::vector<block> &sprites, sf::Vector2f playerVector, float &vertSpeed, sf::Vector2f &lastCheckpoint);
void create_block(sf::RenderWindow &app, std::vector<block> &sprites, sf::View &camera, bool deadly, bool start, bool checkpoint, bool finish, bool breakable, std::vector<sf::Texture> &textures, int &texturePos);
void destroy_block(std::vector<block> &sprites);
void respawn(sf::Sprite &player, sf::Vector2f lastCheckpoint);
void save_game(std::vector<block> &sprites);
void load_save(std::vector<block> &newVector, std::vector<sf::Texture> &textures, sf::Vector2f &levelStart, sf::Vector2f &levelFinish);
void texture_init(std::vector<sf::Texture> &textures);
void play(bool &init, std::string levelName, std::vector<block> &sprites, std::vector<sf::Texture> &textures, sf::Vector2f &levelStart, sf::Vector2f &lastCheckpoint, sf::Vector2f &levelFinish, sf::Sprite &player, sf::View &camera, float &jumpSpeed);
void create(std::vector<block> &sprites, std::vector<sf::Texture> &textures, sf::Sprite &player, sf::RenderWindow &app, sf::View &camera, block &ghost, int &texturePos, sf::Font &font, bool deadly, bool start, bool checkpoint, bool finish, bool breakable);
void initialize(sf::Sprite &player, sf::View camera, std::vector<block> &sprites);



#endif // CUSTOM_H_INCLUDED
