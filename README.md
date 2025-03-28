# Programming-lab5

The program uses a collection file that contains data in json format. Therefore, when you start, you must pass it the path to this collection.
After start program it can executes the user's commands

write help to get command list

## Compile and running
1. install Cmake
https://cgold.readthedocs.io/en/latest/first-step/installation.html
2. install conan (Package manager)
https://docs.conan.io/2/installation.html
3. Don't forget to add conan to the Path on windows!!
4. Use command to compile Project
``` 
conan install . --output-folder=build --build=missing -s build_type=Release
cmake --preset conan-release
ln -s build/build/Release/compile_commands.json .
cmake --build --preset conan-release
```
5. Run program
Program located in build/build/Release/ProgLab5 or ProgLab5.exe
```
<program_name> <collection_file_name.json>
```
