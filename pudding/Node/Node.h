/*
 * pudding.node
 *
 * Copyright (c) 2017 Eason Zhou.
 */

#ifndef NODE_H
#define NODE_H

#include "Renderer/Renderer.h"

namespace pudding
{
    class Node
    {
    private:
        
    public:
        Node();
        virtual ~Node();
        
        virtual void render(Renderer *renderer);
    };
}

#endif
