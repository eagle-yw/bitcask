



add_library(bitcask)


file(GLOB_RECURSE  SRC_FILES "./*.cppm")

message("${SRC_FILES}")

target_sources(bitcask
    PUBLIC FILE_SET CXX_MODULES FILES
    ${SRC_FILES}
)