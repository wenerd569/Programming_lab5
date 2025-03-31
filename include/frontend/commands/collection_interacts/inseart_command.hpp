
#include "common/interface/person_collection_service.hpp"
#include "frontend/commands/command.hpp"
#include <string>
#include <vector>

/**
 * @brief insert_at index {element} : добавить новый элемент в заданную позицию
 * Перед запросом элемента провяет не выходит ли индекс за границы колекции
 */
class InseartCommand : public Command {
public:
    std::shared_ptr<CollectionService> collectionService;

    InseartCommand(std::shared_ptr<IOInterface> ioInterface,
                   std::shared_ptr<CollectionService> collectionService);
    void execute (std::vector<std::string> &args) override;
};