#ifndef TREE_H
#define TREE_H

/**
 * @file    tree.h
 * @author  Vladislav Kurshakov
 * @brief  	Declaration of the tree structure, functionality to
 * 			plant the tree and initialize forest, draw tree and
 * 			their collider. 
 * @version 0.1
 * @date    2022-05-17
 * 
 */

#include <stdlib.h>      // for rand()
#include "time.h"        // to provide a seed (if needed) 

#include "glut_window.h" // for ORTHO_% and g_SCREEN_%

 
typedef struct tree_t
{
	float x;        // X-coordinate of the tree top 
	float y;        // Y-coordinate of the tree top
	float size;     // Size of the tree
} tree_t;

#define NUMBER_OF_TREES     20
#define MINIMUM_TREE_SIZE   0.2f
#define MAXIMUM_TREE_SIZE   0.3f

extern tree_t g_forest[NUMBER_OF_TREES];

// Tree geometry and colors
#define TRUNK_WIDTH      0.2f
#define TRUNK_HEIGHT     0.6f

#define TREE_WIDTH1      1.2f	// width of the first tree crown   
#define TREE_WIDTH2      0.1f	// width of the middle part
#define TREE_WIDTH3      1.9f	// width of the second crown
#define TREE_HEIGHT1     2.0f	// height of the first crown
#define TREE_HEIGHT2     7.0f	// height of the whole tree

#define TRUNK_COLOR      0.407f, 0.133f, 0.011f    
#define CROWN_COLOR1     0.258f, 0.603f, 0.345f		// light green color
#define CROWN_COLOR2     0.133f, 0.545f, 0.133f		// "shadowed" green

#define COLLIDER_SIZE_REDUCTION 1.09f

// Collision detection
#define INTERSECTING_COLOR 		1.0f, 1.0f, 0.0f
#define NOT_INTERSECTING_COLOR	1.0f, 0.0f, 0.0f

extern int intersected_tree;


/**
 * @brief Initializes the tree. X-coordinate and size choosen
 *		randomly, using ORTHO_% and %_TREE_SIZE
 * 
 * @param y_pos_min minimum of random Y-coordinate 
 * @param y_pos_max maximum of random Y-coordinate
 */
void
plant_tree(tree_t *tree, float y_pos_min, float y_pos_max);


//! @brief Initializes g_forest using random numbers with a given seed
void
initialize_forest(unsigned int seed);


//! @note Uses g_SCREEN_%
void
draw_tree(tree_t tree);


//! @note Uses g_SCREEN_%
void
draw_tree_collider(tree_t tree, float r, float g, float b);


#endif // TREE_H