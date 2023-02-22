#include "raylib.h"
#include <unistd.h>

int main()
{
    // window sizes
    int width{800};
    int height{450};

    InitWindow(width, height, "Axe game");

    // circle coordinate init
    int circle_x{200};
    int circle_y{200};
    int circle_radius{25};

    // circle edges init
    int l_circle_x{circle_x - circle_radius};
    int r_circle_x{circle_x + circle_radius};
    int u_circle_y{circle_y - circle_radius};
    int b_circle_y{circle_y + circle_radius};

    // axe coordinate init
    int axe_x{400};
    int axe_y{0};
    int axe_length{50};

    // axe edges init
    int l_axe_x{axe_x};              // left edge
    int r_axe_x{axe_x + axe_length}; // right edge
    int u_axe_y{axe_y};              // upper edge
    int b_axe_y{axe_y + axe_length}; // bottomedge

    int direction{10};

    // collision init
    bool collision_with_axe{false};

    SetTargetFPS(60);

    while (WindowShouldClose() == false)
    {
        BeginDrawing();
        ClearBackground(BLACK);

        if (collision_with_axe)
        {
            DrawText("Game Over!", 350, 200, 20, GREEN);
        }
        else
        {
            // Game logic - BEGIN

            // Update the circle edges
            l_circle_x = circle_x - circle_radius;
            r_circle_x = circle_x + circle_radius;
            u_circle_y = circle_y - circle_radius;
            b_circle_y = circle_y + circle_radius;

            // Update the axe edges
            l_axe_x = axe_x;
            r_axe_x = axe_x + axe_length;
            u_axe_y = axe_y;
            b_axe_y = axe_y + axe_length;

            // Update collision_with_axe
            collision_with_axe =
                (b_axe_y >= u_circle_y) &&
                (u_axe_y <= b_circle_y) &&
                (l_axe_x <= r_circle_x) &&
                (r_axe_x >= l_circle_x);

            DrawCircle(circle_x, circle_y, circle_radius, WHITE);
            DrawRectangle(axe_x, axe_y, axe_length, axe_length, GREEN);

            // move the axe
            axe_y += direction;

            if (axe_y > height || axe_y < 0)
            {
                direction = -direction;
            }

            if (IsKeyDown(KEY_RIGHT) && circle_x < width)
            {
                circle_x += 10;
            }
            if (IsKeyDown(KEY_LEFT) && circle_x > 0)
            {
                circle_x -= 10;
            }
            if (IsKeyDown(KEY_UP) && circle_y >= 25)
            {
                circle_y -= 10;
            }
            if (IsKeyDown(KEY_DOWN) && circle_y <= height)
            {
                circle_y += 10;
            }
            // Game logic - END
        }

        EndDrawing();
    }
};