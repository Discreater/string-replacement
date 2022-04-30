cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
project(signed_digit LANGUAGES CXX)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${TORCH_CXX_FLAGS}")
# Disable C++ extensions
set(CMAKE_CXX_EXTENSIONS OFF)
# Require full C++ standard
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# main.cpp
aux_source_directory(./src SOURCE_DIR)
add_executable(test signed_digit_main.cpp ${SOURCE_DIR})
include_directories(./include)


# link libtorch .a .so
# target_link_libraries(main gmp)
