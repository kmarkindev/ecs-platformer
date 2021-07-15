add_executable(executable)

target_link_libraries(executable PUBLIC glfw EnTT::EnTT glm stb::image imgui)

target_sources(executable PUBLIC
    Main.cpp
    Application.cpp
    Application.h
)

target_include_directories(executable PRIVATE
    "/"
)

add_subdirectory(Window)