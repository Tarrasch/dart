###############################################
# apps/hybrid
PROJECT(hybrid)
FILE(GLOB hybrid_srcs "*.cpp")
FILE(GLOB hybrid_hdrs "*.h")
ADD_EXECUTABLE(hybrid ${hybrid_srcs} ${hybrid_hdrs})
TARGET_LINK_LIBRARIES(hybrid dart ${DARTExt_LIBRARIES})

SET_TARGET_PROPERTIES(hybrid PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")
