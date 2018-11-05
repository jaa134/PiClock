#include <stdio.h>
#include <unistd.h>
#include <bits/stdc++.h>
#include "SystemUsageWidget.hpp"
using namespace std;

SystemUsageWidget::SystemUsageWidget(){
	//future settings?
}

void SystemUsageWidget::printSystemUsage(){
	system("./printStats.sh > stats.txt");
}


int SystemUsageWidget::exec(){
	SystemUsageWidget test;
	test.printSystemUsage();
}
