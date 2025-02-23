#pragma once

#include "../structures/person_precursor.h"
#include "form.h"

class PersonForm : public Form<PersonPrecursor>{
    public:
    PersonForm(IOInterface* ioInterface);
    
    PersonPrecursor build() override;
};