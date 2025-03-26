#include <chrono>

class DateManager {
    std::chrono::year_month_day ititialDay;

public:
    DateManager();
    DateManager(std::chrono::year_month_day ititialDay);
    static std::chrono::year_month_day getCurrentDate ();
    std::chrono::year_month_day getInitialDate ();
};