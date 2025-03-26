
#include "frontend/commands/group_counting_by_name_command.hpp"
#include <string>
#include <utility>
#include <vector>

GroupCountingByNameCommand::GroupCountingByNameCommand(
    std::shared_ptr<IOInterface> ioInterface,
    std::shared_ptr<CommandManager> comandManager,
    std::shared_ptr<CollectionManager> collectionManager)
    : Command(ioInterface, comandManager, collectionManager) {};

void GroupCountingByNameCommand::execute(std::vector<std::string> &args)
{
    if ( ! getZeroArg(args) ) {
        return;
    }
    auto rsp = collectionManager->groupCountingByName();
    if ( rsp.getStatusCode() == Response<std::map<std::string, int>>::OK ) {
        for ( std::pair<std::string, int> line : rsp.getData() ) {
            io->write(line.first + " : " + std::to_string(line.second) + "\n");
        }
    } else {
        printStatus(std::move(rsp));
    }
}

std::string GroupCountingByNameCommand::getDescription()
{
    return " : сгруппировать элементы коллекции по значению поля name, вывести количество элементов в каждой группе";
}
