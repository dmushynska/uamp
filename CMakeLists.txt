cmake_minimum_required(VERSION 3.18.2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_MACOSX_RPATH 1)
set(NAME uamp)

project(${NAME} LANGUAGES CXX)

add_subdirectory(3dparty)
add_subdirectory(app)
