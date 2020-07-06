#ifndef ALGORITHMSVISUALISATION_BUTTON_H
#define ALGORITHMSVISUALISATION_BUTTON_H

#include <raylib.h>
#include <string>
#include <utility>
#include <cmath>
#include <functional>
#include "./component.h"

using std::string;
using std::function;

namespace components {

    class Button : public Component {
    public:
        function<void(const Button&)> callback = nullptr;
        Vector2i text_position {0, 0};
        string text;

    private:
        int text_width = 0;

    public:
        Button(Vector2i position, string text) : Component(position, Vector2i {0, 30}) {
            this->position = position;
            this->text = std::move(text);
            // Compute size properties
            this->compute_sizes();
        }

    public:
        void draw() const override;
        void register_callback(function<void(const Button&)> cb);

    private:
        void compute_sizes();
    };
};

#endif //ALGORITHMSVISUALISATION_BUTTON_H
