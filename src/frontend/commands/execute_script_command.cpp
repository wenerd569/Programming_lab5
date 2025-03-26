
#include "frontend/commands/execute_script_command.hpp"
#include "frontend/file_io.hpp"
#include <ios>
#include <memory>

ExecuteScriptCommand::ExecuteScriptCommand(std::shared_ptr<IOInterface> ioInterface,
                                           std::shared_ptr<CommandManager> comandManager,
                                           std::shared_ptr<CollectionManager> collectionManager)
    : Command(ioInterface, comandManager, collectionManager) {};

void ExecuteScriptCommand::execute(std::vector<std::string> &args)
{
    std::string filePath;
    if ( ! getOneStringArg(args, filePath) ) {
        return;
    }
    try {
        io->openNewReader(std::make_unique<FileReader>(filePath));
    } catch ( std::ios_base::failure e ) {
        io->writeError(e.what());
        io->write("\n");
    }
};

std::string ExecuteScriptCommand::getDescription()
{
    return " file_name : считать и исполнить скрипт из указанного файла. В скрипте содержатся команды в таком же виде, в котором их вводит пользователь в интерактивном режиме.";
};
