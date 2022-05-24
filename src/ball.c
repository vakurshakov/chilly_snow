#include "ball.h"

float ball_x =          0.00f;
float ball_speed =      0.09f;


void
ball_move_callback(int key, int x, int y)
{
	extern float ball_x;

	if(key == GLUT_KEY_LEFT)
	{
		ball_x -= ball_speed;
	}
	else if(key == GLUT_KEY_RIGHT)
	{
		ball_x += ball_speed;
	}
}


void
draw_ball(float ball_x)
{
    extern int g_SCREEN_WIDTH;
    extern int g_SCREEN_HEIGHT;

    // X-coordinates multiplied by 1. / aspect, so circle keeps its shape
    float aspect = (float) g_SCREEN_WIDTH / g_SCREEN_HEIGHT;

    static double PI;
    PI = 4.0 * atan(1.0);

    // Circle is drawn as a set of vertices
	glBegin(GL_POLYGON);

        for(double phi = 0; phi <= 2. * PI; phi += 0.01)
	    {
            // Making a shadow with changing red component
            glColor3f((1. - (phi - 2.) / (2. * PI)), BALL_COLOR_GB);

            glVertex2f(
                ball_x + BALL_RADIUS / aspect * cos(phi),
                BALL_Y + BALL_RADIUS * sin(phi)
            );
	    }

	glEnd();
}