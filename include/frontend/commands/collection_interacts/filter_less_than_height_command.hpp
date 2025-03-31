

#include "common/interface/person_collection_service.hpp"
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
    std::shared_ptr<CollectionService> collectionService;

    FilterLessThanHeightCommand(std::shared_ptr<IOInterface> ioInterface,
                                std::shared_ptr<CollectionService> collectionService);
    void execute (std::vector<std::string> &args) override;
};