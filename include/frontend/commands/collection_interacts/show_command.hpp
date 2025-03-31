
#include "common/interface/person_collection_service.hpp"
#include "frontend/commands/command.hpp"
#include <string>
#include <vector>

/**
 * @brief show : вывести в стандартный поток вывода все элементы коллекции в строковом представлении
 *
 */
class ShowCommand : public Command {
public:
    std::shared_ptr<CollectionService> collectionService;

    ShowCommand(std::shared_ptr<IOInterface> ioInterface,
                std::shared_ptr<CollectionService> collectionService);
    void execute (std::vector<std::string> &args) override;
};