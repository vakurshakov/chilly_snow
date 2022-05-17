#ifndef DRAWER_H
#define DRAWER_H

/**
 * @file    drawer.h
 * @author  Vladislav Kurshakov
 * @brief   This header file provides declaration for a drawing    
 *          callback used in freeglut and for internal draw_% calls.
 * @version 0.1
 * @date    2022-05-17
 * 
 */

#include <GL/gl.h>
#include <GL/freeglut.h>


//! @brief The main render callback, used to pass into glutDisplayFunc
void
draw_callback();


#endif // DRAWER_H