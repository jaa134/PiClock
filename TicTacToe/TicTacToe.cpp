
#include <iostream>
#include <stdio.h>
#include <vector>	
#include <cstdlib>
#include <time.h>
#include <exception>
#include <sstream>
#include <string>

#include "TicTacToe.h"
TicTacToe::TicTacToe(Difficulty difficulty){
	switch(difficulty){
		case Beginner:
			pointsThreshold = 2;
			break;
		case Intermediate:
			pointsThreshold = 4;
			break;
		case Advanced:
			pointsThreshold = 6;
			break;
	}

	for(int row = 0; row < 3; row++){
		for(int col = 0; col < 3; col++){

			board[row][col] = 0;

			Square square;
			square.X = row;
			square.Y = col;
			unfilledSquares.push_back(square);
		}
	}
}

//computer places an 'O' on a random unoccupied square on the board.
//returns null if this move did not finish the game, otherwise returs game result
MoveResult TicTacToe::computerMove(){

	//seeds random number based on system time
	srand(time(NULL));

	//find a random empty square on board, place an O there, remove square from list of empty squares.
	int squareIndex = rand()%(unfilledSquares.size());
	Square square = unfilledSquares.at(squareIndex);
	board[square.X][square.Y] = markO; 
	unfilledSquares.erase(unfilledSquares.begin() + squareIndex);

	//check if this move caused computer to win. If so, return win
	if(threeInARow(square, markO)){
		return Win;
	}
	else{
		//if every square on board is filled, game is a tie
		if(unfilledSquares.size() == 0) {return Tie;}

		//otherwise, game is not over
		else {return Inconclusive;}
	}

}

//check to see if the mark placed in square causes the player to win
bool TicTacToe::threeInARow(Square square, int mark){
	int squareX = square.X;
	int squareY = square.Y;

	//left-right
	if(board[squareX][(squareY + 1)%3] == mark){
		if(board[squareX][(squareY+2)%3] == mark){
			return true;
		}
	}

	//up-down
	if(board[(squareX + 1)%3][squareY] == mark){
		if(board[(squareX + 2)%3][squareY] == mark){
			return true;
		}
	}

	//diagonals win is only applicable if square is on one of the diagonals (in which case the sum of its indices is even)
	if((squareX + squareY)%2 == 0){
		//top left to bottom right diagonal
		//square is on this diagonal if its indices are equal
		if(squareX == squareY){
			if(board[(squareX + 1)%3][(squareY + 1)%3] == mark){
				if(board[(squareX + 2)%3][(squareY + 2)%3] == mark){
					return true;
				}
			}
		}


		//bottom left to top right diagonal
		//square is on this diagonal if it's in the middle or incdices are not equal
		if((squareX == 1 && squareY == 1) || (squareX != squareY)){
			if(board[(squareX + 1)%3][(squareY - 1)%3] == mark){
				if(board[(squareX + 2)%3][(squareY - 2)%3] == mark){
					return true;
				}
			}
		}
	}

		//if none of these are satisfied, player has not won
		return NULL;
}

//Places an X in inputted square
MoveResult TicTacToe::userMove(Square square){
	board[square.X][square.Y] = markX; 

	//finds square in unfilledSquares which matches inputted square
	for(int i = 0; i < unfilledSquares.size(); i++){
		if(unfilledSquares.at(i).X == square.X && unfilledSquares.at(i).Y == square.Y){
			unfilledSquares.erase(unfilledSquares.begin() + i);
			break;
		}
	}

	//check if this move caused user to win. If so, return win
	if(threeInARow(square, markX)){
		return Win;
	}
	else{
		//if every square on board is filled, game is a tie
		if(unfilledSquares.size() == 0) {return Tie;}

		//otherwise, game is not over
		else {return Inconclusive;}
	}
}


	
void TicTacToe::printBoard(){
	for(int i = 0; i < 3 ; i++){
		for(int j = 0; j < 3 ; j++){
			if(board[i][j] == markX){
				printf("X\t");
			}
			else if (board[i][j] == markO){
				printf("O\t");
			}
			else{printf("_\t");}
		}
		printf("\n\n");
	}
}
	

int main(){
	TicTacToe test(Intermediate);

	for(int i = 0; i < 9 ; i++){
		MoveResult result;
		result = test.computerMove();
		test.printBoard();
		if(result == Win){
			printf("Computer wins\n");
			break;
		}
		else if(result == Tie){
			printf("Tie\n");
			break;
		}
		printf("---------------------------\n");

		std::string str;
		Square square;

		std::cout << "X:\t";
		getline(std::cin,str);
		std::stringstream(str) >> square.X;

		std::cout << "Y:\t";
		getline(std::cin,str);
		std::stringstream(str) >> square.Y;

		result = test.userMove(square);
		test.printBoard();
		if(result == Win){
			printf("User wins\n");
			break;
		}
		else if(result == Tie){
			printf("Tie\n");
			break;
		}
		printf("---------------------------\n");
	}
}
