
#include "common/interface/person_collection_service.hpp"
#include "frontend/commands/command.hpp"
#include <string>
#include <vector>

/**
 * @brief save : сохранить коллекцию в файл
 *
 */
class SaveCommand : public Command {
public:
    std::shared_ptr<CollectionService> collectionService;

    SaveCommand(std::shared_ptr<IOInterface> ioInterface,
                std::shared_ptr<CollectionService> collectionService);
    void execute (std::vector<std::string> &args) override;
};