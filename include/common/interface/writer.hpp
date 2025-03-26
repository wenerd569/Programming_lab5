#pragma once

#include <string>

class IWriter {
public:
    enum WriterType {
        Console,
        File
    };

    virtual void write (const std::string &text) = 0;
    virtual WriterType getType () = 0;
    virtual ~IWriter() {};
};
