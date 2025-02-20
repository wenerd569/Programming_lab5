#include "../structures/location.h"
#include "form.h"


class LocationForm : public Form<Location>{
    public:
    LocationForm(IOInterface* ioInterface) : Form{ioInterface} {};
    
    Location build() override {
        return Location{
            askNum<int>("x", "не может быть null", false).value(),
            askNum<float>("y", "не может быть null", false).value(),
            askNum<long>("x", "не может быть null", false).value()
        };
    }
    std::optional<Location> buildOptional() override{
        while (true)
        {
            io->write("Вы хотите добавить location? (да/нет)\n>>>");
            std::string inp = io->readline();
            if (inp == "да"){
                return build();
            } else if (inp == "нет")
            {
                std::optional<Location> res;
                return res;
            } else {
                io->write("Некорректный формат\n");
            }
        }
    }
};