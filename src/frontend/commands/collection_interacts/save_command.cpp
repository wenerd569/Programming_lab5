
#include "frontend/commands/collection_interacts/save_command.hpp"

SaveCommand::SaveCommand(std::shared_ptr<IOInterface> ioInterface,
                         std::shared_ptr<CollectionService> collectionService)
    : Command(ioInterface, ""), collectionService { collectionService } {};

void SaveCommand::execute(std::vector<std::string> &args)
{
    if ( ! getZeroArg(args) ) {
        return;
    }
    printStatus(collectionService->save());
}