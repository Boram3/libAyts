set(CMAKE_TOOLCHAIN_FILE "$ENV{EMROOT}/cmake/Modules/Platform/Emscripten.cmake")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}  -sEXPORT_ALL=1 -sLINKABLE=1")

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

target_compile_options(MMap PUBLIC  -sSIDE_MODULE=1)
target_compile_options(Ann PUBLIC  -sSIDE_MODULE=1)
target_compile_options(libAyts PUBLIC  -sSIDE_MODULE=1)