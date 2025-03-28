
#include "frontend/commands/info_command.hpp"
#include <utility>

InfoCommand::InfoCommand(std::shared_ptr<IOInterface> ioInterface,
                         std::shared_ptr<CommandHandler> comandManager,
                         std::shared_ptr<CollectionService> collectionManager)
    : Command(ioInterface, comandManager, collectionManager) {};

void InfoCommand::execute(std::vector<std::string> &args)
{
    if ( ! getZeroArg(args) ) {
        return;
    }

    auto rsp = collectionManager->getInfo();

    if ( rsp.getStatusCode() == Response<CollectionInfo>::OK ) {
        io->write(toString(rsp.getData()) + '\n');
    } else {
        printStatus(std::move(rsp));
    }
}

std::string InfoCommand::getDescription()
{
    return " : вывести в стандартный поток вывода информацию о коллекции (тип, дата инициализации, количество элементов и т.д.)";
}
