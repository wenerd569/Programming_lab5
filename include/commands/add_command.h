#include <../interface/command.h>

class AddCommand : public Icommand{
    public:
    execute(std::vector<std::string>& args) override{
        
    }
    
    std::string getDescription() override{
        return "добавить новый элемент в коллекцию";
    }
};