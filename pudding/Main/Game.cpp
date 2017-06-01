/*
 * pudding.game
 *
 * Copyright (c) 2017 Eason Zhou.
 */

#include "Game.h"
#include "Engine.h"

namespace pudding
{
    Game::Game()
    {
        
    }
    
    Game::Game(const Game&)
    {
        
    }
    
    Game& Game::operator=(const Game&)
    {
        return *this;
    }
    
    void Game::gameCreated()
    {
        
    }
    
    void Game::gameDestroyed()
    {
        
    }

    Game::~Game()
    {
        
    }
    
    Game* Game::getInstance()
    {
        static Game instance;
        return &instance;
    }
    
    void Game::run()
    {
        Engine *engine = Engine::getInstance();
        engine->init(800, 600, "Demo");
        
        gameCreated();
        
        engine->setVSyncEnabled(false);
        engine->setIsLimitedFrameRate(true);
        engine->gameLoop();
        
        gameDestroyed();
    }
}
