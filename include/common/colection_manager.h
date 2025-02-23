#include <cmath>
#include <vector>
#include <map>

#include "common/date_manager.h"
#include "common/id_manager.h"
#include "structures/person.h"

class CollectionManager
{
    std::vector<Person> persons;
    IdManager idManager;
    DateManager dateManager;
public:
    CollectionManager();
    ~CollectionManager();

    void save();
    void load();

    void add(PersonPrecursor& prePerson);
    void remove(long id);
    void update(long id, PersonPrecursor& prePerson);
    void clear();
    void inseartAt(size_t index, PersonPrecursor& prePerson);
    void addIfMax(PersonPrecursor& prePerson);
    void addIfMin(PersonPrecursor& prePerson);
    
    std::vector<Person> getAllElement();
    std::vector<Person> GetHeightLessElement(double height);
    std::map<std::string, int> group_counting_by_name();
    
private:
    Person createPerson(PersonPrecursor& prePerson);
};