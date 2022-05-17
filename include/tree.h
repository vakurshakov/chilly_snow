#ifndef TREE_H
#define TREE_H

/**
 * @file    tree.h
 * @author  Vladislav Kurshakov
 * @brief   File contains declarations of the tree structure and a
 *          functionality to plant the tree and initialize forest. 
 * @version 0.1
 * @date    2022-05-17
 * 
 */

#include <stdlib.h>      // for rand()
#include "time.h"        // to provide a seed if needed 

#include "glut_window.h" // to use ORTHO_%


typedef struct tree_t
{
	float x;        // X-coordinate of the tree top 
	float y;        // Y-coordinate of the tree top
	float size;     // Size of the tree
} tree_t;

#define NUMBER_OF_TREES     15
#define MINIMUM_TREE_SIZE   0.2f
#define MAXIMUM_TREE_SIZE   0.3f

extern tree_t g_forest[NUMBER_OF_TREES];


/**
 * @brief Initializes the tree. X-coordinate and size choosen
 * 		randomly, using ORTHO_% and %_TREE_SIZE
 * 
 * @see window.h 
 * 
 * @param y_pos Y-coordinate of the planted tree 
 * @return tree_t
 */
tree_t
plant_tree(float y_pos);


//! @brief Initializes g_forest using random numbers with a given seed
void
initialize_forest(unsigned int seed);


#endif // TREE_H