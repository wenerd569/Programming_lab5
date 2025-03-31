
#include "frontend/commands/collection_interacts/add_if_min_command.hpp"
#include "frontend/forms/person_form.hpp"

AddIfMinCommand::AddIfMinCommand(std::shared_ptr<IOInterface> ioInterface,
                                 std::shared_ptr<CollectionService> collectionService)
    : Command(
          ioInterface,
          " {element} : добавить новый элемент в коллекцию, если его значение меньше, чем у наименьшего элемента этой коллекции"),
      collectionService { collectionService } {};

void AddIfMinCommand::execute(std::vector<std::string> &args)
{
    if ( ! getZeroArg(args) ) {
        return;
    }
    PersonPrecursor prePerson = PersonForm(io).build();
    printStatus(collectionService->addIfMin(prePerson));
}
