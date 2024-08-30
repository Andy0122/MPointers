cmake_minimum_required(VERSION 3.29)
project(Progra1Datos2)

set(CMAKE_CXX_STANDARD 20)

# Añade la subdirectorio de la biblioteca MPointers con un directorio binario específico
add_subdirectory(../MPointers ${CMAKE_BINARY_DIR}/MPointers_build)

# Crea el ejecutable de la aplicación principal
add_executable(Progra1Datos2 main.cpp)

# Vincula la biblioteca MPointersLib con tu aplicación
target_link_libraries(Progra1Datos2 PRIVATE MPointersLib)

# Añade el directorio de inclusión para la biblioteca
target_include_directories(Progra1Datos2 PRIVATE ../MPointers/src)
