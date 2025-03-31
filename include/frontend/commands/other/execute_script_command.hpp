
#include "frontend/commands/command.hpp"
#include <string>
#include <vector>

/**
 * @brief execute_script file_name : считать и исполнить скрипт из указанного файла. В скрипте
 * содержатся команды в таком же виде, в котором их вводит пользователь в интерактивном режиме.
 *
 */
class ExecuteScriptCommand : public Command {
public:
    ExecuteScriptCommand(std::shared_ptr<IOInterface> ioInterface);
    void execute (std::vector<std::string> &args) override;
};
