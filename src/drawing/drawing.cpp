#include "drawing.h"
#include <iostream>
#include "../utils/pointer/pointer.h"

void Drawing::draw_loop() const {
    // Prepare buttons
    auto buttons_ptr = buttons.get();
    buttons_ptr->reserve(3);
    buttons_ptr->emplace_back(Vector2i {5, 5}, "Bubble Sort");
    buttons_ptr->emplace_back(Vector2i {100, 5}, "Quick Sort");
    buttons_ptr->emplace_back(Vector2i {188, 5}, "Shaker Sort");

    buttons_ptr->at(0).register_callback([](const Button& button){
        std::cout << "Callback invoked at button " + button.text + "!" << std::endl;
    });

    buttons_ptr->at(1).register_callback([](const Button& button){
        std::cout << "Callback invoked at button " + button.text + "!" << std::endl;
    });

    buttons_ptr->at(2).register_callback([](const Button& button){
        std::cout << "Callback invoked at button " + button.text + "!" << std::endl;
    });

    // Set max height for rendered columns
    const int max_height = this->screen_height - 50;

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Draw array of values
        const auto array = *values; // Pointer dereference is safe as long as "array" stays "const"
        const int size = values->size();
        const int width = this->screen_width / size;

        for (int i = 0; i < size; i++) {
            const int height = (int)((float)max_height * ((float)array[i] / 10.0f));
            const int pos_x = i * width;
            const int pos_y = this->screen_height - height;
            Color color = i % 2 == 0 ? BLACK : BLUE;
            DrawRectangle(pos_x, pos_y, width, height, color);
        }

        // Draw menu
        for (const auto& button : *buttons_ptr) button.draw();

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
        const auto boundaries = button.boundaries();
        if (pointer_pos.x >= boundaries.min_x && pointer_pos.x <= boundaries.max_x) {
            if (pointer_pos.y >= boundaries.min_y && pointer_pos.y <= boundaries.max_y) {
                if (button.callback != nullptr) button.callback(button);
                return; // Don't try other button when there is a match already
            }
        }
    }
}

Drawing::Drawing(int screen_width, int screen_height, int elements_count) {
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
