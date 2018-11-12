
#include "TicTacToe.hpp"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#define REQUIRE_MESSAGE(cond, msg) do { INFO(msg); REQUIRE(cond); } while((void)0, 0)

/*
 * Checks that points threshold is set to correct value given difficulty
 */
TEST_CASE("Testing Point Thresholds for different difficulties", "[pointsThreshold]"){

	TicTacToe test(Beginner);
	REQUIRE_MESSAGE(test.pointsThreshold == 2, "expected points threshold 2");

	TicTacToe test2(Intermediate);
	REQUIRE_MESSAGE(test2.pointsThreshold == 4, "expected points threshold 4");

	TicTacToe test3(Advanced);
	REQUIRE_MESSAGE(test3.pointsThreshold == 6, "expected points threshold 6");
}


/*
 * tests functionality of threeInARow method
 * Creates different boards, places a new mark, and checks whether threeInARow() correctly 
 * determined the result of that mark
 */
TEST_CASE("Testing win conditions", "[threeInARow]"){
	TicTacToe test(Beginner);

	/*
	 * X__
	 * _X_
	 * __X
	 * Win
	 */
	SECTION ("X__\n_X_\n__X"){
		test.clearBoard();
		test.board[0][0] = markX;
		test.board[1][1] = markX;
		Square square;
		square.X = 2;
		square.Y = 2;

		REQUIRE_MESSAGE(test.threeInARow(square, markX) == true, "Expected true (primary diagonal)");
	}

	/*
	 * X__
	 * _X_
	 * _X_
	 * No win
	 */
	SECTION ("X__\n_X_\n_X_"){
		test.clearBoard();
		test.board[0][0] = markX;
		test.board[1][1] = markX;
		Square square;
		square.X = 2;
		square.Y = 1;

		REQUIRE_MESSAGE(test.threeInARow(square, markX) == false, "Expected false");
	}

	/*
	 * __O
	 * _O_
	 * O__
	 * Win
	 */
	SECTION ("__O\n_O_\nO__"){
		test.clearBoard();
		test.board[0][2] = markO;
		test.board[1][1] = markO;
		Square square;
		square.X = 2;
		square.Y = 0;

		REQUIRE_MESSAGE(test.threeInARow(square, markO) == true, "Expected true (secondary diagonal)");
	}

	/*
	 * __O
	 * _X_
	 * O__
	 * no win
	 */
	SECTION ("__O\n_X_\nO__"){
		test.clearBoard();
		test.board[0][2] = markO;
		test.board[1][1] = markX;
		Square square;
		square.X = 2;
		square.Y = 0;

		REQUIRE_MESSAGE(test.threeInARow(square, markO) == false, "Expected false");
	}

	/*
	 * O__
	 * O__
	 * O__
	 * win
	 */
	SECTION ("O__\nO__\nO__"){
		test.clearBoard();
		test.board[0][0] = markO;
		test.board[1][0] = markO;
		Square square;
		square.X = 2;
		square.Y = 0;

		REQUIRE_MESSAGE(test.threeInARow(square, markO) == true, "Expected true (first column)");
	}

	/*
	 * O__
	 * O__
	 * _O_
	 * no win
	 */
	SECTION ("O__\nO__\n_O_"){
		test.clearBoard();
		test.board[0][0] = markO;
		test.board[1][0] = markO;
		Square square;
		square.X = 2;
		square.Y = 1;

		REQUIRE_MESSAGE(test.threeInARow(square, markO) == false, "Expected false");
	}

	/*
	 * ___
	 * XXX
	 * ___
	 * win
	 */
	SECTION ("___\nXXX\n___"){
		test.clearBoard();
		test.board[1][0] = markX;
		test.board[1][1] = markX;
		Square square;
		square.X = 1;
		square.Y = 2;

		REQUIRE_MESSAGE(test.threeInARow(square, markX) == true, "Expected true (middle row)");
	}
	
	/*
	 * XX_
	 * X_X
	 * _XX
	 * no win
	 */
	SECTION ("XX_\nX_X\n_XX"){
		test.clearBoard();
		test.board[0][0] = markX;
		test.board[0][1] = markX;
		test.board[1][0] = markX;
		test.board[1][2] = markX;
		test.board[2][1] = markX;

		Square square;
		square.X = 2;
		square.Y = 2;

		REQUIRE_MESSAGE(test.threeInARow(square, markX) == false, "Expected false");
	}

	/*
	 * XXO
	 * XOX
	 * _XX
	 * no win
	 */
	SECTION ("XXO\nXOX\n_XX"){
		test.clearBoard();
		test.board[0][0] = markX;
		test.board[0][1] = markX;
		test.board[0][2] = markO;
		test.board[1][0] = markX;
		test.board[1][1] = markO;
		test.board[1][2] = markX;
		test.board[2][1] = markX;
		Square square;
		square.X = 2;
		square.Y = 2;

		REQUIRE_MESSAGE(test.threeInARow(square, markX) == false, "Expected false");
	}

	/*
	 * OOX
	 * OXO
	 * XOO
	 * win
	 */
	SECTION ("OOX\nOXO\nXOO"){
		test.clearBoard();
		test.board[0][0] = markO;
		test.board[0][1] = markO;
		test.board[0][2] = markX;
		test.board[1][0] = markO;
		test.board[1][1] = markX;
		test.board[1][2] = markO;
		test.board[2][1] = markO;
		test.board[2][2] = markO;
		Square square;
		square.X = 2;
		square.Y = 0;

		REQUIRE_MESSAGE(test.threeInARow(square, markX) == true, "Expected true (secondary diagonal)");
	}
}

