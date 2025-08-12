#include "feed_parser.h"
#include <fstream>
#include <sstream>

std::vector<Arrival> parse_feed(const std::string& csv_path) {
    std::vector<Arrival> out;
    std::ifstream in(csv_path);
    if (!in) return out;

    std::string line;
    bool first = true;
    while (std::getline(in, line)) {
        if (first) { first = false; continue; }
        if (line.empty()) continue;
        std::stringstream ss(line);
        Arrival a;
        std::getline(ss, a.timestamp, ',');
        std::getline(ss, a.route_id, ',');
        std::getline(ss, a.route_name, ',');
        std::getline(ss, a.stop_id, ',');
        std::getline(ss, a.stop_name, ',');
        std::getline(ss, a.scheduled_time, ',');
        std::getline(ss, a.predicted_time, ',');
        std::getline(ss, a.status, ',');
        out.push_back(a);
    }
    return out;
}
