#pragma once

#include "frontend/commands/command.hpp"
#include <memory>
#include <string>
#include <unordered_map>

class Command;

class CommandManager {
protected:
    std::unordered_map<std::string, std::unique_ptr<Command>> commands;

public:
    void execute (std::string &line);
    void addCommand (std::unique_ptr<Command> coomand, std::string commandName);

    const std::unordered_map<std::string, std::unique_ptr<Command>> &getCommands ();
};
