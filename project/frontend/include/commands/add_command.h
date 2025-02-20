#include "command.h"

class AddCommand : public Command{

    public:
    void execute(std::vector<std::string>& args) override{
        cm->add(PersonForm(io, cm->getIdManager(), cm->getDateManager()).build());
    }
    
    std::string getDescription() override{
        return "добавить новый элемент в коллекцию";
    }
};