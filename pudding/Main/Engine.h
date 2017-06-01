/*
 * pudding.engine
 *
 * Copyright (c) 2017 Eason Zhou.
 */

#ifndef ENGINE_H
#define ENGINE_H

#include <GLFW/glfw3.h>
#include <functional>
#include <string>
#include "Renderer/Renderer.h"

namespace pudding
{
    class Engine
    {
    private:
        unsigned int _width;
        unsigned int _height;
        std::string _title;
        GLFWwindow *_window;
        Renderer *_renderer;
        
        bool _isLimitedFrameRate;
        double _lastTime;
        unsigned int _frameRate;
        double _frameRateCountLastTime;
        unsigned int _frameRateCount;
        
        Engine();
        Engine(const Engine&);
        Engine& operator=(const Engine&);
        
        void render();
        
    public:
        ~Engine();
        
        static Engine* getInstance();
        
        bool init(unsigned int width, unsigned int height, const std::string &title);
        
        void gameLoop();
        
        void setVSyncEnabled(bool enabled);
        
        void setIsLimitedFrameRate(bool limited)
        {
            _isLimitedFrameRate = limited;
        }
        
        void setFrameRate(unsigned int frameRate)
        {
            _frameRate = frameRate;
        }
    };
}

#endif
