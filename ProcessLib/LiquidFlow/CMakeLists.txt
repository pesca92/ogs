append_source_files(SOURCES)

ogs_add_library(LiquidFlow ${SOURCES})
target_link_libraries(LiquidFlow PUBLIC ProcessLib PRIVATE ParameterLib)

if(BUILD_TESTING)
    include(Tests.cmake)
endif()
