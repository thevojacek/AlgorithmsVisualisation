#include "button.h"

void components::Button::draw() const {
    DrawRectangle(
        position.x,
        position.y,
        dimensions.x,
        dimensions.y,
        bg_color
    );

    DrawText(
        text.c_str(),
        text_position.x,
        text_position.y,
        font_size,
        text_color
    );
}

void components::Button::compute_sizes() {
    text_width = (int)(character_width * text.length());
    dimensions.x = text_width + 12; // Margin 5 from both sides
    // +3 accounts for last character having no-margin due to non-existance of another letter
    text_position.x = (((position.x + dimensions.x) - (dimensions.x / 2)) - (text_width / 2)) + 3;
    text_position.y = ((position.y + dimensions.y) - (dimensions.y / 2)) - (font_size / 2);
}
