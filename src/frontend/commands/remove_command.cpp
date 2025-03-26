
#include "frontend/commands/remove_command.hpp"

RemoveCommand::RemoveCommand(std::shared_ptr<IOInterface> ioInterface, std::shared_ptr<CommandManager> comandManager, std::shared_ptr<CollectionManager> collectionManager):
    Command(ioInterface, comandManager, collectionManager) {};

void RemoveCommand::execute(std::vector<std::string>& args){
    long id;
    if (!getOneNumArg<long>(args, id)) return;
    printStatus(collectionManager->remove(id));
}
std::string RemoveCommand::getDescription(){
    return " id : удалить элемент из коллекции по его id";
}
