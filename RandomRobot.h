#ifndef RANDOMROBOT_H
#define RANDOMROBOT_H

#include "Robot.h"
#include <Random>

class RandomRobot : Robot{

	private :
	int randomNumber();

	public :
	RandomRobot();
	void move(Maze& m);

};


#endif