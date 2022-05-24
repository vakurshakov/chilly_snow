#include "drawer.h"


void
draw_callback()
{
    extern tree_t g_forest[NUMBER_OF_TREES];

	glClear(GL_COLOR_BUFFER_BIT);
	
    glLoadIdentity();

    for(int i = 0; i < NUMBER_OF_TREES; ++i)
    {
        draw_tree(g_forest[i]);
    
    #if DEBUG
        draw_tree_collider(g_forest[i]);
    #endif
    }

    glutSwapBuffers();
}


