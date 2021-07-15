project(imgui)

add_library(imgui STATIC
    include/imgui/imgui.cpp
    include/imgui/imgui_demo.cpp
    include/imgui/imgui_widgets.cpp
    include/imgui/imgui_draw.cpp
    include/imgui/imgui_tables.cpp
    include/imgui/backends/imgui_impl_opengl3.cpp
    include/imgui/backends/imgui_impl_glfw.cpp
)

target_link_libraries(imgui glad glfw)

target_include_directories(imgui PUBLIC include)
target_include_directories(imgui PRIVATE include/imgui)