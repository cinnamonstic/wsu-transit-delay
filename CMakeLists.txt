cmake_minimum_required(VERSION 3.12)
project(wsu_transit_delay_notifier CXX)
set(CMAKE_CXX_STANDARD 17)
add_executable(wsu-delay
    src/main.cpp
    src/feed_parser.cpp
    src/delay_analyzer.cpp
)
