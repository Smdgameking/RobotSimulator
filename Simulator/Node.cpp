#include "Node.h"

Node::Node()
{
    x = 0;
    y = 0;

    gCost = 0;
    hCost = 0;
    fCost = 0;

    parent = nullptr;
}

Node::Node(int px, int py)
{
    x = px;
    y = py;

    gCost = 0;
    hCost = 0;
    fCost = 0;

    parent = nullptr;
}

void Node::CalculateFCost()
{
    fCost = gCost + hCost;
}
