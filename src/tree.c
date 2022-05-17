#include "tree.h"

tree_t g_forest[NUMBER_OF_TREES];


float
float_rand(float min, float max)
{
    float scale = (float)rand() / RAND_MAX;
    return min + scale * (max - min);
}


tree_t
plant_tree(float y_pos)
{
    tree_t tree;

    tree.size = float_rand(MINIMUM_TREE_SIZE, MAXIMUM_TREE_SIZE);
	tree.x    = float_rand((float)ORTHO_LEFT, (float)ORTHO_RIGHT);
	tree.y    = y_pos;

    return tree;
}


void
initialize_forest(unsigned int seed)
{
    srand(seed);

    extern tree_t g_forest[NUMBER_OF_TREES];
    
    for (int i = 0; i < NUMBER_OF_TREES; ++i)
    {
        // Let opengl draw tree below the window border
        float y_pos = float_rand((float)ORTHO_BOTTOM, (float)ORTHO_TOP);

	    g_forest[i] = plant_tree(y_pos);
    }
}