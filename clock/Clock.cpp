#include <bits/stdc++.h>
#include <unistd.h>
#include "clock.h"
using namespace std;

Clock::Clock()
{
	clock24hr = DEFAULT_24_HOUR;
}

Clock::Clock(bool setting)
{
	clock24hr = setting;
}


void Clock::printTime()
{ 

	if(clock24hr){
		while(true){
			system("date '+%T'");

			//sleep 1 second
			usleep(1000000);
		}
	}

	else{
		while(true){
			system("date '+%r'");

			//sleep 1 second
			usleep(1000000);
		}
	}
}

void Clock::setclock24hr(bool setting)
{
	clock24hr = setting; 
}

bool Clock::getclock24hr()
{
	return clock24hr;
}

int main(){
	Clock test(false);
	test.setclock24hr(true);
	test.printTime();
	return 0;
}

