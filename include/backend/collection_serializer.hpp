#pragma once

#include "common/structures/person.hpp"
#include "common/structures/collection_info.hpp"
#include <filesystem>
#include <optional>
#include <vector>

class CollectionSerializer
{
    std::filesystem::path filePath;
    public:

    CollectionSerializer(std::filesystem::path filePath);

    void serialize(std::vector<Person>& collection, CollectionInfo& colectionManager);
    std::pair<std::vector<Person>, std::optional<CollectionInfo>> deserialize();
};