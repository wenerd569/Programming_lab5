#include "frontend/commands/command.hpp"
#include <string>
#include <vector>

/**
 * @brief info : вывести в стандартный поток вывода информацию о коллекции (тип, дата инициализации,
 * количество элементов и т.д.)
 *
 */
class InfoCommand : public Command {
public:
    InfoCommand(std::shared_ptr<IOInterface> ioInterface,
                std::shared_ptr<CommandManager> comandManager,
                std::shared_ptr<CollectionManager> collectionManager);
    void execute (std::vector<std::string> &args) override;
    std::string getDescription () override;
};