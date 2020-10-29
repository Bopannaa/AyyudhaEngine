cmake_minimum_required(VERSION 3.15)

project(Ayyudha
        VERSION 1.0.0
        DESCRIPTION "Ayyudha Game Engine Library"
        LANGUAGES CXX)

set (SPDLOG_BUILD_EXAMPLE OFF)
set (SPDLOG_BUILD_TESTS OFF)
set (SPDLOG_INSTALL OFF)
set (CMAKE_BUILD_TYPE "Debug")
add_subdirectory(dependencies/spdlog)

set(SRCS ${CMAKE_CURRENT_SOURCE_DIR}/src/ayyudha/application.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ayyudha/log.cpp)

set(HDRS ${CMAKE_CURRENT_SOURCE_DIR}/src/ayyudha/application.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ayyudha/core.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ayyudha/entrypoint.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ayyudha/log.h)

add_library(${PROJECT_NAME} STATIC ${SRCS} ${HDRS})

target_link_libraries(${PROJECT_NAME} -lXrandr
                                        -lXi
                                        -lGLEW
                                        -lGLU
                                        -lGL
                                        -lX11
                                        -ldl
                                        -lpthread
                                        -lstdc++fs)

target_link_libraries(${PROJECT_NAME} spdlog)

target_include_directories(${PROJECT_NAME}
    PUBLIC ${CMAKE_SOURCE_DIR}/AyyudhaEngine/Ayyudha/src)

target_include_directories(${PROJECT_NAME}
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/dependencies/spdlog/include)

target_compile_definitions(${PROJECT_NAME} PUBLIC -DAA_PLATFORM_LINUX -DAA_BUILD_STATIC)
                            
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 17)

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_11)