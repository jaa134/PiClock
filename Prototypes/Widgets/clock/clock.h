//sets default format
//currenly set on 12 hour
const bool DEFAULT_24_HOUR = false;

/*
 * Prints time and date every second
 * Only customizability is 24 hour or 12 hour clock
 */
class Clock //:PiClockApp?
{
	//true if format is 24 hour time
	bool clock24hr;

	public:
		//constructor with default format
		Clock();

		//constructor with inputted format
		Clock(bool setting);

		void printTime();

		//sets format
		void setclock24hr(bool setting);

		//returns whether format is 24 hour
		bool getclock24hr();
};
