cmake_minimum_required(VERSION 3.0)
project(demo)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin)

file(MAKE_DIRECTORY ${EXECUTABLE_OUTPUT_PATH})

set(CMAKE_CXX_STANDARD 11)
find_package(OpenCV REQUIRED)
message("OpenCV version: ${OpenCV_VERSION}")
message("project name: ${PROJECT_NAME}")

include_directories(${OpenCV_INCLUDE_DIRS})
link_directories(${OpenCV_LIB_DIR})

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src SRC)

add_executable(${PROJECT_NAME} ${SRC})

target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})