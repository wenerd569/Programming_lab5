#pragma once

#include "common/interface/io_interface.hpp"
#include "backend/colection_manager.hpp"
#include "frontend/command_manager.hpp"
#include "common/type_defs.hpp"
#include <memory>
#include <system_error>
#include <vector>

class CommandManager;

class Command{
protected:
    std::shared_ptr<IOInterface> io;
    std::shared_ptr<CommandManager> commandManager;
    std::shared_ptr<CollectionManager> collectionManager;
public:
    Command(std::shared_ptr<IOInterface> ioInterface, std::shared_ptr<CommandManager> comandManager, std::shared_ptr<CollectionManager> collectionManager);

    virtual void execute(std::vector<std::string>& args) = 0;
    virtual std::string getDescription() = 0;
    virtual ~Command() = default;
protected:
    template <NumericType N>
    bool getOneNumArg(std::vector<std::string>& args, N &res);
    
    bool getOneStringArg(std::vector<std::string>& args, std::string &res);
    bool getZeroArg(std::vector<std::string>& args);
    
    template<typename T>
    void printStatus(Response<T> response);

    void printPersonVector(Response<std::vector<Person>> response);

    std::string toString(Person person);
    std::string toString(CollectionInfo info);
};



template <NumericType N>
bool Command::getOneNumArg(std::vector<std::string>& args, N &res){    
    if (args.size() != 1){
        io->writeError("Данная функция принимает один числовой аргумент\n");
        return false;
    }
    
    std::string arg = args[0];

    auto [ptr, ec] = std::from_chars(arg.data(), arg.data() + arg.size(), res);
    
    if (ec == std::errc() && ptr == arg.data() + arg.size()){
        return true;
    } else {
        io->writeError("Данная функция принимает один числовой аргумент\n");
        return false;
    }
}

template<typename T>
void Command::printStatus(Response<T> responce){
    switch (responce.getStatusCode()) {
        case Response<T>::OK:
            io->write("Выполнено!\n");
            break;
        case Response<T>::ERROR_ELEMENT_NOT_FOUND:
            io->writeError("Возникла ошибка: элемент не существует\n");
            break;
        case Response<T>::CANT_SAVE_DATA:
            io->writeError("Возникла ошибка: данные не сохранены\n");
            break;
        case Response<T>::INDEX_OUT_OF_RANGE_EXEPTION:
            io->writeError("Индекс вышел за границы коллекции\n");
            break;
        case Response<T>::NULL_RESULT:
            io->writeError("Результат пуст\n");
            break;
        case Response<T>::FAIL:
            io->writeError("Не удалось выполнить операциюn\n");
            break;
    }
}
