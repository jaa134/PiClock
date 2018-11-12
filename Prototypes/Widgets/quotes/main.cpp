#include <QCoreApplication>
#include "quotes.h"
#include <stdio.h>
#include <iostream>

/*
 * Main function that runs the quotes widget.
 */
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Quotes test;
    test.getQuotes();

    return a.exec();
}

