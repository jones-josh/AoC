#include "6.h"
#include <string>
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>

static bool allDiff(std::string str)
{
	std::unordered_set<char> set;
	for (char c : str) set.insert(c);
	return set.size() == str.size();
}

void Day6::part1()
{
	std::string s;
	std::cin >> s;

	for (int i = 0; i < s.size()-4; ++i)
	{
		if (allDiff(s.substr(i, 4))) {
			std::cout << (i + 4) << std::endl;
			break;
		}
	}
}

void Day6::part2()
{
	std::string s;
	std::cin >> s;

	for (int i = 0; i < s.size() - 14; ++i)
	{
		if (allDiff(s.substr(i, 14))) {
			std::cout << (i + 14) << std::endl;
			break;
		}
	}
}

void Day6::main()
{
	part2();
};