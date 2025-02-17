#include "person.h"

Person::Person(long id, string name, Coordinates coordinates, year_month_day creationDate, double height, optional<Color> eyeColor, Color hairColor, Country nationality, optional<Location> location){
    
}
Person::Person(string name, Coordinates coordinates, double height, optional<Color> eyeColor, Color hairColor, Country nationality, optional<Location> location){
    id = ++last_id;
    
    auto today = floor<days>(system_clock::now());
    this->creationDate = today;

    this->name = name;
    this->coordinates = coordinates;
    this->height = height;
    this->eyeColor = eyeColor;
    this->hairColor = hairColor;
    this->nationality = nationality;
    this->location = location;
}