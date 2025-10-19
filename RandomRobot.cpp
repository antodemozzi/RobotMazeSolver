#include "RandomRobot.h"

RandomRobot::RandomRobot(){
	//useless =6;
}

void RandomRobot::move(Maze& m){
	bool condition = true;

	if(m.getChar() == 'E'){
		condition = false;
	}

	while(condition){

		int num = randomNumber();

		if(num == 1){
			m.moveNorthWest();
		}
		else if(num == 2){
			m.moveUp();
		}
		else if(num == 3){
			m.moveNorthEast();
		}
		else if(num == 4){
			m.moveRight();
		}
		else if(num == 5){
			m.moveSouthEast();
		}
		else if(num == 6){
			m.moveDown();
		}
		else if(num == 7){
			m.moveSouthWest();
		}
		else if(num == 8){
			m.moveLeft();
		}


		if(m.getChar() == 'E'){
			condition = false;
		}
	}
	std::cout << "exit position ";
	m.printPosition();
}

int RandomRobot::randomNumber(){
	std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(1,8); // distribution in range [1, 8]
    int ret = dist6(rng);
    return ret;
}