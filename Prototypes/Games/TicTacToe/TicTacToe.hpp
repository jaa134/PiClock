#define markX 1
#define markO 2
#include <exception>
#include <vector>

/*
 * Used to set points threshold 
 * Beginner -> 2 points
 * Intermediate -> 4 points
 * Advanced -> 6 points
 */
enum Difficulty {Beginner, Intermediate, Advanced};

/*
 * Is returned by several methods as the result of a move or game
 * Inconclusive means move did not result in a win, loss, or tie
 */
enum MoveResult {Win, Loss, Tie, Inconclusive};

/*
 * Represents a square on the board
 * X -> row (0 for top row - 2 for bottom row)
 * Y -> column (0 for leftmost column - 2 for rightmost column
 */
struct Square{
	int X;
	int Y;
};

/*
 * Exception thrown if user inputs invalid square
 */
class UnavailableSquareException: public std::exception{
	virtual const char* what() const throw();
};

/*
 * Class to play tic-tac-toe game
 */
class TicTacToe //:extends Game
{

	public:
	//3 by 3 array representing the board. 0 means square is unoccupied, 1 means X, 2 means Y
	int board[3][3];

	//points accumulated by user. Must pass a threshold determined by difficulty for user to complete game
	int points;

	//holds list of Square structs which do not yet have a mark in them 
	std::vector<Square> unfilledSquares;

	//methods described in tictactoe.cpp
	void addPoints(int);
	MoveResult playGame();
	MoveResult userMove(Square);
	void printBoard();
	MoveResult computerMove();
	int pointsThreshold;
	void ticTacToeGame();
	TicTacToe(Difficulty);
	bool threeInARow(Square, int);
	static int exec();
	void clearBoard();
	bool isValidSquare(Square);
	void removeMarkedSquare(Square);

};

	

