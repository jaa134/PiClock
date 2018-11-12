#include <bits/stdc++.h>
#include <unistd.h>
#include "clock.h"
using namespace std;

/*
 * Default constructor
 * Sets format to value of DEFAULT_24_HR
 */
Clock::Clock()
{
	clock24hr = DEFAULT_24_HOUR;
}

/*
 * Constructor with format input
 * User can choose in settings whether they would like 12 or 24 hour format
 */
Clock::Clock(bool setting)
{
	clock24hr = setting;
}

/*
 * prints time to console every second
 */
void Clock::printTime()
{ 

	//prints in 24 hour format
	if(clock24hr){
		while(true){
			//uses date bash system call
			system("date '+%T'");

			//sleep 1 second
			usleep(1000000);
		}
	}

	//otherwise, do 12 hour format
	else{
		while(true){
			system("date '+%r'");

			//sleep 1 second
			usleep(1000000);
		}
	}
}

/*
 * Sets clock24hr to user input
 * input true -> 24 hr format
 * input false -> 12 hr format
 */
void Clock::setclock24hr(bool setting)
{
	clock24hr = setting; 
}

/*
 * Accessor method for clock24hr
 */
bool Clock::getclock24hr()
{
	return clock24hr;
}

/*
 * Example main method
 * Initially sets clock with 12 hr format, then changes to 24 hr and prints time
 */
int main(){
	Clock test(false);
	test.setclock24hr(true);
	test.printTime();
	return 0;
}

