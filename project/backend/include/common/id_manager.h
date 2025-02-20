#include "../interface/i_id_manager.h"

class IdManager : public IIdManager{
    long last_id;

    public:
    IdManager(long last_id) : last_id{last_id} {};
    
    long getId() override{
        return ++last_id;
    }
};