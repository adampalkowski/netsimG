cmake_minimum_required(VERSION 3.21)
project(netsim)

set(CMAKE_CXX_STANDARD 17)
include_directories(include)
add_compile_options(-Wall -Wextra -Werror -Wpedantic -pedantic-errors -Wconversion)
set(SOURCE_FILES
        src/factory.cpp
        src/helpers.cpp
        src/nodes.cpp
        src/package.cpp
        src/reports.cpp
        src/simulation.cpp
        src/storage_types.cpp
        src/types.cpp
        include/factory.hpp
        include/helpers.hpp
        include/nodes.hpp
        include/package.hpp
        include/reports.hpp
        include/simulation.hpp
        include/storage_types.hpp
        include/types.hpp

        )
add_executable(netsim ${SOURCE_FILES}  main.cpp)
