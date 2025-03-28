
#include "frontend/commands/command.hpp"
#include <string>
#include <vector>

/**
 * @brief insert_at index {element} : добавить новый элемент в заданную позицию
 * Перед запросом элемента провяет не выходит ли индекс за границы колекции
 */
class InseartCommand : public Command {
public:
    InseartCommand(std::shared_ptr<IOInterface> ioInterface,
                   std::shared_ptr<CommandHandler> comandManager,
                   std::shared_ptr<CollectionService> collectionManager);
    void execute (std::vector<std::string> &args) override;
    std::string getDescription () override;
};