
class IdManager{
    long lastId;

    public:
    IdManager();
    IdManager(long last_id);
    
    long getNext();
    long getLast();
};