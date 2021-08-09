find_package(OpenGL REQUIRED)

add_subdirectory(glad)

add_subdirectory(glm)

set(GLFW_BUILD_EXAMPLES OFF)
set(GLFW_BUILD_TESTS OFF)
set(GLFW_BUILD_DOCS OFF)
set(GLFW_INSTALL OFF)
add_subdirectory(glfw)

add_subdirectory(entt)

add_subdirectory(imgui)

add_subdirectory(stb)

set(BOX2D_BUILD_UNIT_TESTS OFF)
set(BOX2D_BUILD_TESTBED OFF)
set(BOX2D_BUILD_DOCS OFF)
set(BOX2D_USER_SETTINGS OFF)
add_subdirectory(box2d)