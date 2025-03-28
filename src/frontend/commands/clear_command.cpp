
#include "frontend/commands/clear_command.hpp"

ClearCommand::ClearCommand(std::shared_ptr<IOInterface> ioInterface,
                           std::shared_ptr<CommandHandler> comandManager,
                           std::shared_ptr<CollectionService> collectionManager)
    : Command(ioInterface, comandManager, collectionManager) {};

void ClearCommand::execute(std::vector<std::string> &args)
{
    if ( ! getZeroArg(args) ) {
        return;
    }
    printStatus(collectionManager->clear());
}

std::string ClearCommand::getDescription()
{
    return " : очистить коллекцию";
}
