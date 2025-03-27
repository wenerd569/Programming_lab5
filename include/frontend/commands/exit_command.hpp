
#include "frontend/commands/command.hpp"
#include <string>
#include <vector>

/**
 * @brief exit : завершить программу (без сохранения в файл)
 *
 */
class ExitCommand : public Command {
public:
    ExitCommand(std::shared_ptr<IOInterface> ioInterface,
                std::shared_ptr<CommandManager> comandManager,
                std::shared_ptr<CollectionManager> collectionManager);
    void execute (std::vector<std::string> &args) override;
    std::string getDescription () override;
};