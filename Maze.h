#ifndef MAZE_H
#define MAZE_H

#include <iostream>
#include <fstream>
#include <array>
#include <string>
#include <stdexcept>

class Maze{
	
	private :
	int x_pos{0};
	int y_pos{0};
	//int x_exit_position{0};
	//int y_exit_position{0};
	std::array<std::array<char,9>,9> matrix;
	void checkBorders();
	void checkStartAndExit();
	void checkPosition();
	
	public:
	Maze(std::string file_name);
	int getXpos();
	int getYpos();
	void printPosition();
	char getChar();
	char getCharAround(int pos);// 1:northWest 2:up 3:northeast 4:Right 5:southEast 6:down 7:southWest 8:left
	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();
	void moveNorthWest();
	void moveNorthEast();
	void moveSouthWest();
	void moveSouthEast();
};

#endif