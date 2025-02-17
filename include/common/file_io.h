#include <fstream>
#include "interface/reader.h"
#include "interface/writer.h"

class FileReader : public IReader
{
    std::ifstream file;
public:
    FileReader(std::string filename) : file{filename} {
    }


    std::string readline() override {
        std::string res;
        std::getline(file, res);
        return res;
    }
};


class FileWriter : public IWriter
{
    std::ofstream file;
public:
    FileWriter(std::string filename) : file{filename} {
    }

    void write(const std::string& text) override {
        file << text;
    }
};