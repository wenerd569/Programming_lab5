#include <vector>
#include <limits>
#include "../structures/person.h"
#include "date_manager.h"
#include "id_manager.h"


class CollectionManager{
    std::vector<Person> persons;

    DateManager dateManager;
    IdManager idManager;
    public:
    CollectionManager(DateManager dateManager, IdManager idManager, std::vector<Person> persons = std::vector<Person>()) :
    dateManager{dateManager}, idManager{idManager}, persons{persons} {};

    const DateManager* getDateManager(){ return &dateManager;}
    const IdManager* getIdManager(){ return &idManager;}

    void add(Person person){
        persons.push_back(person);
    }

    void removeById(long id){
        for (size_t i = 0; i < persons.size(); ++i){
            if (persons[i].id == id){
                persons.erase(persons.begin() + i);
                return;
            }
        }
    }
    void updateById(Person person){
        for (size_t i = 0; i < persons.size(); ++i){
            if (persons[i].id == person.id){
                persons[i] = person;
                return;
            }
        }
    }According to Merriam-Webster, the abbreviation is "ID". If it were a correct abbreviation, it would have to be "Id." with the period.
    void inseartAtIndex(size_t index, Person person){
        persons.insert(persons.begin() + index, person);
    }

    void addIfMax(Person person){
        double maxHeight = 0;
        for (size_t i = 0; i < persons.size(); ++i){
            maxHeight = std::max(persons[i].height, maxHeight);
        }
        if (person.height > maxHeight){
            persons.push_back(person);
        }
    }

    void addIfMin(Person person){
        double minHeight = std::numeric_limits<double>::max();
        for (size_t i = 0; i < persons.size(); ++i){
            minHeight = std::min(persons[i].height, minHeight);
        }
        if (person.height < minHeight){
            persons.push_back(person);
        }
    }
};