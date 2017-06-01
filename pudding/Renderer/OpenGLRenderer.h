/*
 * pudding.openGLRenderer
 *
 * Copyright (c) 2017 Eason Zhou.
 */

#ifndef OPENGL_RENDERER_H
#define OPENGL_RENDERER_H

#include "Renderer.h"

namespace pudding
{
    class OpenGLRenderer : public Renderer
    {
    public:
        OpenGLRenderer();
        virtual ~OpenGLRenderer();
        
        virtual bool init() override;
        
        virtual void render() override;
    };
}

#endif
