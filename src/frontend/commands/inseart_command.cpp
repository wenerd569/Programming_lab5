
#include "frontend/commands/inseart_command.hpp"
#include <cstddef>
#include <frontend/forms/person_form.hpp>

InseartCommand::InseartCommand(std::shared_ptr<IOInterface> ioInterface,
                               std::shared_ptr<CommandManager> comandManager,
                               std::shared_ptr<CollectionManager> collectionManager)
    : Command(ioInterface, comandManager, collectionManager) {};

void InseartCommand::execute(std::vector<std::string> &args)
{
    size_t index;
    if ( ! getOneNumArg<size_t>(args, index) ) {
        return;
    }
    auto rsp1 = collectionManager->getInfo();
    if ( rsp1.getStatusCode() != Response<CollectionInfo>::OK ) {
        printStatus(std::move(rsp1));
        return;
    }
    size_t collect_size = rsp1.getData().size;

    if ( collect_size < index ) {
        io->writeError("В коллекции меньше элементов, чем придоставленный вами индекс\n");
        return;
    }

    PersonPrecursor prePerson = PersonForm { io }.build();

    printStatus(collectionManager->inseartAt(index, prePerson));
}

std::string InseartCommand::getDescription()
{
    return " index {element} : добавить новый элемент в заданную позицию";
}
