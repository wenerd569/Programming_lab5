
#include "frontend/commands/command.hpp"
#include <string>
#include <vector>


class RemoveCommand : public Command {
public:
    RemoveCommand(std::shared_ptr<IOInterface> ioInterface,
                  std::shared_ptr<CommandManager> comandManager,
                  std::shared_ptr<CollectionManager> collectionManager);
    void execute (std::vector<std::string> &args) override;
    std::string getDescription () override;
};