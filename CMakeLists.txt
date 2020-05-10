cmake_minimum_required(VERSION 3.15)
project(protype)

set(CMAKE_CXX_STANDARD 11)

include_directories(LBoost1)
link_directories("/usr/local/lib")

add_executable(protype
        LBoost1/main.cpp)

target_link_libraries(protype
        boost_thread
        boost_system
        pthread)
