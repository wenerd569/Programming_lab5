
#include "frontend/console_io.hpp"
#include <iostream>

std::string ConsoleReader::readline()
{
    std::string line;
    std::getline(std::cin, line);
    return line;
}

bool ConsoleReader::isEndOfReader()
{
    return false;
}

IReader::ReaderType ConsoleReader::getType()
{
    return IReader::Console;
}

void ConsoleWrither::write(const std::string &text)
{
    std::cout << text;
}

IWriter::WriterType ConsoleWrither::getType()
{
    return WriterType::Console;
}