cmake_minimum_required(VERSION 3.2)

set(CMAKE_PROJECT_NAME xhk)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# configuration
option(PRECOMPILE_HEADERS "Use precompiled headers for improved compile time." ON)

project(${CMAKE_PROJECT_NAME} VERSION 1.0.0)
configure_file(config.h.in config.h)

add_subdirectory(vendor/chaiscript)

set(CMAKE_PROJECT_SOURCEFILES
    src/xhk.cpp
)
add_executable(${CMAKE_PROJECT_NAME}
    ${CMAKE_PROJECT_SOURCEFILES}
)

include_directories(${CMAKE_PROJECT_NAME} PRIVATE
    include
)

# optionally: use precompiled headers
if (PRECOMPILE_HEADERS)
    target_precompile_headers(${CMAKE_PROJECT_NAME} PRIVATE
        xhkpch.h
    )
endif(PRECOMPILE_HEADERS)

target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE
    chaiscript
)

target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE
    ${PROJECT_BINARY_DIR}
    ${PROJECT_SOURCE_DIR}/vendor/chaiscript/include
)