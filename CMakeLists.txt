cmake_minimum_required(VERSION 4.1)
project(ListaOrdenada)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(ListaOrdenada
        ListaOrdenada.hpp
        ListaOrdenada.tpp
        main.cpp)
