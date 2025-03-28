
#include "frontend/program.hpp"

#include "frontend/commands/commands.hpp"
#include "frontend/console_io.hpp"
#include "frontend/io_manager.hpp"
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
        io->write("command>>");
        std::string req = io->readline();
        commandManager->execute(req);
    }
}

std::shared_ptr<CommandHandler>
Program::ititialCommandManager(std::shared_ptr<CollectionService> collectionManager,
                               std::shared_ptr<IOInterface> io)
{
    std::shared_ptr<CommandHandler> commandManager = std::make_shared<CommandManager>();

    commandManager->addCommand(std::make_unique<HelpCommand>(io, commandManager, collectionManager),
                               "help");
    commandManager->addCommand(std::make_unique<InfoCommand>(io, commandManager, collectionManager),
                               "info");
    commandManager->addCommand(std::make_unique<ShowCommand>(io, commandManager, collectionManager),
                               "show");
    commandManager->addCommand(std::make_unique<AddCommand>(io, commandManager, collectionManager),
                               "add");
    commandManager->addCommand(std::make_unique<UpdateCommand>(io, commandManager,
                                                               collectionManager),
                               "update");
    commandManager->addCommand(std::make_unique<RemoveCommand>(io, commandManager,
                                                               collectionManager),
                               "remove_by_id");
    commandManager->addCommand(std::make_unique<ClearCommand>(io, commandManager,
                                                              collectionManager),
                               "clear");
    commandManager->addCommand(std::make_unique<SaveCommand>(io, commandManager, collectionManager),
                               "save");
    commandManager->addCommand(std::make_unique<ExecuteScriptCommand>(io, commandManager,
                                                                      collectionManager),
                               "execute_script");
    commandManager->addCommand(std::make_unique<ExitCommand>(io, commandManager, collectionManager),
                               "exit");
    commandManager->addCommand(std::make_unique<InseartCommand>(io, commandManager,
                                                                collectionManager),
                               "inseart_at");
    commandManager->addCommand(std::make_unique<AddIfMaxCommand>(io, commandManager,
                                                                 collectionManager),
                               "add_if_max");
    commandManager->addCommand(std::make_unique<AddIfMinCommand>(io, commandManager,
                                                                 collectionManager),
                               "add_if_min");
    commandManager->addCommand(std::make_unique<GroupCountingByNameCommand>(io, commandManager,
                                                                            collectionManager),
                               "group_counting_by_name");
    commandManager->addCommand(std::make_unique<FilterLessThanHeightCommand>(io, commandManager,
                                                                             collectionManager),
                               "filter_less_than_height");
    commandManager->addCommand(
        std::make_unique<PrintFieldAscengroupCountingByNamedingNationalityCommand>(
            io, commandManager, collectionManager),
        "print_field_ascending_nationality");

    return commandManager;
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
