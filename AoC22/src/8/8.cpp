#include "8.h"

#include <iostream>
#include <string>
#include <vector>
#include <set>

void Day8::part1()
{
	std::string s;
	std::vector<std::vector<char>> cs;
	std::cin >> s;

	while (s != "q")
	{
		cs.push_back(std::vector<char>(s.begin(), s.end()));
		std::cin >> s;
	}

	int width = cs[0].size();
	int height = cs.size();

	std::set<std::pair<int, int>> visible;

	for (int i = 0; i < width; ++i)
	{
		visible.emplace(i, 0);
		
		char highestSeen = cs[0][i];
		for (int j = 1; j < height - 1; ++j)
		{
			if (cs[j][i] > highestSeen)
			{
				highestSeen = cs[j][i];
				visible.emplace(i, j);
			}
		}

		visible.emplace(i, height - 1);

		highestSeen = cs[height - 1][i];
		for (int j = height - 2; j > 0; --j)
		{
			if (cs[j][i] > highestSeen)
			{
				highestSeen = cs[j][i];
				visible.emplace(i, j);
			}
		}
	}

	for (int i = 0; i < height; ++i)
	{
		visible.emplace(0, i);
		char highestSeen = cs[i][0];
		for (int j = 1; j < width - 1; ++j)
		{
			if (cs[i][j] > highestSeen)
			{
				highestSeen = cs[i][j];
				visible.emplace(j, i);
			}
		}

		visible.emplace(width - 1, i);
		highestSeen = cs[i][width - 1];
		for (int j = width - 2; j > 0; --j)
		{
			if (cs[i][j] > highestSeen)
			{
				highestSeen = cs[i][j];
				visible.emplace(j, i);
			}
		}
	}


	std::cout << visible.size() << std::endl;
}

void Day8::part2()
{
	std::string s;
	std::vector<std::vector<char>> cs;
	std::cin >> s;

	while (s != "q")
	{
		cs.push_back(std::vector<char>(s.begin(), s.end()));
		std::cin >> s;
	}

	int width = cs[0].size();
	int height = cs.size();

	int bestScore = 0;

	for (int x = 0; x < width; ++x)
	{
		for (int y = 0; y < height; ++y)
		{
			int score = 1;
			int seen = 0;

			for (int dx = 1; x + dx < width; ++dx)
			{
				++seen;
				if (cs[y][x + dx] >= cs[y][x]) break;
			}
			score *= seen;

			seen = 0;
			for (int dx = 1; x - dx >= 0; ++dx)
			{
				++seen;
				if (cs[y][x - dx] >= cs[y][x]) break;
			}
			score *= seen;

			seen = 0;
			for (int dy = 1; y + dy < height; ++dy)
			{
				++seen;
				if (cs[y + dy][x] >= cs[y][x]) break;
			}
			score *= seen;

			seen = 0;
			for (int dy = 1; y - dy >= 0; ++dy)
			{
				++seen;
				if (cs[y - dy][x] >= cs[y][x]) break;
			}
			score *= seen;

			if (score > bestScore) bestScore = score;
		}
	}

	std::cout << bestScore << std::endl;
}

void Day8::main()
{
	Day8::part2();
}
