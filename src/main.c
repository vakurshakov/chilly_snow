#include "glut_window.h"
#include "physics.h"
#include "drawer.h"


int
main (int argc, char *argv[])
{
    initialize_window(argc, argv);

    initialize_forest(0);

	glClearColor(0.847, 0.901, 1, 1.0);

    glutDisplayFunc(draw_callback);

    glutTimerFunc(0, draw_timer_callback, 0);

    glutTimerFunc(0, physics_timer_callback, 0);

    glutMainLoop();

    return EXIT_SUCCESS;
}