#include "frontend/io_manager.hpp"
#include "common/exeptions/program_terminate_exeption.hpp"
#include <cstdlib>
#include <memory>
#include <vector>

IOManager::IOManager(std::unique_ptr<IReader> reader, std::unique_ptr<IWriter> writer)
    : readerStack {}, writer { std::move(writer) }
{
    readerStack.push_back(std::move(reader));
}

IOManager::~IOManager() {};

std::string IOManager::readline()
{
    std::string res;
    res = readerStack.back()->readline();
    while ( readerStack.back()->isEndOfReader() ) {
        readerStack.pop_back();
        if ( res == "" ) {
            if ( readerStack.empty() ) {
                throw ProgramTerminateException("Принудительное завершение програмы");
            }
            res = readerStack.back()->readline();
        }
    }
    return res;
}

void IOManager::write(const std::string &text)
{
    if ( readerStack.back()->getType() == IReader::File ) {
        return;
    }
    return writer->write(text);
}

void IOManager::writeError(const std::string &text)
{
    return writer->write(text);
}

void IOManager::openNewReader(std::unique_ptr<IReader> reader)
{
    readerStack.push_back(std::move(reader));
}