#include "splashkit.h"

void draw_house_scene()
{
    clear_screen(COLOR_WHITE);
    fill_ellipse(COLOR_BRIGHT_GREEN, 0, 400, 800, 400);
    fill_rectangle(COLOR_GRAY, 300, 300, 200, 200);
    fill_triangle(COLOR_RED, 250, 300, 400, 150, 550, 300);
    refresh_screen(60);
}

void house_message()
{
    clear_screen(COLOR_WHITE);
   draw_text("Incoming house", COLOR_BLACK, 400, 300);
    refresh_screen(60);
}

void earth_message()
{
    clear_screen(COLOR_WHITE);
       draw_text("Incoming earth", COLOR_BLACK, 400, 300);
    refresh_screen(60);
}

void car_message()
{
    clear_screen(COLOR_WHITE);
        draw_text("Incoming car", COLOR_BLACK, 400, 300);
    refresh_screen(60); 
}

void draw_earth_scene()
{
    clear_screen(COLOR_DARK_BLUE);
    fill_circle(COLOR_LIGHT_SKY_BLUE, 400, 300, 200);
    fill_rectangle(COLOR_DARK_GREEN, 317, 310, 50, 44);
    fill_rectangle(COLOR_DARK_GREEN, 362, 247, 65, 60);
    fill_rectangle(COLOR_DARK_GREEN, 450, 182, 70, 54);
    fill_rectangle(COLOR_DARK_GREEN, 496, 272, 25, 22);
    fill_rectangle(COLOR_DARK_GREEN, 402, 315, 15, 59);
    fill_rectangle(COLOR_DARK_GREEN, 353, 223, 20, 80);
    fill_rectangle(COLOR_DARK_GREEN, 287, 313, 35, 67);
    fill_rectangle(COLOR_DARK_GREEN, 235, 292, 5, 34);
    fill_rectangle(COLOR_DARK_GREEN, 372, 299, 10, 76);
    fill_rectangle(COLOR_DARK_GREEN, 501, 346, 75, 45);
    fill_rectangle(COLOR_DARK_GREEN, 260, 163, 60, 12);
    fill_rectangle(COLOR_DARK_GREEN, 300, 322, 40, 56);
    fill_rectangle(COLOR_DARK_GREEN, 221, 239, 80, 98);
    fill_rectangle(COLOR_DARK_GREEN, 276, 212, 45, 23);
    fill_rectangle(COLOR_DARK_GREEN, 423, 364, 55, 61);
    refresh_screen(60);
}

void draw_car_scene()
{
    clear_screen(COLOR_WHITE);
    fill_rectangle(COLOR_SILVER, 20, 250, 750, 180);
    fill_rectangle(COLOR_SILVER, 150, 150, 500, 210);
    fill_circle(COLOR_BLACK, 100, 420, 50);
    fill_circle(COLOR_BLACK, 700, 420, 50);
    fill_rectangle(COLOR_LIGHT_GRAY, 160, 160, 450, 100);
    fill_ellipse(COLOR_BRIGHT_GREEN, 0, 400, 800, 400);
    fill_rectangle(COLOR_WHITE, 30, 255, 20, 20);
    refresh_screen(60);
}

int main()
{
    open_window("House Drawing", 800, 600);
    house_message();
    delay(2500);
    draw_house_scene();
    delay(3000);
    earth_message();
    delay(2500);
    draw_earth_scene();
    delay(3000);
    car_message();
    delay(2500);
    draw_car_scene();
    delay(3000);
    return 0;
}