#include "delay_analyzer.h"
#include <cstdlib>

static int to_minutes(const std::string& hhmm) {
    int h = std::atoi(hhmm.substr(0,2).c_str());
    int m = std::atoi(hhmm.substr(3,2).c_str());
    return h*60 + m;
}

std::vector<DelayRecord> find_delays(const std::vector<Arrival>& arr, int threshold) {
    std::vector<DelayRecord> out;
    for (const auto& a : arr) {
        int sched = to_minutes(a.scheduled_time);
        int pred  = to_minutes(a.predicted_time);
        int diff  = pred - sched;
        if ((a.status == "DELAYED" || diff > 0) && diff >= threshold) {
            out.push_back({a.route_name, a.stop_name, a.scheduled_time, a.predicted_time, diff});
        }
    }
    return out;
}
