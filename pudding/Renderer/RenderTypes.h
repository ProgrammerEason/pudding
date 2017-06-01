/*
 * pudding.renderTypes
 *
 * Copyright (c) 2017 Eason Zhou.
 */

#ifndef RENDER_TYPES_H
#define RENDER_TYPES_H

#include <glm/glm.hpp>

namespace pudding
{
    struct Color4B;
    struct Color4F;
    
    struct Color3B
    {
        unsigned char r;
        unsigned char g;
        unsigned char b;
        
        Color3B();
        Color3B(unsigned char _r, unsigned char _g, unsigned char _b);
        explicit Color3B(const Color4B &color);
        explicit Color3B(const Color4F &color);
        
        bool operator ==(const Color3B &right) const;
        bool operator ==(const Color4B &right) const;
        bool operator ==(const Color4F &right) const;
        bool operator !=(const Color3B &right) const;
        bool operator !=(const Color4B &right) const;
        bool operator !=(const Color4F &right) const;
        
        bool equals(const Color3B &other) const
        {
            return (*this == other);
        }
        
        static const Color3B WHITE;
        static const Color3B YELLOW;
        static const Color3B BLUE;
        static const Color3B GREEN;
        static const Color3B RED;
        static const Color3B MAGENTA;
        static const Color3B BLACK;
        static const Color3B ORANGE;
        static const Color3B GRAY;
    };
    
    struct Color4B
    {
        unsigned char r;
        unsigned char g;
        unsigned char b;
        unsigned char a;
        
        Color4B();
        Color4B(unsigned char _r, unsigned char _g, unsigned char _b, unsigned char _a);
        explicit Color4B(const Color3B &color, unsigned char _a = 255);
        explicit Color4B(const Color4F &color);
        
        inline void set(unsigned char _r, unsigned char _g, unsigned char _b, unsigned char _a)
        {
            r = _r;
            g = _g;
            b = _b;
            a = _a;
        }
        
        bool operator ==(const Color4B &right) const;
        bool operator ==(const Color3B &right) const;
        bool operator ==(const Color4F &right) const;
        bool operator !=(const Color4B &right) const;
        bool operator !=(const Color3B &right) const;
        bool operator !=(const Color4F &right) const;
        
        static const Color4B WHITE;
        static const Color4B YELLOW;
        static const Color4B BLUE;
        static const Color4B GREEN;
        static const Color4B RED;
        static const Color4B MAGENTA;
        static const Color4B BLACK;
        static const Color4B ORANGE;
        static const Color4B GRAY;
    };
    
    struct Color4F
    {
        float r;
        float g;
        float b;
        float a;
        
        Color4F();
        Color4F(float _r, float _g, float _b, float _a);
        explicit Color4F(const Color3B &color, float _a = 1.0f);
        explicit Color4F(const Color4B &color);
        
        bool operator ==(const Color4F &right) const;
        bool operator ==(const Color3B &right) const;
        bool operator ==(const Color4B &right) const;
        bool operator !=(const Color4F &right) const;
        bool operator !=(const Color3B &right) const;
        bool operator !=(const Color4B &right) const;
        
        bool equals(const Color4F &other) const
        {
            return (*this == other);
        }
        
        static const Color4F WHITE;
        static const Color4F YELLOW;
        static const Color4F BLUE;
        static const Color4F GREEN;
        static const Color4F RED;
        static const Color4F MAGENTA;
        static const Color4F BLACK;
        static const Color4F ORANGE;
        static const Color4F GRAY;
    };
    
    struct V3F_C4B_T2F
    {
        glm::vec3 vertices;
        Color4B colors;
        glm::vec2 texCoords;
    };
}

#endif
