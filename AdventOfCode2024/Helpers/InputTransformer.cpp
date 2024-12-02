#include "InputTransformer.h"

#include "Utilities.h"

template<typename T>
std::vector<std::vector<T>> ToMatrix(std::shared_ptr<IInput>& input, std::function<T(std::string)> func, const std::string& delimeter)
{
    input->resetStream();

    std::vector<std::vector<T>> matrix;

    std::string s;

    while (std::getline(*input, s))
    {
        auto line = Util::split(s, delimeter);
        std::vector<T> row{};

        for (const std::string& c : line)
        {
            row.push_back(func(c));
        }

        matrix.push_back(row);
    }

    return matrix;
}

template std::vector<std::vector<int>> ToMatrix<int>(std::shared_ptr<IInput>& input, std::function<int(std::string)> func, const std::string& delimeter);