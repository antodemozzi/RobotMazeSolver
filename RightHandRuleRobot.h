#ifndef RIGHTHANDRULEROBOT_H
#define RIGHTHANDRULEROBOT_H

#include "Robot.h"


class RightHandRuleRobot : Robot{
	private :
	bool isExitNear(Maze& m);
	void goToExit(Maze& m);
	void goUp(Maze& m);
	void goLeft(Maze& m);
	void goRight(Maze& m);
	void goDown(Maze& m);
	void startRight(Maze& m);


	public :
	RightHandRuleRobot();
	void move(Maze& m);
};

#endif