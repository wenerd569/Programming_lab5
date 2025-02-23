#include "commands/commands.h"
#include "forms/person_form.h"
#include <cstdlib>
#include <vector>

//help : вывести справку по доступным командам
//info : вывести в стандартный поток вывода информацию о коллекции (тип, дата инициализации, количество элементов и т.д.)
//show : вывести в стандартный поток вывода все элементы коллекции в строковом представлении
//add {element} : добавить новый элемент в коллекцию
//update id {element} : обновить значение элемента коллекции, id которого равен заданному
//remove_by_id id : удалить элемент из коллекции по его id
//clear : очистить коллекцию
//save : сохранить коллекцию в файл
//execute_script file_name : считать и исполнить скрипт из указанного файла. В скрипте содержатся команды в таком же виде, в котором их вводит пользователь в интерактивном режиме.
//exit : завершить программу (без сохранения в файл)
//insert_at index {element} : добавить новый элемент в заданную позицию
//add_if_max {element} : добавить новый элемент в коллекцию, если его значение превышает значение наибольшего элемента этой коллекции
//add_if_min {element} : добавить новый элемент в коллекцию, если его значение меньше, чем у наименьшего элемента этой коллекции
//group_counting_by_name : сгруппировать элементы коллекции по значению поля name, вывести количество элементов в каждой группе
//filter_less_than_height height : вывести элементы, значение поля height которых меньше заданного
//print_field_ascengroup_counting_by_nameding_nationality : вывести значения поля nationality всех элементов в порядке возрастания



// res is out param
template <typename N, std::enable_if_t<std::is_arithmetic_v<N>, int> = 0>
bool getSingleNumArg(std::vector<std::string>& args, N &res, IOInterface* io){
    if (args.size() != 1){
        io->write("Данная функция принимает один числовой аргумент");
        return false;
    }
    
    std::string arg = args[0];

    auto [ptr, ec] = std::from_chars(arg.data(), arg.data() + arg.size(), res);
    
    if (ec != std::errc() && ptr == arg.data() + arg.size()){
        return true;
    } else {
        io->write("Данная функция принимает один числовой аргумент");
        return false;
    }
}

bool getZeroArg(std::vector<std::string>& args, IOInterface* io){
    if (args.size() != 0){
        io->write("Данная функция не принимает аргументов");
        return false;
    }
    return true;
}






void HelpCommand::execute(std::vector<std::string>& args){
    if (!getZeroArg(args, io)) return;
    for(auto &element : *commandManager)
    {
        io->write(element.first + element.second->getDescription());
    }
}
std::string HelpCommand::getDescription(){
    return " : вывести справку по доступным командам";
}


void InfoCommand::execute(std::vector<std::string>& args){
    if (!getZeroArg(args, io)) return;
}
std::string InfoCommand::getDescription(){
    return " : вывести в стандартный поток вывода информацию о коллекции (тип, дата инициализации, количество элементов и т.д.)";
}


void ShowCommand::execute(std::vector<std::string>& args){
    if (!getZeroArg(args, io)) return;
    
}
std::string Show::getDescription(){
    return " : вывести в стандартный поток вывода все элементы коллекции в строковом представлении";
}


void AddCommand::execute(std::vector<std::string>& args){
    if (!getZeroArg(args, io)) return;
    collectionManager->add(PersonForm(io).build());
}
std::string AddCommand::getDescription(){
    return " {element} : добавить новый элемент в коллекцию";
}


void UpdateCommand::execute(std::vector<std::string>& args){
    long id;
    if (!getSingleNumArg<long>(args, id, io)) return;


}
std::string UpdateCommand::getDescription(){
    return " id {element} : обновить значение элемента коллекции, id которого равен заданному";
}


void RemoveCommand::execute(std::vector<std::string>& args){
    long id;
    if (!getSingleNumArg<long>(args, id, io)) return;

    collectionManager->remove(id);
}
std::string RemoveCommand::getDescription(){
    return " id : удалить элемент из коллекции по его id";
}


void ClearCommand::execute(std::vector<std::string>& args){
    if (!getZeroArg(args, io)) return;
    collectionManager->clear();
}
std::string ClearCommand::getDescription(){
    return " : очистить коллекцию";
}


void SaveCommand::execute(std::vector<std::string>& args){
    if (!getZeroArg(args, io)) return;
    collectionManager->save();
};
std::string SaveCommand::getDescription(){
    return " : сохранить коллекцию в файл";
};


void ExecuteScriptCommand::execute(std::vector<std::string>& args){

};
std::string ExecuteScriptCommand::getDescription(){
    return " file_name : считать и исполнить скрипт из указанного файла. В скрипте содержатся команды в таком же виде, в котором их вводит пользователь в интерактивном режиме.";
};


void ExitCommand::execute(std::vector<std::string>& args){
    if (!getZeroArg(args, io)) return;
    exit(0);
}
std::string ExitCommand::getDescription(){
    return " : завершить программу (без сохранения в файл)";
}


void InseartCommand::execute(std::vector<std::string>& args){
    unsigned id;
    if (!getSingleNumArg<unsigned>(args, id, io)) return;

}
std::string InseartCommand::getDescription(){
    return " index {element} : добавить новый элемент в заданную позицию";
}


void AddIfMaxCommand::execute(std::vector<std::string>& args){
    
}
std::string AddIfMaxCommand::getDescription(){
    return " {element} : добавить новый элемент в коллекцию, если его значение превышает значение наибольшего элемента этой коллекции";
}

void AddIfMinCommand::execute(std::vector<std::string>& args){

}
std::string AddIfMinCommand::getDescription(){
    return " {element} : добавить новый элемент в коллекцию, если его значение меньше, чем у наименьшего элемента этой коллекции";
}


void GroupCountingByNameCommand::execute(std::vector<std::string>& args){

}
std::string GroupCountingByNameCommand::getDescription(){
    return " : сгруппировать элементы коллекции по значению поля name, вывести количество элементов в каждой группе";
}


void FilterLessThanHeightCommand::execute(std::vector<std::string>& args){

}
std::string FilterLessThanHeightCommand::getDescription(){
    return " height : вывести элементы, значение поля height которых меньше заданного";
}


void PrintFieldAscengroupCountingByNamedingNationalityCommand::execute(std::vector<std::string>& args){

}
std::string PrintFieldAscengroupCountingByNamedingNationalityCommand::getDescription(){
    return " : вывести значения поля nationality всех элементов в порядке возрастания";
}
