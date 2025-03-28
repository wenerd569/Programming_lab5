#pragma once

#include "frontend/interface/reader.hpp"
#include <memory>
#include <string>

class IOInterface {
public:
    virtual ~IOInterface() {};
    virtual void openNewReader (std::unique_ptr<IReader> reader) = 0;
    virtual std::string readline () = 0;
    virtual void write (const std::string &text) = 0;
    virtual void writeError (const std::string &text) = 0;
};