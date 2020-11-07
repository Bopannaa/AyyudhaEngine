cmake_minimum_required(VERSION 3.16)

project(Ayyudha
        VERSION 1.0.0
        DESCRIPTION "Ayyudha Game Engine Library"
        LANGUAGES CXX)

set (SPDLOG_BUILD_EXAMPLE OFF)
set (SPDLOG_BUILD_TESTS OFF)
set (SPDLOG_INSTALL OFF)
set (CMAKE_BUILD_TYPE "Debug")
add_subdirectory(dependencies/spdlog)

set (GLFW_BUILD_DOCS OFF)
set (GLFW_BUILD_EXAMPLES OFF)
set (GLFW_BUILD_TESTS OFF)
set (GLFW_INSTALL OFF)
set (CMAKE_BUILD_TYPE "Debug")
add_subdirectory(dependencies/glfw)

set (GLAD_PROFILE "core")
set (CMAKE_BUILD_TYPE "Debug")
add_subdirectory(dependencies/glad)

set (CMAKE_BUILD_TYPE "Debug")
add_subdirectory(dependencies/imgui)

set(glm_DIR dependencies/glm/cmake/glm) # if necessary
find_package(glm REQUIRED)

set(SRCS ${CMAKE_CURRENT_SOURCE_DIR}/src/ayyudha/application.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ayyudha/log.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/platform/linux/linuxWindow.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ayyudha/layer.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ayyudha/layerStack.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ayyudha/imgui/imguiLayer.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/platform/linux/linuxInput.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ayyudha/imgui/imguiBuild.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/platform/opengl/openglContext.cpp)

set(HDRS ${CMAKE_CURRENT_SOURCE_DIR}/src/ayyudha/application.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ayyudha/core.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ayyudha/entrypoint.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ayyudha/log.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ayyudha/events/event.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ayyudha/events/applicationEvent.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ayyudha/events/mouseEvent.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ayyudha/events/keyEvent.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ayyudha/window.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/platform/linux/linuxWindow.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ayyudha/layer.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ayyudha/layerStack.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ayyudha/imgui/imguiLayer.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ayyudha/input.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/platform/linux/linuxInput.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ayyudha/keyCodes.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ayyudha/mouseButtonCodes.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ayyudha/renderer/graphicsContext.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/platform/opengl/openglContext.h)

add_library(${PROJECT_NAME} STATIC ${SRCS} ${HDRS})

target_precompile_headers(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/aapch.h)

target_link_libraries(${PROJECT_NAME} -lXrandr
                                        -lXi
                                        -lGLEW
                                        -lGLU
                                        -lGL
                                        -lX11
                                        -ldl
                                        -lpthread
                                        -lstdc++fs)

target_link_libraries(${PROJECT_NAME} spdlog glfw glad imgui glm::glm)

target_include_directories(${PROJECT_NAME}
    PUBLIC ${CMAKE_SOURCE_DIR}/AyyudhaEngine/Ayyudha/src
    PUBLIC ${CMAKE_SOURCE_DIR}/AyyudhaEngine/Ayyudha/dependencies/imgui)

target_include_directories(${PROJECT_NAME}
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/dependencies/spdlog/include
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/Ayyudha/dependencies/glfw/include
    PRIVATE ${GLAD_OUT_DIR}/include)

target_compile_definitions(${PROJECT_NAME} 
    PUBLIC -DAA_PLATFORM_LINUX -DAA_ENABLE_ASSERTS -DGLFW_INCLUDE_NONE -D_CRT_SECURE_NO_WARNINGS)
                            
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 17)

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_11)