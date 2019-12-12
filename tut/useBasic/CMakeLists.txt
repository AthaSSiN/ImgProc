#spec min version reqd
cmake_minimum_required(VERSION 2.8)

#add proj name
project( DisplayImage)

#specify reqd packages
find_package( OpenCV REQUIRED )

#add dirs containing header files
include_directories( ${OpenCV_INCLUDE_DIRS} )

#specify executable name
add_executable( dispimg dispimg.cpp )
add_executable( cpimg cpimg.cpp )

#link libraries to the executable
target_link_libraries( dispimg ${OpenCV_LIBS} )
target_link_libraries( cpimg ${OpenCV_LIBS} )

