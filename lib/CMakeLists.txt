cmake_minimum_required(VERSION 3.28) # Указываем минимальную необходимуб версию CMake.

set(LIB_NAME lfrs) # Создаем пременную LIB_NAME

project(${LIB_NAME} VERSION 1 LANGUAGES CXX) # Задаем настройки проекта.

set(CMAKE_CXX_STANDARD 20) # Задаем версию C++.
set(CMAKE_CXX_STANDARD_REQUIRED ON) # Говорим строго требовать стандарт или выдавать ошибку.

set(LIB_SRC 
    src/Endpoint.cpp
    src/Parameter.cpp
    src/ParameterParser.cpp
    src/SocketRecv.cpp
    src/SocketRecvConf.cpp) # Записываем в переменную все исходники библиотеки.

add_library(${LIB_NAME} STATIC ${LIB_SRC}) # Указываем цель сборки как статическую библиотеку.
target_include_directories(${LIB_NAME} # Указываем путь к заголовочным файлам.
    PUBLIC
    include)