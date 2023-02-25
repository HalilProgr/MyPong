cmake_minimum_required(VERSION 3.10)

project(Tutorial)

set(SFML_STATIC_LIBRARIES TRUE)
find_package(SFML COMPONENTS graphics window system)

add_executable(pong "src/main.cpp"
					"src/paddle.cpp")

target_link_directories(pong PRIVATE "inc")

target_link_libraries(pong sfml-graphics sfml-audio)