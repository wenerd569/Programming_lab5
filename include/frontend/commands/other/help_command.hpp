#include "frontend/commands/command.hpp"
#include <frontend/command_manager.hpp>
#include <string>
#include <unordered_map>

/**
 * @brief help : вывести справку по доступным командам
 *
 */
class HelpCommand : public Command {
    const std::unordered_map<std::string, std::unique_ptr<Command>> &commands;

public:
    HelpCommand(std::shared_ptr<IOInterface> ioInterface,
                const std::unordered_map<std::string, std::unique_ptr<Command>> &commands);
    void execute (std::vector<std::string> &args) override;
};