
#include "frontend/commands/collection_interacts/info_command.hpp"
#include <utility>

InfoCommand::InfoCommand(std::shared_ptr<IOInterface> ioInterface,
                         std::shared_ptr<CollectionService> collectionService)
    : Command(
          ioInterface,
          " : вывести в стандартный поток вывода информацию о коллекции (тип, дата инициализации, количество элементов и т.д.)"),
      collectionService { collectionService } {};

void InfoCommand::execute(std::vector<std::string> &args)
{
    if ( ! getZeroArg(args) ) {
        return;
    }

    auto rsp = collectionService->getInfo();

    if ( rsp.getStatusCode() == Response<CollectionInfo>::OK ) {
        io->write(toString(rsp.getData()) + '\n');
    } else {
        printStatus(std::move(rsp));
    }
}