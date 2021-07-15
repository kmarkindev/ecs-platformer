add_library(exe_inter INTERFACE)
add_executable(executable)
target_link_libraries(executable PUBLIC exe_inter glfw entt glm Stb::Image ImGui::ImGui)

target_sources(exe_inter INTERFACE
    Main.cpp
)