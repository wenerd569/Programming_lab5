#include <string>
#include <vector>
#include "../common/io_interface.h"
#include "../common/collection_manager.h"
#include "../common/command_manager.h"
#include "../forms/person_form.h"


class Command{
protected:
    IOInterface* io;
    CollectionManager* collection;
    CommandManager* command; 
public:
    Command(CollectionManager* collectionManager, IOInterface* ioInterface) :
    io{ioInterface}, collection{collectionManager} {};
    virtual void execute(std::vector<std::string>& args) = 0;
    virtual std::string getDescription() = 0;
    virtual ~Command() {};
};