#pragma once

#include "forms/coordinate_form.h"

CoorditateForm::CoorditateForm(IOInterface* ioInterface) : Form{ioInterface, "coordinate"} {};

Coordinate CoorditateForm::build() {
    return Coordinate{
        askNum<double>("x", "Поле не может быть null", false).value(),
        askNum<int>("y", "Поле не может быть null", false).value()
    };
}