
#include "frontend/commands/show_command.hpp"
#include <vector>

ShowCommand::ShowCommand(std::shared_ptr<IOInterface> ioInterface,
                         std::shared_ptr<CommandManager> comandManager,
                         std::shared_ptr<CollectionManager> collectionManager)
    : Command(ioInterface, comandManager, collectionManager) {};

void ShowCommand::execute(std::vector<std::string> &args)
{
    if ( ! getZeroArg(args) ) {
        return;
    }
    printPersonVector(collectionManager->getAllElement());
}

std::string ShowCommand::getDescription()
{
    return " : вывести в стандартный поток вывода все элементы коллекции в строковом представлении";
}