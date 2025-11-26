
#include "RightHandRuleRobot.h"

RightHandRuleRobot::RightHandRuleRobot(){}

bool RightHandRuleRobot::isExitNear(Maze& m){
	for(int i = 1 ; i < 9; i++){
		if(m.getCharAround(i) == 'E'){
			return true;
		}
	}
	return false;
}

void RightHandRuleRobot::goToExit(Maze& m){
	for(int i=1 ; i<9 ; i++){

		if(m.getCharAround(i) == 'E'){
			std::cout << "the exit is at ";

			if(i == 1){
				m.moveNorthWest();
			}
			else if(i == 2){
				m.moveUp();
			}
			else if(i == 3){
				m.moveNorthEast();
			}
			else if(i == 4){
				m.moveRight();
			}
			else if(i == 5){
				m.moveSouthEast();
			}
			else if(i == 6){
				m.moveDown();
			}
			else if(i == 7){
				m.moveSouthWest();
			}
			else if(i == 8){
				m.moveLeft();
			}
			m.printPosition();
			return;
		}
	}
}

void RightHandRuleRobot::goUp(Maze& m){
	while( m.getCharAround(4) == '*' && m.getCharAround(2) != '*'){

		if(isExitNear(m) == true){
			goToExit(m);
			return;
		}
		m.moveUp();
	}
	if(m.getCharAround(4) == '*' && m.getCharAround(2) == '*' && m.getCharAround(8) != '*'){
		goLeft(m);
	}
	else if(m.getCharAround(5) == '*' && m.getCharAround(4) != '*'){
		m.moveRight();
		goRight(m);
	}
	else if(m.getCharAround(8) == '*' && m.getCharAround(2) == '*' && m.getCharAround(4) == '*'){
		goDown(m);
	}
}

void RightHandRuleRobot::goRight(Maze& m){
	while(m.getCharAround(6) == '*' && m.getCharAround(4) != '*'){

		if(isExitNear(m) == true){
			goToExit(m);
			return;
		}
		m.moveRight();
	}
	if(m.getCharAround(7) == '*' && m.getCharAround(6) != '*'){
		m.moveDown();
		goDown(m);
	}
	else if(m.getCharAround(6) == '*' && m.getCharAround(4) == '*' && m.getCharAround(2) != '*'){
		goUp(m);
	}
	else if(m.getCharAround(6) == '*' && m.getCharAround(4) == '*' && m.getCharAround(2) == '*'){
		goLeft(m);
	}
}

void RightHandRuleRobot::goLeft(Maze& m){
	while(m.getCharAround(2) == '*' && m.getCharAround(8) != '*'){

		if(isExitNear(m) == true){
			goToExit(m);
			return;
		}
		m.moveLeft();
	}
	if(m.getCharAround(2) == '*' && m.getCharAround(8) == '*' && m.getCharAround(6) != '*'){
		goDown(m);
	}
	else if(m.getCharAround(2) != '*' && m.getCharAround(3) == '*'){
		//se no non funziona
		m.moveUp();
		goUp(m);
	}
	else if(m.getCharAround(6) == '*' && m.getCharAround(8) == '*' && m.getCharAround(2) == '*'){
		goRight(m);
	}
}

void RightHandRuleRobot::goDown(Maze& m){
	while(m.getCharAround(8) == '*' &&m.getCharAround(6) != '*' ){
		
		if(isExitNear(m) == true){
			goToExit(m);
			return;
		}
		
		m.moveDown();
	}
	if(m.getCharAround(8) == '*' && m.getCharAround(6) == '*' && m.getCharAround(4) != '*'){
		goRight(m);
	}
	else if(m.getCharAround(8) != '*' && m.getCharAround(1) == '*'){
		m.moveLeft();
		goLeft(m);
	}
	else if(m.getCharAround(4) == '*' && m.getCharAround(6) == '*' && m.getCharAround(8) == '*'){
		goUp(m);
	}
}

void RightHandRuleRobot::startRight(Maze& m){
	bool rightClear = true;
	while(rightClear){
		if(m.getCharAround(4) == '*' || m.getCharAround(4)=='E' ){
			rightClear = false;
		}
		else{
			m.moveRight();
		}
	}
}
//ci sono due cose che mi fanno girare diciamo
//la prima è quando colpisco un muro con la testa
//la seconda è quando non ho più la mano destra sul muro
//idea : 4 funzioni che si chiamano a vicenda e sanno solo andare nelle 4 direzioni

void RightHandRuleRobot::move(Maze& m){
	bool condition = true;
	startRight(m);

	if(isExitNear(m) == true){
		goToExit(m);
		return;
	}
	goUp(m);

}
