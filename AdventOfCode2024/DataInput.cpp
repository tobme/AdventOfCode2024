#pragma once

#include "DataInputEnvironment.h"

#include "IInput.h"

#include <memory>
#include <string>

static std::shared_ptr<IInput> fetchData(const std::string& day, const DataInputEnvironment& env)
{
	return nullptr;
}

static void sendData(const std::string& answer, const DataInputEnvironment& env)
{

}

