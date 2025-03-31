
#include "frontend/commands/other/exit_command.hpp"
#include "common/exeptions/program_terminate_exeption.hpp"

ExitCommand::ExitCommand(std::shared_ptr<IOInterface> ioInterface)
    : Command(ioInterface, " : завершить программу (без сохранения в файл)") {};

void ExitCommand::execute(std::vector<std::string> &args)
{
    if ( ! getZeroArg(args) ) {
        return;
    }
    throw ProgramTerminateException("Принудительный выход из программы");
}
