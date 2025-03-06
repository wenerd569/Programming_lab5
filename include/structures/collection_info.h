#include <chrono>


struct CollectionInfo
{
    std::string type;
    std::chrono::year_month_day initialDate;
    size_t size;
    long lastId;
};

