#include "drawing.h"
#include <vector>
#include "components/button.h"

// TODO create map of drawn elements (buttons) -> for handling mouse events
using components::Button;
using std::vector;

static vector<Button> buttons = vector<Button>();

void Drawing::draw_loop() const {
    // Prepare buttons
    buttons.reserve(2);
    buttons.emplace_back(Vector2i {5, 5}, "Bubble Sort");
    buttons.emplace_back(Vector2i {100, 5}, "Quick Sort");

    // Set max height for rendered columns
    const int max_height = this->screen_height - 50;

    while(!WindowShouldClose()) {
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
        for (const auto& button : buttons)
            button.draw();

        EndDrawing();
    }

    CloseWindow();
}
