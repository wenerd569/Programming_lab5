#include <chrono>

class IDateManager{
    public:
    virtual std::chrono::year_month_day getDate() = 0;
    virtual ~IDateManager();
};