#pragma once

#include <vector>
#include <string>

std::vector<std::vector<int>> readInts();
std::vector<std::string> split(std::string s, std::string delims);
bool isSubString(const std::string& str, const std::string& sub);