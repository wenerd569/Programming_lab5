#include <vector>
#include "sructures/person.h"

class Program final
{
private: \\innerclass


private: \\ field
    std::vector<Person> persons;
    std::string databaseFileName;


private: \\ inner metods

public:
    Program(/* args */);
    ~Program();
    void help();
    void info();
    void show();
    void add();
    void update(long id);
    void remove_by_id(long id);
    void clear();
    void save();
    void execute_script(std::string file_name);
    void exit();
    void insert_at(int index);
    void add_if_max();
    void add_if_min();
    void group_counting_by_name();
    void filter_less_than_height(double height);
    void print_field_ascending_nationality();
};

using namespace {
    optional<Color> readColor(){
        string inp;
        std::cin >> inp;
        if (string)
    }

    Person readPerson(){

    }
}



void Program::help(){
    std::cout << R"(help : вывести справку по доступным командам
info : вывести в стандартный поток вывода информацию о коллекции (тип, дата инициализации, количество элементов и т.д.)
show : вывести в стандартный поток вывода все элементы коллекции в строковом представлении
add {element} : добавить новый элемент в коллекцию
update id {element} : обновить значение элемента коллекции, id которого равен заданному
remove_by_id id : удалить элемент из коллекции по его id
clear : очистить коллекцию
save : сохранить коллекцию в файл
execute_script file_name : считать и исполнить скрипт из указанного файла. В скрипте содержатся команды в таком же виде, в котором их вводит пользователь в интерактивном режиме.
exit : завершить программу (без сохранения в файл)
insert_at index {element} : добавить новый элемент в заданную позицию
add_if_max {element} : добавить новый элемент в коллекцию, если его значение превышает значение наибольшего элемента этой коллекции
add_if_min {element} : добавить новый элемент в коллекцию, если его значение меньше, чем у наименьшего элемента этой коллекции
group_counting_by_name : сгруппировать элементы коллекции по значению поля name, вывести количество элементов в каждой группе
filter_less_than_height height : вывести элементы, значение поля height которых меньше заданного
print_field_ascending_nationality : вывести значения поля nationality всех элементов в порядке возрастания)" << std::endl; 
}

Program::info();

Program::show();

Program::add(){

}

Program::update(long id);

Program::remove_by_id(long id);

Program::clear();

Program::save();

Program::execute_script(string file_name);

Program::exit();

Program::insert_at(int index);

Program::add_if_max();

Program::add_if_min();

Program::group_counting_by_name();

Program::filter_less_than_height(double height);

Program::print_field_ascending_nationality();