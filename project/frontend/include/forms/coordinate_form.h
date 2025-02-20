#include "../structures/coordinate.h"
#include "form.h"


class CoorditateForm : public Form<Coordinate>{
    public:
    CoorditateForm(IOInterface* ioInterface) : Form{ioInterface} {};
    
    Coordinate build() override {
        return Coordinate{
            askNum<double>("x", "Поле не может быть null", false).value(),
            askNum<int>("y", "Поле не может быть null", false).value()
        };
    }

    std::optional<Coordinate> buildOptional() override{
        while (true)
        {
            io->write("Вы хотите добавить coordinate? (да/нет)\n>>>");
            std::string inp = io->readline();
            if (inp == "да"){
                return build();
            } else if (inp == "нет")
            {
                std::optional<Coordinate> res;
                return res;
            } else {
                io->write("Некорректный формат\n");
            }
        }
    }
};