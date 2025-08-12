#include "feed_parser.h"
#include "delay_analyzer.h"
#include <iostream>
#include <string>
#include <vector>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <feed.csv> [--threshold N]\n";
        return 1;
    }
    std::string feedPath = argv[1];
    int threshold = 5;
    for (int i = 2; i + 1 < argc; ++i) {
        if (std::string(argv[i]) == "--threshold") {
            threshold = std::stoi(argv[i+1]);
        }
    }

    std::vector<Arrival> arrivals = parse_feed(feedPath);
    auto delayed = find_delays(arrivals, threshold);

    for (const auto& d : delayed) {
        std::cout << d.route_name << " @ " << d.stop_name
                  << " scheduled " << d.scheduled_time
                  << " predicted " << d.predicted_time
                  << " (" << d.delay_minutes << " min late)\n";
    }
    return 0;
}
