#include <iostream>
#include "maze.h"
#include "random.h"
#include "vector.h"
#include "set.h"
#include "grid.h"
#include "queue.h"
#include "stack.h"

using namespace std;

Maze generateMaze(int nRows, int nCols);
int cmpRow(pointT a, pointT b);
pointT randomNeighbor(Maze &maze, pointT &p1);
Vector<pointT> getNeighbors(Maze &maze, pointT &p1);
Stack<pointT> solveMaze(Maze &maze);
bool isSamePosition(pointT &p, pointT &des);
void drawRoute(Maze &maze, Stack<pointT> &route);

int main()
{
    Maze maze = generateMaze(17, 30);
    Stack<pointT> route = solveMaze(maze);
    drawRoute(maze, route);
    return 0;
}

Maze generateMaze(int nRows, int nCols)
{
    // init Maze
    Maze maze = Maze(nRows, nCols, true);
    maze.draw();
    Randomize();
    int row = RandomInteger(0, maze.numRows() - 1);
    int col = RandomInteger(0, maze.numCols() - 1);
    pointT starter;
    starter.row = row;
    starter.col = col;
    Set<pointT> includedSet(cmpRow);
    includedSet.add(starter);

    int count = nRows * nCols - 1;

    while (includedSet.size() <= count)
    {
        pointT neighbor = randomNeighbor(maze, starter);
        if (!includedSet.contains(neighbor))
            maze.setWall(starter, neighbor, false);
        includedSet.add(neighbor);
        starter = neighbor;
    }

    return maze;
}

pointT randomNeighbor(Maze &maze, pointT &p1)
{
    Vector<pointT> neighbors = getNeighbors(maze, p1);
    if (neighbors.size() == 0)
        return p1;

    int random = RandomInteger(0, neighbors.size() - 1);
    return neighbors[random];
}
Vector<pointT> getNeighbors(Maze &maze, pointT &p1)
{
    Vector<pointT> neighbors;
    pointT up;
    up.row = p1.row + 1;
    up.col = p1.col;

    pointT down = up;
    down.row -= 2;

    pointT left;
    left.row = p1.row;
    left.col = p1.col - 1;

    pointT right = left;
    right.col += 2;
    neighbors.add(up);
    neighbors.add(down);
    neighbors.add(left);
    neighbors.add(right);

    for (int i = neighbors.size() - 1; i >= 0; i--)
    {
        if (!maze.pointInBounds(neighbors[i]))
            neighbors.removeAt(i);
    }
    return neighbors;
}

int cmpRow(pointT a, pointT b)
{
    if (a.row == b.row && a.col == b.col)
        return 0;
    else if ((a.row < b.row) || (a.row == b.row && a.col < b.col))
        return -1;
    else
        return 1;
}

Stack<pointT> solveMaze(Maze &maze)
{
    pointT src;
    src.row = 0;
    src.col = 0;
    pointT des;
    des.row = maze.numRows() - 1;
    des.col = maze.numCols() - 1;

    Stack<pointT> startPath;
    startPath.push(src);
    Queue<Stack<pointT>> possibilities;
    possibilities.enqueue(startPath);

    Stack<pointT> route;
    Set<pointT> visited(cmpRow);
    visited.add(src);
    while (!possibilities.isEmpty())
    {
        route = possibilities.dequeue();
        pointT lastPos = route.peek();
        if (isSamePosition(lastPos, des))
            return route;
        visited.add(lastPos);
        Vector<pointT> neighbors = getNeighbors(maze, lastPos);
        for (int i = 0; i < neighbors.size(); i++)
        {
            pointT neighbor = neighbors[i];
            if (!visited.contains(neighbor) && !maze.isWall(lastPos, neighbor))
            {
                Stack<pointT> tempStack = route;
                tempStack.push(neighbor);
                possibilities.enqueue(tempStack);
            }
        }
    }
}

bool isSamePosition(pointT &p, pointT &des)
{
    return p.row == des.row && p.col == des.col;
}

void drawRoute(Maze &maze, Stack<pointT> &route)
{
    while (!route.isEmpty())
    {
        pointT t = route.pop();
        maze.drawMark(t, "blue");
    }
}