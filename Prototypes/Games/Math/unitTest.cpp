#include "mathgame.hpp"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#define REQUIRE_MESSAGE(cond, msg) do { INFO(msg); REQUIRE(cond); } while((void)0, 0)

/*
 * Testing if the makeQuestion() function passes and does not crash or have problems.
 */
TEST_CASE("Testing makeQuestion() function", "[MakeQuestion]"){

    MathGame test;
    test.makeQuestion();

    SUCCEED("Make Question function passed.");

}

/*
 * Testing if the correctAnswer() function does what should do. That is, it should update the vector allvalues from
 * being empty to having four values. The test succeeds if it is empty at first and filled this function is called.
 */
TEST_CASE("Testing correctAnswer() function", "[CorrectAnswer]"){

    MathGame test;
    test.makeQuestion();
    if(test.allValues.empty() == true){

        SUCCEED("All Values vector is empty before the call of correct answer.");

    }

    test.correctAnswer();

    if(test.allValues.empty() == false){

        SUCCEED("All values vector now has the values of the correct and incorrect answers.");

    }
}

/*
 * Testing if the getQuestion() function passes. It checks the before and after to see if allvalues
 * updates because that is the main thing this function does.
 */
TEST_CASE("Testing getQuestion() function", "[GetQuestion]"){

    MathGame test;
    test.makeQuestion();
    test.correctAnswer();

    REQUIRE(test.allValues.empty() == false);

    test.getQuestion();

    REQUIRE(test.allValues.empty() == true);


}

/*
 * Testing is submitAnswer() passes by calling it. If the code does not crash, then this test succeeds.
 */
TEST_CASE("Checking if submitAnswer() passes", "[SubmitAnswer]"){

    MathGame test;
    test.makeQuestion();
    test.correctAnswer();
    test.getQuestion();

    test.submitAnswer();

    SUCCEED("submitAnswer function passes.");

}

/*
 * Testing if the evaluateAnswer() function passes, if the code does not crash, this test succeeds.
 */
TEST_CASE("Checking if evaluateAnswer() function does not fail", "[EvaluateAnswer]"){

    MathGame test;

    test.evaluateAnswer();

    SUCCEED("evaluateAnswer function passses.");

}
