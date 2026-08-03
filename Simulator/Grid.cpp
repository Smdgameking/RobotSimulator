#include "Grid.h"

#include <iostream>

Grid::Grid()
{
    width = 0;
    height = 0;
}

void Grid::Create(int w, int h)
{
    width = w;
    height = h;

    cells = std::vector<std::vector<char>>
    (
        height,
        std::vector<char>(width, '.')
    );
}

void Grid::Clear()
{
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            cells[y][x] = '.';
        }
    }
}

bool Grid::IsWalkable(int x, int y)
{
    if (!IsInside(x, y))
        return false;

    return cells[y][x] != '#';
}

void Grid::Render()
{
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            std::cout << cells[y][x] << ' ';
        }

        std::cout << '\n';
    }
}

void Grid::SetCell(int x, int y, char value)
{
    if (IsInside(x, y))
    {
        cells[y][x] = value;
    }
}

char Grid::GetCell(int x, int y)
{
    if (IsInside(x, y))
    {
        return cells[y][x];
    }

    return '\0';
}

bool Grid::IsInside(int x, int y)
{
    return (x >= 0 &&
            x < width &&
            y >= 0 &&
            y < height);
}

int Grid::GetWidth()
{
    return width;
}

int Grid::GetHeight()
{
    return height;
}
