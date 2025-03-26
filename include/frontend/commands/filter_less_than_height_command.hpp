
#include <string>
#include <vector>
#include "frontend/commands/command.hpp"

class FilterLessThanHeightCommand : public Command{
    public:
    FilterLessThanHeightCommand(std::shared_ptr<IOInterface> ioInterface, std::shared_ptr<CommandManager> comandManager, std::shared_ptr<CollectionManager> collectionManager);
    void execute(std::vector<std::string>& args) override;
    std::string getDescription() override;
};