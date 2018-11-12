/*
 * Widget which prints the memory, CPU, and disk usage of the PiClock.
 * Updates values every second.
 */
class SystemUsageWidget //:PiClockApp
{
	public:
		//constructor
		SystemUsageWidget();

		//prints stats
		void printSystemUsage();

		//called by main
		static int exec();
};

