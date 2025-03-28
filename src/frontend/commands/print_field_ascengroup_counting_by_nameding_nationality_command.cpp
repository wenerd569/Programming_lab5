
#include "frontend/commands/print_field_ascengroup_counting_by_nameding_nationality_command.hpp"

PrintFieldAscengroupCountingByNamedingNationalityCommand::
    PrintFieldAscengroupCountingByNamedingNationalityCommand(
        std::shared_ptr<IOInterface> ioInterface,
        std::shared_ptr<CommandHandler> comandManager,
        std::shared_ptr<CollectionService> collectionManager)
    : Command(ioInterface, comandManager, collectionManager) {};

void PrintFieldAscengroupCountingByNamedingNationalityCommand::execute(
    std::vector<std::string> &args)
{
    if ( ! getZeroArg(args) ) {
        return;
    }
    io->write("Я НЕ ПОНЯЛ ЧТО ЭТО ЗНАЧИТ\n");
}

std::string PrintFieldAscengroupCountingByNamedingNationalityCommand::getDescription()
{
    return " : вывести значения поля nationality всех элементов в порядке возрастания";
}
