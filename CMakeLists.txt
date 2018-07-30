cmake_minimum_required(VERSION 3.10)
project(CPP_learn)

set(CMAKE_CXX_STANDARD 11)

#add_executable(CPP_learn main.cpp inheritance/employee.h)
add_executable(CPP_learn main.cpp employee.cpp animal.cpp)

target_link_libraries(CPP_learn pthread)

