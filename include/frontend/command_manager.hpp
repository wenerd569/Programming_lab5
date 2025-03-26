#pragma once

#include <memory>
#include <unordered_map>
#include <string>
#include "frontend/commands/command.hpp"

class Command;

class CommandManager{
protected:
    std::unordered_map<std::string, std::unique_ptr<Command>> commands;
public:
    void execute(std::string& line);
    void addCommand(std::unique_ptr<Command> coomand, std::string commandName);

    const std::unordered_map<std::string, std::unique_ptr<Command>>& getCommands();
};
