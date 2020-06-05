cmake_minimum_required(VERSION 3.10)

project(janux)

add_library(janux STATIC
    src/window.cxx
    src/vector.cxx
    src/matrix.cxx
    src/vertex.cxx
    src/file.cxx
    src/shader.cxx
    src/transform.cxx
    src/drawable.cxx
    src/texture.cxx
    src/renderer.cxx
    src/engine.cxx
)

target_include_directories(janux PUBLIC 
    "${PROJECT_BINARY_DIR}/../include"
)
target_link_libraries(janux
    glfw
    glbinding
    IL
)