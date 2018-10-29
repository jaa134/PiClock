#include <stdio.h>
#include <unistd.h>
#include <bits/stdc++.h>
#include "SystemUsageWidget.h"
using namespace std;

SystemUsageWidget::SystemUsageWidget(){
	//future settings?
}

void SystemUsageWidget::printSystemUsage(){
	system("./printStats.sh");
}


int main(){
	SystemUsageWidget test;
	test.printSystemUsage();
}
