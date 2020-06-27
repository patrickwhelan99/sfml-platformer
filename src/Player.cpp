#include "../include/Player.h"
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Window/Event.hpp>

Player::Player()
{

}

Player::~Player()
{
    //dtor
}

void Player::doMovement(std::vector<block> &blocks, std::vector<std::shared_ptr<Entity>> entities, cfg config, double deltaTime)
{
    Entity::doMovement(blocks, entities, config, deltaTime);

    if(this->getPosition().y > 2000)
        this->death();
}

void Player::death()
{
    this->setIsDead(true);
}

void Player::handleInput()
{
    const float speed = .2;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        this->addVelocity(sf::Vector2f(-speed, 0));
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && this->canJump)
        this->addVelocity(sf::Vector2f(0, -speed*1000));
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        this->addVelocity(sf::Vector2f(speed, 0));
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        this->addVelocity(sf::Vector2f(0, speed));
}

