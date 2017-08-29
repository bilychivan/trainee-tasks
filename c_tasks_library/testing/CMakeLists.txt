set(EXEC_NAME testing)

add_executable(${EXEC_NAME} testing.c)

target_link_libraries(${EXEC_NAME} LINK_PUBLIC simple_c_library_STATIC simple_c_library_2_STATIC)