#http://imaya.blog.jp/archives/6361098.html

cmake_minimum_required(VERSION 2.8)
project(rabbit)

set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(EXECUTABLE_OUTPUT_PATH "${CMAKE_HOME_DIRECTORY}/bin")


#set(SOURCE_FILES    src/main.cpp)
file(GLOB_RECURSE SOURCE_FILES   "src/*.cpp" "src/*.c" )




if (EMSCRIPTEN)
    set(CMAKE_EXECUTABLE_SUFFIX ".html") # デフォルトでは.js
	set(CMAKE_C_COMPILER emcc)	
	set(CMAKE_CXX_COMPILER emcc)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --memory-init-file 0")
endif()


### GL
find_library(GL_LIB OpenGL)
if (NOT GL_LIB)
    message(FATAL_ERROR "GL not found")
endif()



### boost
find_package(Boost 1.57.0 COMPONENTS thread signals filesystem system context chrono container)
if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
	add_executable(rabbit ${SOURCE_FILES})
	if(NOT EMSCRIPTEN)
	    target_link_libraries(rabbit ${GL_LIB} glfw3 )
	endif()
else()
    message(FATAL_ERROR "boost not found")

endif()








