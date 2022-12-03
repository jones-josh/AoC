#include "2.h"
#include "../common.h"
#include <string>
#include <iostream>

void Day2::part1()
{
	std::string opp;
	int score = 0;
	int handScores[3] = { 1, 2, 3 };
	int gameScores[3] = { 0, 3, 6 };
	for (int i = 0; ; ++i) {
		std::string s;
		std::cin >> s;
		if (s == "q") break;
		if (i % 2 == 0) {
			opp = s;
		}
		else {
			score += handScores[s[0] - 'X'];
			int scoreIndex = (s[0] - 'X') - (opp[0] - 'A') + 1;
			scoreIndex = scoreIndex < 0 ? scoreIndex + 3 : scoreIndex % 3;
			score += gameScores[scoreIndex];
		}
	}
	std::cout << score << std::endl;
}

void Day2::part2()
{
	std::string opp;
	int score = 0;
	int handScores[3] = { 1, 2, 3 };
	int gameScores[3] = { 0, 3, 6 };
	for (int i = 0; ; ++i) {
		std::string s;
		std::cin >> s;
		if (s == "q") break;
		if (i % 2 == 0) {
			opp = s;
		}
		else {
			score += gameScores[s[0] - 'X'];
			int throwIndex = (opp[0] - 'A') + (s[0] - 'X') - 1;
			throwIndex = throwIndex < 0 ? throwIndex + 3 : throwIndex % 3;
			score += handScores[throwIndex];
		}
	}
	std::cout << score << std::endl;
}

void Day2::main() {
	part2();
}