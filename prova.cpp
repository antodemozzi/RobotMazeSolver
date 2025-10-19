#include <iostream>
#include <fstream>
#include <array>
#include <string>

int main(){
	
	std::ifstream mytxt;
	mytxt.open("ciao.txt");
	std::string words = "";
	
	//std::vector<std::vector<char>> matrix(9 , std::vector<char>(9));
	std::array<std::array<char,9>,9> mat;
	/*
	for(auto& arr : mat){
		for(auto& c : arr){
			c = 'a';
		}
	}
	*/
	while(mytxt.good()){
		for(int row=0 ; row<9 ; row++){
			for(int col=0 ; col <9;col++){
				mat[row][col] = mytxt.get();
				std::cout << mat[row][col];
			}
			mytxt.get();
			std::cout << "\n";
		}
	}
	/*
	mat[10][19]= 'c';// array non controlla i bounds 
	std::cout << mat[10][19] << "\n";
	*/
	return 0;
}