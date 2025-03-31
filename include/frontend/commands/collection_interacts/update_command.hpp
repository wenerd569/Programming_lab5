
#include "common/interface/person_collection_service.hpp"
#include "frontend/commands/command.hpp"
#include <string>
#include <vector>

/**
 * @brief update id {element} : обновить значение элемента коллекции, id которого равен заданному
 *
 */
class UpdateCommand : public Command {
public:
    std::shared_ptr<CollectionService> collectionService;

    UpdateCommand(std::shared_ptr<IOInterface> ioInterface,
                  std::shared_ptr<CollectionService> collectionService);
    void execute (std::vector<std::string> &args) override;
};