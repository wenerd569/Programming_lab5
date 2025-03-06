#pragma once

#include <string>
#include <vector>
#include "commands/command.h"


class HelpCommand : public Command{
    public:
    HelpCommand(IOInterface* ioInterface, CommandManager* comandManager, CollectionManager* collectionManager) : Command{ioInterface, comandManager, collectionManager} {};
    void execute(std::vector<std::string>& args) override;
    std::string getDescription() override;
};
class InfoCommand : public Command{
    public:
    HelpCommand(IOInterface* ioInterface, CommandManager* comandManager, CollectionManager* collectionManager) : Command{ioInterface, comandManager, collectionManager} {};
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