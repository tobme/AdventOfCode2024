#include "Input.h"

#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>

Input::Input(const std::string& day) : IInput(day)
{

}

void Input::resetStream()
{
    this->clear();
    this->seekg(0);
}

Matrix Input::toMatrix()
{
    resetStream();

    Matrix matrix{};

    std::string s;

    while (std::getline(*this, s))
    {
        std::vector<char> line;

        for (char c : s)
        {
            line.push_back(c);
        }

        matrix.push_back(line);
    }

    return matrix;
}