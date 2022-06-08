#ifndef DRAWER_H
#define DRAWER_H

/**
 * @file    drawer.h
 * @author  Vladislav Kurshakov
 * @brief   Declaration of a draw callback used in freeglut.
 * @version 0.1
 * @date    2022-05-17
 * 
 */

#include <GL/gl.h>
#include <GL/freeglut.h>

#include "tree.h"
#include "ball.h"
#include "score.h"
#include "menus.h"


//! @brief The main render callback, used to pass into glutDisplayFunc
void
draw_callback();


void
draw_game();


void
draw_entry_menu();


void
draw_end_game();


#endif // DRAWER_H