
#include "frontend/commands/collection_interacts/print_field_ascengroup_counting_by_nameding_nationality_command.hpp"
#include <magic_enum/magic_enum.hpp>
#include <string>

PrintFieldAscengroupCountingByNamedingNationalityCommand::
    PrintFieldAscengroupCountingByNamedingNationalityCommand(
        std::shared_ptr<IOInterface> ioInterface,
        std::shared_ptr<CollectionService> collectionService)
    : Command(ioInterface,
              " : вывести значения поля nationality всех элементов в порядке возрастания"),
      collectionService { collectionService } {};

void PrintFieldAscengroupCountingByNamedingNationalityCommand::execute(
    std::vector<std::string> &args)
{
    if ( ! getZeroArg(args) ) {
        return;
    }
    auto rsp = collectionService->getFieldAscendingNationality();
    if ( rsp.getStatusCode() == Response<std::map<long, Country>>::OK ) {
        for ( std::pair<long, Country> line : rsp.getData() ) {
            std::string countryName = (std::string)magic_enum::enum_name(line.second);
            io->write(std::to_string(line.first) + " : " + countryName + "\n");
        }
    } else {
        printStatus(std::move(rsp));
    }
}
