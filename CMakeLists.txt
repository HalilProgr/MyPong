cmake_minimum_required(VERSION 3.10)

project(Tutorial)

#set(SFML_STATIC_LIBRARIES TRUE)
find_package(SFML COMPONENTS graphics window system)

set(HEADER_FILES	inc/algorithm.hpp ;
					inc/circle.hpp ;
					inc/paddle.hpp ;)

set(SOURCES_FILES	src/main.cpp ; 
					src/paddle.cpp ; 
					src/circle.cpp ;
					src/algorithm.cpp ;)

set(RESULT_SORCE ${SOURCES_FILES} ${HEADER_FILES})

include_directories(${Tutorial_SOURCE_DIR}/inc ${Tutorial_SOURCE_DIR})

message(${RESULT_SORCE})

add_executable(pong "${RESULT_SORCE}")

target_link_directories(pong PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/inc" )

target_link_libraries(pong sfml-graphics sfml-audio)