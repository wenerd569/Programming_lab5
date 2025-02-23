#pragma once

#include "interface/io_interface.h"
#include "interface/reader.h"
#include "interface/writer.h"

class IOManager : public IOInterface  
{
protected:
    enum InputMode
    {
        Console,
        File
    };
    InputMode inputMode;
    IReader* reader;
    IWriter* writer;
public:   
    IOManager();
    ~IOManager();
    
    void switchToInputFromeFile(std::string file);
    void switchToConsoleInput();
    
    std::string readline() override;
    void write(const std::string& text) override;
};