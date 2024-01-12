cmake_minimum_required(VERSION 3.26)

set(CMAKE_CXX_STANDARD 20)

if (APPLE)
    set(CMAKE_OSX_ARCHITECTURES "arm64" CACHE STRING "")
    set(CMAKE_TOOLCHAIN_FILE "/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")
    set(SFML_STATIC_LIBRARIES FALSE)
endif ()

project(foxyEngine)

set(PROJECT_SOURCE_DIR ${CMAKE_SOURCE_DIR})
set(CMAKE_MAKE_PROGRAM ${CMAKE_SOURCE_DIR})
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/" ${CMAKE_MODULE_PATH})

file(GLOB SRC src/*.cpp src/system/*.cpp)
file(GLOB INCLUDE include/*.hpp include/system/*.hpp)

add_executable(foxyEngine ${SRC} ${INCLUDE})

if (APPLE)
    message(STATUS "Installing SFML Dependencies...")
    execute_process(
            COMMAND brew install pkg-config freetype glew jpeg libconfig openal-soft flac libogg libvorbis
            RESULT_VARIABLE result
    )
    if (result)
        message(FATAL_ERROR "Failed to install SFML dependencies. Please install them manually.")
    endif()

    message(STATUS "Setting up Vcpkg...")
    execute_process(
            COMMAND ./vcpkg/bootstrap-vcpkg.sh
            WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
            RESULT_VARIABLE result
    )
    if (result)
        message(FATAL_ERROR "Failed to setup Vcpkg. Please setup it manually.")
    else()
        message(STATUS "Vcpkg setup done.")
    endif()

    message(STATUS "Setting up Integrate Vcpkg...")
    execute_process(
            COMMAND ./vcpkg/vcpkg integrate install
            WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
            RESULT_VARIABLE result
    )
    if (result)
        message(FATAL_ERROR "Failed to setup Integrate Vcpkg. Please setup it manually.")
    else()
        message(STATUS "Integrate Vcpkg setup done.")
    endif()

    message(STATUS "Installing SFML using Vcpkg.")
    execute_process(
            COMMAND ./vcpkg/vcpkg install
            WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
            RESULT_VARIABLE VCPKG_RESULT
    )
    if (VCPKG_RESULT)
        message(FATAL_ERROR "Vcpkg failed with result ${VCPKG_RESULT}")
    else ()
        message(STATUS "SFML installed successfully.")
    endif()
endif ()

if (APPLE)
    target_include_directories(foxyEngine PRIVATE ${CMAKE_SOURCE_DIR}/vcpkg/installed/arm64-osx/include)
    find_package(SFML COMPONENTS system window graphics audio network CONFIG REQUIRED)
endif()

target_link_libraries(foxyEngine PRIVATE sfml-graphics sfml-window sfml-audio sfml-network sfml-system)
