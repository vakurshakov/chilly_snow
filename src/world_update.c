#include "world_update.h"


void
world_update(int value)
{
    move_ball();

    extern float ball_speed;

    extern tree_t g_forest[NUMBER_OF_TREES];
    extern int intersected_tree;
    
    for (int i = 0; i < NUMBER_OF_TREES; ++i)
    {
		g_forest[i].y += ball_speed;
        
        intersection_state state = check_ball_tree_collision(g_forest[i]);

    #ifdef DEBUG
        if (state == INTERSECTING) intersected_tree = i;
    #else
        if (state == INTERSECTING) g_game_state = END;
    #endif

        //! @todo: move tree-planting outside
        if (g_forest[i].y - (TREE_HEIGHT2 + TRUNK_HEIGHT) * g_forest[i].size > ORTHO_TOP)
        {
            plant_tree(&g_forest[i], (float) 2. * ORTHO_BOTTOM, (float)ORTHO_BOTTOM);

            if (i == intersected_tree) intersected_tree = -1;
        }
	}

	ball_speed += BALL_SPEED_ADD;
    
    extern game_state_t g_game_state;
    if (g_game_state == GAME)
    {
        glutTimerFunc(1000 / FPS, world_update, 0);   // Set up next timer
    }
}