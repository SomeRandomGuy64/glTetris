cmake_minimum_required(VERSION 3.30)
project(glTetris)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set warning level to 4 and treat warnings as errors
if(MSVC)
    add_compile_options(/W4 /WX)
else()
    add_compile_options(-Wall -Wextra -pedantic -Werror)
endif()

# Find packages
find_package(SDL2 REQUIRED)
find_package(OpenGL REQUIRED)

# Source files
file(GLOB_RECURSE SOURCE_FILES 
    "Source Files/*.c"
    "Source Files/*.cpp"
)

# Header files
file(GLOB_RECURSE HEADER_FILES 
    "Header Files/*.h"
    "Header Files/*.hpp"
)

# Shader files
file(GLOB SHADER_FILES 
    "Shaders/*.vert"
    "Shaders/*.frag"
    "Shaders/*.geom"
    "Shaders/*.comp"
)

# Create the executable
add_executable(${PROJECT_NAME} ${SOURCE_FILES} ${HEADER_FILES} ${SHADER_FILES})

# Include directories
target_include_directories(${PROJECT_NAME} PRIVATE "Third Party")

# Link libraries
target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2 OpenGL::GL)

# Create source groups for better organization in Visual Studio
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${SOURCE_FILES})
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${HEADER_FILES})
source_group("Shaders" FILES ${SHADER_FILES})

# Set the working directory to the project root
set_target_properties(${PROJECT_NAME} PROPERTIES
    VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
)

# Copy shader files to the build directory
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/Shaders
    $<TARGET_FILE_DIR:${PROJECT_NAME}>/Shaders
)