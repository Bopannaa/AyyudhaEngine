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

set (CMAKE_BUILD_TYPE "Debug")
add_subdirectory(dependencies/stb_image)

set(SRCS 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ayyudha/core/application.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ayyudha/core/log.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ayyudha/core/layer.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ayyudha/core/layerStack.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ayyudha/core/orthographicCameraController.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/src/ayyudha/imgui/imguiLayer.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ayyudha/imgui/imguiBuild.cpp
    
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ayyudha/renderer/shader.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ayyudha/renderer/buffer.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ayyudha/renderer/renderer.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ayyudha/renderer/vertexArray.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ayyudha/renderer/renderCommand.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ayyudha/renderer/rendererAPI.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ayyudha/renderer/orthographicCamera.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ayyudha/renderer/texture.cpp
    
    ${CMAKE_CURRENT_SOURCE_DIR}/src/platform/linux/linuxWindow.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/platform/linux/linuxInput.cpp
    
    ${CMAKE_CURRENT_SOURCE_DIR}/src/platform/opengl/openglContext.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/platform/opengl/openglBuffer.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/platform/opengl/openglVertexArray.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/platform/opengl/openglRendererAPI.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/platform/opengl/openglShader.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/platform/opengl/openglTexture.cpp)

set(HDRS 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ayyudha/core/timestep.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ayyudha/core/application.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ayyudha/core/core.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ayyudha/core/entrypoint.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ayyudha/core/log.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ayyudha/core/window.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ayyudha/core/layer.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ayyudha/core/layerStack.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ayyudha/core/input.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ayyudha/core/keyCodes.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ayyudha/core/mouseButtonCodes.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ayyudha/core/orthographicCameraController.h

    ${CMAKE_CURRENT_SOURCE_DIR}/src/ayyudha/renderer/graphicsContext.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ayyudha/renderer/shader.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ayyudha/renderer/buffer.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ayyudha/renderer/renderer.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ayyudha/renderer/vertexArray.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ayyudha/renderer/renderCommand.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ayyudha/renderer/rendererAPI.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ayyudha/renderer/orthographicCamera.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ayyudha/renderer/texture.h

    ${CMAKE_CURRENT_SOURCE_DIR}/src/ayyudha/imgui/imguiLayer.h

    ${CMAKE_CURRENT_SOURCE_DIR}/src/ayyudha/events/event.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ayyudha/events/applicationEvent.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ayyudha/events/mouseEvent.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ayyudha/events/keyEvent.h

    ${CMAKE_CURRENT_SOURCE_DIR}/src/platform/linux/linuxWindow.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/platform/linux/linuxInput.h

    ${CMAKE_CURRENT_SOURCE_DIR}/src/platform/opengl/openglContext.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/platform/opengl/openglBuffer.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/platform/opengl/openglVertexArray.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/platform/opengl/openglRendererAPI.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/platform/opengl/openglShader.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/platform/opengl/openglTexture.h)

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

target_link_libraries(${PROJECT_NAME} spdlog glfw glad imgui glm::glm stb_image)

target_include_directories(${PROJECT_NAME}
    PUBLIC ${CMAKE_SOURCE_DIR}/AyyudhaEngine/Ayyudha/src
    PUBLIC ${CMAKE_SOURCE_DIR}/AyyudhaEngine/Ayyudha/dependencies/imgui)

target_include_directories(${PROJECT_NAME}
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/dependencies/spdlog/include
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/dependencies/glfw/include
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/dependencies/stb_image
    PRIVATE ${GLAD_OUT_DIR}/include)

target_compile_definitions(${PROJECT_NAME} 
    PUBLIC -DAA_ENABLE_ASSERTS -DGLFW_INCLUDE_NONE -D_CRT_SECURE_NO_WARNINGS -DAA_DEBUG)
                            
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 17)

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_11)