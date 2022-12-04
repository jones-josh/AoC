#include "4.h"

#include <iostream>
#include <string>
#include <vector>

#include "../common.h"

void Day4::part1()
{
	std::string s;
	std::cin >> s;

	int total = 0;

	while (s != "q") {
		std::vector<std::string> v = split(s, "-,");
		int ll = stoi(v[0]);
		int lu = stoi(v[1]);
		int rl = stoi(v[2]);
		int ru = stoi(v[3]);

		if (ll <= rl && lu >= ru) total++;
		else if (ll >= rl && lu <= ru) total++;

		std::cin >> s;
	}
	
	std::cout << total << std::endl;
}

void Day4::part2()
{
	std::string s;
	std::cin >> s;

	int total = 0;

	while (s != "q") {
		std::vector<std::string> v = split(s, "-,");
		int ll = stoi(v[0]);
		int lu = stoi(v[1]);
		int rl = stoi(v[2]);
		int ru = stoi(v[3]);

		if (lu >= rl && ll <= ru) total++;

		std::cin >> s;
	}

	std::cout << total << std::endl;
}

void Day4::main()
{
	part2();
}