
#include "TicTacToe.hpp"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#define REQUIRE_MESSAGE(cond, msg) do { INFO(msg); REQUIRE(cond); } while((void)0, 0)

TEST_CASE("Testing Point Thresholds for different difficulties", "[pointsThreshold]"){

	TicTacToe test(Beginner);
	REQUIRE_MESSAGE(test.pointsThreshold == 2, "expected points threshold 2");

	TicTacToe test2(Intermediate);
	REQUIRE_MESSAGE(test2.pointsThreshold == 4, "expected points threshold 4");

	TicTacToe test3(Advanced);
	REQUIRE_MESSAGE(test3.pointsThreshold == 6, "expected points threshold 6");
}

//tests functionality of threeInARow method
TEST_CASE("Testing win conditions", "[threeInARow]"){
	TicTacToe test(Beginner);

	SECTION ("X__\n_X_\n__X"){
		test.clearBoard();
		test.board[0][0] = markX;
		test.board[1][1] = markX;
		Square square;
		square.X = 2;
		square.Y = 2;

		REQUIRE_MESSAGE(test.threeInARow(square, markX) == true, "Expected true (primary diagonal)");
	}

	SECTION ("X__\n_X_\n_X_"){
		test.clearBoard();
		test.board[0][0] = markX;
		test.board[1][1] = markX;
		Square square;
		square.X = 2;
		square.Y = 1;

		REQUIRE_MESSAGE(test.threeInARow(square, markX) == false, "Expected false");
	}

	SECTION ("__O\n_O_\nO__"){
		test.clearBoard();
		test.board[0][2] = markO;
		test.board[1][1] = markO;
		Square square;
		square.X = 2;
		square.Y = 0;

		REQUIRE_MESSAGE(test.threeInARow(square, markO) == true, "Expected true (secondary diagonal)");
	}

	SECTION ("__O\n_X_\nO__"){
		test.clearBoard();
		test.board[0][2] = markO;
		test.board[1][1] = markX;
		Square square;
		square.X = 2;
		square.Y = 0;

		REQUIRE_MESSAGE(test.threeInARow(square, markO) == false, "Expected false");
	}

	SECTION ("O__\nO__\nO__"){
		test.clearBoard();
		test.board[0][0] = markO;
		test.board[1][0] = markO;
		Square square;
		square.X = 2;
		square.Y = 0;

		REQUIRE_MESSAGE(test.threeInARow(square, markO) == true, "Expected true (first column)");
	}

	SECTION ("O__\nO__\n_O_"){
		test.clearBoard();
		test.board[0][0] = markO;
		test.board[1][0] = markO;
		Square square;
		square.X = 2;
		square.Y = 1;

		REQUIRE_MESSAGE(test.threeInARow(square, markO) == false, "Expected false");
	}

	SECTION ("___\nXXX\n___"){
		test.clearBoard();
		test.board[1][0] = markX;
		test.board[1][1] = markX;
		Square square;
		square.X = 1;
		square.Y = 2;

		REQUIRE_MESSAGE(test.threeInARow(square, markX) == true, "Expected true (middle row)");
	}
	
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

//tests functionality of isValidSquare() and removeMarkedSquare() methods
TEST_CASE("Checking whether square is a valid location for a new mark given board", "[isValidSquare]"){
	TicTacToe test(Beginner);

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

	square.X = 1;
	square.Y = 0;
	REQUIRE_MESSAGE(test.isValidSquare(square) == false, "Expected false (square already occupied)");

	square.X = 2;
	square.Y = 1;
	REQUIRE_MESSAGE(test.isValidSquare(square) == false, "Expected false (square already occupied)");

	square.X = 0;
	square.Y = 2;
	REQUIRE_MESSAGE(test.isValidSquare(square) == true, "Expected true");

	square.X = 1;
	square.Y = 1;
	REQUIRE_MESSAGE(test.isValidSquare(square) == true, "Expected true");

	square.X = 3;
	square.Y = 1;
	REQUIRE_MESSAGE(test.isValidSquare(square) == false, "Expected false (X out of bounds)");

	square.X = 0;
	square.Y = 4;
	REQUIRE_MESSAGE(test.isValidSquare(square) == false, "Expected false (Y out of bounds)");
}




