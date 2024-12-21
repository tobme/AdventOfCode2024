#include "17.h"

#include <iostream>
#include <algorithm>
#include "../Helpers/Utilities.h"

Day17::Day17(std::shared_ptr<IInput>& _input) : input(_input)
{}

void Day17::adv(int operand)
{
	unsigned long long opValue = getOperandValue(operand);

	A = static_cast<unsigned long long>((double)A / std::pow(2, opValue));
}

void Day17::bxl(int operand)
{
	B ^= operand;
}

void Day17::bst(int operand)
{
	unsigned long long opValue = getOperandValue(operand);

	B = opValue % 8;
}

void Day17::jnz(int operand)
{
	if (A != 0)
	{
		instructionPointer = operand - 2;
	}
}

void Day17::bxc(int operand)
{
	B ^= C;
}

void Day17::out(int operand)
{
	unsigned long long opValue = getOperandValue(operand) % 8;

	res.append(std::to_string(opValue) + ",");
}

void Day17::bdv(int operand)
{
	unsigned long long opValue = getOperandValue(operand);

	B = static_cast<unsigned long long>((double)A / std::pow(2, opValue));
}

void Day17::cdv(int operand)
{
	unsigned long long opValue = getOperandValue(operand);

	C = static_cast<unsigned long long>((double)A / std::pow(2, opValue));
}



unsigned long long Day17::getOperandValue(int operand)
{
	switch (operand)
	{
	case 0:
	case 1:
	case 2:
	case 3:
		return operand;
	case 4:
		return A;
	case 5:
		return B;
	case 6:
		return C;
	case 7:
		throw;
	}
}

void Day17::performInstruction(int index)
{
	int opcode = std::stoi(instructions[index]);
	int operand = std::stoi(instructions[index+1]);

	switch (opcode)
	{
	case 0:
		adv(operand);
		break;
	case 1:
		bxl(operand);
		break;
	case 2:
		bst(operand);
		break;
	case 3:
		jnz(operand);
		break;
	case 4:
		bxc(operand);
		break;
	case 5:
		out(operand);
		break;
	case 6:
		bdv(operand);
		break;
	case 7:
		cdv(operand);
		break;
	default:
		throw;
	}
}

std::string Day17::runPart1()
{
	std::string s;

	std::getline(*input, s);
	auto ss = Util::split(s, ": ");
	A = std::stoi(ss[1]);

	std::getline(*input, s);
	ss = Util::split(s, ": ");
	B = std::stoi(ss[1]);

	std::getline(*input, s);
	ss = Util::split(s, ": ");
	C = std::stoi(ss[1]);

	std::getline(*input, s);
	std::getline(*input, s);
	ss = Util::split(s, ": ");
	instructions = Util::split(ss[1], ",");

	while (instructionPointer < instructions.size())
	{
		performInstruction(instructionPointer);
		instructionPointer += 2;
	}
	return res;
}

std::string Day17::runPart2()
{
	std::string s;

	std::getline(*input, s);
	auto ss = Util::split(s, ": ");
	A = std::stoi(ss[1]);
	A = 117440;

	std::getline(*input, s);
	ss = Util::split(s, ": ");
	B = std::stoi(ss[1]);

	std::getline(*input, s);
	ss = Util::split(s, ": ");
	C = std::stoi(ss[1]);

	std::getline(*input, s);
	std::getline(*input, s);
	ss = Util::split(s, ": ");
	instructions = Util::split(ss[1], ",");

	while (instructionPointer < instructions.size())
	{
		performInstruction(instructionPointer);
		instructionPointer += 2;
	}
	return res;
}

