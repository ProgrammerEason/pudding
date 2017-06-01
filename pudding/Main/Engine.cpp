/*
 * pudding.engine
 *
 * Copyright (c) 2017 Eason Zhou.
 */

#include <iostream>
#include "Engine.h"
#include "Renderer/Renderer.h"

#define __APPLE__

#ifdef __APPLE__
#include "Renderer/OpenGLRenderer.h"
#endif

#define DEFAULT_FPS 60
#define OPENGL_VERSION_MAJOR 3
#define OPENGL_VERSION_MINOR 3

namespace pudding
{
    void keyfun(GLFWwindow *window, int key, int scancode, int action, int mods)
    {
        if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        {
            glfwSetWindowShouldClose(window, GL_TRUE);
        }
    }
    
    Engine::Engine() :
    _window(nullptr),
    _renderer(nullptr),
    _frameRate(DEFAULT_FPS),
    _frameRateCount(0),
    _isLimitedFrameRate(true)
    {
        
    }
    
    Engine::Engine(const Engine&)
    {
        
    }
    
    Engine& Engine::operator=(const Engine&)
    {
        return *this;
    }
    
    void Engine::render()
    {
        _renderer->render();
        
        glfwSwapBuffers(_window);
        glfwPollEvents();
    }
    
    Engine::~Engine()
    {
        
    }
    
    Engine* Engine::getInstance()
    {
        static Engine instance;
        return &instance;
    }
    
    bool Engine::init(unsigned int width, unsigned int height, const std::string &title)
    {
        _width = width;
        _height = height;
        _title = title;
        
        if (!glfwInit())
        {
            std::cout << "glfw init failed" << std::endl;
            return false;
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, OPENGL_VERSION_MAJOR);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, OPENGL_VERSION_MINOR);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
        
        GLFWwindow *window = glfwCreateWindow(_width, _height, _title.c_str(), NULL, NULL);
        if (!window)
        {
            std::cout << "glfw create window failed" << std::endl;
            
            glfwTerminate();
            return false;
        }
        
        glfwSetKeyCallback(window, keyfun);
        glfwMakeContextCurrent(window);
        
        _window = window;
        
#ifdef __APPLE__
        _renderer = new OpenGLRenderer();
#endif
        
        if (!_renderer->init())
        {
            glfwTerminate();
            return false;
        }
        
        _lastTime = _frameRateCountLastTime = glfwGetTime();
        
        return true;
    }
    
    void Engine::gameLoop()
    {
        while (!glfwWindowShouldClose(_window))
        {
            double nowTime = glfwGetTime();
            if (!_isLimitedFrameRate)
            {
                _frameRateCount++;
                render();
            }
            else
            {
                if (nowTime - _lastTime >= 1.0f / _frameRate)
                {
                    _lastTime = nowTime;
                    _frameRateCount++;
                    render();
                }
            }
            
            if (nowTime - _frameRateCountLastTime >= 1.0f)
            {
                _frameRateCountLastTime = nowTime;
                _frameRateCount = 0;
            }
        }
        
        glfwDestroyWindow(_window);
        glfwTerminate();
    }
    
    void Engine::setVSyncEnabled(bool enabled)
    {
        if (enabled)
        {
            glfwSwapInterval(1);
        }
        else
        {
            glfwSwapInterval(0);
        }
    }
}
