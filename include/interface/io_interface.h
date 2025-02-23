#include "interface/reader.h"
#include "interface/writer.h"

class IOInterface : IReader, IWriter
{
    public:
    virtual std::string readline() override = 0;
    virtual void write(const std::string& text) override;

    virtual ~IOInterface();
};