#include "person"
#include "form.h"
#include "coordinate_form.h"
#include "location_form.h"

class PersonForm : public Form<>{
    public:
    PersonForm(IOInterface* ioInterface) :
    Form{ioInterface} {};
    
    Pe build() override {
        return Person{
            idManager->getNext(),
            askString("name", "не может быть null или пустой", false).value(),
            CoorditateForm(io).build(),
            dateManager->getDate(),
            askNum<double>("height", "высота должна быть больше 0", false, [](double h) -> bool {return h > 0;}).value(),
            askEnum<Color>("eyeColor", true),
            askEnum<Color>("hairColor", false).value(),
            askEnum<Country>("nationality", false).value(),
            LocationForm(io).buildOptional()
        };
    }
    std::optional<Person> buildOptional() override{
        while (true)
        {
            io->write("Вы хотите добавить person? (да/нет)\n>>>");
            std::string inp = io->readline();
            if (inp == "да"){
                return build();
            } else if (inp == "нет")
            {
                std::optional<Person> res;
                return res;
            } else {
                io->write("Некорректный формат\n");
            }
        }
    }
};