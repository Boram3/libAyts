# include("$ENV{WASI_SDK_PATH}/share/cmake/wasi-sdk.cmake")
# include("$ENV{EMROOT}/cmake/Modules/Platform/Emscripten.cmake")
set(CMAKE_TOOLCHAIN_FILE "$ENV{EMROOT}/cmake/Modules/Platform/Emscripten.cmake")

# set(CMAKE_C_FLAGS "-s LINKABLE=1 -Oz")

cmake_minimum_required(VERSION 3.10)
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

# target_compile_options(MMap PRIVATE  -sSIDE_MODULE=1 -sEXPORT_KEEPALIVE=1 -sSTANDALONE_WASM)
# target_compile_options(Ann PRIVATE  -sSIDE_MODULE=1 -sEXPORT_KEEPALIVE=1 -sSTANDALONE_WASM)
# target_compile_options(libAyts PRIVATE -sSTANDALONE_WASM)


add_library(_Ayts ${PROJECT_SOURCE_DIR}/dummy.c)
target_link_libraries(_Ayts	PUBLIC libAyts)
# target_compile_options(Ayts PUBLIC  ${CMAKE_C_FLAGS} -sEXPORTED_FUNCTIONS=_dummy)

add_custom_command(
 	TARGET _Ayts
 	POST_BUILD COMMAND 
 	emcc 
	${CMAKE_CURRENT_BINARY_DIR}/lib_Ayts.a 
	-o${CMAKE_CURRENT_BINARY_DIR}/Ayts.js
 	-sEXPORTED_FUNCTIONS=_dummy
)

add_custom_command(
  	TARGET _Ayts 
  	POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy
 	${CMAKE_CURRENT_BINARY_DIR}/Ayts.wasm ${CMAKE_CURRENT_SOURCE_DIR}/Module/Ayts.wasm
)
