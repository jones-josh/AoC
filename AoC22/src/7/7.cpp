#include "7.h"
#include <string>
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <map>
#include "../common.h"
#include <algorithm>

static std::string flatten(std::vector<std::string> v)
{
	std::string out = "";
	bool first = true;
	for (std::string s : v) { 
		out += s;
		if (!first) out += "/";
		first = false;
	}
	return out;
}

void Day7::part1()
{
	std::string s;
	std::cin >> s;
	std::vector<std::string> workingDir;
	std::map<std::string, int> rawSizes;

	while (s != "q")
	{
		if (s == "$")
		{
			// process command
			std::cin >> s;
			if (s == "cd")
			{
				std::cin >> s; // dir
				if (s == "..") workingDir.pop_back();
				else {
					workingDir.push_back(s);
					
				}
				std::cin >> s;
			}
			else if (s == "ls")
			{
				std::cin >> s;
				int total = 0;
				while (s != "$")
				{
					if (s == "dir") {
						std::cin >> s; std::cin >> s;
					}
					else {
						total += std::stoi(s);
						std::cin >> s; std::cin >> s;
					}
				}
				rawSizes[flatten(workingDir)] = total;
			}
		}
	}

	int limitedTotal = 0;

	for (auto parent = rawSizes.begin(); parent != rawSizes.end(); ++parent)
	{
		int total = parent->second;
		for (auto child = rawSizes.begin(); child != rawSizes.end(); ++child)
		{
			if (isSubString(child->first, parent->first)) total += child->second;
		}
		if (total < 100000) limitedTotal += total;
	}

	std::cout << limitedTotal << std::endl;
}

void Day7::part2()
{
	std::string s;
	std::cin >> s;
	std::vector<std::string> workingDir;
	std::map<std::string, int> rawSizes;

	int totalUsedSize = 0;

	while (s != "q")
	{
		if (s == "$")
		{
			// process command
			std::cin >> s;
			if (s == "cd")
			{
				std::cin >> s; // dir
				if (s == "..") workingDir.pop_back();
				else {
					workingDir.push_back(s);

				}
				std::cin >> s;
			}
			else if (s == "ls")
			{
				std::cin >> s;
				int total = 0;
				while (s != "$")
				{
					if (s == "dir") {
						std::cin >> s; std::cin >> s;
					}
					else {
						total += std::stoi(s);
						std::cin >> s; std::cin >> s;
					}
				}
				rawSizes[flatten(workingDir)] = total;
				totalUsedSize += total;
			}
		}
	}

	int requiredSize = 30000000 - (70000000 - totalUsedSize);
	int minSize = INT_MAX;
	std::unordered_map<std::string, int> sss;
	std::vector<int> v;

	for (auto parent = rawSizes.begin(); parent != rawSizes.end(); ++parent)
	{
		int total = parent->second;
		for (auto child = rawSizes.begin(); child != rawSizes.end(); ++child)
		{
			if (isSubString(child->first, parent->first)) total += child->second;
		}
		sss[parent->first] = total;
		v.push_back(total);
		if (total >= requiredSize && total < minSize) minSize = total;
	}

	std::sort(v.begin(), v.end());
	std::cout << minSize << std::endl;
}

void Day7::main()
{
	part2();
};