
template <typename T>
class ISerializer
{
public:
    virtual void serialize(T obj);
    virtual T deserialize();
    virtual ~ISerializer();
};