#include <unordered_map>
#include <string>
#include "../interface/command.h"
#include "../common/.h"



class CommandManager{
    std::unordered_map<std::string, ICommand> commands;
    
    public:
    
    void execute(){
        
    }

    void addCommand(ICommand& coomand, std::string cmmandName){
        commands[commandName] = command; //!!!!!!!!!!!
    }
}