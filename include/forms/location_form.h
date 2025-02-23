#pragma once

#include "structures/location.h"
#include "form.h"


class LocationForm : public Form<Location>{
    public:
    LocationForm(IOInterface* ioInterface);

    Location build() override;
};