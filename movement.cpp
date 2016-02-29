#include "custom.h"
#include <SFML/Graphics.hpp>
#include <iostream>

sf::Vector2f movement(sf::Sprite &player, std::vector<block> &sprites, sf::Vector2f playerVector, float &vertSpeed, sf::Vector2f &lastCheckpoint, cfg config)
{
        const float speed = 0.15 * config.speed;
        const float gravity = 0.05 * config.gravity;
        bool canJump = false;
        float x = playerVector.x - playerVector.x / 2;
        float y = playerVector.y - playerVector.y / 2;


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            x -= speed;

	// check if proposed x movement will cause collision
        player.move(x, 0);

        bool hit = false;
	int counter = 0;
        for (auto const &sprite: sprites)
        {
            sf::FloatRect boxHitBox = sprite.getGlobalBounds();
 	    sf::FloatRect playerHitBox = player.getGlobalBounds();

            while (playerHitBox.intersects(boxHitBox))
            {
                hit = true;
                if(sprite.deadly == true)
                    respawn(player, lastCheckpoint);

                if(sprite.breakable == true)
                    sprites.erase(sprites.begin() + counter);

		if(sprite.savePoint)
                {
                    sf::Vector2f temp = sprite.getPosition();
                    temp.y -= 50;
                    lastCheckpoint = temp;
                }
	     player.move(-x, y);
	     playerHitBox = player.getGlobalBounds();
            }
        }

        }// end left if




        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            x += speed;

	// check if proposed x movement will cause collision
        player.move(x, 0);

        bool hit = false;
	int counter = 0;
        for (auto const &sprite: sprites)
        {
            sf::FloatRect boxHitBox = sprite.getGlobalBounds();
 	    sf::FloatRect playerHitBox = player.getGlobalBounds();

            while (playerHitBox.intersects(boxHitBox))
            {
                hit = true;
                if(sprite.deadly == true)
                    respawn(player, lastCheckpoint);

                if(sprite.breakable == true)
                    sprites.erase(sprites.begin() + counter);

		if(sprite.savePoint)
                {
                    sf::Vector2f temp = sprite.getPosition();
                    temp.y -= 50;
                    lastCheckpoint = temp;
                }
	     player.move(-x, 0);
	     playerHitBox = player.getGlobalBounds();
            }
        }


        } // end right if




/********************************************************************************/
/**                           X - Stuff                                        **/
/**                                                                            **/
/**                           Y - Stuff                                        **/
/********************************************************************************/

	y += gravity;


	// check if proposed y movement will cause collision
        player.move(0, y);

        bool hit = false;
	int counter = 0;
	bool canjump = false;
        for (auto const &sprite: sprites)
        {
            sf::FloatRect boxHitBox = sprite.getGlobalBounds();
 	    sf::FloatRect playerHitBox = player.getGlobalBounds();

            while (playerHitBox.intersects(boxHitBox))
            {
                canjump = true;
		hit = true;
                if(sprite.deadly == true)
                    respawn(player, lastCheckpoint);

                if(sprite.breakable == true)
                    sprites.erase(sprites.begin() + counter);

		if(sprite.savePoint)
                {
                    sf::Vector2f temp = sprite.getPosition();
                    temp.y -= 50;
                    lastCheckpoint = temp;
                }
	     y -= 1;
	     player.move(0, y);
	     playerHitBox = player.getGlobalBounds();
            }
        }



	y = 0;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && canjump)
                {
                   vertSpeed = speed*1000; // set initial velocity for the jump
		   y -= gravity;
                }

        if (vertSpeed > 0)
        {
            vertSpeed -= vertSpeed / 1.5; // smaller the division the more 'steps' in the jump (smoother)
	    y -= vertSpeed;
        }
        else
        {
            vertSpeed = 0;
        }




	player.move(0, y);

	hit = false;
	counter = 0;
	canjump = false;
        for (auto const &sprite: sprites)
        {
            sf::FloatRect boxHitBox = sprite.getGlobalBounds();
 	    sf::FloatRect playerHitBox = player.getGlobalBounds();

            while (playerHitBox.intersects(boxHitBox))
            {
		hit = true;
                if(sprite.deadly == true)
                    respawn(player, lastCheckpoint);

                if(sprite.breakable == true)
                    sprites.erase(sprites.begin() + counter);

		if(sprite.savePoint)
                {
                    sf::Vector2f temp = sprite.getPosition();
                    temp.y -= 50;
                    lastCheckpoint = temp;
                }
	     y = 0;
	     y += 1;
	     player.move(0, y);
	     playerHitBox = player.getGlobalBounds();
            }
        }

    playerVector = {x, y};

return playerVector;
}
