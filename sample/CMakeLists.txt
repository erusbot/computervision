cmake_minimum_required(VERSION 2.8)
find_package( OpenCV 2 REQUIRED )

include_directories (${OpenCV_INCLUDE_DIRS} libs)

file(GLOB SOURCES "src/*.cpp")

add_executable( main main.cpp ${SOURCES})

target_link_libraries( main ${OpenCV_LIBS} )

