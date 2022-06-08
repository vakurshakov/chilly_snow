#include "tree.h"

tree_t g_forest[NUMBER_OF_TREES];
int intersected_tree = -1;


float
float_rand(float min, float max)
{
    float scale = (float)rand() / RAND_MAX;
    return min + scale * (max - min);
}


void
plant_tree(tree_t *tree, float y_pos_min, float y_pos_max)
{
    tree->size = float_rand(MINIMUM_TREE_SIZE, MAXIMUM_TREE_SIZE);
	tree->x    = float_rand((float)ORTHO_LEFT, (float)ORTHO_RIGHT);
	tree->y    = float_rand(y_pos_min, y_pos_max);
}


void
initialize_forest(unsigned int seed)
{
    srand(seed);

    extern tree_t g_forest[NUMBER_OF_TREES];
    
    for (int i = 0; i < NUMBER_OF_TREES; ++i)
    {
        // Let opengl draw tree below the window border
	    plant_tree(&g_forest[i], (float) 2 * ORTHO_BOTTOM, 0);
    }
}


void
draw_tree(tree_t tree)
{
    extern int g_SCREEN_WIDTH;
    extern int g_SCREEN_HEIGHT;

    // X-coordinates multiplied by the aspect, so that forest is always on the screen
    float aspect = (float) g_SCREEN_WIDTH / g_SCREEN_HEIGHT;

    float x = tree.x;
    float y = tree.y;
    float s = tree.size;

    // Draw tree trunk. Draw calls separated to avoid color mixing
    glBegin(GL_POLYGON);

		glColor3f(TRUNK_COLOR);
		glVertex2f((x - TRUNK_WIDTH * s) * aspect, y - (TREE_HEIGHT2 + 0.0         ) * s);
		glVertex2f((x - TRUNK_WIDTH * s) * aspect, y - (TREE_HEIGHT2 + TRUNK_HEIGHT) * s);
		glVertex2f((x + TRUNK_WIDTH * s) * aspect, y - (TREE_HEIGHT2 + TRUNK_HEIGHT) * s);
		glVertex2f((x + TRUNK_WIDTH * s) * aspect, y - (TREE_HEIGHT2 + 0.0         ) * s);

    glEnd();

    // Draw the rest of the tree. It's drawn counter clockwise
	glBegin(GL_POLYGON);

        // Left side
		glColor3f(CROWN_COLOR1);
		glVertex2f(x * aspect, y);
		glVertex2f((x - TREE_WIDTH1 * s) * aspect, y - TREE_HEIGHT1 * s);
		glVertex2f((x - TREE_WIDTH2 * s) * aspect, y - TREE_HEIGHT1 * s);
		glVertex2f((x - TREE_WIDTH3 * s) * aspect, y - TREE_HEIGHT2 * s);
		
        // Right side. Here internal color mixing is used to make "shadow"
		glColor3f(CROWN_COLOR2);
		glVertex2f((x + TREE_WIDTH3 * s) * aspect, y - TREE_HEIGHT2 * s);
		glVertex2f((x + TREE_WIDTH2 * s) * aspect, y - TREE_HEIGHT1 * s);
		glVertex2f((x + TREE_WIDTH1 * s) * aspect, y - TREE_HEIGHT1 * s);
		glVertex2f(x * aspect, y);

	glEnd();
}


void
draw_tree_collider(tree_t tree, float r, float g, float b)
{
    extern int g_SCREEN_WIDTH;
    extern int g_SCREEN_HEIGHT;

    // X-coordinates multiplied by the aspect, so that forest is always on the screen
    float aspect = (float) g_SCREEN_WIDTH / g_SCREEN_HEIGHT;

    float x = tree.x;
    float y = tree.y;
    float s = tree.size / COLLIDER_SIZE_REDUCTION;

    glBegin(GL_LINE_LOOP);

		glColor3f(r, g, b);

		glVertex2f(x * aspect, y - s * COLLIDER_SIZE_REDUCTION);
		glVertex2f((x - TREE_WIDTH3 * s) * aspect, y - TREE_HEIGHT2 * s);
		glVertex2f((x + TREE_WIDTH3 * s) * aspect, y - TREE_HEIGHT2 * s);

	glEnd();
}