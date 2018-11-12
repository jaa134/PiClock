#include <stdio.h>
#include <unistd.h>
#include <bits/stdc++.h>
#include "SystemUsageWidget.hpp"
using namespace std;

/*
 * Constructor.
 * As of now, systemUsageWidget always functions the same way so no input parameters are specified
 */
SystemUsageWidget::SystemUsageWidget(){
	//future settings?
}

/*
 * printStats.sh shell script does all the work, including printing results
 */
void SystemUsageWidget::printSystemUsage(){
	system("./printStats.sh");
}


/*
 * Used for unit testing purposes. Called by main method in main.cpp
 */
int SystemUsageWidget::exec(){
	SystemUsageWidget test;
	test.printSystemUsage();
}
