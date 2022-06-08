#include "score.h"


static text_t score = {
    .y = -70,
    .r = 0.447f,
    .g = 0.501f,
    .b = 1.0f,
};


char*
calculate_score()
{
    extern float ball_speed;
    int score = (int) ((ball_speed - 0.09f) / (30.0f * BALL_SPEED_ADD));

    static char score_string[500];
    sprintf(score_string, "%d", score);

    return score_string;
}


void
draw_score()
{
    score.text = calculate_score();

    float width = stb_easy_font_width(score.text);

    score.x = - (float) width / 2.; 

    draw_text(score);
}