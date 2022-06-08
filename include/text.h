#ifndef TEXT_H
#define TEXT_H

/**
 * @file    text.h
 * @author  Vladislav Kurshakov
 * @brief   Text structure and rendering routine.
 * @version 0.1
 * @date    2022-06-07
 * 
 */

#include <stb_easy_font.h>

#include "glut_window.h"    // for ORTHO_%


typedef struct text_t
{
    float x, y;     // Text position
    char *text;     // Text string
    float r, g, b;  // Text color
} text_t;


void
draw_text(text_t message);


#endif // TEXT_H