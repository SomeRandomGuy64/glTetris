
# Add source to this project's executable.
add_executable (glTetris 
  main.cpp
  glad.c
)

set_property(TARGET glTetris PROPERTY CXX_STANDARD 20)

if(MSVC)
    target_compile_options(glTetris PRIVATE /W4 -WX)
else()
    add_compile_options(glTetris PRIVATE -Wall -Wextra -pedantic -Werror)
endif()

add_compile_options(glTetris PRIVATE /utf-8)

target_include_directories(glTetris PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

target_link_libraries(glTetris PUBLIC SDL3::SDL3 OpenGL::GL fmt::fmt glm stb_image imgui)

add_custom_command(TARGET glTetris POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:glTetris> $<TARGET_FILE_DIR:glTetris>
  COMMAND_EXPAND_LISTS
  )