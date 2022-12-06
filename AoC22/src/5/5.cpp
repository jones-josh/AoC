#include "5.h"
#include <string>
#include <iostream>
#include <vector>
#include <stack>

void Day5::part1()
{
	std::string s;
	std::vector<std::string> v;
	std::getline(std::cin, s);

	while (s != "")
	{
		v.push_back(s);
		std::getline(std::cin, s);
	}

	v.pop_back();
	int numStacks = (v[0].size() + 1) / 4;

	std::vector<std::stack<char>> stacks(numStacks);
	for (auto row = v.rbegin(); row != v.rend(); ++row)
	{
		for (int i = 0; i < row->size(); ++i)
		{
			char c = row->at(i);
			if (c >= 'A' && c <= 'Z')
			{
				stacks[(i - 1) / 4].push(c);
			}
		}
	}

	std::cin >> s;
	while (s != "q")
	{
		int count;
		std::cin >> count;
		std::cin >> s; // skip "from"
		int from;
		std::cin >> from;
		std::cin >> s; // skip "to"
		int to;
		std::cin >> to;

		for (int i = 0; i < count; ++i)
		{
			char c = stacks[from-1].top();
			stacks[from-1].pop();
			stacks[to-1].push(c);
		}
		std::cin >> s;
	}

	for (auto st : stacks) std::cout << st.top();
	std::cout << std::endl;
}

void Day5::part2()
{
	std::string s;
	std::vector<std::string> v;
	std::getline(std::cin, s);

	while (s != "")
	{
		v.push_back(s);
		std::getline(std::cin, s);
	}

	v.pop_back();
	int numStacks = (v[0].size() + 1) / 4;

	std::vector<std::stack<char>> stacks(numStacks);
	for (auto row = v.rbegin(); row != v.rend(); ++row)
	{
		for (int i = 0; i < row->size(); ++i)
		{
			char c = row->at(i);
			if (c >= 'A' && c <= 'Z')
			{
				stacks[(i - 1) / 4].push(c);
			}
		}
	}

	std::cin >> s;
	while (s != "q")
	{
		int count;
		std::cin >> count;
		std::cin >> s; // skip "from"
		int from;
		std::cin >> from;
		std::cin >> s; // skip "to"
		int to;
		std::cin >> to;

		std::stack<char> temp;

		for (int i = 0; i < count; ++i)
		{
			char c = stacks[from - 1].top();
			stacks[from - 1].pop();
			temp.push(c);
		}

		for (int i = 0; i < count; ++i)
		{
			char c = temp.top();
			temp.pop();
			stacks[to - 1].push(c);
		}
		std::cin >> s;
	}

	for (auto st : stacks) std::cout << st.top();
	std::cout << std::endl;
}

void Day5::main()
{
	part2();
};