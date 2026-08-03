#include <iostream>
#include <unistd.h>
#include "Simulator/Grid.h"
#include "Simulator/Robot.h"
#include "Simulator/AStar.h"
#include "Simulator/TTS.h"

int main()
{
    Grid grid;
    Robot robot;
    AStar astar;

    int width;
    int height;

    std::cout<<"Grid Width : ";
    std::cin>>width;

    std::cout<<"Grid Height : ";
    std::cin>>height;

    grid.Create(width,height);

    int rx,ry;

    std::cout<<"Robot X : ";
    std::cin>>rx;

    std::cout<<"Robot Y : ";
    std::cin>>ry;

    robot.SetPosition(rx,ry);

    int gx,gy;

    std::cout<<"Goal X : ";
    std::cin>>gx;

    std::cout<<"Goal Y : ";
    std::cin>>gy;

    grid.SetCell(gx,gy,'G');

    int obstacleCount;

    std::cout<<"Obstacle Count : ";
    std::cin>>obstacleCount;

    for(int i=0;i<obstacleCount;i++)
    {
        int x,y;

        std::cout<<"Obstacle "<<i+1<<" X : ";
        std::cin>>x;

        std::cout<<"Obstacle "<<i+1<<" Y : ";
        std::cin>>y;

        grid.SetCell(x,y,'#');
    }

    robot.Draw(grid);

    std::system("clear");

    grid.Render();

    if(astar.FindPath(grid,rx,ry,gx,gy))
    {
        std::vector<Node> path = astar.GetPath();

        for(Node node : path)
        {
            std::system("clear");

            grid.Clear();

            grid.SetCell(gx,gy,'G');

            robot.SetPosition(node.x,node.y);

            robot.Draw(grid);

            grid.Render();

            usleep(200000);
        }

        TTS::Speak("Goal Reached");
    }
    else
    {
        TTS::Speak("Path not found");
    }

    return 0;
}
