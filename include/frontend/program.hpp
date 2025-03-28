
#include "backend/colection_manager.hpp"
#include "common/interface/person_collection_service.hpp"
#include "frontend/command_manager.hpp"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <filesystem>
#include <memory>
#include <nlohmann/detail/input/input_adapters.hpp>

/**
 * @brief Класс программы
 */
class Program {
    std::shared_ptr<CommandHandler> commandManager;
    std::shared_ptr<CollectionService> collectionManager;
    std::shared_ptr<IOInterface> io;

    /**
     * @brief Инициализирует менеджер команд
     * Добавляет в него все команды из задания
     * принимаемые значения специально чтобы соблюдать порядок инициализации
     * @param collectionManager
     * @param io
     * @return std::shared_ptr<CommandManager>
     */
    virtual std::shared_ptr<CommandHandler>
    ititialCommandManager (std::shared_ptr<CollectionService> collectionManager,
                           std::shared_ptr<IOInterface> io);
    /**
     * @brief Инициализирует CollectionManager
     *
     * @param filePath
     * @return std::shared_ptr<CollectionManager>
     */
    virtual std::shared_ptr<CollectionService>
    initialCollectionManager (std::filesystem::path filePath);
    /**
     * @brief Инициализирует IOManager
     *
     * @return std::shared_ptr<IOInterface>
     */
    virtual std::shared_ptr<IOInterface> initialIO ();

public:
    /**
     * @brief Конструктор программы вызывает инициализаторы всех полей класса
     * @param filePath
     */
    Program(std::filesystem::path filePath);
    virtual ~Program() = default;
    /**
     * @brief Начинает бесконечный цикл обработки команд
     *
     */
    virtual void start ();
};
