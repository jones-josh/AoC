#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>

#include "1.h"
#include "../common.h"

void Day1::main()
{
	std::vector<std::vector<int>> nums = readInts();

	std::vector<int> sums;
	for (auto v : nums){
		sums.push_back(std::reduce(v.begin(), v.end()));
	}

	std::cout << *std::max_element(sums.begin(), sums.end()) << std::endl;
	std::sort(sums.begin(), sums.end(), std::greater<int>());
	int total = 0;
	for (size_t i = 0; i < 3; i++)
	{
		total += sums[i];
	}
	std::cout << total << std::endl;
}
