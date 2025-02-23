#pragma once

#include "forms/form.h"
#include "external_libs/magic_enum.hpp"

template<typename T>
Form<T>::Form(IOInterface* ioInterface, const char* T_name) :
    io{ioInterface}, T_name{T_name} {};

template<typename T>
std::optional<T> Form<T>::buildOptional() {
        while (true)
        {
            io->write("Вы хотите добавить " + T_name + "? (да/нет)\n>>>");
            std::string inp = io->readline();
            if (inp == "да"){
                return build();
            } else if (inp == "нет")
            {
                std::optional<T> res;
                return res;
            } else {
                io->write("Некорректный формат\n");
            }
        }
}

template<typename T>
std::optional<std::string> Form<T>::askString(std::string fieldName, std::string restriction,
                                    bool canBeEmpty, std::function<bool(const std::string&)> validate)
{
    while (true)
    {
        io->write("Введите " + fieldName + " (" + restriction + ")\n>>> ");
        std::string inp = io->readline();
        if (!inp.empty() && validate(inp)){
            return inp;
        } else if (inp.empty() && canBeEmpty){
            return std::optional<std::string>();
        } else {
            io->write("Некорректный формат\n");
        }   
    }
}
template<typename T>
template <typename N, std::enable_if_t<std::is_arithmetic_v<N>, int>>
std::optional<N> Form<T>::askNum(std::string fieldName, std::string restriction,
                        bool canBeEmpty, std::function<bool(N)> validate)
{
    while (true)
    {
        io->write("Введите " + fieldName + " (" + restriction + ")\n>>> ");
        std::string inp = io->readline();
        
        N res;
        auto [ptr, ec] = std::from_chars(inp.data(), inp.data() + inp.size(), res);
        
        if (ec != std::errc() && ptr == inp.data() + inp.size() && validate(res)){
            return res;
        } else if (inp.empty() && canBeEmpty){
            return std::optional<N>();
        } else {
            io->write("Некорректный формат\n");
        }
    }
}

template<typename T>
template <typename EnumType, typename std::enable_if_t<std::is_enum<EnumType>::value>>
std::optional<EnumType> Form<T>::askEnum(std::string fieldName, bool canBeEmpty)
{
    while (true)
    {
        io->write("Введите " + fieldName + "\nДоступные значения : ( ");
        for (EnumType i : magic_enum::enum_values<EnumType>()) {
            io->write(magic_enum::enum_name(i) + ", ");
        }
        io->write(")\n>>> ");
        std::string inp = io->readline();
        std::optional<EnumType> res = magic_enum::enum_cast<EnumType>(inp);
        if (res.has_value()){
            return res;
        } else if (inp.empty() && canBeEmpty){
            return std::optional<EnumType>();
        } else {
            io->write("Некорректный формат\n");
        }
    }
}
