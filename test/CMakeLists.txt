cmake_minimum_required (VERSION 3.9.2)

set(TEST_TARGET_NAME "${TARGET_NAME}Tests")
add_executable(${TEST_TARGET_NAME}
    "${_CD}/test/main.cpp") 
target_include_directories(${TEST_TARGET_NAME} PUBLIC
    ${HEADER_SEARCH_PATHS})
target_link_libraries(${TEST_TARGET_NAME}
    ${TARGET_NAME})
