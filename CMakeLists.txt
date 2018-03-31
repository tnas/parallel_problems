cmake_minimum_required(VERSION 2.6)
project(parallel_problems)

find_package (Threads)

add_executable(parallel_problems 
	main.c
	samples/sum_vector.c)

target_link_libraries (parallel_problems ${CMAKE_THREAD_LIBS_INIT})
	
install(TARGETS parallel_problems RUNTIME DESTINATION bin)

add_subdirectory(instances)
add_subdirectory(samples)