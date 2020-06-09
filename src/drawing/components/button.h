#ifndef ALGORITHMSVISUALISATION_BUTTON_H
#define ALGORITHMSVISUALISATION_BUTTON_H

#include <raylib.h>
#include <string>
#include "../../utils/vector_i.h"

using types::Vector2i;
using std::string;

namespace components {
    void draw_button(Vector2i position, Vector2i dimensions, const string& text);
};

#endif //ALGORITHMSVISUALISATION_BUTTON_H
