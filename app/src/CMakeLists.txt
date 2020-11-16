cmake_minimum_required(VERSION 3.18.2)

set(NAME src)

find_package(Qt5 REQUIRED COMPONENTS Core Quick Sql Widgets Multimedia)
file(GLOB SOURCE *.cpp *.h *.ui)

add_library(${NAME} STATIC ${SOURCE})
target_link_libraries(${NAME} Qt5::Widgets Qt5::Multimedia Qt5::Core Qt5::Quick Qt5::Sql)
