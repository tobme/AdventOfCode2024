#include "21.h"

#include <iostream>
#include <algorithm>
#include<unordered_map>
#include "../Helpers/PairHash.h"

std::unordered_map<char, std::pair<int, int>> keyPad = { {'7', {0,0}}, {'8', {0,1}}, {'8', {0,2}}, {'4', {1,0}}, {'5', {1,1}}, {'6', {1,2}}, {'1', {2,0}}, {'2', {2,1}}, {'3', {2,2}}, {'0', {3,1}}, {'A', {3,2}} };
std::unordered_map<char, std::pair<int, int>> dirKeyPad = { {'^', {0,1}}, {'A', {0,2}}, {'<', {1,0}}, {'v', {1,1}}, {'>', {1,2}} };

Day21::Day21(std::shared_ptr<IInput>& _input) : input(_input)
{}

char moveHelper(std::pair<int, int>& currPos, const std::pair<int, int>& goalPos)
{
	if (currPos.first < goalPos.first)
	{
		currPos.first++;
		return 'v';
	}
	else if (currPos.first > goalPos.first)
	{
		currPos.first--;
		return '^';
	}

	if (currPos.second < goalPos.second)
	{
		currPos.second++;
		return '>';
	}
	else if (currPos.second > goalPos.second)
	{
		currPos.second--;
		return '<';
	}


	return ' ';
}

std::unordered_map < std::string, std::string > memory;

std::string move(std::vector < std::pair<int, int>>& pos, const std::pair<int, int>& goalPos, int currLayer, int maxLayer)
{
	std::string id = std::to_string(pos[currLayer].first) + "_" + std::to_string(pos[currLayer].second) + ":" + std::to_string(goalPos.first) + "_" + std::to_string(goalPos.second) + ":" + std::to_string(currLayer);

	if (memory.contains(id))
		return memory[id];

	std::string res = "";

	while (pos[currLayer] != goalPos)
	{
		char d = moveHelper(pos[currLayer], goalPos);

		if (currLayer != maxLayer)
		{
			res.append(move(pos, dirKeyPad[d], currLayer + 1, maxLayer));
		}
		else
			res += d;
	}

	if (currLayer != maxLayer)
	{
		res.append(move(pos, dirKeyPad['A'], currLayer + 1, maxLayer));
	}

	if (currLayer == maxLayer)
		res.append("A"); // PRESS A

	memory[id] = res;

	return res;
}

std::string Day21::runPart1()
{


	std::string s;
	
	int totRes = 0;
	std::pair<int, int> dirKeyPadPos = { 0,2 };
	std::pair<int, int> keyPadPos = { 3,2 };

	std::vector < std::pair<int, int>> dirKeyPadPosses{ 3, dirKeyPadPos};
	while (std::getline(*input, s))
	{
		std::string numberId = s;
		numberId.pop_back();
		int numberIdI = std::stoi(numberId);
		std::string res = "";

		for (auto& c : s)
		{
			std::pair<int, int> goalPos = keyPad[c];

			while (keyPadPos != goalPos)
			{
				char d = moveHelper(keyPadPos, goalPos);
				std::string tmp = move(dirKeyPadPosses, dirKeyPad[d], 0, 1);
				res += tmp;
			}

			std::string tmp = move(dirKeyPadPosses, dirKeyPad['A'], 0, 1);
			res += tmp;
		}
		auto size = res.size();
		totRes += size * numberIdI;
	}
	return std::to_string(totRes);
}

std::string Day21::runPart2()
{
	return "";
}

