
#include "frontend/commands/command.hpp"
#include <string>
#include <vector>

/**
 * @brief save : сохранить коллекцию в файл
 *
 */
class SaveCommand : public Command {
public:
    SaveCommand(std::shared_ptr<IOInterface> ioInterface,
                std::shared_ptr<CommandManager> comandManager,
                std::shared_ptr<CollectionManager> collectionManager);
    void execute (std::vector<std::string> &args) override;
    std::string getDescription () override;
};