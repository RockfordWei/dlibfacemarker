cmake_minimum_required(VERSION 3.10.1)
project(dlibfacemarker VERSION 1.0 DESCRIPTION "dlib face detector C lib wrapper")
set(BUILD_SHARED_LIBS true)
add_subdirectory(dlib dlib_build)
add_library(dlibfacemarker SHARED
    dlibfacemarker.cpp
)
set_target_properties(dlibfacemarker PROPERTIES PUBLIC_HEADER dlibfacemarker.h)
target_link_libraries(dlibfacemarker dlib::dlib)
