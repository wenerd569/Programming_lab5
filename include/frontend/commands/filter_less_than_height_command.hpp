
#include "frontend/commands/command.hpp"
#include <string>
#include <vector>

/**
 * @brief filter_less_than_height height : вывести элементы, значение поля height которых меньше
 * заданного
 *
 */
class FilterLessThanHeightCommand : public Command {
public:
    FilterLessThanHeightCommand(std::shared_ptr<IOInterface> ioInterface,
                                std::shared_ptr<CommandHandler> comandManager,
                                std::shared_ptr<CollectionService> collectionManager);
    void execute (std::vector<std::string> &args) override;
    std::string getDescription () override;
};