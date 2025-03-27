
#include "frontend/commands/command.hpp"
#include <string>
#include <vector>

/**
 * @brief add_if_min {element} : добавить новый элемент в коллекцию, если его значение меньше, чем у
 * наименьшего элемента этой коллекции
 *
 */
class AddIfMinCommand : public Command {
public:
    AddIfMinCommand(std::shared_ptr<IOInterface> ioInterface,
                    std::shared_ptr<CommandManager> comandManager,
                    std::shared_ptr<CollectionManager> collectionManager);
    void execute (std::vector<std::string> &args) override;
    std::string getDescription () override;
};
