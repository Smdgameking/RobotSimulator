#include "Node.h"

Node::Node()
{
    x = 0;
    y = 0;

    gCost = 0;
    hCost = 0;
    fCost = 0;

    parentX = -1;
    parentY = -1;
}

Node::Node(int px, int py)
{
    x = px;
    y = py;

    gCost = 0;
    hCost = 0;
    fCost = 0;

    parentX = -1;
    parentY = -1;
}

void Node::CalculateFCost()
{
    fCost = gCost + hCost;
}
