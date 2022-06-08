#ifndef WORLD_UPDATE_H
#define WORLD_UPDATE_H

/**
 * @file    physics.h
 * 
 * @author  Vladislav Kurshakov
 * @brief   World update timer for glutTimerFunc.  
 * @version 0.1
 * @date    2022-05-26
 *
 */

#include "glut_window.h" // for FPS and ORTHO_%
#include "tree.h"
#include "ball.h"
#include "collision.h"


//! @brief Carries world update, changes game state with collision
void
world_update(int value);


#endif // WORLD_UPDATE_H