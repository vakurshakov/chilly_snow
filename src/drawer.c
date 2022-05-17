#include "drawer.h"

void
draw_callback()
{
	glClear(GL_COLOR_BUFFER_BIT);
	
    glutSwapBuffers();
}