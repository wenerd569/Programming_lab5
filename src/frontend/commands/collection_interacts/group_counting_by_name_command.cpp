
#include "frontend/commands/collection_interacts/group_counting_by_name_command.hpp"
#include <string>
#include <utility>
#include <vector>

GroupCountingByNameCommand::GroupCountingByNameCommand(
    std::shared_ptr<IOInterface> ioInterface, std::shared_ptr<CollectionService> collectionService)
    : Command(
          ioInterface,
          " : сгруппировать элементы коллекции по значению поля name, вывести количество элементов в каждой группе"),
      collectionService { collectionService } {};

void GroupCountingByNameCommand::execute(std::vector<std::string> &args)
{
    if ( ! getZeroArg(args) ) {
        return;
    }
    auto rsp = collectionService->groupCountingByName();
    if ( rsp.getStatusCode() == Response<std::map<std::string, int>>::OK ) {
        for ( std::pair<std::string, int> line : rsp.getData() ) {
            io->write(line.first + " : " + std::to_string(line.second) + "\n");
        }
    } else {
        printStatus(std::move(rsp));
    }
}
