#ifndef ALGORITHMSVISUALISATION_DRAWING_H
#define ALGORITHMSVISUALISATION_DRAWING_H

#include <raylib.h>
#include <memory>
#include <vector>
#include <iostream>
#include <ctime>
#include "./components/button.h"
#include "./components/message.h"
#include "../utils/random/random.h"

using components::Button;
using components::Message;
using std::vector;
using std::unique_ptr;
using std::make_unique;
using std::time_t;
using std::time;
using std::mktime;

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
    unique_ptr<Message> message = nullptr;
    time_t remove_message = time(nullptr);

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
    void draw_loop();
    void set_values_ptr(vector<int>* pointer);
    void unset_values_ptr();
    void display_message(const string& text);

private:
    void handle_left_mouse_click_event() const;
    void unset_message_ptr();
};


#endif //ALGORITHMSVISUALISATION_DRAWING_H
