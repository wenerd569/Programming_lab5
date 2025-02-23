#pragma once

#include "structures/person_precursor.h"
#include "forms/person_form.h"
#include "forms/coordinate_form.h"
#include "forms/location_form.h"

PersonForm::PersonForm(IOInterface* ioInterface) : Form{ioInterface} {};
    
PersonPrecursor PersonForm::build() {
    return PersonPrecursor{
        askString("name", "не может быть null или пустой", false).value(),
        CoorditateForm(io).build(),
        askNum<double>("height", "высота должна быть больше 0", false, [](double h) -> bool {return h > 0;}).value(),
        askEnum<Color>("eyeColor", true),
        askEnum<Color>("hairColor", false).value(),
        askEnum<Country>("nationality", false).value(),
        LocationForm(io).buildOptional()
    };
}