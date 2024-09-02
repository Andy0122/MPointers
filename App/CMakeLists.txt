cmake_minimum_required(VERSION 3.29)
project(App)

set(CMAKE_CXX_STANDARD 20)

# Añade la subdirectorio de la biblioteca MPointers con un directorio binario específico
add_subdirectory(../MPointers ${CMAKE_BINARY_DIR}/MPointers_build)

# Crea el ejecutable de la aplicación principal
add_executable(App main.cpp
        include/DoublyLinkedList.h
        include/Node.h
        include/SortingAlgrithms.h)

# Vincula la biblioteca MPointersLib con tu aplicación
target_link_libraries(App PRIVATE MPointersLib)

# Añade el directorio de inclusión para la biblioteca y el proyecto
target_include_directories(App PRIVATE
        ../MPointers/include  # Directorio de cabecera de MPointers
        ${CMAKE_CURRENT_SOURCE_DIR}/include  # Directorio de cabecera del proyecto App
)

