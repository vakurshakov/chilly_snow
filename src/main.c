#include "glut_window.h"
#include "drawer.h"


int
main (int argc, char** argv)
{
    initialize_window(argc, argv);

    initialize_forest(0);

	glClearColor(0.847, 0.901, 1, 1.0);

    glutReshapeFunc(reshape_window_callback);

    glutDisplayFunc(draw_callback);

    glutTimerFunc(0, draw_timer_callback, 0);

    glutSpecialFunc(ball_move_callback);

    glutMainLoop();

    return EXIT_SUCCESS;
}