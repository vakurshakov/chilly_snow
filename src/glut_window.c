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