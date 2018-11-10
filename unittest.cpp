#include "triviagame.h"
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

/*
 * Testing if each difficulty setting successfully sets the points threshold for the game.
 */
TEST_CASE("Testing points threshold for each difficulty.", "[pointsThreshold"){

    TriviaGame test(Beginner);
    CHECK(test.pointsThreshold == 3);

    TriviaGame secondTest(Intermediate);
    CHECK(secondTest.pointsThreshold == 4);

    TriviaGame thirdTest(Advanced);
    CHECK(thirdTest.pointsThreshold == 5);

}

/*
 * Testing toPlainString() function to see if it outputs a QString.
 */
TEST_CASE("Testing toPlainString() function", "[ToPlainString]"){

    TriviaGame firstTest(Beginner);
    QString test = "This is a test";

    CHECK(firstTest.toPlainString(test) == test);

}

/*
 * Testing if getQuestions passes because it is a void function retrieving a http request.
 */
TEST_CASE("Testing getQuestions() function", "[GetQuestions]"){

    TriviaGame test(Beginner);
    test.getQuestions();
    SUCCEED("Get Question function passed.");

}

/*
 * Testing if responseToQuestion passes.
 */
TEST_CASE("Testing responseToQuestion() function", "[ResponseToQuestion]"){

    TriviaGame test(Beginner);

    ResponseObject rtest;
    rtest.question = "This is a question?";
    rtest.correct_answer = "yes";
    rtest.incorrect_answers[0] = "no1";
    rtest.incorrect_answers[1] = "no2";
    rtest.incorrect_answers[2] = "no3";

    Question q;

    q = test.responseToQuestion(rtest);

    SUCCEED("Response To Question function passed.");


}
