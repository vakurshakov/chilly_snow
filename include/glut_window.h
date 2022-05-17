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

// Used to set orthographic projection 
#define ORTHO_LEFT              -10
#define ORTHO_RIGHT             +10
#define ORTHO_BOTTOM            -10
#define ORTHO_TOP               +10

extern int g_SCREEN_WIDTH;
extern int g_SCREEN_HEIGHT;

 
//! @brief Set up window using freeglut 
void
initialize_window(int argc, char *argv[]);


//! @brief Internal. Used to change window size and reset ortho-projection  
void
reshape_window_callback(int, int);

#endif // GLUT_WINDOW_H