#ifndef ALGORITHMSVISUALISATION_COMPONENT_H
#define ALGORITHMSVISUALISATION_COMPONENT_H

#include "./boundaries.h"
#include "../../utils/vector_i.h"

using types::Vector2i;

static const int font_size = 12;
// Character width for default font is approximately 58% of the font size, truncated to nearest integer
static const int character_width = (int)std::round(font_size * 0.58f);

namespace components {

    class Component {
    public:
        Vector2i dimensions {0, 0};
        Vector2i position {0, 0};
        Boundaries boundaries {0, 0, 0, 0};
    public:
        virtual void draw() const = 0;
    public:
        Component(Vector2i p, Vector2i d) {
            this->dimensions = d;
            this->position = p;
            this->boundaries = Boundaries {p.x, d.x, p.y, d.y};
        }
    protected:
        static int compute_text_width(const size_t num_characters) {
            // TODO fix precisely text width computation and text position (perhaps per word?)
            return (int)(character_width * num_characters);
        }
    };
}

#endif //ALGORITHMSVISUALISATION_COMPONENT_H
