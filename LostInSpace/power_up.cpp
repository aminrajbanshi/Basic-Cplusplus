#include "splashkit.h"
#include "power_up.h"

using namespace std;

/**
 * The power up bitmap function converts a power up kind into a 
 * bitmap that can be used.
 * 
 * @param kind  The kind of power up you want the bitmap of
 * @return      The bitmap matching this power up kind
 */
bitmap power_up_bitmap(power_up_kind type)
{
    switch (type)
    {
    case FUEL:
        return bitmap_named("fuel");
        break;
    case SHIELD:
        return bitmap_named("shield");
        break;
    case STAR:
        return bitmap_named("star");
        break;
    case POTION:
        return bitmap_named("potion");
        break;
    case BULLET:
        return bitmap_named("bullet");
        break;
    case TIME:
        return bitmap_named("time");
        break;
    default:
        return bitmap_named("fuel");
        break;
    }
}

power_up_data new_power_up()
{
    power_up_data result;
    power_up_kind kind;

    // Choose a random power up
    kind = static_cast<power_up_kind>(rnd(6));

    // Create the bitmap of the chosen power up
    result.power_up_sprite = create_sprite(power_up_bitmap(kind));

    // Position and move the power up with a velocity around the screen randomly
    sprite_set_x(result.power_up_sprite, rnd(200, 600));
    sprite_set_y(result.power_up_sprite, rnd(200, 600));
    sprite_set_dx(result.power_up_sprite, rnd() * 4 - 2);
    sprite_set_dy(result.power_up_sprite, rnd() * 4 - 2);

    return result;
}

void draw_power_up(const power_up_data &power_to_draw)
{
    draw_sprite(power_to_draw.power_up_sprite);
}

void update_power_up(power_up_data &power_to_update)
{
    update_sprite(power_to_update.power_up_sprite);
}