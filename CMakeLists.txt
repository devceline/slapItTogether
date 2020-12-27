cmake_minimum_required(VERSION 3.10)


set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(slapItTogether)

find_package(GLEW REQUIRED)

add_executable(
	slapItTogether
	src/main.cpp
	src/utils/file.cpp
	src/glAbstractions/program.cpp
)

add_subdirectory(deps/glfw)

target_include_directories(
	slapItTogether
	PUBLIC
	./include/
)

target_link_libraries(
	slapItTogether
	glfw
	GLEW::GLEW
	${GLEW_LIBRARIES}
	-lGL
	-lGLEW
)
