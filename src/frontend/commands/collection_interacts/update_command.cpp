
#include "frontend/commands/collection_interacts/update_command.hpp"
#include "frontend/forms/person_form.hpp"

UpdateCommand::UpdateCommand(std::shared_ptr<IOInterface> ioInterface,
                             std::shared_ptr<CollectionService> collectionService)
    : Command(ioInterface,
              " id {element} : обновить значение элемента коллекции, id которого равен заданному"),
      collectionService { collectionService } {};

void UpdateCommand::execute(std::vector<std::string> &args)
{
    long id;
    if ( ! getOneNumArg<long>(args, id) ) {
        return;
    }

    auto rsp1 = collectionService->checkElement(id);

    if ( rsp1.getStatusCode() != Response<void>::OK ) {
        printStatus(std::move(rsp1));
        return;
    }
    PersonPrecursor prePerson = PersonForm(io).build();
    printStatus(collectionService->update(id, prePerson));
}