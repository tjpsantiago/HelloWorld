cmake_minimum_required(VERSION 2.6)
project(JenkinsTrial C CXX)

add_executable(JenkinsTrial src/main.cpp)

target_include_directories(JenkinsTrial
    PRIVATE
        hdr
        hdr/logger
)