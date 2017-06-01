/*
 * pudding.vbo
 *
 * Copyright (c) 2017 Eason Zhou.
 */

#ifndef VBO_H
#define VBO_H

#include "Renderer/RenderTypes.h"

namespace pudding
{
    class VBO
    {
    private:
		GLuint _vbo;
		V3F_C4B_T2F *_buffer;
		unsigned int _capacity;
		unsigned int _count;
        
        void ensureCapacity(unsigned int count);
        
        bool init();
        
    public:
        VBO();
        ~VBO();
        
        static VBO* create();
        
        void setup();
        
        void addPoint(const glm::vec3& position, const Color4B &color, const glm::vec2 &texcoord);
    };
}

#endif
