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

std::string outValue = "";

void Day17::out(int operand)
{
	unsigned long long opValue = getOperandValue(operand) % 8;

	res.append(std::to_string(opValue) + ",");
	outValue = std::to_string(opValue);
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

	int resPtr = 0;

	int timesCounter = 0;

	std::vector<unsigned long long> resHelper(16,0);

	int stepInc = 1;

	for (unsigned long long i = 0; i < std::pow(8, 16) - 1; i+= stepInc)
	{
		instructionPointer = 0;
		A = i;
		B = 0;
		C = 0;
		resPtr = 0;
		while (instructionPointer < instructions.size())
		{
			performInstruction(instructionPointer);

			if (instructionPointer > 0 && instructions[instructionPointer] == "5")
			{
				if (outValue != instructions[resPtr])
					break;

				//std::cout << "INC " << resPtr << " A VALUE " << i - resHelper[resPtr] << std::endl;
				resHelper[resPtr] = i;

				if (resPtr == 0 && stepInc == 1)
					stepInc = 8;
				else if (resPtr == 1 && stepInc == 8)
					stepInc = 512;
				else if (resPtr == 2 && stepInc == 512)
					stepInc = 2048;
				else if (resPtr == 3 && stepInc == 2048)
					stepInc = 4096;
				else if (resPtr == 4 && stepInc == 4096)
					stepInc = 65536;
				else if (resPtr == 5 && stepInc == 65536)
					stepInc = 262144;

				resPtr++;
			}

			instructionPointer += 2;
		}

		if (resPtr == 16)
			break;
		timesCounter++;
	}


	return res;
}

