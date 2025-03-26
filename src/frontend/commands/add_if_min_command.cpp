
#include "frontend/commands/add_if_min_command.hpp"
#include "frontend/forms/person_form.hpp"

AddIfMinCommand::AddIfMinCommand(std::shared_ptr<IOInterface> ioInterface, std::shared_ptr<CommandManager> comandManager, std::shared_ptr<CollectionManager> collectionManager):
Command(ioInterface, comandManager, collectionManager) {};

void AddIfMinCommand::execute(std::vector<std::string>& args){
    if (!getZeroArg(args)) return;
    PersonPrecursor prePerson = PersonForm(io).build();
    printStatus(collectionManager->addIfMin(prePerson));
}
std::string AddIfMinCommand::getDescription(){
    return " {element} : добавить новый элемент в коллекцию, если его значение меньше, чем у наименьшего элемента этой коллекции";
}
