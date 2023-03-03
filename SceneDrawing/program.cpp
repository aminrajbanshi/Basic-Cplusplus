#include "splashkit.h"

void launch_rocket()
{

    /** clear_screen(COLOR_WHITE);
    draw_bitmap("images", 350, 425);
    delay(500);
    refresh_screen(60);
    clear_screen(COLOR_WHITE);
    draw_bitmap("images", 350, 400);
    delay(500);
    refresh_screen(60);
    clear_screen(COLOR_WHITE);
    draw_bitmap("images", 350, 375);
    delay(500);
    refresh_screen(60);
    clear_screen(COLOR_WHITE);
    draw_bitmap("images", 350, 350);
    delay(500);
    refresh_screen(60);
    clear_screen(COLOR_WHITE);
    draw_bitmap("images", 350, 325);
    delay(500);
    refresh_screen(60);
    clear_screen(COLOR_WHITE);
    draw_bitmap("images", 350, 300);
    delay(500);
    refresh_screen(60);
    clear_screen(COLOR_WHITE);
    draw_bitmap("images", 350, 275);
    delay(500);
    refresh_screen(60);
    clear_screen(COLOR_WHITE);
    draw_bitmap("images", 350, 250);
    delay(500);
    refresh_screen(60); */
}

void launch_sound()
{
    load_sound_effect("sounds", "Rocket Launch Sound Effect.mp3");
    play_sound_effect("sounds");
}

void count_down()
{
    draw_text("10", COLOR_BLACK, 100, 150);
    refresh_screen(60);
    delay(1000);
        draw_text("9", COLOR_BLACK, 120, 150);
    refresh_screen(60);
    delay(1000);
        draw_text("8", COLOR_BLACK, 150, 150);
    refresh_screen(60);
    delay(1000);
        draw_text("7", COLOR_BLACK, 170, 150);
    refresh_screen(60);
    delay(1000);
        draw_text("6", COLOR_BLACK, 200, 150);
    refresh_screen(60);
    delay(1000);
        draw_text("5", COLOR_BLACK, 150, 180);
    refresh_screen(60);
    delay(1000);
        draw_text("4", COLOR_BLACK, 160, 200);
    refresh_screen(60);
    delay(1000);
        draw_text("3", COLOR_BLACK, 170, 220);
    refresh_screen(60);
    delay(1000);
        draw_text("2", COLOR_BLACK, 220, 150);
    refresh_screen(60);
    delay(1000);
        draw_text("1", COLOR_BLACK, 250, 150);
    refresh_screen(60);
    delay(1000);
        draw_text("0", COLOR_BLACK, 260, 250);
    refresh_screen(60);
    delay(1000);
}

int main()
{
    int new_pos, y_pos, y_pos1, add_height;
    y_pos = 500;
    add_height = 25;
    

    launch_sound();
    open_window("Rocket Launching", 800, 600);
    load_bitmap("images", "Rocket3.png");
    draw_bitmap("images", 350, y_pos);
    count_down();

    do
    {
        clear_screen(COLOR_WHITE);
        load_bitmap("images", "Rocket3.png");
        draw_bitmap("images", 350, y_pos);
        y_pos1 = y_pos - add_height;
        new_pos = y_pos1 - add_height;
        delay(500);
        refresh_screen(60);
    } while (new_pos == 250);

    refresh_screen(60);
    delay(500);
    return 0;
}