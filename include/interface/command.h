#include <../common/io_interface.h>
#include <../common/command_manager.h>
#include <string>
#include <vector>


class ICommand{
    public:
    virtual void execute(std::vector<std::string>& args) = 0;
    virtual std::string getDescription() = 0;
    virtual ~ICommand() {};  
};