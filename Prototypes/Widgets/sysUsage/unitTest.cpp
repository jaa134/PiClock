#include <unistd.h>
#include <iostream>
#include <fstream>
#include "SystemUsageWidget.hpp"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#define REQUIRE_MESSAGE(cond, msg) do { INFO(msg); REQUIRE(cond); } while((void)0, 0)

TEST_CASE("Make sure that values printed are nonzero and < 100%", "[printStats]"){
	std::fstream file("stats.txt", std::ios_base::in);

	for(int i = 0; i < 10; i++){
		usleep(10000);
		
		SystemUsageWidget test;
		test.printSystemUsage();

		double cpu;
		double mem;

		file >> cpu;
		file >> mem;

		REQUIRE_MESSAGE(cpu > 0, "CPU usage should be greater than 0 percent");
		REQUIRE_MESSAGE(cpu < 1, "CPU usage should be less than 100 percent");
		REQUIRE_MESSAGE(mem > 0, "Memory usage should be greater than 0 percent");
		REQUIRE_MESSAGE(mem < 1, "Memory usage should be less than 100 percent");
	}
}

