cmake_minimum_required( VERSION 3.0 )
project( Keypoints-Detection-and-Matching )


set( CMAKE_CXX_FLAGS "-std=c++11" )
set(CMAKE_BUILD_TYPE "Release")

find_package( OpenCV 3 REQUIRED )

include_directories( ${OpenCV_INCLUDE_DIRS} )

add_executable( test main.cpp )

target_link_libraries( test ${OpenCV_LIBS} )
