set(CMAKE_TOOLCHAIN_FILE "$ENV{EMROOT}/cmake/Modules/Platform/Emscripten.cmake")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -sEXPORT_ALL=1")

cmake_minimum_required(VERSION 3.10)
enable_testing()

project(Ayts)

set(ae2f_float double CACHE STRING double)

option(ae2f_TEST	"" ON)
option(ae2fCL_needed	"" OFF)
option(ae2f_CXX		"" OFF)

include(fetch.cmake)

ae2f_CoreLibFetch_NS(ae2f ae2fCL CL-Ann main)

file(GLOB_RECURSE incAyts-src include/Ayts/*.h*)
file(GLOB_RECURSE libAyts-src src/*.c*)

add_library(incAyts INTERFACE	${incAyts-src})
add_library(libAyts 		${libAyts-src})

target_include_directories(	incAyts INTERFACE	${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(	incAyts INTERFACE	${ae2f__ae2fCL__CL-Ann-H__FETCHED})

target_link_libraries(		libAyts PUBLIC 		incAyts)
target_include_directories(	libAyts PUBLIC		${ae2f__ae2fCL__CL-Ann__FETCHED})

# target_compile_options(MMap PRIVATE  -sSIDE_MODULE=1 -sEXPORT_KEEPALIVE=1)
# target_compile_options(Ann PRIVATE  -sSIDE_MODULE=1 -sEXPORT_KEEPALIVE=1)
# target_compile_options(libAyts PRIVATE  -sSIDE_MODULE=1 -sEXPORT_KEEPALIVE=1)


add_executable(Ayts ${PROJECT_SOURCE_DIR}/dummy.c)
target_link_libraries(Ayts	PUBLIC libAyts)
add_custom_command(
	TARGET Ayts 
	POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy
	${CMAKE_CURRENT_BINARY_DIR}/Ayts.js ${CMAKE_CURRENT_SOURCE_DIR}/Module/Ayts.auto.js
)

add_custom_command(
	TARGET Ayts 
	POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy
	${CMAKE_CURRENT_BINARY_DIR}/Ayts.wasm ${CMAKE_CURRENT_SOURCE_DIR}/Module/Ayts.auto.wasm
)
