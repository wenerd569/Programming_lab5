#include "frontend/forms/coordinate_form.hpp"
#include <memory>

CoorditateForm::CoorditateForm(std::shared_ptr<IOInterface> ioInterface) : Form{ioInterface, "coordinate"} {};

Coordinate CoorditateForm::build() {
    return Coordinate{
        askNum<double>("x", "Поле не может быть null", false).value(),
        askNum<int>("y", "Поле не может быть null", false).value()
    };
}