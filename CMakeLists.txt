cmake_minimum_required(VERSION 3.10)
project(SmartNVR)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set the path to the vcpkg toolchain file
set(CMAKE_TOOLCHAIN_FILE "D:/source/common/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "Vcpkg toolchain file")

# Find required packages
find_package(CUDA REQUIRED)
find_package(OpenCV CONFIG REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_check_modules(GSTREAMER REQUIRED gstreamer-1.0)

# Include directories
include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(${GSTREAMER_INCLUDE_DIRS})

# Add source files
file(GLOB SOURCES "*.cpp")

# Add header files
file(GLOB HEADERS "*.h")

# Add executable
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

# Link libraries
target_link_libraries(${PROJECT_NAME} PRIVATE ${OpenCV_LIBS} ${GSTREAMER_LIBRARIES})
