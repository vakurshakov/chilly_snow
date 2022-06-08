#ifndef SCORE_H
#define SCORE_H

/**
 * @file    score.h
 * @author  Vladislav Kurshakov
 * @brief   Score calculation and drawing.
 * @version 0.1
 * @date    2022-05-30
 * 
 */

#include <stdio.h>  // for sprintf

#include "ball.h"   // score calculated from ball_speed
#include "text.h"


//! @note Uses initial ball_speed and BALL_SPEED_ADD
int
calculate_score();


void
draw_score();


#endif // SCORE_H