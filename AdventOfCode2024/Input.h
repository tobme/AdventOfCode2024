#pragma once

#include "IInput.h"

class Input : public IInput
{
	Input(const std::string& day);

	void resetStream() override;

	Matrix toMatrix() override;
};

