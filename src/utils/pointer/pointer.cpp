#include "pointer.h"

Vector2i pointer::get_pointer_position() {
    return types::Vector2i {
        GetMouseX(),
        GetMouseY()
    };
}
