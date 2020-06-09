#include "button.h"

static const auto bg_color = GRAY;
static const auto text_color = WHITE;
static const int font_size = 12;
static const int character_width = (font_size / 4);

void components::draw_button(Vector2i position, Vector2i dimensions, const string& text) {
    // TODO solve callback?
    const int text_width = (int)(character_width * text.length());
    const int text_x = ((position.x + dimensions.x) - (dimensions.x / 2)) - text_width;
    const int text_y = ((position.y + dimensions.y) - (dimensions.y / 2)) - 6;
    DrawRectangle(position.x, position.y, dimensions.x, dimensions.y, bg_color);
    DrawText(text.c_str(), text_x, text_y, font_size, text_color);
}
