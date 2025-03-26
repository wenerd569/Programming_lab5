#include "frontend/forms/location_form.hpp"
#include <memory>

LocationForm::LocationForm(std::shared_ptr<IOInterface> ioInterface) : Form{ioInterface, "location"} {};

Location LocationForm::build() {
    return Location{
        askNum<int>("x", "не может быть null", false).value(),
        askNum<float>("y", "не может быть null", false).value(),
        askNum<long>("x", "не может быть null", false).value()
    };
}