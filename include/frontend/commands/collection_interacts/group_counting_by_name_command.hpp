
#include "common/interface/person_collection_service.hpp"
#include "frontend/commands/command.hpp"
#include <string>
#include <vector>

/**
 * @brief group_counting_by_name : сгруппировать элементы коллекции по значению поля name, вывести
 * количество элементов в каждой группе
 *
 */
class GroupCountingByNameCommand : public Command {
public:
    std::shared_ptr<CollectionService> collectionService;

    GroupCountingByNameCommand(std::shared_ptr<IOInterface> ioInterface,
                               std::shared_ptr<CollectionService> collectionService);
    void execute (std::vector<std::string> &args) override;
};