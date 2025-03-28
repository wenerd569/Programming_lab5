
#include "frontend/commands/add_command.hpp"
#include "frontend/forms/person_form.hpp"

AddCommand::AddCommand(std::shared_ptr<IOInterface> ioInterface,
                       std::shared_ptr<CommandHandler> comandManager,
                       std::shared_ptr<CollectionService> collectionManager)
    : Command(ioInterface, comandManager, collectionManager) {};

void AddCommand::execute(std::vector<std::string> &args)
{
    if ( ! getZeroArg(args) ) {
        return;
    }
    PersonPrecursor prePerson = PersonForm { io }.build();
    printStatus(collectionManager->add(prePerson));
}

std::string AddCommand::getDescription()
{
    return " {element} : добавить новый элемент в коллекцию";
}
