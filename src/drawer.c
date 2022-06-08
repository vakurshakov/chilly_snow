#include "drawer.h"


void
draw_callback()
{
	glClear(GL_COLOR_BUFFER_BIT);
 
    if (g_game_state == GAME)
    {
        draw_game();
    }
    else if (g_game_state == ENTRY)
    {
        draw_entry_menu();
    }
    else if (g_game_state == END)
    {
        draw_end_game();
    }

    glutSwapBuffers();
}


void
draw_game()
{
    extern float ball_x;
    extern tree_t g_forest[NUMBER_OF_TREES];

    extern int intersected_tree;
	
    glLoadIdentity();

    draw_ball(ball_x);

    for(int i = 0; i < NUMBER_OF_TREES; ++i)
    {
        draw_tree(g_forest[i]);
    
    #if DEBUG
        if (i == intersected_tree)
        {
            draw_tree_collider(g_forest[i], INTERSECTING_COLOR);
        }
        else
        {
            draw_tree_collider(g_forest[i], NOT_INTERSECTING_COLOR);
        }
    #endif
    }

    draw_score();
}


void
draw_entry_menu()
{
    extern button_t entry_menu_buttons[];
    extern int hovered_entry_menu_button;

    static text_t name = {
        -33.5f, -60.0f,
        "CHILLY SNOW",
        0.447f, 0.501f, 1.0f
    };
    draw_text(name);

    draw_menu(entry_menu_buttons, ENTRY_MENU_BUTTONS_NUMBER, hovered_entry_menu_button);
}


void
draw_end_game()
{
    extern button_t end_game_buttons[];
    extern int hovered_end_game_button;

    static text_t name = {
        -63.5f, -60.0f,
        "Game over, once more?",
        0.447f, 0.501f, 1.0f
    };
    draw_text(name);

    draw_menu(end_game_buttons, END_GAME_BUTTONS_NUMBER, hovered_end_game_button);
}