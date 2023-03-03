#include "splashkit.h"
#include "player.h"
#include "power_up.h"
#include "lost_in_space.h"

/**
 * Load the game images, sounds, etc.
 */
void load_resources()
{
    load_resource_bundle("game_bundle", "lost_in_space.txt");
}

/**
 * Entry point.
 * 
 * Manages the initialisation of data, the event loop, and quitting.
 */
int main()
{

    open_window("Lost In Space", 800, 800);
    load_resources();

    /**
    player_data player;
    player = new_player();

    power_up_data power;
    power = new_power_up();
    */

    game_data game;
    game = new_game();

    while (not quit_requested())
    {
        // Handle input to adjust player movement
        process_events();
        handle_input(game.player);

        // Perform movement and update the camera
        /**
        update_player(player);
        update_power_up(power);
        draw_power_up(power);
        */
        update_game(game);
        draw_game(game);
        write_line("Hey");

        // Redraw everything
        //clear_screen(COLOR_BLACK);

        // including something stationary - it doesn't move
        //fill_rectangle(COLOR_WHITE, 400, 400, 10, 10);

        // as well as the player who can move
        /**
        draw_player(player);
        heads_up_display(player);
        draw_map(player);
        draw_power_up(power);
        */
        //refresh_screen(60);
    }

    return 0;
}
