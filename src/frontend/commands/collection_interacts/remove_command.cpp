
#include "frontend/commands/collection_interacts/remove_command.hpp"

RemoveCommand::RemoveCommand(std::shared_ptr<IOInterface> ioInterface,
                             std::shared_ptr<CollectionService> collectionService)
    : Command(ioInterface, " id : удалить элемент из коллекции по его id"),
      collectionService { collectionService } {};

void RemoveCommand::execute(std::vector<std::string> &args)
{
    long id;
    if ( ! getOneNumArg<long>(args, id) ) {
        return;
    }
    printStatus(collectionService->remove(id));
}
