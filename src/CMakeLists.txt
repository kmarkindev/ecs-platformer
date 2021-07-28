add_executable(executable)

target_link_libraries(executable PUBLIC glfw EnTT::EnTT glm stb::image imgui)

target_sources(executable PUBLIC
    Main.cpp
)

target_include_directories(executable PRIVATE
    "/"
)

add_custom_command(TARGET executable POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/resources/ $<TARGET_FILE_DIR:executable>/resources/)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
	message("Debug build detected. Define DEBUG_MODE definition")
	target_compile_definitions(executable PRIVATE DEBUG_BUILD)
endif()

add_subdirectory(Application)
add_subdirectory(Window)
add_subdirectory(Assets)
add_subdirectory(Render)
add_subdirectory(Input)
add_subdirectory(Utils)
add_subdirectory(Container)
add_subdirectory(Scene)
add_subdirectory(Components)
add_subdirectory(Systems)
add_subdirectory(Math)