#pragma once

#include "frontend/interface/reader.hpp"
#include "frontend/interface/writer.hpp"
#include <fstream>

class FileReader : public IReader {
    std::ifstream file;

public:
    FileReader(std::string filename);

    std::string readline () override;
    bool isEndOfReader () override;
    IReader::ReaderType getType () override;
};

class FileWriter : public IWriter {
    std::ofstream file;

public:
    FileWriter(std::string filename);

    void write (const std::string &text) override;
    IWriter::WriterType getType () override;
};