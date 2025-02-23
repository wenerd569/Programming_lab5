#pragma once

#include "common/io_manager.h"
#include "common/console_io.h"
#include "common/file_io.h"

IOManager::IOManager() : reader{new ConsoleReader}, writer{new ConsoleWrither}, inputMode(Console){}

IOManager::~IOManager() {
    delete reader;
    delete writer;
}

void IOManager::switchToInputFromeFile(std::string file){
    if (inputMode == Console){
        delete reader;
        reader = new FileReader(file);
        inputMode = File;
    }
}
void IOManager::switchToConsoleInput(){
    if (inputMode == File){
        delete reader;
        reader = new ConsoleReader();
        inputMode = Console;
    }
}
    
std::string IOManager::readline(){
    return reader->readline();
}

void IOManager::write(const std::string& text){
    return writer->write(text);
}