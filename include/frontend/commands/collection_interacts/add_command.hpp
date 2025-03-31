

#include "common/interface/person_collection_service.hpp"
#include "frontend/commands/command.hpp"
#include <string>
#include <vector>

/**
 * @brief add {element} : добавить новый элемент в коллекцию
 *
 */
class AddCommand : public Command {
public:
    std::shared_ptr<CollectionService> collectionService;
    AddCommand(std::shared_ptr<IOInterface> ioInterface,
               std::shared_ptr<CollectionService> collectionService);
    void execute (std::vector<std::string> &args) override;
};