#include "frontend/commands/command.hpp"
#include <string>
#include <vector>

/**
 * @brief show : вывести в стандартный поток вывода все элементы коллекции в строковом представлении
 *
 */
class ShowCommand : public Command {
public:
    ShowCommand(std::shared_ptr<IOInterface> ioInterface,
                std::shared_ptr<CommandHandler> comandManager,
                std::shared_ptr<CollectionService> collectionManager);
    void execute (std::vector<std::string> &args) override;
    std::string getDescription () override;
};