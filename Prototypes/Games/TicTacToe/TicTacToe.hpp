#define markX 1
#define markO 2
#include <exception>
#include <vector>

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

	public:
	int board[3][3];
	int points;
	std::vector<Square> unfilledSquares;

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

	

