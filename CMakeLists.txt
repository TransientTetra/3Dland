cmake_minimum_required(VERSION 3.16)
project(3Dland)

set(CMAKE_CXX_STANDARD 17)

set(ASSETS_FOLDER ${PROJECT_SOURCE_DIR}/res)

find_package(SDL2 REQUIRED)
find_library(GL_LIBRARY NAME GL)
find_library(GLEW_LIBRARY NAME GLEW)
find_library(GLM_LIBRARY NAME GLM)

find_package(Threads REQUIRED)
find_package(OpenGL REQUIRED)

set(BINARY ${CMAKE_PROJECT_NAME})

set(CMAKE_CXX_STANDARD 17)
set(
        SRC
        application.cpp
        mesh.cpp
        shader.cpp
        texture.cpp
)
set(SRC ${SRC})

add_library(${BINARY}_lib STATIC ${SRC})

add_subdirectory(lib)
include_directories(lib/glm)


add_executable(${CMAKE_PROJECT_NAME} main.cpp)
target_link_libraries(${CMAKE_PROJECT_NAME} ${CMAKE_PROJECT_NAME}_lib Threads::Threads)
target_link_libraries(${CMAKE_PROJECT_NAME} SDL2 GLEW GL glm)


#copying assets
add_custom_command(TARGET ${CMAKE_PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${ASSETS_FOLDER} $<TARGET_FILE_DIR:${CMAKE_PROJECT_NAME}>/res)