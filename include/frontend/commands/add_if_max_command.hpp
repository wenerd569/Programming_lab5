
#include "frontend/commands/command.hpp"
#include <string>
#include <vector>

/**
 * @brief add_if_max {element} : добавить новый элемент в коллекцию, если его значение превышает
 * значение наибольшего элемента этой коллекции
 *
 */
class AddIfMaxCommand : public Command {
public:
    AddIfMaxCommand(std::shared_ptr<IOInterface> ioInterface,
                    std::shared_ptr<CommandManager> comandManager,
                    std::shared_ptr<CollectionManager> collectionManager);
    void execute (std::vector<std::string> &args) override;
    std::string getDescription () override;
};