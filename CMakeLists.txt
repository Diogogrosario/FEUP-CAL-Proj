cmake_minimum_required(VERSION 3.15)
project(FichaJUNG)

set(CMAKE_CXX_STANDARD 14)
# The line below is necessary if you are under Windows only
# Comment the line below if you are under Linux or Mac OS
# link_libraries(ws2_32 wsock32)

include_directories(lib)
include_directories(resources)
add_executable(Project main.cpp lib/connection.cpp lib/graphviewer.cpp readFile.cpp readFile.h Node.cpp Node.h Client.cpp Client.h Time.cpp Time.h Algorithms.cpp Algorithms.h Vehicle.cpp Vehicle.h Utils.cpp Utils.h)
