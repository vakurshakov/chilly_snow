#ifndef MENUS_H
#define MENUS_H

/**
 * @file    menus.h
 * @author  Vladislav Kurshakov
 * @brief   Menu interface and presets.
 * @version 0.1
 * @date    2022-06-06
 * 
 */

#include <string.h> // for strcmp

#include "glut_window.h"    // for key_states, KEY_%PRESSED
#include "text.h"


typedef struct button_t
{
    float vertices[8];  // Button rectangle 
    float r, g, b;      // Button color
    text_t message;     // Button's text 
} button_t;


// Buttons presets
#define ENTRY_MENU_BUTTONS_NUMBER      2  
#define END_GAME_BUTTONS_NUMBER        2

extern button_t entry_menu_buttons[ENTRY_MENU_BUTTONS_NUMBER];
extern int hovered_entry_menu_button;

extern button_t end_game_buttons[END_GAME_BUTTONS_NUMBER];
extern int hovered_end_game_button;


#define GLUT_KEY_ENTER  13


void
draw_menu(button_t *buttons, int number_of_buttons, int hovered_button);


void
draw_button(button_t button);


void
draw_hovered_button(button_t button);


void
chose_menu_button_on_key(int number_of_buttons, int *hovered_button);


//! @return button's text if %_ENTER pressed, NULL otherwise
char*
check_button_pressed(button_t *buttons, int hovered_button);


#endif // MENUS_H