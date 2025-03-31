
#include "frontend/commands/collection_interacts/show_command.hpp"
#include <vector>

ShowCommand::ShowCommand(std::shared_ptr<IOInterface> ioInterface,
                         std::shared_ptr<CollectionService> collectionService)
    : Command(
          ioInterface,
          " : вывести в стандартный поток вывода все элементы коллекции в строковом представлении"),
      collectionService { collectionService } {};

void ShowCommand::execute(std::vector<std::string> &args)
{
    if ( ! getZeroArg(args) ) {
        return;
    }
    printPersonVector(collectionService->getAllElement());
}