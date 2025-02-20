#include "command.h"

class AddCommand : public Command{

    public:
    void execute(std::vector<std::string>& args) override{
        command->
    }
    
    std::string getDescription() override{
        return "добавить новый элемент в коллекцию";
    }
};
