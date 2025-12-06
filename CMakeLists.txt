cmake_minimum_required(VERSION 3.28)
project(FastRecvSend VERSION 1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SRC 
    src/main.cpp
    src/Endpoint.cpp
    src/BindParameter.cpp
    src/BufferSizeParameter.cpp
    src/ParameterParser.cpp)

add_executable(frs ${SRC})

target_include_directories(frs 
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include)