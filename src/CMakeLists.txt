add_library(intervals "")

file(GLOB_RECURSE SOURCES "*.cc")

target_sources(
    intervals
    PRIVATE
        ${SOURCES}
    )

target_include_directories(
    intervals
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
    )
