cmake_minimum_required (VERSION 2.6)
project (DOMINO_DEMO)

set ( PROJECT_SOURCE_DIR src)
set ( DOMINO_DEMO_SOURCES 
        ${PROJECT_SOURCE_DIR}/Camera.cpp
        ${PROJECT_SOURCE_DIR}/CMesh.cpp
        ${PROJECT_SOURCE_DIR}/CSceneNode.cpp
        ${PROJECT_SOURCE_DIR}/Light.cpp
        ${PROJECT_SOURCE_DIR}/main.cpp
        ${PROJECT_SOURCE_DIR}/OFF.cpp
        ${PROJECT_SOURCE_DIR}/Test1.cpp
    )

include_directories(./include ../include)
FIND_LIBRARY(DOMINO_LIB NAMES domino PATHS /home/adrian/work/domino-physics/)

add_executable(demo ${DOMINO_DEMO_SOURCES})
TARGET_LINK_LIBRARIES(demo ${DOMINO_LIB})
TARGET_LINK_LIBRARIES(demo GL)
TARGET_LINK_LIBRARIES(demo GLEW)
TARGET_LINK_LIBRARIES(demo glut)
TARGET_LINK_LIBRARIES(demo GLU)
