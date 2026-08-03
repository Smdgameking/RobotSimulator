#include "AStar.h"

#include <algorithm>
#include <cmath>

AStar::AStar()
{
}

void AStar::Clear()
{
    openList.clear();
    closedList.clear();
    path.clear();
}

int AStar::Heuristic(int x1, int y1, int x2, int y2)
{
    return std::abs(x1 - x2) + std::abs(y1 - y2);
}

bool AStar::IsInOpenList(int x, int y)
{
    for (const Node& node : openList)
    {
        if (node.x == x && node.y == y)
        {
            return true;
        }
    }

    return false;
}

bool AStar::IsInClosedList(int x, int y)
{
    for (const Node& node : closedList)
    {
        if (node.x == x && node.y == y)
        {
            return true;
        }
    }

    return false;
}

Node* AStar::GetLowestFCostNode()
{
    if (openList.empty())
    {
        return nullptr;
    }

    int lowestIndex = 0;

    for (int i = 1; i < openList.size(); i++)
    {
        if (openList[i].fCost < openList[lowestIndex].fCost)
        {
            lowestIndex = i;
        }
        else if (openList[i].fCost == openList[lowestIndex].fCost)
        {
            if (openList[i].hCost < openList[lowestIndex].hCost)
            {
                lowestIndex = i;
            }
        }
    }

    return &openList[lowestIndex];
}

void AStar::ReconstructPath(Node* goalNode)
{
    path.clear();

    Node* current = goalNode;

    while (current != nullptr)
    {
        path.push_back(*current);

        if (current->parent == nullptr)
        {
            break;
        }

        current = current->parent;
    }

    std::reverse(path.begin(), path.end());
}

std::vector<Node> AStar::GetPath()
{
    return path;
}

bool AStar::FindPath(
    Grid& grid,
    int startX,
    int startY,
    int goalX,
    int goalY)
{
    Clear();

    Node start(startX, startY);

    start.gCost = 0;
    start.hCost = Heuristic(startX, startY, goalX, goalY);
    start.CalculateFCost();

    openList.push_back(start);

    while (!openList.empty())
    {
        Node* current = GetLowestFCostNode();

        if (current == nullptr)
        {
            return false;
        }

        if (current->x == goalX &&
            current->y == goalY)
        {
            ReconstructPath(current);
            return true;
        }

        Node currentCopy = *current;

        openList.erase(
            std::remove_if(
                openList.begin(),
                openList.end(),
                [&](const Node& n)
                {
                    return n.x == currentCopy.x &&
                           n.y == currentCopy.y;
                }),
            openList.end());

        closedList.push_back(currentCopy);

        const int dx[4] = {0, 0, -1, 1};
        const int dy[4] = {-1, 1, 0, 0};

        for (int i = 0; i < 4; i++)
        {
            int nx = currentCopy.x + dx[i];
            int ny = currentCopy.y + dy[i];

            if (!grid.IsInside(nx, ny))
                continue;

            if (!grid.IsWalkable(nx, ny))
                continue;

            if (IsInClosedList(nx, ny))
                continue;

            int newG = currentCopy.gCost + 1;

            bool found = false;

            for (Node& node : openList)
            {
                if (node.x == nx &&
                    node.y == ny)
                {
                    found = true;

                    if (newG < node.gCost)
                    {
                        node.gCost = newG;
                        node.hCost =
                            Heuristic(
                                nx,
                                ny,
                                goalX,
                                goalY);

                        node.CalculateFCost();

                        node.parentX = currentCopy.x;
                        node.parentY = currentCopy.y;
                    }

                    break;
                }
            }

            if (!found)
            {
                Node neighbour(nx, ny);

                neighbour.gCost = newG;

                neighbour.hCost =
                    Heuristic(
                        nx,
                        ny,
                        goalX,
                        goalY);

                neighbour.CalculateFCost();

                neighbour.parentX = currentCopy.x;
                neighbour.parentY = currentCopy.y;

                openList.push_back(neighbour);
            }
        }
    }

    return false;
}

void AStar::ReconstructPath(Node* goalNode)
{
    path.clear();

    Node current = *goalNode;

    while (true)
    {
        path.push_back(current);

        if (current.parentX == -1 &&
            current.parentY == -1)
        {
            break;
        }

        bool found = false;

        for (const Node& node : closedList)
        {
            if (node.x == current.parentX &&
                node.y == current.parentY)
            {
                current = node;
                found = true;
                break;
            }
        }

        if (!found)
        {
            break;
        }
    }

    std::reverse(path.begin(), path.end());
}

std::vector<Node> AStar::GetPath()
{
    return path;
}

