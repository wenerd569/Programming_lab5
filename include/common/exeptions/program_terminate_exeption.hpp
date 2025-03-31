
#include "string"
#include <exception>
#include <stdexcept>

class ProgramTerminateException : public std::logic_error {
public:
    ProgramTerminateException(std::string message) : std::logic_error { std::move(message) } { }
};