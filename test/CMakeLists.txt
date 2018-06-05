cmake_minimum_required (VERSION 3.9.2)

set(_CD ${CMAKE_CURRENT_SOURCE_DIR})
set(TEST_TARGET_NAME "${TARGET_NAME}Tests")
add_executable(${TEST_TARGET_NAME}
    "${_CD}/main.cpp") 
target_include_directories(${TEST_TARGET_NAME} PUBLIC
    ${HEADER_SEARCH_PATHS})
target_link_libraries(${TEST_TARGET_NAME}
    ${TARGET_NAME})

target_compile_definitions(${TEST_TARGET_NAME} PUBLIC -DTESTDIRECTORY="${_CD}/testdata")


#enable_testing()
#add_test(NAME ${TEST_TARGET_NAME} COMMAND ${TEST_TARGET_NAME})
#set_tests_properties(${TEST_TARGET_NAME} PROPERTIES WORKING_DIRECTORY "${_CD}/testdata")
