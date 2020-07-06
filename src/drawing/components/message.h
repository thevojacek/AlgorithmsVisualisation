#ifndef ALGORITHMSVISUALISATION_MESSAGE_H
#define ALGORITHMSVISUALISATION_MESSAGE_H

#include <raylib.h>
#include <string>
#include <cmath>
#include "./component.h"

using types::Vector2i;
using std::string;

namespace components {
    class Message : public Component {
    public:
        Vector2i text_position {0, 0};
        string text;

    private:
        int text_width = 0;

    public:
        Message(Vector2i position, Vector2i dimensions, string text) : Component(position, dimensions) {
            this->text = std::move(text);
            this->compute_sizes(); // Compute size properties
        }

    public:
        void draw() const override;

    private:
        void compute_sizes();
    };
}


#endif //ALGORITHMSVISUALISATION_MESSAGE_H
