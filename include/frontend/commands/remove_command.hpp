
#include "frontend/commands/command.hpp"
#include <string>
#include <vector>

/**
 * @brief remove_by_id id : удалить элемент из коллекции по его id
 *
 */
class RemoveCommand : public Command {
public:
    RemoveCommand(std::shared_ptr<IOInterface> ioInterface,
                  std::shared_ptr<CommandHandler> comandManager,
                  std::shared_ptr<CollectionService> collectionManager);
    void execute (std::vector<std::string> &args) override;
    std::string getDescription () override;
};