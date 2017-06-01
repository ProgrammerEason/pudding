/*
 * pudding.vbo
 *
 * Copyright (c) 2017 Eason Zhou.
 */

#include <GL/glew.h>
#include <cassert>
#include "VBO.h"
#include "OpenGLMacros.h"

namespace pudding
{
    void VBO::ensureCapacity(unsigned int count)
    {
        assert(count > 0);
        
        if (_count + count > _capacity)
        {
            _capacity += glm::max(_capacity, count);
            _buffer = (V3F_C4B_T2F*)realloc(_buffer, _capacity * sizeof(V3F_C4B_T2F));
        }
    }
    
    bool VBO::init()
    {
        ensureCapacity(4);
        return true;
    }
    
    VBO::VBO() :
    _vbo(0),
    _buffer(nullptr),
    _capacity(0),
    _count(0)
    {
        
    }
    
    VBO::~VBO()
    {
		glDeleteBuffers(1, &_vbo);
    }
    
    VBO* VBO::create()
    {
        VBO *vbo = new VBO();
        if (!vbo->init())
        {
            delete vbo;
            vbo = nullptr;
        }
        
        return vbo;
    }
    
    void VBO::setup()
    {
        // generate, bind and set data
        glGenBuffers(1, &_vbo);
        glBindBuffer(GL_ARRAY_BUFFER, _vbo);
        glBufferData(GL_ARRAY_BUFFER, sizeof(V3F_C4B_T2F) * _capacity, _buffer, GL_STREAM_DRAW);
        
        // vertex
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(V3F_C4B_T2F), (GLvoid*)offsetof(V3F_C4B_T2F, vertices));
        
        // color
        glEnableVertexAttribArray(1);
        glVertexAttribPointer(1, 4, GL_UNSIGNED_BYTE, GL_TRUE, sizeof(V3F_C4B_T2F), (GLvoid*)offsetof(V3F_C4B_T2F, colors));
        
        // texcoord
        glEnableVertexAttribArray(2);
        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(V3F_C4B_T2F), (GLvoid*)offsetof(V3F_C4B_T2F, texCoords));
        
        // end
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }
    
    void VBO::addPoint(const glm::vec3& position, const Color4B &color, const glm::vec2 &texcoord)
    {
        ensureCapacity(1);
        
        V3F_C4B_T2F *pointer = (V3F_C4B_T2F*)(_buffer + _count);
        V3F_C4B_T2F point = {position, color, texcoord};
        *pointer = point;
        
        _count += 1;
    }
}
