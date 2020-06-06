#ifndef ALGORITHMSVISUALISATION_DRAWING_H
#define ALGORITHMSVISUALISATION_DRAWING_H

#include <raylib.h>
#include <memory>
#include <vector>
#include <iostream>
#include "../utils/random/random.h"

class Drawing {

private:
    int elements_count;
    int screen_width;
    int screen_height;

public:
    std::unique_ptr<std::vector<int>> values = std::make_unique<std::vector<int>>();

public:
    Drawing(int screen_width, int screen_height, int elements_count) {
        this->screen_width = screen_width;
        this->screen_height = screen_height;
        this->elements_count = elements_count;

        // Get function with own distribution to generate random numbers
        auto get_random_number = random_utils::get_int_function(10);

        // Fill-in values array with random values
        values->reserve(this->elements_count);
        for (int i = 0; i < this->elements_count; i++)
            values->push_back(get_random_number());

        InitWindow(screen_width, screen_height, "Algorithms Visualisation");
        SetTargetFPS(60); // TODO lower FPS when screen is not active (lower to +- 30) for smaller CPU usage
    }

public:
    void draw_loop() const;
};


#endif //ALGORITHMSVISUALISATION_DRAWING_H
