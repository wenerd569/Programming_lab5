#pragma once

#include <fstream>
#include "interface/reader.h"
#include "interface/writer.h"

class FileReader : public IReader
{
    std::ifstream file;
public:
    FileReader(std::string filename);

    std::string readline() override;
};


class FileWriter : public IWriter
{
    std::ofstream file;
public:
    FileWriter(std::string filename);

    void write(const std::string& text) override;
};