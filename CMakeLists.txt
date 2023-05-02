cmake_minimum_required(VERSION 3.15)

# matlab to cpp tools

option(M2CPP_CONAN_USE "Use Conan to manage dependencies" OFF)
option(M2CPP_CONAN_EXEC_CMD "Execute conan install command automatically" OFF)
option(M2CPP_COMPILE_MAIN "Compile main executable" OFF)

if (M2CPP_CONAN_USE)
    message (STATUS "Using Conan to manage dependencies")
    if (M2CPP_CONAN_EXEC_CMD)
        message (STATUS "Executing conan install command")
        execute_process(COMMAND conan install .. -s build_type=${CMAKE_BUILD_TYPE} --build missing)
    endif()
    include(${CMAKE_BINARY_DIR}/conan_paths.cmake)
endif()

# find_package could be done with any other package manager.
find_package(Eigen3 REQUIRED)
# find_package(FFTW3f REQUIRED)

project(m2cpp)

# sample main executable to test the library
add_library(${PROJECT_NAME} INTERFACE)
target_include_directories(${PROJECT_NAME} INTERFACE include)
target_link_libraries(${PROJECT_NAME} INTERFACE Eigen3::Eigen)
# target_link_libraries(${PROJECT_NAME} INTERFACE FFTW3::fftw3f)

add_executable(${PROJECT_NAME}_main src/main.cpp)
target_link_libraries(${PROJECT_NAME}_main PRIVATE ${PROJECT_NAME})