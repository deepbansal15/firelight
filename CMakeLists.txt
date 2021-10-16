cmake_minimum_required(VERSION 3.10...3.18)

if($CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

# Default configuration
# Chossing default build to debug
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# Note: Even after choosing c++17, -std=gnu++17 still exists in the commands
set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS}  -Wall -Wextra -pedantic -Wshadow -Werror -Wconversion")
set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -W -Wpointer-arith -Wreturn-type -Wcast-qual -Wwrite-strings")
set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -Wswitch -Wunused-parameter -Wcast-align -Wchar-subscripts -Winline -Wredundant-decls")
set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -std=c++17 -fPIE -fPIC -fexceptions -frtti")

# TODO: Optimization flags and dumping of instruction set to debug further.

# Export the compile commands to better configure visual studio code.
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# Manually choose the compiler rather than letting cmake make the guess
# Warning: Don't use clang-cpp-13, it throws a clang: linker warning
set(CMAKE_CXX_COMPILER clang++-14)
# Warning: Even if we don't use C but some libraries might and then cmake have to make a guess again
set(CMAKE_C_COMPILER clang-14)

# Dynamic configuration options
option(ENABLE_TEST "Enable Testing" OFF)

project(firelight
        DESCRIPTION "Firelight"
        LANGUAGES CXX
        VERSION 0.0.1)

find_package(Threads REQUIRED)

add_executable(${PROJECT_NAME} main.cpp)
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)

if(ENABLE_TEST)
  include(FetchContent)
  FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
  )
  # For Windows: Prevent overriding the parent project's compiler/linker settings
  set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
  FetchContent_MakeAvailable(googletest)
endif()

# TODO: Add sanitizers and detailed instructions on how to use these sanitizers.


