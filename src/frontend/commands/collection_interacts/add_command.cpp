
#include "frontend/commands/collection_interacts/add_command.hpp"
#include "frontend/forms/person_form.hpp"

AddCommand::AddCommand(std::shared_ptr<IOInterface> ioInterface,
                       std::shared_ptr<CollectionService> collectionService)
    : Command(ioInterface, " {element} : добавить новый элемент в коллекцию"),
      collectionService { collectionService } {};

void AddCommand::execute(std::vector<std::string> &args)
{
    if ( ! getZeroArg(args) ) {
        return;
    }
    PersonPrecursor prePerson = PersonForm { io }.build();
    printStatus(collectionService->add(prePerson));
}
