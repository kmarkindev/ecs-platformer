project(stb)

# stb image
add_library(stbimage STATIC stb_init.cpp)
add_library(stb::image ALIAS stbimage)
target_include_directories(stbimage PUBLIC include)