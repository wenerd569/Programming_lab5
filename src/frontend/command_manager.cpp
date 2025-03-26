#include <memory>
#include <sstream>
#include <string>

#include "frontend/command_manager.hpp"

void CommandManager::execute(std::string &line)
{
    char delimiter = ' ';
    std::stringstream ss { line };

    std::string command;
    std::getline(ss, command, delimiter);
    if ( commands.contains(command) ) {
        std::vector<std::string> args;
        std::string item;
        while ( std::getline(ss, item, delimiter) ) {
            args.push_back(item);
        }
        commands[command]->execute(args);
    };
}

void CommandManager::addCommand(std::unique_ptr<Command> command, std::string commandName)
{
    commands[commandName] = std::move(command);
}

const std::unordered_map<std::string, std::unique_ptr<Command>> &CommandManager::getCommands()
{
    return commands;
}