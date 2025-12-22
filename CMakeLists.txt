cmake_minimum_required(VERSION 3.28)
project(FastRecvSend VERSION 1 LANGUAGES CXX)


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SRC src/main.cpp)
add_executable(frs ${SRC})

add_subdirectory(lib)
target_link_libraries(frs PUBLIC lfrs)