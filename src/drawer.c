#include "drawer.h"


void
draw_callback()
{
    extern float ball_x;
    extern tree_t g_forest[NUMBER_OF_TREES];

	glClear(GL_COLOR_BUFFER_BIT);
	
    glLoadIdentity();

    draw_ball(ball_x);

    for(int i = 0; i < NUMBER_OF_TREES; ++i)
    {
        draw_tree(g_forest[i]);
    
    #if DEBUG
        draw_tree_collider(g_forest[i]);
    #endif
    }

    glutSwapBuffers();
}


void
draw_timer_callback(int value)
{
    glutPostRedisplay();    // Redraw everything on window
    glutTimerFunc(1000 / FPS, draw_timer_callback, 0);   // Set up next timer 
}
