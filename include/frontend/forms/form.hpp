#pragma once

#include "common/interface/io_interface.hpp"
#include "common/type_defs.hpp"
#include "magic_enum/magic_enum.hpp"
#include <charconv>
#include <functional>
#include <memory>
#include <optional>
#include <string>
#include <system_error>


template<typename T>
class Form {
protected:
    std::shared_ptr<IOInterface> io;
    std::string T_name;

public:
    Form(std::shared_ptr<IOInterface> ioInterface, const char *T_name);

    virtual T build () = 0;
    virtual ~Form();

    template<typename FT>
    std::optional<FT> askFоrm (std::string fieldName, Form<FT> *form, bool canBeEmpty);

    std::optional<std::string> askString (
        std::string fieldName,
        std::string restriction,
        bool canBeEmpty,
        std::function<bool(const std::string &)> validate = [] (const std::string &) -> bool {
            return true;
        });

    template<NumericType N>
    std::optional<N> askNum (
        std::string fieldName,
        std::string restriction,
        bool canBeEmpty,
        std::function<bool(N)> validate = [] (N) -> bool {
            return true;
        });

    template<EnumType E>
    std::optional<E> askEnum (std::string fieldName, std::string restriction, bool canBeEmpty);
};

template<typename T>
Form<T>::Form(std::shared_ptr<IOInterface> ioInterface, const char *T_name)
    : io { ioInterface }, T_name { T_name } {};

template<typename T>
Form<T>::~Form() {};

template<typename T>
std::optional<std::string> Form<T>::askString(std::string fieldName,
                                              std::string restriction,
                                              bool canBeEmpty,
                                              std::function<bool(const std::string &)> validate)
{
    while ( true ) {
        io->write("Введите " + fieldName + " (" + restriction + ")\n>>> ");
        std::string inp = io->readline();
        if ( ! inp.empty() && validate(inp) ) {
            return inp;
        } else if ( inp.empty() && canBeEmpty ) {
            return std::optional<std::string>();
        } else {
            io->writeError("Некорректный формат\n");
        }
    }
}

template<typename T>
template<NumericType N>
std::optional<N> Form<T>::askNum(std::string fieldName,
                                 std::string restriction,
                                 bool canBeEmpty,
                                 std::function<bool(N)> validate)
{
    while ( true ) {
        io->write("Введите " + fieldName + " (" + restriction + ")\n>>> ");
        std::string inp = io->readline();

        N res;
        auto [ptr, ec] = std::from_chars(inp.data(), inp.data() + inp.size(), res);

        if ( ec == std::errc() && ptr == inp.data() + inp.size() && validate(res) ) {
            return res;
        } else if ( inp.empty() && canBeEmpty ) {
            return std::optional<N>();
        } else {
            io->write("Некорректный формат\n");
        }
    }
}

template<typename T>
template<EnumType E>
std::optional<E> Form<T>::askEnum(std::string fieldName, std::string restriction, bool canBeEmpty)
{
    while ( true ) {
        io->write("Введите " + fieldName + " (" + restriction + ")\nДоступные значения : ( ");
        for ( E i : magic_enum::enum_values<E>() ) {
            io->write((std::string)magic_enum::enum_name(i) + ", ");
        }
        io->write(")\n>>> ");
        std::string inp = io->readline();
        std::optional<E> res = magic_enum::enum_cast<E>(inp);
        if ( res.has_value() ) {
            return res;
        } else if ( inp.empty() && canBeEmpty ) {
            return std::optional<E>();
        } else {
            io->writeError("Некорректный формат\n");
        }
    }
}

template<typename T>
template<typename FT>
std::optional<FT> Form<T>::askFоrm(std::string fieldName, Form<FT> *form, bool canBeEmpty)
{
    if ( canBeEmpty ) {
        while ( true ) {
            io->write("Вы хотите добавить " + fieldName + "? (y/n)\n>>>");
            std::string inp = io->readline();
            if ( inp == "y" ) {
                return form->build();
            } else if ( inp == "n" ) {
                std::optional<FT> res;
                return res;
            } else {
                io->writeError("Некорректный формат\n");
            }
        }
    }
    io->write("Введите " + fieldName + ":\n");
    return form->build();
}