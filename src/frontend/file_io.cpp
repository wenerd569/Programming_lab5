#include "frontend/file_io.hpp"
#include <fstream>
#include <ios>

FileReader::FileReader(std::string filename)
{
    file = std::ifstream { filename };
    if ( ! file ) {
        throw std::ios_base::failure { "Не удалось открыть файл" };
    }
}

std::string FileReader::readline()
{
    std::string res;
    std::getline(file, res);
    return res;
}

bool FileReader::isEndOfReader()
{
    return file.peek() == std::ifstream::traits_type::eof();
}

IReader::ReaderType FileReader::getType()
{
    return IReader::File;
}

FileWriter::FileWriter(std::string filename)
{
    file = std::ofstream { filename };
    if ( ! file ) {
        throw std::ios_base::failure { "Не удалось открыть файл" };
    }
}

void FileWriter::write(const std::string &text)
{
    file << text;
}

IWriter::WriterType FileWriter::getType()
{
    return WriterType::File;
}