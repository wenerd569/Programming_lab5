#pragma once

#include "interface/io_interface.h"
#include "common/colection_manager.h"
#include "common/command_manager.h"

class CommandManager;

class Command{
protected:
    IOInterface* io;
    CommandManager* commandManager;
    CollectionManager* collectionManager;
public:
    Command(IOInterface* ioInterface, CommandManager* comandManager, CollectionManager* collectionManager);
    virtual void execute(std::vector<std::string>& args) = 0;
    virtual std::string getDescription() = 0;
    virtual ~Command() {};  
};