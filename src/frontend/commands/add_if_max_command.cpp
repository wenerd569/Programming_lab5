
#include "frontend/commands/add_if_max_command.hpp"
#include "frontend/forms/person_form.hpp"

AddIfMaxCommand::AddIfMaxCommand(std::shared_ptr<IOInterface> ioInterface,
                                 std::shared_ptr<CommandHandler> comandManager,
                                 std::shared_ptr<CollectionService> collectionManager)
    : Command(ioInterface, comandManager, collectionManager) {};

void AddIfMaxCommand::execute(std::vector<std::string> &args)
{
    if ( ! getZeroArg(args) ) {
        return;
    }
    PersonPrecursor prePerson = PersonForm(io).build();
    printStatus(collectionManager->addIfMax(prePerson));
}

std::string AddIfMaxCommand::getDescription()
{
    return " {element} : добавить новый элемент в коллекцию, если его значение превышает значение наибольшего элемента этой коллекции";
}
