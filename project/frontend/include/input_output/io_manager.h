#include "../common/console_io.h"
#include "../common/file_io.h"
#include "../interface/i_reader.h"
#include "../interface/i_writer.h"


class IOInterface
{
protected:
    enum InputMode
    {
        Console,
        File
    };
    InputMode inputMode;
    IReader* reader;
    IWriter* writer;
    
public:
    IOInterface() : reader{new ConsoleReader()}, writer{new ConsoleWrither}, inputMode{Console} {}

    void switchToInputFromeFile(std::string file){
        if (inputMode == Console){
            reader = new FileReader(file);
            inputMode = File;
        } else{
            abort();
        }
    }
    void switchToConsoleInput(){
        if (inputMode == File){
            reader = new ConsoleReader();
            inputMode = Console;
        } else
        {
            abort();
        }
    }
    
    std::string readline(){
        return reader->readline();
    }

    void write(std::string text){
        return writer->write(text);
    }
};