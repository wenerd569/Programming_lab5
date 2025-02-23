#include "common/command_manager.h"
#include <sstream>
#include <string>


void CommandManager::execute(std::string& line){
    char delimiter = ' ';
    std::stringstream ss{line};

    std::string command;
    std::getline(ss, command, delimiter);
    if (commands.contains(command)){
        std::vector<std::string> args;
        std::string item;
        while (std::getline(ss, item, delimiter)){
            args.push_back(item);
        }
        commands[command].execute(args);
    };
}

void CommandManager::addCommand(Command& command, std::string commandName){
    commands[commandName] = command;
}

std::unordered_map<std::string, Command>::const_iterator CommandManager::begin(){
    return commands.begin();
}

std::unordered_map<std::string, Command>::const_iterator CommandManager::end(){
    return commands.end();
}