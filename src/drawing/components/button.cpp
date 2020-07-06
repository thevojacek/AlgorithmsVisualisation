#include "button.h"

#include <utility>

void components::Button::draw() const {
    DrawRectangle(
        position.x,
        position.y,
        dimensions.x,
        dimensions.y,
        GRAY
    );

    DrawText(
        text.c_str(),
        text_position.x,
        text_position.y,
        font_size,
        WHITE
    );
}

void components::Button::compute_sizes() {
    text_width = Component::compute_text_width(text.length());
    dimensions.x = text_width + 12; // Margin 5 from both sides
    int max_x = position.x + dimensions.x;
    int max_y = position.y + dimensions.y;
    // +3 accounts for last character having no-margin due to non-existence of next letter
    text_position.x = ((max_x - (dimensions.x / 2)) - (text_width / 2)) + 3;
    text_position.y = (max_y - (dimensions.y / 2)) - (font_size / 2);
    boundaries = Boundaries {position.x, max_x, position.y, max_y};
}

void components::Button::register_callback(std::function<void(const Button &)> cb) {
    this->callback = std::move(cb);
}
