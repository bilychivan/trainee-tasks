file(GLOB SOURCES "*.c")

include_directories(../library/include)

add_executable (lyslib_demo ${SOURCES})

target_link_libraries (lyslib_demo LINK_PUBLIC lyslib_static)
