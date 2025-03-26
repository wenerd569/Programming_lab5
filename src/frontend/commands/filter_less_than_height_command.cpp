

#include "frontend/commands/filter_less_than_height_command.hpp"

FilterLessThanHeightCommand::FilterLessThanHeightCommand(std::shared_ptr<IOInterface> ioInterface, std::shared_ptr<CommandManager> comandManager, std::shared_ptr<CollectionManager> collectionManager):
    Command(ioInterface, comandManager, collectionManager) {};

void FilterLessThanHeightCommand::execute(std::vector<std::string>& args){
    double height;
    if(!getOneNumArg<double>(args, height)) return;
    printPersonVector(collectionManager->getHeightLessElement(height));
}
std::string FilterLessThanHeightCommand::getDescription(){
    return " height : вывести элементы, значение поля height которых меньше заданного";
}
