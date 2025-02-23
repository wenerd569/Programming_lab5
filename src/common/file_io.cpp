#pragma once

#include <fstream>
#include "common/file_io.h"

FileReader::FileReader(std::string filename) : file{filename} {}

std::string FileReader::readline(){
    std::string res;
    std::getline(file, res);
    return res;
}


FileWriter::FileWriter(std::string filename) : file{filename} {}

void FileWriter::write(const std::string& text){
    file << text;
}