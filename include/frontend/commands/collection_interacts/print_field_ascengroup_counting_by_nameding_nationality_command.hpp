
#include "common/interface/person_collection_service.hpp"
#include "frontend/commands/command.hpp"
#include <string>
#include <vector>

/**
 * @brief print_field_ascending_nationality : вывести значения поля nationality всех элементов в
 * порядке возрастания Пока не реализованно
 */
class PrintFieldAscengroupCountingByNamedingNationalityCommand : public Command {
public:
    std::shared_ptr<CollectionService> collectionService;

    PrintFieldAscengroupCountingByNamedingNationalityCommand(
        std::shared_ptr<IOInterface> ioInterface,
        std::shared_ptr<CollectionService> collectionService);
    void execute (std::vector<std::string> &args) override;
};