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

#include "TicTacToe.hpp"

/*
 * exception method
 * Thrown when user attempts to place an 'X' in an occupied or out-of-bounds square
 * returns error message string
 */
const char* UnavailableSquareException::what() const throw(){
	return "That square is unavailable! Try again.";
}

/*
 * constructor 
 * input: difficulty
 * Sets points threshold based on difficulty, 
 * sets initial points value to 0
 */
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


/*
 * computer places an 'O' on a random unoccupied square on the board.
 * Uses threeInARow() to test result of this move.
 * returns:
 * Win if this move caused computer to win
 * Tie if this move did not cause computer to win but all squares are now occupied
 * Inconclusive otherwise
 */
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

/*
 * Checks whether given square and mark causes the player with that mark to win
 * input:
 * square - coordinates of square where mark was placed
 * mark - X or O
 * returns:
 * true if mark at square gives 3 in a row for player who placed it
 * false otherwise
 */
bool TicTacToe::threeInARow(Square square, int mark){
	int squareX = square.X;
	int squareY = square.Y;

	//checks if other two squares in row also contain this mark
	if(board[squareX][(squareY + 1)%3] == mark){
		if(board[squareX][(squareY+2)%3] == mark){
			return true;
		}
	}

	//checks other two squares in column
	if(board[(squareX + 1)%3][squareY] == mark){
		if(board[(squareX + 2)%3][squareY] == mark){
			return true;
		}
	}

	//checks diagonals.
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
			if(board[(squareX - 1)%3][(squareY + 1)%3] == mark){
				if(board[(squareX - 2)%3][(squareY + 2)%3] == mark){
					return true;
				}
			}
		}
	}

		//if none of these are satisfied, player has not won
		return false;
}

/*
 * Takes square chosen by user in playGame(), places an 'X' in that square
 * Uses threeInARow to determine whether this play has caused user to win the game
 * returns:
 * Win if this move caused user to win
 * Tie if this move did not cause user to win but all squares are now occupied
 * Inconclusive otherwise
 */
MoveResult TicTacToe::userMove(Square square){
	board[square.X][square.Y] = markX; 

	//finds square in unfilledSquares which matches inputted square
	removeMarkedSquare(square);

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

/*
 * Plays an individual TicTacToe game.
 * Note this differs from ticTacToeGame() - which runs larger game consisting of multiple individual tic-tac-toe
 * games which user wins by gathering enough points from winning the individual games.
 * Resets board, then loops between getting user input and calling computerMove() until decisive result is reached.
 * Returns a MoveResult which represents the result of the game from the user's perspective - Win, Loss, or Tie
 */
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
	//user and computer alternate turns until result is reached
	while(true){
		//User Makes move
		try
		{
			//input square from user
			std::cout << "Enter coordinates of square to place X\n";
			std::cout << "Row:\t";
			getline(std::cin,str);
			std::stringstream(str) >> square.X;

			std::cout << "Column:\t";
			getline(std::cin,str);
			std::stringstream(str) >> square.Y;


			//if user tried to place an X in an out of bounds square or one which already had a symbol in it
			if (!isValidSquare(square)){
				UnavailableSquareException exc;
				throw exc;
			}
		}
		//If exception was thrown, print warning message and have user enter a new square
		catch (std::exception& exc){
			std::cout << exc.what() << std::endl;
			continue;
		}

		//get result (win, tie, inconclusive), from placing an x at user's specified square
		result = userMove(square);
		printBoard();
		if(result == Win){
			return Win;
		}
		else if(result == Tie){
			return Tie;
		}

		//now computer moves
		printf("---------------------------\n");
		result = computerMove();

		//pauses to give notion that computer is 'thinking'
		usleep(1000000);
		printBoard();

		//if computer's move caused it to win, then this game is a loss from user's perspective
		if(result == Win){
			return Loss;
		}
		else if(result == Tie){
			return Tie;
		}
		printf("---------------------------\n");

	}
}

/*
 * Runs larger tic-tac-toe game
 * User plays individual games until they pass the points threshold
 * Win gives 2 points
 * Tie gives 1 point
 * Loss gives 0 points
 */
void TicTacToe::ticTacToeGame(){
	printf("You have to get %d points to complete the challenge\n", pointsThreshold);
	printf("You are awarded:\n2 points for a win,\n1 point for a tie,\nand 0 points for a loss.\n");
	printf("You have X and go first. Good luck!\n\n");

	MoveResult result;	

	//play games until user has enough points
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

	//loop breaks when user has enough points
	printf("Congratulations! You have completed the challenge!\n");
		
}
	
/*
 * Tests whether inputted square is unoccupied
 * returns:
 * false if unfilledSquares does not contain a square which matched inputted square or square is out of bounds
 * true otherwise
 */
bool TicTacToe::isValidSquare(Square square){
	bool validSquare = false;

	//searches through unfilledSquares to find one which matches both X and Y of square
	for(int i = 0; i < unfilledSquares.size(); i++){
		if(square.X == unfilledSquares.at(i).X){
			if(square.Y == unfilledSquares.at(i).Y){
				//if a match was found, square can still be valid
				validSquare = true;
				break;
			}
		}
	}

	//Square must be unoccupied and have X and Y within bounds to be valid
	if (!validSquare || square.Y > 2 || square.X > 2){return false;}
	else {return true;}
}

/*
 * finds and removes square in unfilledSquares which matches inputted square.
 */
void TicTacToe::removeMarkedSquare(Square square){
	for(int i = 0; i < unfilledSquares.size(); i++){
		//if both X and Y match, then squares match
		if(unfilledSquares.at(i).X == square.X && unfilledSquares.at(i).Y == square.Y){
			unfilledSquares.erase(unfilledSquares.begin() + i);
			break;
		}
	}
}

/*
 * Sets all squares to value 0 (clears board of all marks)
 */
void TicTacToe::clearBoard(){
	for(int i = 0; i < 3 ; i++){
		for(int j = 0; j < 3 ; j++){
			board[i][j] = 0;
		}
	}
}

/*
 * prints out a representation of the board.
 * Leaves square blank (prints underscore) if no mark in it, otherwise prints which mark it contains
 */
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
	
/*
 * example with Intermediate difficulty
 * Called by main.cpp
 */
int TicTacToe::exec(){
	TicTacToe test(Intermediate);
	test.ticTacToeGame();
}
