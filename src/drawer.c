#include "drawer.h"

void
draw_callback()
{
    extern tree_t g_forest[NUMBER_OF_TREES];

	glClear(GL_COLOR_BUFFER_BIT);
	
    glLoadIdentity();

    for(int i = 0; i < NUMBER_OF_TREES; ++i)
    {
        draw_tree(g_forest[i]);
    }

    glutSwapBuffers();
}


// Constants to draw the tree
static float trunk_width  =     0.2f;
static float trunk_height =     0.6f;
 
static float tree_width1  =     1.2f;   // width of the first tree crown   
static float tree_width2  =     0.1f;   // width of the middle part
static float tree_width3  =     1.9f;   // width of the second crown
static float tree_height1 =     2.0f;   // height of the first crown
static float tree_height2 =     7.0f;   // height of the whole tree


void
draw_tree(tree_t tree)
{
    extern int g_SCREEN_WIDTH;
    extern int g_SCREEN_HEIGHT;

    // X-coordinates multiplied by the aspect, so that forest is always on the screen.
    float aspect = (float) g_SCREEN_WIDTH / g_SCREEN_HEIGHT;

    float x = tree.x;
    float y = tree.y;
    float s = tree.size;

    // Draws tree trunk. Draw calls separated to avoid color mixing
    glBegin(GL_POLYGON);

		glColor3f(0.407, 0.133, 0.011);
		glVertex2f((x - trunk_width * s) * aspect, y - (tree_height2 + 0.0         ) * s);
		glVertex2f((x - trunk_width * s) * aspect, y - (tree_height2 + trunk_height) * s);
		glVertex2f((x + trunk_width * s) * aspect, y - (tree_height2 + trunk_height) * s);
		glVertex2f((x + trunk_width * s) * aspect, y - (tree_height2 + 0.0         ) * s);

    glEnd();

    // Draw the rest of the tree. It's drawn counter clockwise
	glBegin(GL_POLYGON);

        // Left side
		glColor3f(0.258, 0.603, 0.345);
		glVertex2f(x * aspect, y);
		glVertex2f((x - tree_width1 * s) * aspect, y - tree_height1 * s);
		glVertex2f((x - tree_width2 * s) * aspect, y - tree_height1 * s);
		glVertex2f((x - tree_width3 * s) * aspect, y - tree_height2 * s);
		
        // Right side. Here we use internal color mixing to make "shadow"
		glColor3f(0.133, 0.545, 0.133);
		glVertex2f((x + tree_width3 * s) * aspect, y - tree_height2 * s);
		glVertex2f((x + tree_width2 * s) * aspect, y - tree_height1 * s);
		glVertex2f((x + tree_width1 * s) * aspect, y - tree_height1 * s);
		glVertex2f(x * aspect, y);

	glEnd();

}