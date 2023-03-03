#ifndef LOST_IN_SPACE_POWER_UP
#define LOST_IN_SPACE_POWER_UP

#include "splashkit.h"
#include <vector>

using namespace std;

/**
 * Different options for the kind of power up.
 * Adjusts the image used.
 */
enum power_up_kind
{
    FUEL,
    SHIELD,
    STAR,
    POTION,
    BULLET,
    TIME
};

/**
 * The power up data keeps track of all of the information related to the power up.
 * 
 * @field   power_up_sprite   The power up's sprite
 * @field   type              Current kind of power up
 */
struct power_up_data
{
    power_up_kind type;
    sprite power_up_sprite;
};

/**
 * Creates a new random power up bitmap in the location provided to 'x' and 'y'.
 * 
 * @returns     The new power up data
 */
power_up_data new_power_up();

/**
 * Draws the power up to the screen. 
 * 
 * @param power_to_draw    The power up to draw to the screen
 */
void draw_power_up(const power_up_data &power_to_draw);

/**
 * Actions a location update of the power up.
 * 
 * @param power_to_update      The power up being updated
 */
void update_power_up(power_up_data &power_to_update);

#endif
