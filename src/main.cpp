
#include "frontend/program.hpp"
#include <iostream>

int main(int argc, char* argv[]){
    if(argc != 2){
        std::cerr << "Программа принимает на вход 1 аргумент, который должен содержать название файла коллекции" << std::endl;
        exit(1);
    }
    std::string fileName = argv[1];
    std::filesystem::path filePath = std::filesystem::path{fileName};
    Program program = Program(filePath);
    program.start();
}



