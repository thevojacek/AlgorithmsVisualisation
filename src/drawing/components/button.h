#ifndef ALGORITHMSVISUALISATION_BUTTON_H
#define ALGORITHMSVISUALISATION_BUTTON_H

#include <raylib.h>
#include <string>
#include <utility>
#include <cmath>
#include <functional>
#include "./boundaries.h"
#include "../../utils/vector_i.h"

// TODO utilise inheritance

using types::Vector2i;
using std::string;
using std::function;

static const auto bg_color = GRAY;
static const auto text_color = WHITE;
static const int font_size = 12;
// Character width for default font is approximately 58% of the font size, truncated to nearest integer
static const int character_width = (int)std::round(font_size * 0.58f);

namespace components {

    class Button {
    public:
        function<void(const Button&)> callback = nullptr;
        Vector2i position {0, 0};
        Vector2i dimensions {0, 30};
        Vector2i text_position {0, 0};
        Boundaries boundaries {0, 0, 0, 0};
        string text;

    private:
        int text_width = 0;

    public:
        Button(Vector2i position, string text) {
            this->position = position;
            this->text = std::move(text);
            this->compute_sizes(); // Compute size properties
        }

    public:
        void draw() const;
        void register_callback(function<void(const Button&)> cb);

    private:
        void compute_sizes();
    };
};

#endif //ALGORITHMSVISUALISATION_BUTTON_H
