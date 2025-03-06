#include "common/from_to_json.h"
#include <chrono>
#include <optional>

using json = nlohmann::json;


void to_json(json& j, const Coordinate& p){
    j = json{{"x", p.x}, {"y", p.y}};
}
void from_json(const json& j, Coordinate& p){
    j.at("x").get_to(p.x);
    j.at("y").get_to(p.y);
}


void to_json(json& j, const Location& p){
    j = json{{"x", p.x}, {"y", p.y}, {"z", p.z}};
}
void from_json(const json& j, Location& p){
    j.at("x").get_to(p.x);
    j.at("y").get_to(p.y);
    j.at("z").get_to(p.z);
}


void to_json(json& j, const PersonPrecursor& p){
    j =  json{
        {"name", p.name},
        {"coordinate", p.coordinate},
        {"height", p.height},
        {"eyeColor", p.eyeColor},
        {"hairColor", p.hairColor},
        {"nationality", p.nationality},
        {"location", p.location}
    };
}
void from_json(const json& j, PersonPrecursor& p){
    j.at("name").get_to(p.name);
    from_json(j.at("coordinate"), p.coordinate);
    j.at("height").get_to(p.height);
    if (j.at("eyeColor").is_null()){
        p.eyeColor = std::optional<Color>();
    } else {
        p.eyeColor = j.at("eyeColor").get<Color>();
    }
    
    j.at("hairColor").get_to(p.hairColor);
    j.at("nationality").get_to(p.nationality);
    from_json(j.at("location"), p.location);
}

void to_json(nlohmann::json& j, const std::chrono::year_month_day& p){
    j = json{
        {"year", p.year()},
        {"month", p.month()},
        {"day", p.day()}
    };
}
void from_json(const nlohmann::json& j, std::chrono::year_month_day& p){

}

void to_json(nlohmann::json& j, const Person& p){
    to_json(j, (PersonPrecursor)p);
    j["id"] = p.id;
    j["creationDate"] = p.creationDate.; 
}
void from_json(const nlohmann::json& j, Person& p){

}