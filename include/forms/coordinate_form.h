#pragma once

#include "../structures/coordinate.h"`
#include "form.h"


class CoorditateForm : public Form<Coordinate>{
    public:
    CoorditateForm(IOInterface* ioInterface);
    
    Coordinate build() override;
};