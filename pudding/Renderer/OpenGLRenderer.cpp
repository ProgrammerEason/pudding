/*
 * pudding.openGLRenderer
 *
 * Copyright (c) 2017 Eason Zhou.
 */

#define GLEW_STATIC

#include <GL/glew.h>
#include <iostream>
#include "OpenGLRenderer.h"

namespace pudding
{
    OpenGLRenderer::OpenGLRenderer()
    {
        _type = RendererType::OpenGL;
    }
    
    OpenGLRenderer::~OpenGLRenderer()
    {
        
    }
    
    bool OpenGLRenderer::init()
    {
        GLenum ret = glewInit();
        if (ret != GLEW_OK)
        {
            std::cout << "glew init failed" << std::endl;
            std::cout << "glew version:" << glewGetString(GLEW_VERSION) << std::endl;
            std::cout << glewGetErrorString(ret) << std::endl;
            
            return false;
        }
        
        return true;
    }
    
    void OpenGLRenderer::render()
    {
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
    }
}
