
#include "frontend/commands/collection_interacts/clear_command.hpp"

ClearCommand::ClearCommand(std::shared_ptr<IOInterface> ioInterface,
                           std::shared_ptr<CollectionService> collectionService)
    : Command(ioInterface, " : очистить коллекцию"), collectionService { collectionService } {};

void ClearCommand::execute(std::vector<std::string> &args)
{
    if ( ! getZeroArg(args) ) {
        return;
    }
    printStatus(collectionService->clear());
}
