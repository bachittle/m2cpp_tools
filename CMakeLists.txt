cmake_minimum_required(VERSION 3.15)

# matlab to cpp tools

# Dependency management is with conan.
option(USE_CONAN "Use Conan to manage dependencies" ON)
if (USE_CONAN)
    include(${CMAKE_BINARY_DIR}/conan_paths.cmake)
endif()

# find_package could be done with any other package manager.
find_package(Eigen3 REQUIRED)
# find_package(FFTW3f REQUIRED)

project(matlab2cpp)

# sample main executable to test the library
add_executable(${PROJECT_NAME} src/main.cpp)
target_include_directories(${PROJECT_NAME} PRIVATE include)
target_link_libraries(${PROJECT_NAME} Eigen3::Eigen)
# target_link_libraries(${PROJECT_NAME} FFTW3::fftw3f)