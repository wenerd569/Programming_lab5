#pragma once

#include <string>

class IReader{
    public:
    virtual std::string readline() = 0;
    virtual ~IReader() {};
};