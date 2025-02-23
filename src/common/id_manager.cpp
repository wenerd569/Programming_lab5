
class IdManager{
    long last_id;

    public:
    IdManager(long last_id) : last_id{last_id} {};
    
    long getNext(){
        return ++last_id;
    }
};