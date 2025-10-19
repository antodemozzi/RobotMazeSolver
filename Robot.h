#ifndef ROBOT_H
#define ROBOT_H

#include "Maze.h"

class Robot{
	private:
	int useless{0};

	public :
	Robot();
	virtual void move(Maze& m);
};

#endif