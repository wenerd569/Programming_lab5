#pragma once

#include "interface/reader.h"
#include "interface/writer.h"



class ConsoleReader : public IReader
{
public:
    std::string readline() override;
};


class ConsoleWrither : public IWriter
{
public:
    void write(const std::string& text) override;
};