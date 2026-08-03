#ifndef GRID_H
#define GRID_H

#include <vector>

class Grid
{
private:
    int width;
    int height;

    std::vector<std::vector<char>> cells;

public:

    Grid();

    void Create(int width, int height);

    void Clear();

    void Render();

    bool IsWalkable(int x, int y);

    void SetCell(int x, int y, char value);

    char GetCell(int x, int y);

    bool IsInside(int x, int y);

    int GetWidth();

    int GetHeight();
};

#endif
