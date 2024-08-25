cmake_minimum_required(VERSION 3.30)
project(glTetris)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory("Third Party")

find_package(OpenGL REQUIRED)

set (CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin")
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin")

add_subdirectory("Source Files")

# Shader files
file(GLOB SHADER_FILES 
    "Shaders/*.vert"
    "Shaders/*.frag"
    "Shaders/*.geom"
    "Shaders/*.comp"
)

target_include_directories(${PROJECT_NAME} PUBLIC "Third Party")

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${SOURCE_FILES})
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${HEADER_FILES})
source_group("Shaders" FILES ${SHADER_FILES})

set_target_properties(${PROJECT_NAME} PROPERTIES
    VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
)