cmake_minimum_required(VERSION 3.23)

project(Tetris)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(deps/wx)
add_executable(
    tetris_run 
    main.cpp 
    ./src/shape.cpp 
    ./src/board.cpp 
    ./src/tetris.cpp
)
target_include_directories(tetris_run PRIVATE ./src)
target_link_libraries(tetris_run PRIVATE wx::net wx::core wx::base)

if (WIN32)
    # the manifest file needed for windows
    target_sources(tetris_run PRIVATE deps/wx/include/wx/msw/wx.rc)
endif()
