cmake_minimum_required(VERSION 3.10)

project(Ray-n-vader)

set (CMAKE_CXX_STANDARD 17)

include_directories("include")

file(GLOB SOURCES "src/*.cpp" "src/entities/*.cpp"  "src/scenes/*.cpp")
file(GLOB SOURCES "include" "src/*" "src/entities/*"  "src/scenes/*")

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries (${PROJECT_NAME} "-L${CMAKE_SOURCE_DIR}/lib" raylib opengl32 gdi32 winmm  )