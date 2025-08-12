#pragma once
#include "feed_parser.h"
#include <vector>

struct DelayRecord {
    std::string route_name;
    std::string stop_name;
    std::string scheduled_time;
    std::string predicted_time;
    int delay_minutes;
};

std::vector<DelayRecord> find_delays(const std::vector<Arrival>& arrivals, int threshold_minutes);
