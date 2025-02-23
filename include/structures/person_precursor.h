#include <string>
#include <optional>
#include "coordinate.h"
#include "location.h"
#include "color.h"
#include "country.h"

struct PersonPrecursor {
    std::string name; //
    Coordinate coordinate; //
    double height; //>0
    std::optional<Color> eyeColor; //null
    Color hairColor; //
    Country nationality; //
    std::optional<Location> location; //null
    
    PersonPrecursor(std::string name, Coordinate coordinate, double height, std::optional<Color> eyeColor, Color hairColor, Country nationality, std::optional<Location> location) :
    name{name}, coordinate{coordinate}, height{height}, eyeColor{eyeColor}, hairColor{hairColor}, nationality{nationality}, location{location} {}
};
