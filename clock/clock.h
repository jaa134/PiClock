class Clock //:PiClockApp?
{
	const bool DEFAULT_24_HOUR = false;
	bool clock24hr;
	public:
		Clock();
		Clock(bool setting);
		void printTime();
		void setclock24hr(bool setting);
		bool getclock24hr();
};
