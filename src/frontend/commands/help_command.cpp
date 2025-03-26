
#include "frontend/commands/help_command.hpp"

HelpCommand::HelpCommand(std::shared_ptr<IOInterface> ioInterface,
                         std::shared_ptr<CommandManager> comandManager,
                         std::shared_ptr<CollectionManager> collectionManager)
    : Command(ioInterface, comandManager, collectionManager) {};

void HelpCommand::execute(std::vector<std::string> &args)
{
    if ( ! getZeroArg(args) ) {
        return;
    }
    for ( auto &element : commandManager->getCommands() ) {
        io->write(element.first + element.second->getDescription() + '\n');
    }
}

std::string HelpCommand::getDescription()
{
    return " : вывести справку по доступным командам";
}