/*tests functionality of isValidSquare() and removeMarkedSquare() methods
 * Creates a board, attemps to place a square on the board
 * should inValidSquare should return false if square is already occupied or out of bounds
 * removes squares from unfilledSquares as they are places on board using removeMarkedSquare()
 */
TEST_CASE("Checking whether square is a valid location for a new mark given board", "[isValidSquare]"){
	TicTacToe test(Beginner);

	//resets board, fills up unfilledSquares with all squares
	test.clearBoard();
	for(int row = 0; row < 3; row++){
		for(int col = 0; col < 3; col++){
			Square square;
			square.X = row;
			square.Y = col;
			test.unfilledSquares.push_back(square);
		}
	}
	Square square;

	/*
	 * creates this board:
	 * OO_
	 * X__
	 * XOX
	 */

	test.board[0][0] = markO;
	square.X = 0;
	square.Y = 0;
	test.removeMarkedSquare(square);

	test.board[0][1] = markO;
	square.X = 0;
	square.Y = 1;
	test.removeMarkedSquare(square);

	test.board[1][0] = markX;
	square.X = 1;
	square.Y = 0;
	test.removeMarkedSquare(square);

	test.board[2][0] = markX;
	square.X = 2;
	square.Y = 0;
	test.removeMarkedSquare(square);
	
	test.board[2][1] = markO;
	square.X = 2;
	square.Y = 1;
	test.removeMarkedSquare(square);

	test.board[2][2] = markX;
	square.X = 2;
	square.Y = 2;
	test.removeMarkedSquare(square);

	//sqaure is already occupied
	square.X = 1;
	square.Y = 0;
	REQUIRE_MESSAGE(test.isValidSquare(square) == false, "Expected false (square already occupied)");

	//sqaure is already occupied
	square.X = 2;
	square.Y = 1;
	REQUIRE_MESSAGE(test.isValidSquare(square) == false, "Expected false (square already occupied)");

	//square is free and in bounds, so it is valid
	square.X = 0;
	square.Y = 2;
	REQUIRE_MESSAGE(test.isValidSquare(square) == true, "Expected true");

	//square is free and in bounds, so it is valid
	square.X = 1;
	square.Y = 1;
	REQUIRE_MESSAGE(test.isValidSquare(square) == true, "Expected true");

	//square is out of bounds (X is too large)
	square.X = 3;
	square.Y = 1;
	REQUIRE_MESSAGE(test.isValidSquare(square) == false, "Expected false (X out of bounds)");

	//square is out of bounds (Y is too large)
	square.X = 0;
	square.Y = 4;
	REQUIRE_MESSAGE(test.isValidSquare(square) == false, "Expected false (Y out of bounds)");
}




