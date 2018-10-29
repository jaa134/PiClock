#include <unistd.h>
#include <iostream>
#include <stdio.h>
#include <vector>	
#include <cstdlib>
#include <time.h>
#include <exception>
#include <sstream>
#include <string>
#include <exception>

#include "TicTacToe.h"

const char* UnavailableSquareException::what() const throw(){
	return "That square is unavailable! Try again.";
}

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

	points = 0;
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

MoveResult TicTacToe::playGame(){

	//resets board, refills unfilledSquares with all squares
	for(int row = 0; row < 3; row++){
		for(int col = 0; col < 3; col++){
			board[row][col] = 0;

			Square square;
			square.X = row;
			square.Y = col;
			unfilledSquares.push_back(square);
		}
	}

	MoveResult result;
	std::string str;
	Square square;
	bool validSquare;
	//user and computer alternate turns until result is reached
	while(true){
		//User Makes move
		try
		{
			std::cout << "Enter coordinates of square to place X\n";
			std::cout << "Row:\t";
			getline(std::cin,str);
			std::stringstream(str) >> square.X;

			std::cout << "Column:\t";
			getline(std::cin,str);
			std::stringstream(str) >> square.Y;

			validSquare = false;
			for(int i = 0; i < unfilledSquares.size(); i++){
				if(square.X == unfilledSquares.at(i).X){
					if(square.Y == unfilledSquares.at(i).Y){
						validSquare = true;
						break;
					}
				}
			}

			//if user tried to place an X in an out of bounds square or one which already had a symbol in it
			if (!validSquare || square.Y > 2 || square.X > 2){
				UnavailableSquareException exc;
				throw exc;
			}
		}
		//Print warning message and have user enter a new square
		catch (std::exception& exc){
			std::cout << exc.what() << std::endl;
			continue;
		}

		result = userMove(square);
		printBoard();
		if(result == Win){
			return Win;
		}
		else if(result == Tie){
			return Tie;
		}
		printf("---------------------------\n");
		result = computerMove();

		usleep(1000000);
		printBoard();
		if(result == Win){
			return Loss;
		}
		else if(result == Tie){
			return Tie;
		}
		printf("---------------------------\n");

	}
}

void TicTacToe::ticTacToeGame(){
	printf("You have to get %d points to complete the challenge\n", pointsThreshold);
	printf("You are awarded:\n2 points for a win,\n1 point for a tie,\nand 0 points for a loss.\n");
	printf("You have X and go first. Good luck!\n\n");

	MoveResult result;	
	while(points < pointsThreshold){
		result = playGame();

		switch(result){
			case Win:
				points += 2;
				printf("You Win!\n+2 points!\n");
				break;
			case Tie:
				points += 1;
				printf("Tie game.\n+1 point.\n");
				break;
			default:
				printf("You lose.\n+0 points.\n");
				break;
		}

		printf("You now have %d points.\n\n", points);
	}

	printf("Congratulations! You have completed the challenge!\n");
		
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
	test.ticTacToeGame();
}
