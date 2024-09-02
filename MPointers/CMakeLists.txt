cmake_minimum_required(VERSION 3.29)
project(MPointers)

set(CMAKE_CXX_STANDARD 20)

# Crear la biblioteca (puedes darle un nombre diferente para evitar conflictos)
add_library(MPointersLib STATIC
        src/MPointer.cpp
        src/MPointerGC.cpp
        src/MPointerBase.cpp
        include/MPointerBase.h
        src/RefCountList.cpp
        include/RefCountList.h
)
