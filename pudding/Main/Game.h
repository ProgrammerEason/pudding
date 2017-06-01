/*
 * pudding.game
 *
 * Copyright (c) 2017 Eason Zhou.
 */

#ifndef GAME_H
#define GAME_H

namespace pudding
{
    class Game
    {
    private:
        Game();
        Game(const Game&);
        Game& operator=(const Game&);
        
        void gameCreated();
        
        void gameDestroyed();
        
    public:
        ~Game();
        
        static Game* getInstance();
        
        void run();
    };
}

#endif
