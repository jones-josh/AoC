#include "10.h"

#include <iostream>
#include <set>
#include <string>

void Day10::part1()
{
	std::string s;
	std::cin >> s;

	int cycle = 1;
	int x = 1;

	std::set<int> emitTimes{ 20, 60, 100, 140, 180, 220 };

	int signalStrength = 0;

	while (s != "q") {
		if (s == "noop") {
			if (emitTimes.contains(cycle)) signalStrength += x * cycle;
			++cycle;
		}
		else if (s == "addx") {
			int val;
			std::cin >> val;
			if (emitTimes.contains(cycle)) signalStrength += x * cycle;
			if (emitTimes.contains(cycle+1)) signalStrength += x * (cycle+1);
			x += val;
			cycle += 2;
		}

		std::cin >> s;
	}

	std::cout << signalStrength << std::endl;
}

static char getChar(int x, int cycle) {
	int col = cycle % 40;
	if (col == (x - 1) || col == x || col == (x + 1)) return '#';
	return '.';
}

void Day10::part2()
{
	std::string s;
	std::cin >> s;

	int cycle = 1;
	int x = 1;

	std::string out = "";

	while (s != "q") {
		if (s == "noop") {
			out += getChar(x, cycle);
			if ((cycle - 1) % 40 == 0) out += std::to_string(cycle) + "\na\n";

			++cycle;
		}
		else if (s == "addx") {
			int val;
			std::cin >> val;
			
			out += getChar(x, cycle);
			out += getChar(x, cycle + 1);
			if ((cycle - 1) % 40 == 0) out += std::to_string(cycle) + "\nb\n";
			if ((cycle) % 40 == 0) out += std::to_string(cycle+1) + "\nc\n";

			x += val;
			cycle += 2;
		}

		std::cin >> s;
	}

	std::cout << out << std::endl;
}

void Day10::main()
{
	part2();
}
