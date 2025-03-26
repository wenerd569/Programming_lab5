#pragma once

#include <cmath>
#include <map>
#include <vector>

#include "backend/collection_serializer.hpp"
#include "backend/date_manager.hpp"
#include "backend/id_manager.hpp"
#include "common/response.hpp"
#include "common/structures/collection_info.hpp"
#include "common/structures/person.hpp"

class CollectionManager {
    std::vector<Person> persons;
    IdManager idManager;
    DateManager dateManager;
    CollectionSerializer collectionSerializer;

    std::string type;

public:
    CollectionManager(CollectionSerializer collectionSerializer);

    Response<void> save ();

    Response<CollectionInfo> getInfo ();

    Response<void> add (PersonPrecursor &prePerson);
    Response<void> remove (long id);
    Response<void> update (long id, PersonPrecursor &prePerson);
    Response<void> clear ();
    Response<void> inseartAt (size_t index, PersonPrecursor &prePerson);
    Response<void> addIfMax (PersonPrecursor &prePerson);
    Response<void> addIfMin (PersonPrecursor &prePerson);

    Response<void> checkElement (long id);

    Response<std::vector<Person>> getAllElement ();
    Response<std::vector<Person>> getHeightLessElement (double height);
    Response<std::map<std::string, int>> groupCountingByName ();

private:
    Person createPerson (PersonPrecursor &prePerson);
    CollectionInfo configureInfo ();
};