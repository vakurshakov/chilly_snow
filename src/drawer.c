#include "drawer.h"


void
draw_callback()
{
    extern float ball_x;
    extern tree_t g_forest[NUMBER_OF_TREES];

    extern int intersected_tree;

	glClear(GL_COLOR_BUFFER_BIT);
	
    glLoadIdentity();

    draw_ball(ball_x);

    for(int i = 0; i < NUMBER_OF_TREES; ++i)
    {
        draw_tree(g_forest[i]);
    
    #if DEBUG
        if (i == intersected_tree)
        {
            draw_tree_collider(g_forest[i], INTERSECTING_COLOR);
        }
        else
        {
            draw_tree_collider(g_forest[i], NOT_INTERSECTING_COLOR);
        }
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
