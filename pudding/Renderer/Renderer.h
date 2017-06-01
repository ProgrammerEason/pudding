/*
 * pudding.renderer
 *
 * Copyright (c) 2017 Eason Zhou.
 */

#ifndef RENDERER_H
#define RENDERER_H

namespace pudding
{
    enum class RendererType
    {
        Invalid = -1,
        OpenGL
    };
    
    class Renderer
    {
    protected:
        RendererType _type;
        
    public:
        Renderer();
        virtual ~Renderer();
        
        virtual bool init();
        
        virtual void render();
    };
}

#endif
