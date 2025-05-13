cmake_minimum_required(VERSION 3.10)
enable_testing()

project(Ayts)

include(fetch.cmake)

option(ae2f_TEST ON)
ae2f_CoreLibFetch_NS(ae2f ae2fCL CL-Ann main)

file(GLOB_RECURSE incAyts-src include/Ayts/*.h*)
file(GLOB_RECURSE libAyts-src src/*.c*)

add_library(incAyts INTERFACE	${incAyts-src})
add_library(libAyts 		${libAyts-src})

target_include_directories(	incAyts INTERFACE	${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(	incAyts INTERFACE	${ae2f__ae2fCL__CL-Ann-H__FETCHED})

target_link_libraries(		libAyts PUBLIC 		incAyts)
target_include_directories(	libAyts PUBLIC		${ae2f__ae2fCL__CL-Ann__FETCHED})
