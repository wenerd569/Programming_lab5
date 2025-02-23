#pragma once

#include "interface/io_interface.h"
#include "common/colection_manager.h"
#include "common/command_manager.h"
#include <string>
#include <vector>

class CommandManager;

class Command{
protected:
    IOInterface* io;
    CommandManager* commandManager;
    CollectionManager* collectionManager;
public:
    Command(IOInterface* ioInterface, CommandManager* comandManager, CollectionManager* collectionManager);
    virtual void execute(std::vector<std::string>& args) = 0;
    virtual std::string getDescription() = 0;
    virtual ~Command() {};  
};

class HelpCommand : public Command{
    public:
    void execute(std::vector<std::string>& args) override;
    std::string getDescription() override;
};
class InfoCommand : public Command{
    public:
    void execute(std::vector<std::string>& args) override;
    std::string getDescription() override;
};
class ShowCommand : public Command{
    public:
    void execute(std::vector<std::string>& args) override;
    std::string getDescription() override;
};
class AddCommand : public Command{
    public:
    void execute(std::vector<std::string>& args) override;
    std::string getDescription() override;
};
class UpdateCommand : public Command{
    public:
    void execute(std::vector<std::string>& args) override;
    std::string getDescription() override;
};
class RemoveCommand : public Command{
    public:
    void execute(std::vector<std::string>& args) override;
    std::string getDescription() override;
};
class ClearCommand : public Command{
    public:
    void execute(std::vector<std::string>& args) override;
    std::string getDescription() override;
};
class SaveCommand : public Command{
    public:
    void execute(std::vector<std::string>& args) override;
    std::string getDescription() override;
};
class ExecuteScriptCommand : public Command{
    public:
    void execute(std::vector<std::string>& args) override;
    std::string getDescription() override;
};
class ExitCommand : public Command{
    public:
    void execute(std::vector<std::string>& args) override;
    std::string getDescription() override;
};
class InseartCommand : public Command{
    public:
    void execute(std::vector<std::string>& args) override;
    std::string getDescription() override;
};
class AddIfMaxCommand : public Command{
    public:
    void execute(std::vector<std::string>& args) override;
    std::string getDescription() override;
};
class AddIfMinCommand : public Command{
    public:
    void execute(std::vector<std::string>& args) override;
    std::string getDescription() override;
};
class GroupCountingByNameCommand : public Command{
    public:
    void execute(std::vector<std::string>& args) override;
    std::string getDescription() override;
};
class FilterLessThanHeightCommand : public Command{
    public:
    void execute(std::vector<std::string>& args) override;
    std::string getDescription() override;
};
class PrintFieldAscengroupCountingByNamedingNationalityCommand : public Command{
    public:
    void execute(std::vector<std::string>& args) override;
    std::string getDescription() override;
};