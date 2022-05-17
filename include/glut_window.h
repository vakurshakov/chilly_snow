#ifndef GLUT_WINDOW_H
#define GLUT_WINDOW_H

/**
 * @file    glut_window.h
 * 
 * @author  Vladislav Kurshakov
 * @brief   This header file provides a description for a freeglut window.  
 * @version 0.1
 * @date    2022-05-17
 *
 */

#include <GL/freeglut.h>

#define SCREEN_INITPOINT_X      200
#define SCREEN_INITPOINT_Y      100

extern int g_SCREEN_WIDTH;
extern int g_SCREEN_HEIGHT;

 
//! @brief Set up window using freeglut 
void
initialize_window(int argc, char *argv[]);


#endif // GLUT_WINDOW_H