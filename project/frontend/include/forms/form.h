#include <magic_enum.hpp>
#include "../common/io_interface.h"


template <typename T>
class Form{
protected:
    IOInterface* io;
public:
    Form(IOInterface* ioInterface){
        io = ioInterface;
    }

    virtual T build() = 0;
    virtual std::optional<T> buildOptional() = 0;
    virtual ~Form();

    std::optional<std::string> askString(std::string fieldName, std::string restriction,
                bool canBeEmpty, std::function<bool(const std::string&)> validate = [](std::string&) -> bool {return true})
    {
        while (true)
        {
            io->write("Введите " + fieldName + " (" + restriction + ')\n>>> ');
            std::string inp = io->readline();
            if (!inp.empty() && validate(inp)){
                return inp;
            } else if (inp.empty() && canBeEmpty){
                return nullptr;
            } else {
                io->write("Некорректный формат\n");
            }   
        }
    }

    template <typename N, typename = std::enable_if_t<std::is_arithmetic_v<N>>>
    std::optional<N> askNum(std::string fieldName, std::string restriction,
                            bool canBeEmpty, std::function<bool(N)> validate = [](N) -> bool {return true})
    {
        while (true)
        {
            io->write("Введите " + fieldName + " (" + restriction + ')\n>>> ');
            std::string inp = io->readline();
            
            N res;
            auto [ptr, ec] = std::from_chars(inp.data(), inp.data() + inp.size(), res);
            
            if (ec != std::errc() && ptr == str.data() + str.size() && validate(res)){
                return res;
            } else if (inp.empty() && canBeEmpty){
                return nullptr;
            } else {
                io->write("Некорректный формат\n");
            }
        }
    }

    template <typename EnumType, typename = std::enable_if_t<std::is_enum<EnumType>::value>>
    std::optional<EnumType> askEnum(std::string fieldName, bool canBeEmpty)
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
                return nullptr;
            } else {
                io->write("Некорректный формат\n");
            }
        }
    }
};
