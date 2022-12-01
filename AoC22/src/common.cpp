#include "common.h"
#include <iostream>
#include <memory>
#include <string>

std::unique_ptr<std::vector<std::vector<int>>> readInts()
{
	std::string prev = "";
	std::string cur;

	auto nums = std::make_unique<std::vector<std::vector<int>>>();
	nums->push_back({});
	std::getline(std::cin, cur);

	while (cur != "" || prev != "") {
		if (cur == "") {
			nums->push_back({});
		}
		else nums->at(nums->size() - 1).push_back(std::stoi(cur));
		prev = cur;
		std::getline(std::cin, cur);
	}

	nums->pop_back();
	return nums;
}
