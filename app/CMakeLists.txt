cmake_minimum_required(VERSION 3.18.2)

set(CMAKE_CXX_STANDARD 17)
set(NAME uamp)
set(SOURCE_EXE main.cpp dtagmusic.cpp generalwindow.cpp
    musicwidget.cpp musiclist.cpp playmusic.cpp windowsetting.cpp)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

project(${NAME})

add_compile_options(
    -Wall
    -Wextra
    -Werror
    -Wpedantic
)

find_library(TAGLIB 3dtarty/libtag)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt5Multimedia REQUIRED)

include_directories(
    ./src
    ../build/3dparty/taglib
    ../3dparty/taglib/taglib/ape
    ../3dparty/taglib/taglib/asf
    ../3dparty/taglib/taglib/flac
    ../3dparty/taglib/taglib/it
    ../3dparty/taglib/taglib/mod
    ../3dparty/taglib/taglib/mp4
    ../3dparty/taglib/taglib/mpc
    ../3dparty/taglib/taglib/mpeg
    ../3dparty/taglib/taglib/mpeg/id3v2
    ../3dparty/taglib/taglib/mpeg/id3v1
    ../3dparty/taglib/taglib/mpeg/id3v2/frames
    ../3dparty/taglib/taglib/ogg
    ../3dparty/taglib/taglib/riff
    ../3dparty/taglib/taglib/s3m
    ../3dparty/taglib/taglib/toolkit
    ../3dparty/taglib/taglib/trueaudio
    ../3dparty/taglib/taglib/wavpack
    ../3dparty/taglib/taglib/xm
    ../3dparty/taglib/taglib
    ../3dparty/taglib/
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../../)

add_executable(${NAME} ${SOURCE_EXE})


target_link_libraries(${NAME} tag Qt5::Widgets Qt5::Multimedia)
