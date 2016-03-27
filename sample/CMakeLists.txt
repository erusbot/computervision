find_package( OpenCV 2 REQUIRED )

include_directories (${OpenCV_INCLUDE_DIRS})

add_executable( main main.cpp crop.cpp threshold.cpp concatenate.cpp add_image.cpp blend_image.cpp)

target_link_libraries( main ${OpenCV_LIBS} )

