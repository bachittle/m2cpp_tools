cmake_minimum_required(VERSION 3.15)

# matlab to cpp tools

option(USE_CONAN "Use Conan to manage dependencies" ON)

if (USE_CONAN)
    include(${CMAKE_BINARY_DIR}/conan_paths.cmake)
endif()

find_package(Eigen3 REQUIRED)
find_package(FFTW3f REQUIRED)

project(matlab2cpp)

add_executable(${PROJECT_NAME} src/main.cpp)
target_include_directories(${PROJECT_NAME} PRIVATE include)
target_link_libraries(${PROJECT_NAME} Eigen3::Eigen FFTW3::fftw3f)