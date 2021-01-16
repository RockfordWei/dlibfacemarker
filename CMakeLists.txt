cmake_minimum_required(VERSION 3.14.1)
project(dlibfacemarker VERSION 1.0 DESCRIPTION "dlib face detector C lib wrapper")
include(FetchContent)
FetchContent_Declare(dlib
   GIT_REPOSITORY https://github.com/davisking/dlib.git
   GIT_TAG        v19.18
)
FetchContent_MakeAvailable(dlib)

add_library(dlibfacemarker SHARED
    dlibfacemarker.cpp
)

install(TARGETS dlibfacemarker
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

set_target_properties(dlibfacemarker PROPERTIES PUBLIC_HEADER dlibfacemarker.h)
set(CMAKE_POSITION_INDEPENDENT_CODE True)
add_definitions("-fPIC")
target_link_libraries(dlibfacemarker dlib::dlib)
