#include <QCoreApplication>
#include "triviagame.h"

/*
 * Main function that runs the trivia game.
 */
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    TriviaGame t(Difficulty::Intermediate);
    t.getQuestions();

    return a.exec();
}
