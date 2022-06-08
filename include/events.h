#ifndef EVENTS_H
#define EVENTS_H

/**
 * @file    events.h
 * @author  Vladislav Kurshakov
 * @brief   Event handling through glutTimerFunc.
 * @version 0.1
 * @date    2022-06-07
 * 
 */

#include "glut_window.h"    // for g_game_state
#include "world_update.h"
#include "menus.h"  // for menus presets


//! @brief Event handler, pass it into glutTimerFunc  
void
handle_events(int value);


/**
 * @brief Changes game state according to incoming button
 * @note Uses concrete button texts
 * 
 * @param button_text whether NULL or button's text
 */
void
handle_button_pressed(char* button_text);


#endif // EVENTS_H