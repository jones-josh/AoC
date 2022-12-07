#include "common.h"
#include <iostream>
#include <memory>
#include <string>
#include <unordered_set>

std::vector<std::vector<int>> readInts()
{
	std::string prev = "";
	std::string cur;

	std::vector<std::vector<int>> nums{ {} };
	std::getline(std::cin, cur);

	while (cur != "" || prev != "") {
		if (cur == "") {
			nums.push_back({});
		}
		else nums.at(nums.size() - 1).push_back(std::stoi(cur));
		prev = cur;
		std::getline(std::cin, cur);
	}

	nums.pop_back();
	return nums;
}

std::vector<std::string> split(std::string s, std::string delims)
{
	std::unordered_set<char> delimsSet;
	for (char d : delims) delimsSet.insert(d);

	std::vector<std::string> v;
	std::string current = "";
	for (char c : s) {
		if (delimsSet.contains(c)) {
			v.push_back(current);
			current = "";
		}
		else {
			current += c;
		}
	}
	v.push_back(current);

	return v;
}

bool isSubString(const std::string& str, const std::string& sub)
{
	return str.size() > sub.size() && str.find(sub) == 0;
}