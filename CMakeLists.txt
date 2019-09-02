cmake_minimum_required(VERSION 3.13)

project(GameOfLife)

# Set binary output directories
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(GameOfLife
    src/Game.cpp
    src/Grid.cpp
    src/ImageButton.cpp
    src/Main.cpp
)

# Dependency: SFML
add_subdirectory(ext/SFML)
target_link_libraries(GameOfLife PRIVATE sfml-graphics)

add_custom_command(TARGET GameOfLife POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_directory
                       ${CMAKE_SOURCE_DIR}/assets $<TARGET_FILE_DIR:GameOfLife>/assets)
