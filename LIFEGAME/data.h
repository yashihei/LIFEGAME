#pragma once
#include <unordered_map>
#include <string>

class Data {
public:
	Data();
	void load(std::string fn, std::string n);
	int getHandle(std::string n);
private:
	std::unordered_map<std::string, int> dataMap;
};

