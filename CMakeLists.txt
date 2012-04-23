cmake_minimum_required (VERSION 2.6)
project (DOMINO)

set ( PROJECT_SOURCE_DIR src)
set ( DOMINO_SOURCES 
        ${PROJECT_SOURCE_DIR}/Engine.cpp
    )

include_directories(./include)
add_library(domino SHARED ${DOMINO_SOURCES})
