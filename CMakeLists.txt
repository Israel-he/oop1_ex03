cmake_minimum_required (VERSION 3.26)

project (oop1_ex03)
set (MY_AUTHORS "YOUR-NAME-HERE")

include (cmake/CompilerSettings.cmake)

add_executable (${CMAKE_PROJECT_NAME})

target_compile_options(${CMAKE_PROJECT_NAME} PRIVATE $<$<CONFIG:DEBUG>:-fsanitize=address>)
target_link_options(${CMAKE_PROJECT_NAME} PRIVATE $<$<CONFIG:DEBUG>:-fsanitize=address>)

add_subdirectory (include)
add_subdirectory (src)
add_subdirectory (resources)

include (cmake/Zip.cmake)

set (Catch2_DIR "external/Catch2/lib/cmake/Catch2")
find_package (Catch2 REQUIRED)

add_executable (Tests "")
target_link_libraries (Tests Catch2::Catch2)
add_subdirectory (tests)

set (TARGET_TO_MIMIC ${CMAKE_PROJECT_NAME})

get_target_property (Mimic_SOURCES ${TARGET_TO_MIMIC} SOURCES)
get_target_property (Mimic_INCLUDE_DIRECTORIES ${TARGET_TO_MIMIC} INCLUDE_DIRECTORIES)

list (FILTER Mimic_SOURCES EXCLUDE REGEX ".*main.cpp")

target_sources (Tests PRIVATE ${Mimic_SOURCES})
target_include_directories (Tests PRIVATE ${Mimic_INCLUDE_DIRECTORIES})

include (CTest)
include (Catch)
catch_discover_tests (Tests)

