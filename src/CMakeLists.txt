add_executable(executable)

target_link_libraries(executable PUBLIC glfw EnTT::EnTT glm stb::image imgui)

target_sources(executable PUBLIC
    Main.cpp
)

target_include_directories(executable PRIVATE
    "/"
)

add_subdirectory(Application)
add_subdirectory(Window)
add_subdirectory(Assets)
add_subdirectory(Render)