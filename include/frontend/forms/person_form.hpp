#pragma once

#include "common/structures/person_precursor.hpp"
#include "frontend/forms/form.hpp"
#include <memory>

class PersonForm : public Form<PersonPrecursor>{
    public:
    PersonForm(std::shared_ptr<IOInterface> ioInterface);
    
    PersonPrecursor build() override;
};