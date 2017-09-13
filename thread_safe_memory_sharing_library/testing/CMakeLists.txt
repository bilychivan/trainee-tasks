set(EXEC_NAME1 testing)
set(EXEC_NAME2 main)

add_executable(${EXEC_NAME1} ${EXEC_NAME1}.cpp)

target_link_libraries(${EXEC_NAME1} LINK_PUBLIC memory_manager_library_STATIC)

add_executable(${EXEC_NAME2} ${EXEC_NAME2}.cpp)

target_link_libraries(${EXEC_NAME2} LINK_PUBLIC memory_manager_library_STATIC)