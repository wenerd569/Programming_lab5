
#include "frontend/program.hpp"

#include "backend/colection_manager.hpp"
#include "frontend/commands/commands.hpp"
#include "frontend/io_manager.hpp"
#include <memory>
#include <string>

Program::Program(std::filesystem::path filePath)
{
    collectionManager = initialCollectionManager(filePath);
    io = initialIO();
    commandManager = ititialCommandManager(collectionManager, io);
}

void Program::start()
{
    while ( true ) {
        io->write("\ncommand>> ");
        std::string req = io->readline();
        if ( ! commandManager->execute(req) ) {
            io->write("Неизвестная команда\n");
        }
    }
}

std::unique_ptr<CommandManager>
Program::ititialCommandManager(std::shared_ptr<CollectionService> collectionManager,
                               std::shared_ptr<IOManager> io)
{
    std::unique_ptr<CommandManager> commandManager = std::make_unique<CommandManager>();

    commandManager->addCommand(std::move(HelpCommand::make(io, commandManager->getCommands())),
                               "help");
    commandManager->addCommand(std::move(ExecuteScriptCommand::make(io)), "execute_script");
    commandManager->addCommand(std::move(ExitCommand::make(io)), "exit");

    commandManager->addCommand(std::move(InfoCommand::make(io, collectionManager)), "info");
    commandManager->addCommand(std::move(ShowCommand::make(io, collectionManager)), "show");
    commandManager->addCommand(std::move(AddCommand::make(io, collectionManager)), "add");
    commandManager->addCommand(std::move(UpdateCommand::make(io, collectionManager)), "update");
    commandManager->addCommand(std::move(RemoveCommand::make(io, collectionManager)),
                               "remove_by_id");
    commandManager->addCommand(std::move(ClearCommand::make(io, collectionManager)), "clear");
    commandManager->addCommand(std::move(SaveCommand::make(io, collectionManager)), "save");
    commandManager->addCommand(std::move(InseartCommand::make(io, collectionManager)),
                               "inseart_at");
    commandManager->addCommand(std::move(AddIfMaxCommand::make(io, collectionManager)),
                               "add_if_max");
    commandManager->addCommand(std::move(AddIfMinCommand::make(io, collectionManager)),
                               "add_if_min");
    commandManager->addCommand(std::move(GroupCountingByNameCommand::make(io, collectionManager)),
                               "group_counting_by_name");
    commandManager->addCommand(std::move(FilterLessThanHeightCommand::make(io, collectionManager)),
                               "filter_less_than_height");
    commandManager->addCommand(
        std::move(
            PrintFieldAscengroupCountingByNamedingNationalityCommand::make(io, collectionManager)),
        "print_field_ascending_nationality");

    return std::move(commandManager);
}

std::shared_ptr<CollectionService> Program::initialCollectionManager(std::filesystem::path filePath)
{
    CollectionSerializer collectionSerializer = CollectionSerializer { filePath };
    return std::make_shared<CollectionManager>(collectionSerializer);
}

std::shared_ptr<IOManager> Program::initialIO()
{
    return std::make_shared<IOManager>(Reader::makeConsoleReader(), Writer::makeCinsoleWriter());
}
