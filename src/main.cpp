
#include "common/exeptions/program_terminate_exeption.hpp"
#include "frontend/program.hpp"
#include <iostream>
#include <ostream>

int main (int argc, char *argv[])
{
    if ( argc != 2 ) {
        std::cerr
            << "Программа принимает на вход 1 аргумент, который должен содержать название файла коллекции"
            << std::endl;
        exit(1);
    }
    std::string fileName = argv[1];
    std::filesystem::path filePath = std::filesystem::path { fileName };
    Program program = Program(filePath);
    try {
        program.start();
    } catch ( ProgramTerminateException e ) {
        std::cout << e.what() << std::endl;
    } catch ( std::ios::failure e ) {
        std::cout << e.what() << std::endl;
    }
}
