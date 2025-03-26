
#include "frontend/commands/update_command.hpp"
#include "frontend/forms/person_form.hpp"

UpdateCommand::UpdateCommand(std::shared_ptr<IOInterface> ioInterface,
                             std::shared_ptr<CommandManager> comandManager,
                             std::shared_ptr<CollectionManager> collectionManager)
    : Command(ioInterface, comandManager, collectionManager) {};

void UpdateCommand::execute(std::vector<std::string> &args)
{
    long id;
    if ( ! getOneNumArg<long>(args, id) ) {
        return;
    }

    auto rsp1 = collectionManager->checkElement(id);

    if ( rsp1.getStatusCode() != Response<void>::OK ) {
        printStatus(std::move(rsp1));
        return;
    }
    PersonPrecursor prePerson = PersonForm(io).build();
    printStatus(collectionManager->update(id, prePerson));
}

std::string UpdateCommand::getDescription()
{
    return " id {element} : обновить значение элемента коллекции, id которого равен заданному";
}
