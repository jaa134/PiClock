#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <time.h>
#include <vector>
#include <random>
#include <limits>

using namespace std;

static int numberValues[40];
static char operatorValues[4] = {'+', '-', '/', '*'};
static char outputGuesses[4] = {'A', 'B', 'C', 'D'};

/*
 * Public class that consists of the multiple choice math game initialization.
 */
class MathGame{

    public:

    double firstValue;
    double secondValue;
    double correctValue;
    char operatorV;
    double wrongValues[3];
    vector<double> allValues;
    double userAnswer = 0;
    int correct = 0;
    int difficulty = 4;

    MathGame(){ }
    void makeQuestion();
    void correctAnswer();
    void listOfAnswers();
    void getQuestion();
    void submitAnswer();
    void evaluateAnswer();
};
