cmake_minimum_required(VERSION 2.8.12)

project(chilly_snow)

find_package(OpenGL REQUIRED)

add_executable(${PROJECT_NAME}
    src/world_update.c
    src/glut_window.c
    src/collision.c
    src/drawer.c
    src/events.c
    src/menus.c
    src/score.c
    src/text.c
    src/ball.c
    src/tree.c
    src/main.c
)

# add_compile_definitions(DEBUG) # Game wouldn't stop (collision detection)
 
add_subdirectory(external/FreeGLUT)

target_include_directories(${PROJECT_NAME}
    PUBLIC include
    PUBLIC external/FreeGLUT/include
    PUBLIC external/stb
    PUBLIC ${OPENGL_INCLUDE_DIRS}
)

target_link_directories(${PROJECT_NAME}
    PRIVATE external/FreeGLUT/lib
)

target_link_libraries(${PROJECT_NAME}
    glut
    GLU
    m
    ${OPENGL_LIBRARY}
)