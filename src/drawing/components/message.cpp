#include "message.h"

void components::Message::draw() const {
    DrawRectangle(
        position.x,
        position.y,
        dimensions.x,
        dimensions.y,
        RED
    );

    DrawText(
        text.c_str(),
        text_position.x,
        text_position.y,
        font_size,
        WHITE
    );
}

void components::Message::compute_sizes() {
    text_width = Component::compute_text_width(text.length());
    // +3 accounts for last character having no-margin due to non-existence of next letter
    text_position.x = (((position.x + dimensions.x) - (dimensions.x / 2)) - (text_width / 2)) + 3;
    text_position.y = ((position.y + dimensions.y) - (dimensions.y / 2)) - (font_size / 2);
}
