#include "drawing/drawing.h"

int main() {
    auto drawing_instance = Drawing(800, 450, 80);
    drawing_instance.draw_loop();

    return 0;

//    Vector2 ball_position = {50, 50};
//    while(!WindowShouldClose()) {
//        if (IsKeyDown(KEY_RIGHT))
//            ball_position.x += 2.0f;
//
//        if (IsKeyDown(KEY_LEFT))
//            ball_position.x -= 2.0f;
//
//        if (IsKeyDown(KEY_UP))
//            ball_position.y -= 2.0f;
//
//        if (IsKeyDown(KEY_DOWN))
//            ball_position.y += 2.0f;
//        auto scale = GetWindowScaleDPI();
//        std::cout << "Window DPI scale: " << scale.x << "-" << scale.y << std::endl;

//        BeginDrawing();
//        DrawFPS(0, 0);
//        ClearBackground(RAYWHITE);

//        DrawText("Algorithms visualisation", 190, 200, 20, BLACK);
//        DrawCircleV(ball_position, 50, MAROON);
//        DrawRectangle(0, 150, 20, 300, BLACK);

//        for (int i = 0; i < screen_width / 10; i++) {
//            DrawRectangle(i * 10, 150, 10, 300, i % 2 == 0 ? BLACK : BLUE);
//        }
//
//        EndDrawing();
//    }
//
//    CloseWindow();
}
