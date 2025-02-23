#pragma once

#include <string>

class IWriter{
    public:
    virtual void write(const std::string& text) = 0;
    virtual ~IWriter() {};
};
