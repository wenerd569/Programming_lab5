#pragma once

#include "frontend/interface/io_interface.hpp"
#include "frontend/interface/reader.hpp"
#include "frontend/interface/writer.hpp"
#include <memory>
#include <vector>

class IOManager : public IOInterface {
protected:
    std::vector<std::unique_ptr<IReader>> readerStack;
    std::unique_ptr<IWriter> writer;

public:
    IOManager(std::unique_ptr<IReader> reader, std::unique_ptr<IWriter> writer);
    ~IOManager();

    void openNewReader (std::unique_ptr<IReader> reader) override;
    std::string readline () override;
    void write (const std::string &text) override;
    void writeError (const std::string &text) override;
};