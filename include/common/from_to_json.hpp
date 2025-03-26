#include "structures/person.hpp"
#include "structures/collection_info.hpp"
#include <chrono>
#include <nlohmann/json.hpp>


void to_json(nlohmann::json& j, const Coordinate& p);
void from_json(const nlohmann::json& j, Coordinate& p);

void to_json(nlohmann::json& j, const Location& p);
void from_json(const nlohmann::json& j, Location& p);

void to_json(nlohmann::json& j, const PersonPrecursor& p);
void from_json(const nlohmann::json& j, PersonPrecursor& p);

void to_json(nlohmann::json& j, const std::chrono::year_month_day& p);
void from_json(const nlohmann::json& j, std::chrono::year_month_day& p);

void to_json(nlohmann::json& j, const Person& p);
void from_json(const nlohmann::json& j, Person& p);

void to_json(nlohmann::json& j, const CollectionInfo& p);
void from_json(const nlohmann::json& j, CollectionInfo& p);


NLOHMANN_JSON_SERIALIZE_ENUM( Country, {
    {UNITED_KINGDOM, "UNITED_KINGDOM"},
    {ITALY, "ITALY"},
    {NORTH_KOREA, "NORTH_KOREA"}
});

NLOHMANN_JSON_SERIALIZE_ENUM( Color, {
    {RED, "RED"},
    {BLUE, "BLUE"},
    {YELLOW, "YELLOW"},
    {WHITE, "WHITE"},
    {GREEN, "GREEN"},
    {BROWN, "BROWN"}
});


namespace nlohmann{
    template <>
    struct adl_serializer<std::chrono::year_month_day> {
        static void to_json(json& j, const std::chrono::year_month_day& ymd);
        static void from_json(const json& j, std::chrono::year_month_day& ymd);
    };
}