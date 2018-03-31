cmake_minimum_required(VERSION 2.6)
project(parallel_samples)

find_package (Threads)

add_executable(parallel_samples 
	main.c
	samples/sum_vector.c)

target_link_libraries (parallel_samples ${CMAKE_THREAD_LIBS_INIT})
	
install(TARGETS parallel_samples RUNTIME DESTINATION bin)

add_subdirectory(instances)
add_subdirectory(samples)