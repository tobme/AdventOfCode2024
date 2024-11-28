#pragma once

#include <fstream>
#include <vector>

using Matrix = std::vector<std::vector<char>>;

class IInput : public std::fstream
{
public:
	IInput(const std::string& day) : std::fstream(day) {}
	~IInput() = default;

	virtual void resetStream() = 0;

	virtual Matrix toMatrix() = 0;
};