#include "message.h"

void components::Message::draw() const {
    DrawRectangle(
            position.x,
            position.y,
            dimensions.x,
            dimensions.y,
            mbg_color
    );

    DrawText(
            text.c_str(),
            text_position.x,
            text_position.y,
            mfont_size,
            mtext_color
    );
}

void components::Message::compute_sizes() {
    text_width = (int)(mcharacter_width * text.length());
    // +3 accounts for last character having no-margin due to non-existence of next letter
    text_position.x = (((position.x + dimensions.x) - (dimensions.x / 2)) - (text_width / 2)) + 3;
    text_position.y = ((position.y + dimensions.y) - (dimensions.y / 2)) - (mfont_size / 2);
    boundaries = Boundaries {position.x, dimensions.x, position.y, dimensions.y};
}
