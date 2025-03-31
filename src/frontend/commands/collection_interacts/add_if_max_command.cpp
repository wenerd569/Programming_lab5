
#include "frontend/commands/collection_interacts/add_if_max_command.hpp"
#include "frontend/forms/person_form.hpp"

AddIfMaxCommand::AddIfMaxCommand(std::shared_ptr<IOInterface> ioInterface,
                                 std::shared_ptr<CollectionService> collectionService)
    : Command(
          ioInterface,
          " {element} : добавить новый элемент в коллекцию, если его значение превышает значение наибольшего элемента этой коллекции"),
      collectionService { collectionService } {};

void AddIfMaxCommand::execute(std::vector<std::string> &args)
{
    if ( ! getZeroArg(args) ) {
        return;
    }
    PersonPrecursor prePerson = PersonForm(io).build();
    printStatus(collectionService->addIfMax(prePerson));
}
