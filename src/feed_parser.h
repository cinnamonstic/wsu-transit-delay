#pragma once
#include <string>
#include <vector>

struct Arrival {
    std::string timestamp;      // YYYY-MM-DD HH:MM (optional in sample)
    std::string route_id;
    std::string route_name;
    std::string stop_id;
    std::string stop_name;
    std::string scheduled_time; // HH:MM
    std::string predicted_time; // HH:MM
    std::string status;         // ON_TIME / DELAYED / CANCELED
};

std::vector<Arrival> parse_feed(const std::string& csv_path);
