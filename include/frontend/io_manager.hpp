#pragma once

#include "frontend/interface/io_interface.hpp"
#include "frontend/interface/reader.hpp"
#include "frontend/interface/writer.hpp"
#include <memory>
#include <vector>

/**
 * @brief Класс реализующий вывод в консоль/ввод с любого источника
 *
 */
class IOManager : public IOInterface {
protected:
    std::vector<std::unique_ptr<IReader>> readerStack;
    std::unique_ptr<IWriter> writer;

public:
    IOManager(std::unique_ptr<IReader> reader, std::unique_ptr<IWriter> writer);
    ~IOManager();
    /**
     * @brief Добавляет новый reader в readerStack
     *
     * @param reader
     */
    void openNewReader (std::unique_ptr<IReader> reader) override;
    /**
     * @brief Читает строку с последнего открытого reader
     * Сам закрывает закончившиеся reader'ы, пока не сможет получить строку
     * @return std::string
     */
    std::string readline () override;
    /**
     * @brief Пишет данные в writer если последний writer консольный
     * Иначе не делает ничего
     * @param text
     */
    void write (const std::string &text) override;
    /**
     * @brief Пишет данные в writer всегда
     *
     * @param text
     */
    void writeError (const std::string &text) override;
};