

#include "frontend/commands/collection_interacts/filter_less_than_height_command.hpp"

FilterLessThanHeightCommand::FilterLessThanHeightCommand(
    std::shared_ptr<IOInterface> ioInterface, std::shared_ptr<CollectionService> collectionService)
    : Command(ioInterface,
              " height : вывести элементы, значение поля height которых меньше заданного"),
      collectionService { collectionService } {};

void FilterLessThanHeightCommand::execute(std::vector<std::string> &args)
{
    double height;
    if ( ! getOneNumArg<double>(args, height) ) {
        return;
    }
    printPersonVector(collectionService->getHeightLessElement(height));
}