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
using std::unique_ptr;
using std::make_unique;

class Drawing {
private:
    Drawing() = default;

private:
    bool initialized = false;
    int elements_count = 0;
    int screen_width = 0;
    int screen_height = 0;

public:
    vector<int>* values_ptr = nullptr;
    unique_ptr<vector<Button>> buttons = make_unique<vector<Button>>();

public:
    // for singleton pattern safety
    Drawing(const Drawing&) = delete;
    Drawing& operator=(const Drawing &) = delete;
    Drawing(Drawing &&) = delete;
    Drawing & operator=(Drawing &&) = delete;

    // singleton getter using C++ magic statics
    static auto& instance(){
        static Drawing instance;
        return instance;
    }

public:

public:
    void init(int screen_width, int screen_height, int elements_count);
    void draw_loop() const;
    void set_values_ptr(vector<int>* pointer);
    void unset_values_ptr();

private:
    void handle_left_mouse_click_event() const;
};


#endif //ALGORITHMSVISUALISATION_DRAWING_H
