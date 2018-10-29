#define markX 1
#define markO 2

enum Difficulty {Beginner, Intermediate, Advanced};
enum MoveResult {Win, Loss, Tie, Inconclusive};
struct Square{
	int X;
	int Y;
};

class TicTacToe //:extends Game
{
	int board[3][3];
	int points;
	int pointsThreshold;
	std::vector<Square> unfilledSquares;

	bool threeInARow(Square, int);
	void addPoints(int);

	public:
	void playGame();
	MoveResult userMove(Square);
	TicTacToe(Difficulty);
	void printBoard();
	MoveResult computerMove();

};

	

