#include "drawing.h"
#include "../utils/pointer/pointer.h"
#include "../showcase/showcase.h"
#include "../algorithms/bubble_sort.h"
#include "../algorithms/quick_sort.h"
#include "../algorithms/shaker_sort.h"
#include "../algorithms/insertion_sort.h"
#include "../algorithms/merge_sort.h"

static const int window_fps = 60;
static bool window_low_fps = false;
static bool window_focused = false;
static time_t window_last_focused;

void Drawing::draw_loop() {
    if (!this->initialized) return;

    // Prepare buttons
    auto buttons_ptr = buttons.get();
    buttons_ptr->reserve(5);
    buttons_ptr->emplace_back(Vector2i {5, 5}, "Bubble Sort");
    buttons_ptr->emplace_back(Vector2i {100, 5}, "Quick Sort");
    buttons_ptr->emplace_back(Vector2i {188, 5}, "Shaker Sort");
    buttons_ptr->emplace_back(Vector2i {283, 5}, "Insertion Sort");
    buttons_ptr->emplace_back(Vector2i {400, 5}, "Merge Sort");

    buttons_ptr->at(0).register_callback([this](const Button& button) {
        showcase::algorithm(bubble_sort(), this->elements_count);
    });

    buttons_ptr->at(1).register_callback([this](const Button& button){
        showcase::algorithm(quick_sort(), this->elements_count);
    });

    buttons_ptr->at(2).register_callback([this](const Button& button){
        showcase::algorithm(shaker_sort(), this->elements_count);
    });

    buttons_ptr->at(3).register_callback([this](const Button& button){
        showcase::algorithm(insertion_sort(), this->elements_count);
    });

    buttons_ptr->at(4).register_callback([this](const Button& button){
        showcase::algorithm(merge_sort(), this->elements_count);
    });

    // Set max height for rendered columns
    const int max_height = this->screen_height - 50;

    while (!WindowShouldClose()) {
        Drawing::set_window_fps();

        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Draw array of values
        if (this->values_ptr != nullptr) {
            const int size = this->values_ptr->size();
            const int width = this->screen_width / size;

            // TODO implement red color highlight using array copying?
            // TODO or think of some other more efficient solution
            for (int i = 0; i < size; i++) {
                const int height = (int)((float)max_height * ((float)this->values_ptr->at(i) / 10.0f));
                const int pos_x = i * width;
                const int pos_y = this->screen_height - height;
                Color color = i % 2 == 0 ? BLACK : BLUE;
                DrawRectangle(pos_x, pos_y, width, height, color);
            }
        }

        // Draw menu
        for (const auto& button : *buttons_ptr) button.draw();

        // Draw message
        if (this->message != nullptr) {
            if (time(nullptr) > this->remove_message) this->unset_message_ptr();
            else this->message->draw();
        }

        // Left mouse button click handling
        if (IsMouseButtonPressed(0))
            this->handle_left_mouse_click_event();

        EndDrawing();
    }

    CloseWindow();
}

void Drawing::handle_left_mouse_click_event() const {
    const auto pointer_pos = pointer::get_pointer_position();

    for (const auto& button : *this->buttons) {
        const auto boundaries = button.boundaries;

        if (pointer_pos.x >= boundaries.min_x && pointer_pos.x <= boundaries.max_x) {
            if (pointer_pos.y >= boundaries.min_y && pointer_pos.y <= boundaries.max_y) {
                if (button.callback != nullptr) button.callback(button);
                return; // Don't try other button when there is a match already
            }
        }
    }
}

void Drawing::init(int width, int height, int elements) {
    if (this->initialized) return;

    this->screen_width = width;
    this->screen_height = height;
    this->elements_count = elements;

    // Get function with own distribution to generate random numbers
    auto get_random_number = random_utils::get_int_function(10);

    InitWindow(screen_width, screen_height, "Algorithms Visualisation");
    SetTargetFPS(window_fps);

    this->initialized = true;
}

void Drawing::set_values_ptr(vector<int> *pointer) {
    this->unset_values_ptr();
    this->values_ptr = pointer;
}

void Drawing::unset_values_ptr() {
    if (this->values_ptr != nullptr) {
        free(this->values_ptr);
        this->values_ptr = nullptr;
    }
}

void Drawing::display_message(const string& text) {
    this->unset_message_ptr();

    // Sets time to remove message to 5 seconds in the future
    auto t = time(nullptr);
    auto ts = localtime(&t);
    ts->tm_sec = ts->tm_sec + 5;
    this->remove_message = mktime(ts);

    this->message = make_unique<Message>(
        Vector2i {0, this->screen_height - 30},
        Vector2i {this->screen_width, 30},
        text
    );
}

void Drawing::unset_message_ptr() {
    if (this->message != nullptr) {
        free(this->message.release());
        this->message = nullptr;
    }
}

void Drawing::set_window_fps() {
    if (!window_focused && IsWindowFocused()) {
        window_last_focused = time(nullptr);
        window_focused = true;
        window_low_fps = false;
        SetTargetFPS(window_fps);
    } else if (window_focused && !IsWindowFocused()) {
        window_focused = false;
        window_low_fps = false;
        SetTargetFPS(window_fps / 2);
    }

    if (!window_low_fps
        && !IsWindowFocused()
        && (time(nullptr) - window_last_focused) > 10
    ) {
        window_low_fps = true;
        SetTargetFPS(window_fps / 10);
    }
}
