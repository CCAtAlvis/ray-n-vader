cmake_minimum_required(VERSION 3.10)

project(Ray-n-vader)

set (CMAKE_CXX_STANDARD 17)

find_package(raylib CONFIG REQUIRED)

include_directories("include/")

file(GLOB SOURCES "src/*" "src/entities/*" "src/scenes/*")

add_executable(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE ${RAYLIB_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PRIVATE ${RAYLIB_LIBRARIES})