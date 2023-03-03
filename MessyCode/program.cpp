// TODO: The score is not showing...
// TODO: Ensure the score increases when the user splats a fruit.

#include "splashkit.h"

using namespace std;

// Setting unique constant numbers for each fruit.
#define CHERRY 0
#define GOOSEBERRY 1
#define BLUEBERRY 2
#define POMEGRANATE 3
#define APRICOT 4
#define RASPBERRY 5
#define BLACKBERRY 6
#define STRAWBERRY 7
#define CURRANT 8
#define NUM_FRUIT 9

void load_resources()// This function loads all the necessary resources.
{
    load_bitmap("Cherry", "Cherry.png");
    load_bitmap("Gooseberry", "Gooseberry.png");
    load_bitmap("Blueberry", "Blueberry.png");
    load_bitmap("Pomegranate", "Pomegranate.png");
    load_bitmap("Apricot", "Apricot.png");
    load_bitmap("Raspberry", "Raspberry.png");
    load_bitmap("Blackberry", "Blackberry.png");
    load_bitmap("Strawberry", "Strawberry.png");
    load_bitmap("Currant", "Currant.png");
    load_sound_effect("Splat", "Splat-SoundBible.com-1826190667.wav"); // Recorded by Mike Koenig - http://soundbible.com/642-Splat.html
}

bitmap fruit_bitmap(int fruit_num)// This function returns the name of the fruit associated with the random number that is generated.
{
    switch (fruit_num)
    {
    case CHERRY:
        return bitmap_named("Cherry");
        break;
    case GOOSEBERRY:
        return bitmap_named("Gooseberry");
        break;
    case BLUEBERRY:
        return bitmap_named("Blueberry");
        break;
    case POMEGRANATE:
        return bitmap_named("Pomegranate");
        break;
    case APRICOT:
        return bitmap_named("Apricot");
        break;
    case RASPBERRY:
        return bitmap_named("Raspberry");
        break;
    case BLACKBERRY:
        return bitmap_named("Blackberry");
        break;
    case STRAWBERRY:
        return bitmap_named("Strawberry");
        break;
    case CURRANT:
        return bitmap_named("Currant");
        break;
    default:
        return bitmap_named("Currant");
        break;
    }
}

int main()
{
    // Declaring all necessary parameters.
    int score_counter = 0;
    bitmap fruit_name;
    double fruit_pos_y, fruit_pos_x;

    open_window("Fruit Punch", 600, 600);// Openeing the window where the game will be played.

    load_resources();// Calling the function load_resources.

    fruit_name = fruit_bitmap(rnd(NUM_FRUIT));// Setting value to the fruit_name parameter.
    fruit_pos_y = rnd(screen_width() - bitmap_width(fruit_name));// Setting value to the fruit_pos_y parameter.
    fruit_pos_x = rnd(screen_height() - bitmap_height(fruit_name));// Setting value to the fruit_pos_y parameter.

    while (not quit_requested())// This will keep the program in loop unless user requests to quit.
    {
        process_events();// Call function process_events.
        draw_text("Score: " + to_string(score_counter), COLOR_BLACK, 25, 25);// Outputs score to the screen.
        refresh_screen(60);
        draw_bitmap(fruit_name, fruit_pos_y, fruit_pos_x);// Outputs first random bitmap image to the screen.
        refresh_screen(60);
        if (mouse_clicked(LEFT_BUTTON) and bitmap_point_collision(fruit_name, fruit_pos_y, fruit_pos_x, mouse_x(), mouse_y()))
        {
            // The following commands will only run if above conditions are met.
            play_sound_effect("Splat");
            score_counter = score_counter + 1;// Updating the score.
            fruit_name = fruit_bitmap(rnd(NUM_FRUIT));// Setting new value to the parameters.
            fruit_pos_y = rnd(screen_width() - bitmap_width(fruit_name));
            fruit_pos_x = rnd(screen_height() - bitmap_height(fruit_name));
            clear_screen(COLOR_WHITE);// Clearing screen to re run the loop.
        }
    }
    return 0;// End.
}