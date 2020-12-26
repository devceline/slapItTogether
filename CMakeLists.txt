cmake_minimum_required(VERSION 3.10)


set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(slapItTogether)

find_package(GLEW REQUIRED)

add_executable(
	slapItTogether
	src/main.cpp
)

add_subdirectory(deps/glfw)

target_link_libraries(
	slapItTogether
	glfw
	GLEW::GLEW
	${GLEW_LIBRARIES}
	-lGL
	-lGLEW
)
