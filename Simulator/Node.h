#ifndef NODE_H
#define NODE_H

class Node
{
public:
    int x;
    int y;

    int gCost;
    int hCost;
    int fCost;

    int parentX;
    int parentY;

    Node();

    Node(int x, int y);

    void CalculateFCost();

    bool operator==(const Node& other) const
    {
        return x == other.x && y == other.y;
    }
};

#endif
