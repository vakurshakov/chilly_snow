#include "events.h"


void
handle_events(int value)
{
    extern game_state_t g_game_state;
    static int game_initialized = 0;
    
    if (g_game_state == GAME) 
    {
        if (game_initialized == 0)
        {
            extern float ball_x;
            extern float ball_speed;
    
            ball_x = 0;
            ball_speed = 0.09f;
            initialize_forest(time(NULL));
            glutTimerFunc(0, world_update, 0);
            
            game_initialized = 1;
        }
    }
    else if (g_game_state == ENTRY)
    {
        extern button_t entry_menu_buttons[ENTRY_MENU_BUTTONS_NUMBER];
        extern int hovered_entry_menu_button;

        chose_menu_button_on_key(ENTRY_MENU_BUTTONS_NUMBER, &hovered_entry_menu_button);
        char* check_result = check_button_pressed(entry_menu_buttons, hovered_entry_menu_button);
        handle_button_pressed(check_result);
    }
    else if (g_game_state == END)
    {
        game_initialized = 0;

        extern button_t end_game_buttons[END_GAME_BUTTONS_NUMBER];
        extern int hovered_end_game_button;

        chose_menu_button_on_key(END_GAME_BUTTONS_NUMBER, &hovered_end_game_button);
        char* check_result = check_button_pressed(end_game_buttons, hovered_end_game_button);
        handle_button_pressed(check_result);
    }

    glutPostRedisplay();    // redraw "event"

    glutTimerFunc(1000 / FPS, handle_events, 0);   // Set up next timer
}


void
handle_button_pressed(char* button_text)
{
    if (button_text == NULL) return;

    extern game_state_t g_game_state;

    if (strcmp(button_text, "New game") == 0 ||
        strcmp(button_text, "Restart")  == 0)
    {
        g_game_state = GAME;
    }
    else if (strcmp(button_text, "Quit") == 0)
    {
        exit(EXIT_SUCCESS);
    }
}