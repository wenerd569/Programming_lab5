#pragma once

#include "common/interface/reader.hpp"
#include "common/interface/writer.hpp"

class ConsoleReader : public IReader {
public:
    std::string readline () override;
    bool isEndOfReader () override;
    IReader::ReaderType getType () override;
};

class ConsoleWrither : public IWriter {
public:
    void write (const std::string &text) override;
    IWriter::WriterType getType () override;
};