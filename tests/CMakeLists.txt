cmake_minimum_required(VERSION 3.28)
project(TestFrs VERSION 1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(FILE_NAME frstest)

add_executable(${FILE_NAME} 
    test_main.cpp)

find_package(GTest REQUIRED)
target_link_libraries(${FILE_NAME} PRIVATE GTest::gtest)
target_link_libraries(${FILE_NAME} PRIVATE lfrs)

include(GoogleTest) # Подключаем "GoogleTest.cmake" для использование команды gtest_discover_tests
gtest_discover_tests(${FILE_NAME}) # Регистрируем тесты в системе CTest