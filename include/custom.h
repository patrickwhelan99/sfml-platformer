#include <SFML/Graphics.hpp>
#include <vector>
#include "Player.h"
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

class cfg
{
    public:
        cfg();
        virtual ~cfg();
        int xres;
        int yres;
        float gravity;
        float speed;
        double maxHorizontalMovement;
        double maxVerticalMovement;
        float terminalVelocity;
        float terminalHorizontalVelocity;

    protected:
    private:
};

void update_view(sf::RenderWindow &app, sf::View &camera, std::vector<block> sprites, sf::Sprite player);
sf::View create_camera(sf::Sprite player);
void movement(Player &player, std::vector<block> &sprites, sf::Vector2f &lastCheckpoint, cfg config);
void create_block(sf::RenderWindow &app, std::vector<block> &sprites, sf::View &camera, bool deadly, bool start, bool checkpoint, bool finish, bool breakable, std::vector<sf::Texture> &textures, int &texturePos);
void destroy_block(std::vector<block> &sprites);
void respawn(sf::Sprite &player, sf::Vector2f lastCheckpoint);
void save_game(std::vector<block> &sprites);
void load_save(std::vector<block> &newVector, std::vector<sf::Texture> &textures, sf::Vector2f &levelStart, sf::Vector2f &levelFinish);
void texture_init(std::vector<sf::Texture> &textures);
void play(bool &init, std::string levelName, std::vector<block> &sprites, std::vector<sf::Texture> &textures, sf::Vector2f &levelStart, sf::Vector2f &lastCheckpoint, sf::Vector2f &levelFinish, Player &player, sf::View &camera, cfg config);
void create(std::vector<block> &sprites, std::vector<sf::Texture> &textures, sf::Sprite &player, sf::RenderWindow &app, sf::View &camera, block &ghost, int &texturePos, sf::Font &font, bool deadly, bool start, bool checkpoint, bool finish, bool breakable);
cfg load_cfg();


#endif // CUSTOM_H_INCLUDED
