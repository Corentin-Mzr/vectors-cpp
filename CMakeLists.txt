cmake_minimum_required(VERSION 3.28)
project(Vectors VERSION 0.1.0 LANGUAGES CXX)

# Set C++ standard to C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Output directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Glob for source files
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
    ${CMAKE_SOURCE_DIR}/src/*.cpp
)

# Create exe
add_executable(${PROJECT_NAME} ${SOURCES})

# Include directories
target_include_directories(${PROJECT_NAME}
    PRIVATE
    ${CMAKE_SOURCE_DIR}/src
)


# --------- Add tests --------- #

# Add test executable
add_executable(test_vector2 ${CMAKE_SOURCE_DIR}/tests/test_vector2.cpp)
add_executable(test_vector3 ${CMAKE_SOURCE_DIR}/tests/test_vector3.cpp)
add_executable(test_vector4 ${CMAKE_SOURCE_DIR}/tests/test_vector4.cpp)

target_include_directories(test_vector2
    PRIVATE
    ${CMAKE_SOURCE_DIR}/src
)

target_include_directories(test_vector3
    PRIVATE
    ${CMAKE_SOURCE_DIR}/src
)

target_include_directories(test_vector4
    PRIVATE
    ${CMAKE_SOURCE_DIR}/src
)

# Enable testing
enable_testing()

# Register test executable with CTest
add_test(NAME TestVector2 COMMAND test_vector2)
add_test(NAME TestVector3 COMMAND test_vector3)
add_test(NAME TestVector4 COMMAND test_vector4)
