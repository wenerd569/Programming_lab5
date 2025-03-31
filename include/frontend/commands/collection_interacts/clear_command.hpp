

#include "common/interface/person_collection_service.hpp"
#include "frontend/commands/command.hpp"
#include <string>
#include <vector>

/**
 * @brief clear : очистить коллекцию
 *
 */
class ClearCommand : public Command {
public:
    std::shared_ptr<CollectionService> collectionService;

    ClearCommand(std::shared_ptr<IOInterface> ioInterface,
                 std::shared_ptr<CollectionService> collectionService);
    void execute (std::vector<std::string> &args) override;
};