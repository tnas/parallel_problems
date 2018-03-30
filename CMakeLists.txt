cmake_minimum_required(VERSION 2.6)
project(parallel_samples)

add_executable(parallel_samples main.cpp)

install(TARGETS parallel_samples RUNTIME DESTINATION bin)
