#pragma once

#include <string>

class IReader {
public:
    enum ReaderType {
        Console,
        File
    };

    virtual std::string readline () = 0;
    virtual bool isEndOfReader () = 0;
    virtual ReaderType getType () = 0;
    virtual ~IReader() {};
};