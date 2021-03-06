#include <SFML/Graphics.hpp>
#include <vector>
#include "Player.h"
#include "block.h"
#include "gameState.h"
#ifndef CUSTOM_H_INCLUDED
#define CUSTOM_H_INCLUDED




void update_view(sf::RenderWindow &app, sf::View &camera, std::vector<block> &blocks, std::vector<std::shared_ptr<Entity>> &entities);
sf::View create_camera(sf::Sprite player);
//void movement(Player &player, std::vector<block> &sprites, sf::Vector2f &lastCheckpoint, cfg config);
void create_block(sf::RenderWindow &app, sf::View &camera, gameState *gs);
void destroy_block(std::vector<block> &sprites);
void respawn(sf::Sprite &player, sf::Vector2f lastCheckpoint);
void save_game(std::vector<block> &blocks, std::vector<std::shared_ptr<Entity>> entities);
void load_save(gameState &gs);
void texture_init(std::vector<sf::Texture> &textures);
void play(gameState *gs, std::shared_ptr<Player> &player, sf::View &camera, cfg config, double deltaTime);
void create(gameState &gs, std::shared_ptr<Player> &player, sf::RenderWindow &app, sf::View &camera, block &ghost, sf::Font &font);
cfg load_cfg();


void handleInput(sf::RenderWindow &app, sf::View camera, sf::Event event, std::shared_ptr<Player> &p, gameState *gs);
sf::Vector2f getClosestSnappingPoint(sf::Vector2f currentPosition, gameState *gs);


#endif // CUSTOM_H_INCLUDED
