project(pymoca_fmu)

cmake_minimum_required(VERSION 3.5)

list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

set(SUNDIALS_REQUIRED_LIB sundials_ida)
find_package(sundials)

link_directories(${SUNDIALS_LIBRARY_DIR})
include_directories(${SUNDIALS_INCLUDE_DIR})

add_library(model_lib SHARED
	src/gen/f_c.c
	src/gen/f_i.c
	src/gen/f_J.c
	src/gen/f_m.c
	src/gen/f_y.c
	src/gen/f_x_rhs.c
	)

add_executable(model_sim
	src/model_main.cpp)
target_link_libraries(model_sim
	model_lib
	${SUNDIALS_LIBRARIES}
	)
