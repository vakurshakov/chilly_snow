#ifndef GLUT_WINDOW_H
#define GLUT_WINDOW_H

/**
 * @file    glut_window.h
 * 
 * @author  Vladislav Kurshakov
 * @brief   This header file provides a description for a freeglut window.  
 * @version 0.1
 * @date    2022-05-17
 *
 */

#include <GL/freeglut.h>

#define SCREEN_INITPOINT_X      200
#define SCREEN_INITPOINT_Y      100

// Used to set orthographic projection 
#define ORTHO_LEFT              -10
#define ORTHO_RIGHT             +10
#define ORTHO_BOTTOM            -10
#define ORTHO_TOP               +10

#define FPS                     60

extern int g_SCREEN_WIDTH;
extern int g_SCREEN_HEIGHT;

#define KEY_PRESSED             1
#define KEY_NOT_PRESSED         0

extern unsigned char key_states[256];    // Key buffer

typedef enum game_state_t
{
    GAME=0,
    ENTRY,
    END,
} game_state_t;

extern game_state_t g_game_state;


//! @brief Set up window using freeglut 
void
initialize_window(int argc, char *argv[]);


//! @brief Internal. Used to change window size and reset ortho-projection  
void
reshape_window_callback(int, int);


//! @brief Internal. Used to handle key pressed events
void
key_pressed_callback(int key, int mouse_x, int mouse_y);


//! @brief Internal. Used to handle key released events
void
key_released_callback(int key, int mouse_x, int mouse_y);


#endif // GLUT_WINDOW_H