#ifndef ALGORITHMSVISUALISATION_BUTTON_H
#define ALGORITHMSVISUALISATION_BUTTON_H

#include <raylib.h>
#include <string>
#include <utility>
#include <cmath>
#include "../../utils/vector_i.h"

using types::Vector2i;
using std::string;

static const auto bg_color = GRAY;
static const auto text_color = WHITE;
static const int font_size = 12;
// Character width for default font is approximately 58% of the font size, truncated to nearest integer
static const int character_width = (int)std::round(font_size * 0.58f);

namespace components {
    class Button {
    public:
        Vector2i position {0, 0};
        Vector2i dimensions {0, 30};
        Vector2i text_position {0, 0};
        string text;

    private:
        int text_width = 0;

    public:
        // TODO layout system is needed to compute margins between buttons!
        // TODO solve click callback
        Button(Vector2i position, string text) {
            this->position = position;
            this->text = std::move(text);
            // Compute size properties
            this->compute_sizes();
        }

    public:
        // TODO in RayGui library -> render will be performed by layout system :)
        void draw() const;

    private:
        void compute_sizes();
    };
};

#endif //ALGORITHMSVISUALISATION_BUTTON_H
