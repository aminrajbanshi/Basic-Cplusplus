#include "splashkit.h"
#include "lost_in_space.h"

game_data new_game()
{
    game_data result;
    result.player = new_player();
    return result;
}

void draw_game(const game_data &game)
{
    int i = game.power.size() - 1;

    draw_power_up(game.power[i]);
    
    clear_screen(COLOR_BLACK);
    
    draw_player(game.player);
    
    heads_up_display(game.player);
    
    draw_map(game.power);
    
    draw_power_up(game.power[i]);
    
    refresh_screen(60);
}

void update_game(game_data &game)
{
    update_player(game.player);
    
    add_power_up(game);

    int i = game.power.size() - 1;
    
    update_power_up(game.power[i]);
    
    check_collisions(game);
}

void check_collisions(game_data &game)
{
    for (int i = 0; i  < game.power.size(); i = i + 1)
    {
        bool colide = sprite_collision(game.player.player_sprite, game.power[i].power_up_sprite);
        if (colide == true)
        {
            apply_power_up(game);
        }
        if (colide == false)
        {
            remove_power_up(game, i);
        }
    }
}

void apply_power_up(game_data &game)
{
    game.player.fuel_pct = 0;
    draw_text("You got it", COLOR_WHITE, 400, 400);
    while (game.player.fuel_pct < 1)
    {
        game.player.fuel_pct = game.player.fuel_pct + 0.25;
    }
}

void add_power_up(game_data &game)
{
    float random_float = rnd();
    if (random_float < 0.005)
    {
        game.power.push_back(new_power_up());
    }
}

void remove_power_up(game_data &game, int index)
{
    game.power[index] = game.power[game.power.size() - 1];
    game.power.pop_back();
}

void heads_up_display(const player_data &player)
{
    draw_text("SCORE: ", COLOR_WHITE, 5, 18, option_to_screen());
    draw_text("LOCATION: " + point_to_string(center_point(player.player_sprite)), COLOR_WHITE, 5, 28, option_to_screen());
    draw_text("MAIN DISPLAY", COLOR_WHITE, 5, 8, option_to_screen());
    draw_text("MAP", COLOR_WHITE, 323, 3, option_to_screen());
    draw_text("YOUR HEALTH", COLOR_WHITE, 5, 52, option_to_screen());
    draw_text("YOUR FUEL", COLOR_WHITE, 5, 102, option_to_screen());

    load_bitmap("images", "orange_bar.png");
    draw_bitmap("orange_bar.png", 0, 110, option_part_bmp(0, 0, player.fuel_pct * bitmap_width("orange_bar.png"), bitmap_height("orange_bar.png"), option_to_screen()));

    draw_rectangle(COLOR_WHITE, 0, 45, 320, bitmap_height("empty.png") * 2 + 30, option_to_screen());
    draw_rectangle(COLOR_WHITE, 0, 3, 320, 40, option_to_screen());
    draw_rectangle(COLOR_WHITE, 323, 13, 105, 105, option_to_screen());
    fill_rectangle(COLOR_BLACK, 325, 15, 100, 100, option_to_screen());

    load_bitmap("images", "green_bar_bubbles.png");
    draw_bitmap("green_bar_bubbles.png", 0, 58, option_to_screen());

    load_bitmap("images", "empty.png");
    draw_bitmap("empty.png", 0, 110, option_to_screen());

    draw_rectangle(COLOR_WHITE, 0, 162, 160, 132, option_to_screen());
    draw_text("YOUR STAR", COLOR_WHITE, 5, 168, option_to_screen());
    load_bitmap("images", "star.png");

    int i = 0;
    int x = -32;
    while (i < 5)
    {
        draw_bitmap("star.png", x, 142, option_scale_bmp(0.25, 0.25, option_to_screen()));
        x = x + 30;
        i = i + 1;
    }

    draw_text("YOUR BULLET", COLOR_WHITE, 5, 210, option_to_screen());
    load_bitmap("images", "bullet.png");

    int j = 0;
    int y = -32;
    while (j < 5)
    {
        draw_bitmap("bullet.png", y, 185, option_scale_bmp(0.25, 0.25, option_to_screen()));
        y = y + 30;
        j = j + 1;
    }

    draw_text("YOUR TIME", COLOR_WHITE, 5, 252, option_to_screen());
    load_bitmap("images", "time.png");

    int k = 0;
    int z = -32;
    while (k < 5)
    {
        draw_bitmap("time.png", z, 228, option_scale_bmp(0.25, 0.25, option_to_screen()));
        z = z + 30;
        k = k + 1;
    }

    draw_circle(COLOR_WHITE, center_point(player.player_sprite).x / 800 * 100 + 325, center_point(player.player_sprite).y / 800 * 100 + 15, 2.5, option_to_screen());
}

point_2d mini_map_coordinate(const power_up_data &power_up)
{
    point_2d result;
    double pos_x = sprite_x(power_up.power_up_sprite);
    double pos_y = sprite_y(power_up.power_up_sprite);
    double x = (pos_x - (-1500) / 3000 * 100 + 325);
    double y = (pos_y - (-1500) / 3000 * 100 + 15);
    result = point_at(x, y);
    return result;
}

void draw_mini_map(const vector<power_up_data> power_ups)
{
    for (int i = 0; i < power_ups.size(); i = i + 1)
    {
        point_2d power_up_sprite_pos = mini_map_coordinate(power_ups[i]);
        draw_pixel(COLOR_WHITE, power_up_sprite_pos, option_to_screen());
    }
}

void draw_map(const vector<power_up_data> &power)
{
    draw_mini_map(power);
}