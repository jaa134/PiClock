#define markX 1
#define markO 2
#include <exception>

enum Difficulty {Beginner, Intermediate, Advanced};
enum MoveResult {Win, Loss, Tie, Inconclusive};
struct Square{
	int X;
	int Y;
};

class UnavailableSquareException: public std::exception{
	virtual const char* what() const throw();
};

class TicTacToe //:extends Game
{
	int board[3][3];
	int points;
	int pointsThreshold;
	std::vector<Square> unfilledSquares;

	bool threeInARow(Square, int);
	void addPoints(int);
	MoveResult playGame();
	MoveResult userMove(Square);
	void printBoard();
	MoveResult computerMove();

	public:
	void ticTacToeGame();
	TicTacToe(Difficulty);

};

	

