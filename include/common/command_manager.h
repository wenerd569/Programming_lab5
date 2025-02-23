#pragma once

#include <unordered_map>
#include <string>
#include "commands/commands.h"

class Command;


class CommandManager{
protected:
    std::unordered_map<std::string, Command*> commands;
public:
    void execute(std::string& line);
    void addCommand(Command* coomand, std::string cmmandName);

    std::unordered_map<std::string, Command*>::const_iterator begin();
    std::unordered_map<std::string, Command*>::const_iterator end();
};
