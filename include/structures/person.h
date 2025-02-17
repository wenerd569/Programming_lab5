#include <string>
#include <chrono>
#include <optional>
#include "coordinate.h"
#include "location.h"
#include "color.h"
#include "country.h"

class Person {
    long id; //>0, uniq, auto
    std::string name; //
    Coordinate coordinate; //
    std::chrono::year_month_day creationDate; //auto
    double height; //>0
    std::optional<Color> eyeColor; //null
    Color hairColor; //
    Country nationality; //
    std::optional<Location> location; //null
    
    public:
    Person(long id, std::string name, Coordinate coordinate, std::chrono::year_month_day creationDate, double height, std::optional<Color> eyeColor, Color hairColor, Country nationality, std::optional<Location> location) :
    id{id}, name{name}, coordinate{coordinate}, creationDate{creationDate}, height{height}, eyeColor{eyeColor}, hairColor{hairColor}, nationality{nationality}, location{location} {}
};
