#include "score.h"


static text_t score = {
    .y = -70,
    .r = 0.447f,
    .g = 0.501f,
    .b = 1.0f,
};


int
calculate_score()
{
    extern float ball_speed;
    int result = (int) ((ball_speed - 0.09f) / (30.0f * BALL_SPEED_ADD));

    return result;
}


void
draw_score()
{
    int result = calculate_score();
    
    static char score_text[500];
    sprintf(score_text, "%d", result);
    score.text = score_text;

    float width = stb_easy_font_width(score.text);

    score.x = - width / 2.;

    draw_text(score);
}