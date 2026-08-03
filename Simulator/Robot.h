#ifndef ROBOT_H
#define ROBOT_H

#include "Grid.h"

class Robot
{
private:
    int x;
    int y;

public:
    Robot();

    void SetPosition(int x, int y);

    void MoveUp();
    void MoveDown();
    void MoveLeft();
    void MoveRight();

    int GetX();
    int GetY();

    void Draw(Grid &grid);
};

#endif
