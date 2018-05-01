cmake_minimum_required(VERSION 2.6)
project(parallel_problems)

find_package(Threads)
find_package(OpenMP)

if (OPENMP_FOUND)
    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
    set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
endif()

set(COMPILER_FLAGS "-Wall -O3")

add_executable(parallel_problems 
	main.cpp
	pthreads/sum_vector.c
	pthreads/stencil.c
	openmp/Matrix.cpp
	openmp/MatrixMultiplier.cpp)

target_link_libraries (parallel_problems ${CMAKE_THREAD_LIBS_INIT})
	
install(TARGETS parallel_problems RUNTIME DESTINATION bin)

add_subdirectory(openmp)
add_subdirectory(pthreads)