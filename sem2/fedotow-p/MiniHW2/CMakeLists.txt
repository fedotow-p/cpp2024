cmake_minimum_required(VERSION 3.30)
project(MiniHW2)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)
FetchContent_Declare(SFML
		GIT_REPOSITORY https://github.com/SFML/SFML.git
		GIT_TAG 3.0.0
		GIT_SHALLOW ON
		EXCLUDE_FROM_ALL
		SYSTEM)
FetchContent_MakeAvailable(SFML)

add_executable(MiniHW2 main.cpp)

target_link_libraries(MiniHW2 sfml-graphics)
