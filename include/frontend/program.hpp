
#include "backend/colection_manager.hpp"
#include "frontend/command_manager.hpp"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <filesystem>
#include <memory>
#include <nlohmann/detail/input/input_adapters.hpp>

class Program {

    std::shared_ptr<CommandManager> commandManager;
    std::shared_ptr<CollectionManager> collectionManager;
    std::shared_ptr<IOInterface> io;

    virtual std::shared_ptr<CommandManager>
    ititialCommandManager (std::shared_ptr<CollectionManager> collectionManager,
                           std::shared_ptr<IOInterface> io);
    virtual std::shared_ptr<CollectionManager>
    initialCollectionManager (std::filesystem::path filePath);
    virtual std::shared_ptr<IOInterface> initialIO ();

public:
    Program(std::filesystem::path filePath);
    virtual ~Program() = default;
    virtual void start ();
};
