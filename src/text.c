#include "text.h"


void
draw_text(text_t message)
{
    static char buffer[99999]; // ~500 chars
    int num_quads;

    num_quads = stb_easy_font_print(
        message.x, message.y, message.text,
        NULL, buffer, sizeof(buffer)
    );

    glPushMatrix();
        gluOrtho2D(ORTHO_LEFT, ORTHO_RIGHT, -ORTHO_BOTTOM, -ORTHO_TOP);

        glColor3f(message.r, message.g, message.b);  
        
        glEnableClientState(GL_VERTEX_ARRAY);
        
            glVertexPointer(2, GL_FLOAT, 16, buffer);
            glDrawArrays(GL_QUADS, 0, num_quads * 4);
    
        glDisableClientState(GL_VERTEX_ARRAY);
    glPopMatrix();
}
