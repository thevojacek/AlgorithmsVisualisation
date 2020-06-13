#ifndef ALGORITHMSVISUALISATION_DRAWING_H
#define ALGORITHMSVISUALISATION_DRAWING_H

#include <raylib.h>
#include <memory>
#include <vector>
#include <iostream>
#include "./components/button.h"
#include "../utils/random/random.h"

using components::Button;
using std::vector;

class Drawing {

private:
    int elements_count;
    int screen_width;
    int screen_height;

public:
    std::unique_ptr<vector<int>> values = std::make_unique<vector<int>>();
    std::unique_ptr<vector<Button>> buttons = std::make_unique<vector<Button>>();

public:
    Drawing(int screen_width, int screen_height, int elements_count);

public:
    void draw_loop() const;

private:
    void handle_left_mouse_click_event() const;
};


#endif //ALGORITHMSVISUALISATION_DRAWING_H
