#include "interface/reader.h"
#include "interface/writer.h"

class IOInterface
{
    public:
    virtual std::string readline() = 0;
    virtual void write(const std::string& text);

    virtual ~IOInterface();
};