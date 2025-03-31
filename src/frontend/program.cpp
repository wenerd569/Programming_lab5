
#include "frontend/program.hpp"

#include "backend/colection_manager.hpp"
#include "frontend/commands/commands.hpp"
#include "frontend/console_io.hpp"
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
                               std::shared_ptr<IOInterface> io)
{
    std::unique_ptr<CommandManager> commandManager = std::make_unique<CommandManager>();

    commandManager->addCommand(std::make_unique<HelpCommand>(io, commandManager->getCommands()),
                               "help");
    commandManager->addCommand(std::make_unique<ExecuteScriptCommand>(io), "execute_script");
    commandManager->addCommand(std::make_unique<ExitCommand>(io), "exit");

    commandManager->addCommand(std::make_unique<InfoCommand>(io, collectionManager), "info");
    commandManager->addCommand(std::make_unique<ShowCommand>(io, collectionManager), "show");
    commandManager->addCommand(std::make_unique<AddCommand>(io, collectionManager), "add");
    commandManager->addCommand(std::make_unique<UpdateCommand>(io, collectionManager), "update");
    commandManager->addCommand(std::make_unique<RemoveCommand>(io, collectionManager),
                               "remove_by_id");
    commandManager->addCommand(std::make_unique<ClearCommand>(io, collectionManager), "clear");
    commandManager->addCommand(std::make_unique<SaveCommand>(io, collectionManager), "save");
    commandManager->addCommand(std::make_unique<InseartCommand>(io, collectionManager),
                               "inseart_at");
    commandManager->addCommand(std::make_unique<AddIfMaxCommand>(io, collectionManager),
                               "add_if_max");
    commandManager->addCommand(std::make_unique<AddIfMinCommand>(io, collectionManager),
                               "add_if_min");
    commandManager->addCommand(std::make_unique<GroupCountingByNameCommand>(io, collectionManager),
                               "group_counting_by_name");
    commandManager->addCommand(std::make_unique<FilterLessThanHeightCommand>(io, collectionManager),
                               "filter_less_than_height");
    commandManager->addCommand(
        std::make_unique<PrintFieldAscengroupCountingByNamedingNationalityCommand>(
            io, collectionManager),
        "print_field_ascending_nationality");

    return std::move(commandManager);
}

std::shared_ptr<CollectionService> Program::initialCollectionManager(std::filesystem::path filePath)
{
    CollectionSerializer collectionSerializer = CollectionSerializer { filePath };
    return std::make_shared<CollectionManager>(collectionSerializer);
}

std::shared_ptr<IOInterface> Program::initialIO()
{
    return std::make_shared<IOManager>(std::make_unique<ConsoleReader>(),
                                       std::make_unique<ConsoleWrither>());
}
