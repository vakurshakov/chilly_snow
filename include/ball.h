#ifndef BALL_H
#define BALL_H

/**
 * @file    ball.h
 * @author  Vladislav Kurshakov
 * @brief   Ball information, move callback and draw call. 
 * @version 0.1
 * @date    2022-05-25
 * 
 */

#include <math.h>
#include "glut_window.h" // for g_SCREEN_%


// Physics constants
#define BALL_Y              2.0f
#define BALL_RADIUS         0.5f
#define BALL_SPEED_ADD      1e-6f
#define BALL_MOVE_MODIFIER  0.6f

// Graphics constants
#define BALL_COLOR_GB   0.113f, 0.027f 

extern float ball_x;
extern float ball_speed;


//! @brief Carries ball x-coordinate update 
void
move_ball();


//! @note Uses g_SCREEN_%
void
draw_ball(float ball_x);


#endif // BALL_H