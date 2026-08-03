#include "Robot.h"

Robot::Robot()
{
    x = 0;
    y = 0;
}

void Robot::SetPosition(int px, int py)
{
    x = px;
    y = py;
}

void Robot::MoveUp()
{
    y--;
}

void Robot::MoveDown()
{
    y++;
}

void Robot::MoveLeft()
{
    x--;
}

void Robot::MoveRight()
{
    x++;
}

int Robot::GetX()
{
    return x;
}

int Robot::GetY()
{
    return y;
}

void Robot::Draw(Grid &grid)
{
    grid.SetCell(x, y, 'R');
}
