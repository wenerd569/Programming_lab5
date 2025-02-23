#include "common/date_manager.h"

std::chrono::year_month_day DateManager::getDate(){
    auto now = std::chrono::system_clock::now();
    auto local_time = std::chrono::zoned_time{std::chrono::current_zone(), now};

    auto days = std::chrono::floor<std::chrono::days>(local_time.get_local_time());
    std::chrono::year_month_day res{days};
    return res;
}