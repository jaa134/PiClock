#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

//Program to print current 12-hour time (hh:mm:ss AM/PM) every second
int main(){
	while(true){
		system("date '+%r'");

		//sleep 1 second
		usleep(1000000);
	}
}

