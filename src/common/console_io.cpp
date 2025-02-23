#pragma once

#include <iostream>
#include "common/console_io.h"

std::string ConsoleReader::readline() {
    std::string line;
    std::getline(std::cin, line);
    return line;
}

void ConsoleWrither::write(const std::string& text) {
    std::cout << text;
}