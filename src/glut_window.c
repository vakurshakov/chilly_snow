#include "glut_window.h"

int g_SCREEN_WIDTH =      800;
int g_SCREEN_HEIGHT =     600;


void
initialize_window(int argc, char *argv[])
{
    extern int g_SCREEN_WIDTH;
    extern int g_SCREEN_HEIGHT;

    glutInit(&argc,argv);
	
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowPosition(SCREEN_INITPOINT_X, SCREEN_INITPOINT_Y);
	glutInitWindowSize(g_SCREEN_WIDTH, g_SCREEN_HEIGHT);
	
    glutCreateWindow("chilly snow");
}


void
reshape_window_callback(int new_width, int new_height)
{
    extern int g_SCREEN_WIDTH;
    extern int g_SCREEN_HEIGHT;

    g_SCREEN_WIDTH = new_width;
    g_SCREEN_HEIGHT = new_height;

    // Set viewport to the new one
    glViewport(0, 0, new_width, new_height);
	
    // Set orthographic projection to ours
    glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
    gluOrtho2D(ORTHO_LEFT, ORTHO_RIGHT, ORTHO_BOTTOM, ORTHO_TOP);
	
    // Reset matrix mode to default
    glMatrixMode(GL_MODELVIEW);
}