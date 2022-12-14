#include "9.h"
#include <string>
#include <iostream>
#include <set>
#include <array>
#include <vector>

void Day9::part1()
{
	std::string s;
	std::cin >> s;

	int headX = 0;
	int headY = 0;
	int tailX = 0;
	int tailY = 0;

	std::set<std::pair<int, int>> tailVisited;
	tailVisited.emplace(0, 0);

	while (s != "q")
	{
		int distance;
		std::cin >> distance;

		int dx = 0;
		int dy = 0;
		if (s == "R") dx = 1;
		else if (s == "L") dx = -1;
		else if (s == "U") dy = 1;
		else if (s == "D") dy = -1;

		for (int i = 0; i < distance; ++i) {
			headX += dx;
			headY += dy;

			int x = headX - tailX;
			int y = headY - tailY;
			
			if (std::abs(x) == 2 && std::abs(y) == 2) {
				tailX += x / 2;
				tailY += y / 2;
			}
			else if (std::abs(x) == 2) {
				tailX += x / 2;
				tailY += y;
			}
			else if (std::abs(y) == 2) {
				tailX += x;
				tailY += y / 2;
			}

			tailVisited.emplace(tailX, tailY);
		}

		std::cin >> s;
	}

	std::cout << tailVisited.size() << std::endl;
}

static void printRope(const uint64_t w, const uint64_t h, int sx, int sy, int hx, int hy, std::array<int, 9> txs, std::array<int, 9> tys) {
	std::vector<std::string> grid{h, std::string(w, '.')};

	grid[sy][sx] = 's';
	for (int i = 8; i >= 0; --i) grid[tys[i] + sy][txs[i] + sx] = ('0' + i + 1);
	grid[hy + sy][hx + sx] = 'H';

	for (auto row = grid.rbegin(); row != grid.rend(); ++row) std::cout << *row << std::endl;
	std::cout << std::endl;
}

static void printVisited(const uint64_t w, const uint64_t h, int sx, int sy, const std::set<std::pair<int,int>>& visited) {
	std::vector<std::string> grid{ h, std::string(w, '.') };

	for (auto [x, y] : visited) grid[y + sy][x + sx] = '#';
	grid[sy][sx] = 's';

	for (auto row = grid.rbegin(); row != grid.rend(); ++row) std::cout << *row << std::endl;
	std::cout << std::endl;
}

void Day9::part2()
{
	std::string s;
	std::cin >> s;

	int headX = 0;
	int headY = 0;

	std::array<int, 9> tailXs = { 0 };
	std::array<int, 9> tailYs = { 0 };

	std::set<std::pair<int, int>> tailVisited;
	tailVisited.emplace(0, 0);

	printRope(26, 21, 11, 5, headX, headY, tailXs, tailYs);

	while (s != "q")
	{
		int distance;
		std::cin >> distance;

		int dx = 0;
		int dy = 0;
		if (s == "R") dx = 1;
		else if (s == "L") dx = -1;
		else if (s == "U") dy = 1;
		else if (s == "D") dy = -1;

		for (int i = 0; i < distance; ++i) {
			headX += dx;
			headY += dy;

			int hx = headX;
			int hy = headY;

			for (int j = 0; j < 9; ++j) {
				int x = hx - tailXs[j];
				int y = hy - tailYs[j];
				if (std::abs(x) == 2) {
					tailXs[j] += x / 2;
					tailYs[j] += y;
				}
				else if (std::abs(y) == 2) {
					tailXs[j] += x;
					tailYs[j] += y / 2;
				}
				hx = tailXs[j];
				hy = tailYs[j];
			}
				
			tailVisited.emplace(tailXs[8], tailYs[8]);
		}

		std::cin >> s;
		printRope(26, 21, 11, 5, headX, headY, tailXs, tailYs);
	}

	printRope(26, 21, 11, 5, headX, headY, tailXs, tailYs);
	printVisited(26, 21, 11, 5, tailVisited);
	std::cout << tailVisited.size() << std::endl;

}

void Day9::main()
{
	part2();
}
