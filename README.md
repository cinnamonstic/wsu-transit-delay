# WSU Transit Delay Notifier

A tiny CLI that reads a CSV feed of campus transit arrivals and prints any routes delayed beyond a threshold.

> used by our club to keep tabs on late shuttles around State Hall / UGL.

## Build
With g++:
```bash
g++ -std=cpp17 -O2 src/main.cpp src/feed_parser.cpp src/delay_analyzer.cpp -o wsu-delay
```

With CMake:
```bash
cmake -S . -B build
cmake --build build
```

## Usage

```bash
./wsu-delay data/sample_feed.csv --threshold 7
```

* `--threshold` (minutes, default 5): show delays >= threshold.

## CSV schema (data/sample_feed.csv)

`timestamp, route_id, route_name, stop_id, stop_name, scheduled_time, predicted_time, status`

* times in local 24h, `HH:MM`
* `status` is one of: `ON_TIME`, `DELAYED`, `CANCELED`

## Notes

* See `assets/lakeside.jpg` used for the club poster.
