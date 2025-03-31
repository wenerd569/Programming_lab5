
#include "common/interface/person_collection_service.hpp"
#include "frontend/commands/command.hpp"
#include <string>
#include <vector>

/**
 * @brief remove_by_id id : удалить элемент из коллекции по его id
 *
 */
class RemoveCommand : public Command {
public:
    std::shared_ptr<CollectionService> collectionService;

    RemoveCommand(std::shared_ptr<IOInterface> ioInterface,
                  std::shared_ptr<CollectionService> collectionService);
    void execute (std::vector<std::string> &args) override;
};