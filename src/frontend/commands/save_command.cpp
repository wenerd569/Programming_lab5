
#include "frontend/commands/save_command.hpp"

SaveCommand::SaveCommand(std::shared_ptr<IOInterface> ioInterface,
                         std::shared_ptr<CommandHandler> comandManager,
                         std::shared_ptr<CollectionService> collectionManager)
    : Command(ioInterface, comandManager, collectionManager) {};

void SaveCommand::execute(std::vector<std::string> &args)
{
    if ( ! getZeroArg(args) ) {
        return;
    }
    printStatus(collectionManager->save());
};

std::string SaveCommand::getDescription()
{
    return " : сохранить коллекцию в файл";
};
