#pragma once

#include "forms/location_form.h"

LocationForm::LocationForm(IOInterface* ioInterface) : Form{ioInterface, "location"} {};


Location LocationForm::build() {
    return Location{
        askNum<int>("x", "не может быть null", false).value(),
        askNum<float>("y", "не может быть null", false).value(),
        askNum<long>("x", "не может быть null", false).value()
    };
}