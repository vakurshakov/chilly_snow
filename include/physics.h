#ifndef PHYSICS_H
#define PHYSICS_H

/**
 * @file    physics.h
 * 
 * @author  Vladislav Kurshakov
 * @brief   Physics world update and collision detection.  
 * @version 0.1
 * @date    2022-05-26
 *
 */

#include "tree.h"
#include "ball.h"
#include "glut_window.h" // for FPS and ORTHO_%


#define SIGN(x) (((x) < 0) ? 0 : 1)


typedef struct vector2
{
    float x;
    float y;
} vector2;

typedef enum bool
{
    FALSE=0,
    TRUE,
} bool;

typedef enum intersection_state
{
    NOT_INTERSECTING=0,
    INTERSECTING,
} intersection_state;


extern intersection_state g_state;


//! @brief Carries physics update
void
physics_timer_callback(int value);


//! @brief Simplified collision detection
intersection_state
check_ball_tree_collision(tree_t tree);


//! @brief z-component of cross product AB by PQ
float
cross2d_product(vector2 a, vector2 b, vector2 p, vector2 q);


//! @brief checks AB, PQ intersection via cross2d_products
intersection_state
check_segments_intersection(float ab_ap, float ab_aq, float pq_pa, float pq_pb);


//! @brief whether P or Q lies in triangle ABC
bool
find_inner(float ab_ap, float ab_aq, float ab_ac, int *inner_count);


//! @brief whether segment PQ intersect triangle ABC
intersection_state
check_segment_triangle_intersection(vector2 p, vector2 q, vector2 a, vector2 b, vector2 c);


#endif // PHYSICS_H