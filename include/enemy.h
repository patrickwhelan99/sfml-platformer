#ifndef ENEMY_H
#define ENEMY_H

#include "Entity.h"

enum class AIState {none, attacking, defending, searching};

class enemy : public Entity
{
    public:
        enemy();
        virtual ~enemy();

        float Gethealth() { return health; }
        void Sethealth(float val) { health = val; }
        AIState GetcurrentState() { return currentState; }
        void SetcurrentState(AIState val) { currentState = val; }



    protected:

    private:
        float health = 100.0f;
        AIState currentState;

};

#endif // ENEMY_H
