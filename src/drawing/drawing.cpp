#include "drawing.h"

void Drawing::draw_loop() const {
    while(!WindowShouldClose()) {
        BeginDrawing();
        DrawFPS(0, 0);
        ClearBackground(RAYWHITE);

        const auto array = *values; // Pointer dereference is safe as long as "array" stays "const"
        const int size = values->size();
        const int width = this->screen_width / size;

        for (int i = 0; i < size; i++) {
            int height = (int)((float)this->screen_height * ((float)array[i] / 10.0f));
            int pos_x = i * width;
            int pos_y = this->screen_height - height;
            Color color = i % 2 == 0 ? BLACK : BLUE;
            DrawRectangle(pos_x, pos_y, width, height, color);
        }

        EndDrawing();
    }

    CloseWindow();
}
