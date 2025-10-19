
#include "Maze.h"
#include "RandomRobot.h"
#include "RightHandRuleRobot.h"

int main(){//g++ -o test Maze.cpp Robot.cpp RandomRobot.cpp RightHandRuleRobot.cpp tester.cpp
	
	std::string file = "ciao.txt";
	Maze lab(file);
	lab.printPosition();
	RandomRobot rob;
	rob.move(lab);

	Maze room(file);
	room.printPosition();
	RightHandRuleRobot robottino;
	robottino.move(room);


	return 1;
}
