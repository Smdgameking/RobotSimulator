#ifndef ASTAR_H
#define ASTAR_H

#include <vector>

#include "Grid.h"
#include "Node.h"

class AStar
{
private:

    std::vector<Node> openList;
    std::vector<Node> closedList;
    std::vector<Node> path;

    Node* GetLowestFCostNode();

    bool IsInOpenList(int x, int y);

    bool IsInClosedList(int x, int y);

    int Heuristic(int x1, int y1, int x2, int y2);

    void ReconstructPath(Node* goalNode);

public:

    AStar();

    bool FindPath(
        Grid& grid,
        int startX,
        int startY,
        int goalX,
        int goalY
    );

    std::vector<Node> GetPath();

    void Clear();
};

#endif
