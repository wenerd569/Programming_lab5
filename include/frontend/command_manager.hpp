#pragma once

#include "frontend/commands/command.hpp"
#include <memory>
#include <string>
#include <unordered_map>

class Command;

/**
 * @brief Класс управляющий обработкой команд
 *
 */
class CommandManager {
protected:
    std::unordered_map<std::string, std::unique_ptr<Command>> commands;

public:
    /**
     * @brief Выполнить команду по её названию
     * @param line через пробел должна содержать команду и её описание
     */
    void execute (std::string &line);
    /**
     * @brief Добавить команду для обработки
     * Используется при инициализации класса
     * @param coomand
     * @param commandName
     */
    void addCommand (std::unique_ptr<Command> coomand, std::string commandName);

    /**
     * @brief Получить список всех команд
     * Используется только командой help
     * @return const std::unordered_map<std::string, std::unique_ptr<Command>>&
     */
    const std::unordered_map<std::string, std::unique_ptr<Command>> &getCommands ();
};
