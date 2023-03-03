#include "splashkit.h"

#define RADIUS 50

int main()
{
    double x;
    double y;
    double r;
    color circle_color = COLOR_GREEN;
    open_window("Circle Mover by Amin", 800, 600);

    x = screen_width() / 2;
    y = screen_height() / 2;
    r = 50;

    while (not quit_requested())
    {
        process_events();
        if (key_typed(C_KEY))
        {
            circle_color = random_color();
        }

        if (key_typed(ESCAPE_KEY))
        {
            x = screen_width() / 2;
            y = screen_height() / 2;
        }
        if (key_typed(A_KEY))
        {
            r = r + 10;
        }
        if (key_typed(S_KEY))
        {
            r = r - 10;
        }
        if ( r <= 10)
        {
            r = 10;
        }
        if ( r >= 200)
        {
            r = 200;
        }

        if (key_down(UP_KEY))
        {
            y = y - 3;
        }
        if (key_down(DOWN_KEY))
        {
            y = y + 3;
        }

        if (key_down(RIGHT_KEY))
        {
            x = x + 3;
        }
        if (key_down(LEFT_KEY))
        {
            x = x - 3;
        }

        if (x + r > screen_width())
        {
            x = screen_width() - r;
        }
        if (x - r < 0)
        {
            x = r;
        }
        if (y + r > screen_height())
        {
            y = screen_height() - r;
        }
        if (y - r < 0)
        {
            y = r;
        }

        clear_screen(COLOR_WHITE);
        fill_circle(circle_color, x, y, r);
        refresh_screen(60);
    }
    return 0;
}