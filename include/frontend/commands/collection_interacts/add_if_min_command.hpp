

#include "common/interface/person_collection_service.hpp"
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
    std::shared_ptr<CollectionService> collectionService;

    AddIfMinCommand(std::shared_ptr<IOInterface> ioInterface,
                    std::shared_ptr<CollectionService> collectionService);
    void execute (std::vector<std::string> &args) override;
};
