#pragma once

#include <memory>
#include <string>
#include <functional>
#include "interface/io_interface.h"

template <typename T>
class Form{
protected:
    IOInterface* io;
    std::string T_name;
public:
    Form(IOInterface* ioInterface, const char* T_name);

    virtual T build() = 0;
    virtual ~Form() = 0;
    
    std::optional<T> buildOptional();

    std::optional<std::string> askString(std::string fieldName, std::string restriction,
                                        bool canBeEmpty, std::function<bool(const std::string&)> validate =
                                        [](const std::string&) -> bool {return true;});

    template <typename N, std::enable_if_t<std::is_arithmetic_v<N>, int> = 0>
    std::optional<N> askNum(std::string fieldName, std::string restriction,
                                        bool canBeEmpty, std::function<bool(N)> validate = 
                                        [](N) -> bool {return true;});

    template <typename EnumType, typename std::enable_if_t<std::is_enum<EnumType>::value>>
    std::optional<EnumType> askEnum(std::string fieldName, bool canBeEmpty);
};
