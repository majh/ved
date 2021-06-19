cmake_minimum_required(VERSION 3.10)

project (ved)

file(GLOB ved_SRC
    "src/*.hpp"
    "src/*.cpp"
)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(GIT_EXECUTABLE git)

set(CMAKE_CXX_FLAGS_DEBUG_INIT "-Wall")
set(CMAKE_CXX_FLAGS_RELEASE_INIT "-Wall")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -W -Wall -Wextra -Wpointer-arith -Wredundant-decls")

add_executable(ved ${ved_SRC})

execute_process(COMMAND ${GIT_EXECUTABLE} describe --abbrev=6 --dirty --always
                WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
                OUTPUT_VARIABLE PACKAGE_GIT_VERSION
                ERROR_QUIET
                OUTPUT_STRIP_TRAILING_WHITESPACE)

add_definitions(-DPACKAGE_GIT_VERSION="${PACKAGE_GIT_VERSION}")

target_link_libraries(ved event_pthreads)
target_link_libraries(ved event)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../module/fmt/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../module/spdlog/include)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/module/catch2)
add_subdirectory (test.d)
