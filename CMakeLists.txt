cmake_minimum_required (VERSION 3.9.2)

set(_CD "${CMAKE_SOURCE_DIR}")
set(TARGET_NAME "SyncLib")

set(CMAKE_CONFIGURATION_TYPES
    Test)

# cmake --DCMAKE_TOOLCHAIN_FILE=... noetig fuer Android
# Bis dahin hard coded Tests kompilieren:
set(TEST on)

project (${TARGET_NAME})

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory("${_CD}/dependencies/json11")
add_subdirectory("${_CD}/dependencies/cppsupport")

add_library(${TARGET_NAME} SHARED
    "${_CD}/include/BasicException.hpp"
    "${_CD}/include/DirectoryImpl.hpp"
    "${_CD}/source/DirectoryImpl.cpp"
    "${_CD}/include/FileSystemRepositoryImpl.hpp"
    "${_CD}/source/FileSystemRepositoryImpl.cpp"
)

set(HEADER_SEARCH_PATHS
    "${_CD}/generated_src/cpp/"
    "${_CD}/include/"
    "${_CD}/dependencies/json11/"
    "${_CD}/dependencies/cppsupport/")
  
target_include_directories(${TARGET_NAME} PUBLIC
    ${HEADER_SEARCH_PATHS}
)
target_link_libraries(${TARGET_NAME}
    cppsupport)

#set_target_properties(${TARGET_NAME} PROPERTIES
#  PUBLIC_HEADER
#  include/DirectoryTree.hpp)

#install(TARGETS ${TARGET_NAME}
#  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
#  PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

if (${TEST})
    add_subdirectory("${_CD}/test")
endif()
