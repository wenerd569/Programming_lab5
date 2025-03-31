
#include "frontend/commands/other/help_command.hpp"

HelpCommand::HelpCommand(std::shared_ptr<IOInterface> ioInterface,
                         const std::unordered_map<std::string, std::unique_ptr<Command>> &commands)
    : Command(ioInterface, " : вывести справку по доступным командам"), commands { commands } {};

void HelpCommand::execute(std::vector<std::string> &args)
{
    if ( ! getZeroArg(args) ) {
        return;
    }
    for ( auto &element : commands ) {
        io->write(element.first + element.second->getDescription() + '\n');
    }
}