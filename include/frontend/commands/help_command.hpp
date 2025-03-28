#include "frontend/commands/command.hpp"
#include <string>
#include <vector>

/**
 * @brief help : вывести справку по доступным командам
 *
 */
class HelpCommand : public Command {
public:
    HelpCommand(std::shared_ptr<IOInterface> ioInterface,
                std::shared_ptr<CommandHandler> comandManager,
                std::shared_ptr<CollectionService> collectionManager);
    void execute (std::vector<std::string> &args) override;
    std::string getDescription () override;
};