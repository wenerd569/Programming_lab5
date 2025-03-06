#include <cstdio>
#include <vector>
#include "interface/serializer.h"
#include "structures/person.h"
#include <fstream>
#include <filesystem>

class JSONPersonVectorSerializer : public ISerializer<std::vector<Person>>
{
    std::filesystem::path filePath;
    std::ofstream file;
public:
    JSONPersonVectorSerializer(std::filesystem::path fillePath);
    
    void serialize(std::vector<Person> collection) override;
    std::vector<Person> deserialize() override;
};