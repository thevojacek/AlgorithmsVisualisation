#ifndef ALGORITHMSVISUALISATION_MESSAGE_H
#define ALGORITHMSVISUALISATION_MESSAGE_H

#include <raylib.h>
#include <string>
#include <cmath>
#include "./boundaries.h"
#include "../../utils/vector_i.h"

using types::Vector2i;
using std::string;

static const auto mbg_color = RED;
static const auto mtext_color = WHITE;
static const int mfont_size = 12;
// Character width for default font is approximately 58% of the font size, truncated to nearest integer
static const int mcharacter_width = (int)std::round(mfont_size * 0.58f);

namespace components {
    class Message {
    public:
        Vector2i position {0, 0};
        Vector2i dimensions {0, 30};
        Vector2i text_position {0, 0};
        Boundaries boundaries {0, 0, 0, 0};
        string text;

    private:
        int text_width = 0;

    public:
        Message(Vector2i position, Vector2i dimensions, string text) {
            this->position = position;
            this->dimensions = dimensions;
            this->text = std::move(text);
            this->compute_sizes(); // Compute size properties
        }

    public:
        void draw() const;

    private:
        void compute_sizes();
    };
}


#endif //ALGORITHMSVISUALISATION_MESSAGE_H
