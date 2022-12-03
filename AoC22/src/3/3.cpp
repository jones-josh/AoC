#include "3.h"

#include <iostream>
#include <string>
#include <unordered_set>

void Day3::part1()
{
	std::string s;
	std::cin >> s;
	int p = 0;
	while (s != "q") {
		std::unordered_set<char> set;
		std::unordered_set<char> seen;
		std::string c1 = s.substr(0, s.size() / 2);
		std::string c2 = s.substr(s.size() / 2, s.size() / 2);

		for (char c : c1) set.insert(c);
		for (char c : c2) {
			if (set.contains(c) && !seen.contains(c)) {
				p += (c >= 'a' && c <= 'z') ? (c - 'a' + 1) : (c - 'A' + 27);
				seen.insert(c);
			}
		}
		std::cin >> s;
	}
	std::cout << p << std::endl;
}

void Day3::part2()
{
	std::string s;
	std::cin >> s;
	int p = 0;
	while (s != "q") {
		std::unordered_set<char> set1;
		std::unordered_set<char> set2;

		for (char c : s) set1.insert(c);

		std::cin >> s;
		for (char c : s) if (set1.contains(c)) set2.insert(c);

		set1.clear();
		std::cin >> s;
		for (char c : s) if (set2.contains(c)) set1.insert(c);

		for (char c : set1) {
			p += (c >= 'a' && c <= 'z') ? (c - 'a' + 1) : (c - 'A' + 27);
		}
		std::cin >> s;
	}
	std::cout << p << std::endl;
}

void Day3::main()
{
	part2();
}
