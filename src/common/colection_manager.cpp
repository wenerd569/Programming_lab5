#include <cmath>
#include <limits>

#include <common/colection_manager.h>

Person CollectionManager::createPerson(PersonPrecursor& prePerson){
    return Person(prePerson, idManager.getNext(), dateManager.getDate());    
}




void CollectionManager::add(PersonPrecursor& prePerson){
    persons.push_back(createPerson(prePerson));
}

void CollectionManager::remove(long id){
    for (size_t i = 0; i < persons.size(); ++i){
        if (persons[i].id == id){
            persons.erase(i + persons.begin());
            return;
        }
    }
}

void CollectionManager::update(long id, PersonPrecursor& prePerson){
    for (size_t i = 0; i < persons.size(); ++i){
        if (persons[i].id == id){
            persons[i] = Person(prePerson, id, persons[i].creationDate);
            return;
        }
    }
}
void CollectionManager::clear(){
    persons.clear();
}
void CollectionManager::save(){

}

void CollectionManager::inseartAt(size_t index, PersonPrecursor& prePerson){
    persons.insert(index + persons.begin(), createPerson(prePerson));
}

void CollectionManager::addIfMax(PersonPrecursor& prePerson){
    double max = -1;
    for (size_t i = 0; i < persons.size(); ++i){
        max = std::max(persons[i].height, max);
    }

    if (max < prePerson.height){
        add(prePerson);
    }
}

void CollectionManager::addIfMin(PersonPrecursor& prePerson){
    double min = std::numeric_limits<double>::max();
    for (size_t i = 0; i < persons.size(); ++i){
        min = std::min(persons[i].height, min);
    }

    if (min > prePerson.height){
        add(prePerson);
    }
}

std::vector<Person> CollectionManager::getAllElement(){
    return persons;
}

std::vector<Person> CollectionManager::GetHeightLessElement(double height){
    std::vector<Person> res = std::vector<Person>();
    for (size_t i = 0; i < persons.size(); ++i){
        if (persons[i].height < height){
            res.push_back(persons[i]);
        }
    }
    return res;
}

std::map<std::string, int> CollectionManager::group_counting_by_name(){
    std::map<std::string, int> res = std::map<std::string, int>();

    for (size_t i = 0; i < persons.size(); ++i){
        if (res.contains(persons[i].name)){
            res[persons[i].name] += 1;
        }
        persons[i].name = 1;
    }

    return res;
}


