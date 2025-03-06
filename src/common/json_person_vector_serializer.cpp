#include <iostream>
#include <ios>
#include <ostream>

#include "common/json_person_vector_serializer.h"
#include "json_fwd.hpp"


using json = nlohmann::json;
JSONPersonVectorSerializer::JSONPersonVectorSerializer(std::filesystem::path filePath)
{
    this->filePath = filePath;
    file = std::ofstream(filePath, std::ios::app);
    if (!file){
        std::cerr << "Не удаётся открыть файл колекции" << std::endl;
        throw std::ios_base::failure("Не удаётся открыть файл колекции");
    }
}

void JSONPersonVectorSerializer::serialize(std::vector<Person> collection){
    json res = json{"collection", nullptr};
    for (Person p : collection){
        res["collection"] += p;
    }
    if (file.is_open()) file.close();
    file.open(filePath, std::ios::out | std::ios::trunc);

    file << res.dump() << std::endl;
}

std::vector<Person> JSONPersonVectorSerializer::deserialize(){
    if (file.is_open()) file.close();
    file.open(filePath, std::ios::in);
    
    json data = json::parse(file.rdbuf());
    std::vector<Person> res = std::vector<Person>();
    for (json j : data["collection"]){
        Person p;
        from_json(j, p);
        res.push_back(p);
    }
}


