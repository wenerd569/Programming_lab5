
#include "frontend/commands/command.hpp"
#include <string>
#include <vector>

/**
 * @brief update id {element} : обновить значение элемента коллекции, id которого равен заданному
 *
 */
class UpdateCommand : public Command {
public:
    UpdateCommand(std::shared_ptr<IOInterface> ioInterface,
                  std::shared_ptr<CommandHandler> comandManager,
                  std::shared_ptr<CollectionService> collectionManager);
    void execute (std::vector<std::string> &args) override;
    std::string getDescription () override;
};