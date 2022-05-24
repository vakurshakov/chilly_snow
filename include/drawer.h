#ifndef DRAWER_H
#define DRAWER_H

/**
 * @file    drawer.h
 * @author  Vladislav Kurshakov
 * @brief   This header file provides declaration for a drawing    
 *          callback used in freeglut.
 * @version 0.1
 * @date    2022-05-17
 * 
 */

#include <GL/gl.h>
#include <GL/freeglut.h>

#include "tree.h"
#include "glut_window.h" // for g_SCREEN_%


//! @brief The main render callback, used to pass into glutDisplayFunc
void
draw_callback();


#endif // DRAWER_H