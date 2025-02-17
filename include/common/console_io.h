#include <iostream>
#include "interface/reader.h"
#include "interface/writer.h"



class ConsoleReader : public IReader
{
public:
    std::string readline() override {
        std::string line;
        std::getline(std::cin, line);
        return line;
    }
};


class ConsoleWrither : public IWriter
{
public:
    void write(const std::string& text) override {
        std::cout << text;
    }
};