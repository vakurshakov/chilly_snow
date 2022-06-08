#include "menus.h"


button_t entry_menu_buttons[ENTRY_MENU_BUTTONS_NUMBER] = {
    {
        -3.0f, 1.0f,  +3.0f, 1.0f,  +3.0f, 2.5f,  -3.0f, 2.5f,  // vertices
        0.547f, 0.601f, 1.0f,   // button color
        {   // text_t struct
            -25.0f, -22.0f,
            "New game",
            0.747f, 0.901f, 1.0f    
        }
    },
    {
        -1.5f, -1.0f,  +1.5f, -1.0f,  +1.5f, -2.5f,  -1.5f, -2.5f,  // vertices
        0.547f, 0.601f, 1.0f,   // button color
        {   // text_t struct
            -10.5f, +14.0f,
            "Quit",
            0.747f, 0.901f, 1.0f    
        }
    }
};
int hovered_entry_menu_button = 0;


button_t end_game_buttons[END_GAME_BUTTONS_NUMBER] = {
    {
        -2.5f, 1.0f,  +2.5f, 1.0f,  +2.5f, 2.5f,  -2.5f, 2.5f,  // vertices
        0.547f, 0.601f, 1.0f,   // button color
        {   // text_t struct
            -19.0f, -22.0f,
            "Restart",
            0.747f, 0.901f, 1.0f    
        }
    },
    {
        -1.5f, -1.0f,  +1.5f, -1.0f,  +1.5f, -2.5f,  -1.5f, -2.5f,  // vertices
        0.547f, 0.601f, 1.0f,   // button color
        {   // text_t struct
            -10.5f, +14.0f,
            "Quit",
            0.747f, 0.901f, 1.0f    
        }
    }
};
int hovered_end_game_button = 0;


void
draw_rect_primitive(unsigned int mode, button_t button)
{
    glBegin((GLenum)mode);

        glColor3f(button.r, button.g, button.b);

        glVertex2f(button.vertices[0], button.vertices[1]);
        glVertex2f(button.vertices[2], button.vertices[3]);
        glVertex2f(button.vertices[4], button.vertices[5]);
        glVertex2f(button.vertices[6], button.vertices[7]);

    glEnd();    
}


void
draw_button(button_t button)
{
    draw_rect_primitive(GL_QUADS, button);
}


void
draw_hovered_button(button_t button)
{
    draw_button(button);

    button.r *= 0.5;
    button.g *= 0.5;
    button.b *= 0.5;
    
    //! @todo Apply line width locally.
    glLineWidth(3.0f);
    draw_rect_primitive(GL_LINE_LOOP, button);   
}


void
draw_menu(button_t *buttons, int number_of_buttons, int hovered_button)
{
    if (buttons == NULL) return; // Causes error

    for (int i = 0; i < number_of_buttons; ++i)
    {
        if (i == hovered_button)
        {
            draw_hovered_button(buttons[i]);
        }
        else
        {
            draw_button(buttons[i]);
        }

        draw_text(buttons[i].message);
    }
}


void
chose_menu_button_on_key(int number_of_buttons, int *hovered_button)
{
    //! @todo Key repeat event handling
    // De-buffering pressed key
    static char DOWN_PRESSED    = 0;
    static char UP_PRESSED      = 0;

    if (key_states[GLUT_KEY_DOWN] == KEY_PRESSED && DOWN_PRESSED == 0)
    {
        DOWN_PRESSED = 1;

        *hovered_button += 1;
        *hovered_button %= number_of_buttons;
    }
    else if (key_states[GLUT_KEY_DOWN] == KEY_NOT_PRESSED)
    {
        DOWN_PRESSED = 0;
    }


    if (key_states[GLUT_KEY_UP] == KEY_PRESSED && UP_PRESSED == 0)
    {
        UP_PRESSED = 1;

        *hovered_button -= 1;

        if (*hovered_button < 0)
            *hovered_button = number_of_buttons - 1;
    }
    else if (key_states[GLUT_KEY_UP] == KEY_NOT_PRESSED)
    {
        UP_PRESSED = 0;
    }
}


char*
check_button_pressed(button_t *buttons, int hovered_button)
{
    if (buttons == NULL) return;    // Causes error

    if (key_states[GLUT_KEY_ENTER] == KEY_PRESSED)
    {
        return buttons[hovered_button].message.text;
    }
    else
    {
        return NULL;
    }
}