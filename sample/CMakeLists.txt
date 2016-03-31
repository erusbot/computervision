find_package( OpenCV 2 REQUIRED )

include_directories (${OpenCV_INCLUDE_DIRS})

add_executable( main main.cpp )

add_executable( threshold threshold.cpp )

add_executable( canais canais.cpp )

add_executable( concatena concatena.cpp )

add_executable( recortar recortar.cpp )

add_executable( sal sal.cpp )

target_link_libraries( main ${OpenCV_LIBS} )
target_link_libraries( threshold ${OpenCV_LIBS} )
target_link_libraries( canais ${OpenCV_LIBS} )
target_link_libraries( concatena ${OpenCV_LIBS} )
target_link_libraries( recortar ${OpenCV_LIBS} )
target_link_libraries( sal ${OpenCV_LIBS} )
