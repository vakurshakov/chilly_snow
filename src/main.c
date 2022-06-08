#include "glut_window.h"
#include "drawer.h"
#include "events.h"


int
main (int argc, char *argv[])
{
    initialize_window(argc, argv);

	glClearColor(0.847, 0.901, 1, 1.0);

    glutDisplayFunc(draw_callback);

    glutTimerFunc(0, handle_events, 0);

    glutMainLoop();

    return EXIT_SUCCESS;
}