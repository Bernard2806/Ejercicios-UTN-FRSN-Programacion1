# Establecer el mínimo requerido para CMake
cmake_minimum_required(VERSION 3.10)

# Nombre de tu proyecto
project(Ejercicios-UTN-FRSN-Programacion1)

# Definir el tipo de compilación (esto es opcional y puede ser "Debug" o "Release")
set(CMAKE_BUILD_TYPE Release)

# Incluir todos los archivos .c y .cpp del directorio actual y subdirectorios
file(GLOB_RECURSE SOURCES "*.c" "*.cpp")

# Crear el ejecutable a partir de todos los archivos encontrados
add_executable(${PROJECT_NAME} ${SOURCES})
