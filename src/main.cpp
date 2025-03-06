#pragma once

#include "commands/commands.h"
#include "common/command_manager.h"
#include "common/colection_manager.h"

void ititialCommandManager(CommandManager& cm){
    cm.addCommand(HelpCommand(), "help"};
}
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
//print_field_ascending_nationality : вывести значения поля nationality всех элементов в порядке возрастания



int main(){
    CollectionManager collectionManager = CollectionManager();
    collectionManager.load();

}