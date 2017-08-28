file(GLOB SOURCES "*.c")

add_executable (lyslib_demo ${SOURCES})

target_link_libraries (lyslib_demo LINK_PUBLIC lyslib_static)
