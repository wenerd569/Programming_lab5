
#include "common/interface/person_collection_service.hpp"
#include "frontend/commands/command.hpp"
#include <string>
#include <vector>

/**
 * @brief info : вывести в стандартный поток вывода информацию о коллекции (тип, дата инициализации,
 * количество элементов и т.д.)
 *
 */
class InfoCommand : public Command {
public:
    std::shared_ptr<CollectionService> collectionService;

    InfoCommand(std::shared_ptr<IOInterface> ioInterface,
                std::shared_ptr<CollectionService> collectionService);
    void execute (std::vector<std::string> &args) override;
};