#include "frontend/commands/command.hpp"
#include <string>
#include <vector>

/**
 * @brief add {element} : добавить новый элемент в коллекцию
 *
 */
class AddCommand : public Command {
public:
    AddCommand(std::shared_ptr<IOInterface> ioInterface,
               std::shared_ptr<CommandHandler> comandManager,
               std::shared_ptr<CollectionService> collectionManager);
    void execute (std::vector<std::string> &args) override;
    std::string getDescription () override;
};