#pragma once

#include "ChallengeSelector.h"

#include "InputSelector.h"
#include "DataInput.cpp"

#include <iostream>

int main()
{
	// Get day
	std::string day = "1";

	auto part = InputSelector::GetInputFromList({ "Part1", "Part2"});

	auto dataSelection = InputSelector::GetInputFromList({ "Test Data", "Real Data" });

	DataInputEnvironment env = dataSelection == "1" ? DataInputEnvironment::TEST_DATA : DataInputEnvironment::REAL_DATA;

	auto input = fetchData(day, env);

	auto challengeSelector = std::make_unique<ChallengeSelector>(day, input);

	std::string answer = "";

	if (part == "1")
	{
		answer = challengeSelector->runChallengePart1();
	}
	else
	{
		answer = challengeSelector->runChallengePart2();
	}
	
	bool doSendData = InputSelector::GetBoolFromQuestion("Send Answer?");

	if (doSendData)
		sendData(answer, env);

	return 0;
}