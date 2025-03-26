#include <cmath>
#include <limits>

#include <backend/colection_manager.hpp>
#include <nlohmann/json_fwd.hpp>
#include <vector>
#include "iostream"

CollectionManager::CollectionManager(CollectionSerializer collectionSerializer) :
collectionSerializer{collectionSerializer} {
    std::optional<CollectionInfo> nullInfo;
    try{
        auto tmp = collectionSerializer.deserialize();
        persons = tmp.first;
        nullInfo = tmp.second;
    } catch (std::ios_base::failure e){
        std::cerr << e.what() << std::endl;
        exit(1);
    };

    if (nullInfo.has_value()){
        dateManager = DateManager{nullInfo->initialDate};
        idManager = IdManager(nullInfo->lastId);
        type = nullInfo->type;
    } else{
        idManager = IdManager{};
        dateManager = DateManager{};
        type = "Person";
    }
};


Person CollectionManager::createPerson(PersonPrecursor& prePerson){
    return Person(prePerson, idManager.getNext(), dateManager.getCurrentDate());    
}

CollectionInfo CollectionManager::configureInfo(){
    return CollectionInfo(type,
        dateManager.getInitialDate(),
        persons.size(),
        idManager.getLast());
}


Response<CollectionInfo> CollectionManager::getInfo(){
    return Response<CollectionInfo>::success(configureInfo());
}

Response<void> CollectionManager::add(PersonPrecursor& prePerson){
    persons.push_back(createPerson(prePerson));
    return Response<void>::success();
}

Response<void> CollectionManager::remove(long id){
    for (size_t i = 0; i < persons.size(); ++i){
        if (persons[i].id == id){
            persons.erase(i + persons.begin());
            return Response<void>::success();
        }
    }
    return Response<void>::failure(Response<void>::ERROR_ELEMENT_NOT_FOUND);
}

Response<void> CollectionManager::update(long id, PersonPrecursor& prePerson){
    for (size_t i = 0; i < persons.size(); ++i){
        if (persons[i].id == id){
            persons[i] = Person(prePerson, id, persons[i].creationDate);
            return Response<void>::success();
        }
    }
    return Response<void>::failure(Response<void>::ERROR_ELEMENT_NOT_FOUND);
}

Response<void> CollectionManager::checkElement(long id){
    for (size_t i = 0; i < persons.size(); ++i){
        if (persons[i].id == id){
            return Response<void>::success();
        }
    }
    return Response<void>::failure(Response<void>::ERROR_ELEMENT_NOT_FOUND);
}


Response<void> CollectionManager::clear(){
    persons.clear();
    return Response<void>::success();
}

Response<void> CollectionManager::save(){
    CollectionInfo info = configureInfo();
    try{
        collectionSerializer.serialize(persons, info);
        return Response<void>::success();
    } catch (std::ios_base::failure e){
        return Response<void>::failure(Response<void>::CANT_SAVE_DATA);
    }
}

Response<void> CollectionManager::inseartAt(size_t index, PersonPrecursor& prePerson){
    if (index > persons.size()){
        return Response<void>::failure(Response<void>::INDEX_OUT_OF_RANGE_EXEPTION);
    }
    persons.insert(index + persons.begin(), createPerson(prePerson));
    return Response<void>::success();
}

Response<void> CollectionManager::addIfMax(PersonPrecursor& prePerson){
    double max = -1;
    for (size_t i = 0; i < persons.size(); ++i){
        max = std::max(persons[i].height, max);
    }

    if (max < prePerson.height){
        add(prePerson);
        return Response<void>::success();
    }
    return Response<void>::failure(Response<void>::FAIL);
}

Response<void> CollectionManager::addIfMin(PersonPrecursor& prePerson){
    double min = std::numeric_limits<double>::max();
    for (size_t i = 0; i < persons.size(); ++i){
        min = std::min(persons[i].height, min);
    }

    if (min > prePerson.height){
        add(prePerson);
        return Response<void>::success();
    }
    return Response<void>::failure(Response<void>::FAIL);
}

Response<std::vector<Person>> CollectionManager::getAllElement(){
    if (persons.empty()) return Response<std::vector<Person>>::failure(Response<std::vector<Person>>::NULL_RESULT);
    return Response<std::vector<Person>>::success(persons);
}

Response<std::vector<Person>> CollectionManager::getHeightLessElement(double height){
    std::vector<Person> res = std::vector<Person>();
    for (size_t i = 0; i < persons.size(); ++i){
        if (persons[i].height < height){
            res.push_back(persons[i]);
        }
    }
    if (res.empty()) return Response<std::vector<Person>>::failure(Response<std::vector<Person>>::NULL_RESULT);
    return  Response<std::vector<Person>>::success(res);
}

Response<std::map<std::string, int>> CollectionManager::groupCountingByName(){
    std::map<std::string, int> res = std::map<std::string, int>();

    for (size_t i = 0; i < persons.size(); ++i){
        if (res.contains(persons[i].name)){
            res[persons[i].name] += 1;
        }
        persons[i].name = 1;
    }
    if (res.empty()) return Response<std::map<std::string, int>>::failure(Response<std::map<std::string, int>>::NULL_RESULT);
    return  Response<std::map<std::string, int>>::success(res);
}