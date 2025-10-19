#include "Maze.h"


Maze::Maze(std::string file_name){
	std::ifstream my_maze;
	my_maze.open(file_name);

	for(int row = 0 ; row < 9 ; row++){
		for(int col = 0 ; col < 9; col++){
			matrix[row][col] = my_maze.get();

			if(matrix[row][col] == 'S'){
				x_pos = col;
				y_pos = row;
			}

			/*
			if(matrix[row][col] == 'E'){
				x_exit_position = col;
				y_exit_position = row;
			}
			*/	
		}
		char nextLineChar = my_maze.get();
	}

	checkBorders();
	checkStartAndExit();
}

int Maze::getXpos(){
	return x_pos;
}
int Maze::getYpos(){
	return y_pos;
}

void Maze::checkBorders(){
	bool allGood = true;
	for(int row = 0 ; row < 9 ; row++){

		if(row == 0 || row == 8){
			for(int col =0; col<9 ; col++){
				if(matrix[row][col] =='*' || matrix[row][col] == 'S' || matrix[row][col] == 'E'){
					allGood = true;
				}
				else{
					allGood = false;
				}
			}
		}
		else{
			if(matrix[row][0] == '*' || matrix[row][0] == 'S' || matrix[row][0] == 'E'){
				allGood = true;
			}else{
				allGood = false;
			}
			if(matrix[row][8] == '*' || matrix[row][8] == 'S' || matrix[row][8] == 'E'){
				allGood = true;
			}else{
				allGood = false;
			}
		}
	}
	if(!allGood){
		throw std::invalid_argument("borders are not closed");
	}
}

char Maze::getChar(){

	return matrix[y_pos][x_pos];
}

void Maze::checkPosition(){

	if(x_pos > 9 || y_pos > 9 || x_pos <0 || y_pos <0){
		//throw std::invalid_argument("position out of bounds");
	}
}


void Maze::checkStartAndExit(){

	int S_counter = 0;
	int E_counter = 0;
	for(int i =0 ; i< 9 ; i++){

		for(int j =0 ; j< 9 ; j++){

			if(matrix[i][j] == 'E'){
				E_counter++;
			}
			if(matrix[i][j] == 'S'){
				S_counter++;
			}
			
		}
	}
	if(S_counter == 0 || S_counter >1){
		throw std::invalid_argument("controlla lo start");
	}
	if(E_counter ==0){
		throw std::invalid_argument("controlla l'exit");
	}
}

void Maze::printPosition(){
	std::cout << "pos S " << "x:"<< x_pos <<" y:"<<y_pos << "\n";

}

void Maze::moveUp(){

	if(matrix[y_pos - 1][x_pos] != '*' &&  matrix[y_pos - 1][x_pos] != 'S' ){
		y_pos = y_pos -1;
	}
	checkPosition();
}

void Maze::moveDown(){

	if(matrix[y_pos+1][x_pos] != '*' &&  matrix[y_pos+1][x_pos] != 'S' ){
		y_pos = y_pos +1;
	}
	checkPosition();
}

void Maze::moveLeft(){

	if(matrix[y_pos][x_pos -1] != '*' && matrix[y_pos][x_pos -1] != 'S'){
		x_pos = x_pos -1;
	}
	checkPosition();
}

void Maze::moveRight(){

	if(matrix[y_pos][x_pos +1] != '*' && matrix[y_pos][x_pos +1] != 'S'){
		x_pos = x_pos +1;
	}
	checkPosition();
}

void Maze::moveNorthWest(){

	if(matrix[y_pos-1][x_pos-1] != '*' && matrix[y_pos-1][x_pos-1] != 'S' ){
		y_pos = y_pos -1;
		x_pos = x_pos -1;
	}
	checkPosition();
}

void Maze::moveNorthEast(){

	if(matrix[y_pos-1][x_pos+1] != '*' && matrix[y_pos-1][x_pos+1] != 'S' ){
		y_pos = y_pos -1;
		x_pos = x_pos +1;
	}
	checkPosition();
}

void Maze::moveSouthWest(){

	if(matrix[y_pos+1][x_pos-1] != '*' && matrix[y_pos+1][x_pos-1] != 'S' ){
		y_pos = y_pos +1;
		x_pos = x_pos -1;
	}
	checkPosition();
}

void Maze::moveSouthEast(){

	if(matrix[y_pos+1][x_pos+1] != '*' && matrix[y_pos+1][x_pos+1] != 'S' ){
		y_pos = y_pos +1;
		x_pos = x_pos +1;
	}
	checkPosition();
}

char Maze::getCharAround(int pos){
	//in base all'input (guarda l'header) guardo cosa c'è nella casella attornoa a me
	if(pos == 1){
		return matrix[y_pos-1][x_pos-1];
	}
	else if(pos == 2){
		return matrix[y_pos-1][x_pos];
	}
	else if(pos == 3){
		return matrix[y_pos-1][x_pos+1];
	}
	else if(pos == 4){
		return matrix[y_pos][x_pos +1];
	}
	else if(pos == 5){
		return matrix[y_pos+1][x_pos+1];
	}
	else if(pos == 6){
		return matrix[y_pos+1][x_pos];
	}
	else if(pos == 7){
		return matrix[y_pos+1][x_pos-1];
	}
	else if(pos == 8){
		return matrix[y_pos][x_pos -1];
	}
	return 'a';
}
