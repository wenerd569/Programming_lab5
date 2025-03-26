
#include "frontend/commands/exit_command.hpp"

ExitCommand::ExitCommand(std::shared_ptr<IOInterface> ioInterface, std::shared_ptr<CommandManager> comandManager, std::shared_ptr<CollectionManager> collectionManager):
Command(ioInterface, comandManager, collectionManager) {};

void ExitCommand::execute(std::vector<std::string>& args){
    if (!getZeroArg(args)) return;
    exit(0);
}
std::string ExitCommand::getDescription(){
    return " : завершить программу (без сохранения в файл)";
}
