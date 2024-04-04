cmake_minimum_required(VERSION 3.28.0)
project(Integral VERSION 0.1.0 LANGUAGES C CXX)
include("vcpkg.cmake")

file(GLOB_RECURSE SOURCES "src/*.hpp")

add_executable(Integral ${SOURCES} "src/Integral.cpp")

find_package(muparser CONFIG REQUIRED)
find_package(SFML COMPONENTS system window graphics CONFIG REQUIRED)
find_package(implot CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)
find_package(ImGui-SFML CONFIG REQUIRED)
target_link_libraries(Integral PRIVATE muparser::muparser sfml-system sfml-graphics sfml-window  ImGui-SFML::ImGui-SFML imgui::imgui implot::implot)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Integral PROPERTY CXX_STANDARD 20)
endif()

set(SOURCE_DIR "${CMAKE_SOURCE_DIR}/Fonts")
set(DESTINATION_DIR ${CMAKE_BINARY_DIR})
file(COPY ${SOURCE_DIR} DESTINATION "${DESTINATION_DIR}")
