#ifndef LOST_IN_SPACE_LOST_IN_SPACE
#define LOST_IN_SPACE_LOST_IN_SPACE

#include "splashkit.h"
#include "player.h"
#include "power_up.h"
#include <vector>

#define powerup_range_max 1500
#define powerup_range_min -1500

using std::vector;
using namespace std;

struct game_data
{
    player_data player;
    vector<power_up_data> power;
    timer game_timer;
};

game_data new_game();

void draw_game(const game_data &game_to_draw);

void update_game(game_data &game_to_update);

void add_power_up(game_data &game);

void apply_power_up(game_data &game);

void remove_power_up(game_data &game, int index);

void check_collisions(game_data &game);

void heads_up_display(const player_data &player);

void draw_mini_map(const vector<power_up_data> power_ups);

void draw_map(const vector<power_up_data> &power);

point_2d mini_map_coordinate(const power_up_data &power_up);

#endif