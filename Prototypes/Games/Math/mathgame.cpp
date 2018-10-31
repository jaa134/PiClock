#include "mathgame.hpp"

/*
 * Function to make the Question.
 */
void MathGame::makeQuestion(){

    int i;
    srand(time(NULL));
    int randomValueIndex = rand() % 40;
    int anotherValueIndex = rand() % 40;
    int randomOperatorIndex = rand() % 4;

    //numberValues consists of the numbers between -20 and 20.
    for(i = -25; i < 25; i++){
        numberValues[i + 25] = i;
    }

    //All the random possible values for the two integers and the operators.
    firstValue = numberValues[randomValueIndex];
    secondValue = numberValues[anotherValueIndex];
    operatorV = operatorValues[randomOperatorIndex];

}

/*
 * Function to retrieve the correct value of the question and input all that data in a vector.
 */
void MathGame::correctAnswer(){
    switch(operatorV){

        case '+':
            correctValue = firstValue + secondValue;
            wrongValues[0] = firstValue - secondValue;
            wrongValues[1] = secondValue - secondValue;
            wrongValues[2] = firstValue * secondValue;
            break;

        case '-':
            correctValue = firstValue - secondValue;
            wrongValues[0] = firstValue + secondValue;
            wrongValues[1] = secondValue + secondValue;
            wrongValues[2] = firstValue * secondValue;
            break;

        case '/':

            if(secondValue != 0){
                correctValue = firstValue / secondValue;
            }
            else{
                secondValue = 1;
                correctValue = firstValue / secondValue;
            }
            wrongValues[0] = firstValue / firstValue;
            wrongValues[1] = firstValue * secondValue;
            wrongValues[2] = firstValue - secondValue;
            break;

        case '*':
            correctValue = firstValue * secondValue;
            wrongValues[0] = firstValue + secondValue;
            wrongValues[1] = firstValue / secondValue;
            wrongValues[2] = firstValue - secondValue;
            break;

        default:
            cout << "The program has received an error!";
            break;
    }

    allValues.push_back(correctValue);
    for(int i = 0; i < 3; i++){
        allValues.push_back(wrongValues[i]);
    }
    random_shuffle(allValues.begin(), allValues.end());
}

/*
 * Outputs to stdout the list of answers.
 */
void MathGame::listOfAnswers(){
    for(int i = 0; i < 4; i++)
        cout << outputGuesses[i] << ": " << allValues[i] << endl;
    allValues.clear();
}

/*
 * Outputs the question with the list of answers.
 */
void MathGame::getQuestion(){
    cout << "What is the solution to " << firstValue << " " << operatorV << " " << secondValue << "?\n";
    listOfAnswers();

}

/*
 * Retrieves the answer the user inputs and compares it to the correct value. Returns the respective response.
 */
void MathGame::submitAnswer(){
    //getline(cin, userAnswer, '\n');
    cin >> userAnswer;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    if(userAnswer == correctValue){
        cout << "Your answer is correct!" << endl;
        correct++;
    }
    else{
        cout << "Your answer is incorrect! The correct answer is: " << correctValue << endl;
    }
}

/*
 * Keeps track of the number of questions the user got correct.
 */
void MathGame::evaluateAnswer(){
    while(correct != difficulty){
        makeQuestion();
        correctAnswer();
        getQuestion();
        submitAnswer();
    }

    cout << "The Alarm has been turned off!" << endl;

}