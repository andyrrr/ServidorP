cmake_minimum_required(VERSION 3.13)
project(ServidorP)

set(CMAKE_CXX_STANDARD 14)

add_executable(ServidorP main.cpp empaquetar.cpp empaquetar.h Lista.cpp Lista.h Nodo.cpp Nodo.h json.hpp Juego.cpp Juego.h)