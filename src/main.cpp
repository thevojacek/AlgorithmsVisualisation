#include "drawing/drawing.h"

int main() {
    Drawing::instance().init(800, 450, 80);
    Drawing::instance().draw_loop();
    return 0;
}
