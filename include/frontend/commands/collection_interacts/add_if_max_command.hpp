

#include "common/interface/person_collection_service.hpp"
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
    std::shared_ptr<CollectionService> collectionService;

    AddIfMaxCommand(std::shared_ptr<IOInterface> ioInterface,
                    std::shared_ptr<CollectionService> collectionService);
    void execute (std::vector<std::string> &args) override;
};