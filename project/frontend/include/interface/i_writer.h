#include <string>

class IWriter{
    public:
    virtual void write(const std::string& text) = 0;
    virtual void writeline(const std::string& text) = 0;
    virtual ~IWriter() {};
};
