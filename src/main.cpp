#include "world.h"

#include "bn_core.h"
#include "bn_sprite_text_generator.h"
#include "bn_regular_bg_items_overworld.h"

#include "common_variable_8x16_sprite_font.h"

#include <bn_regular_bg_ptr.h>

int main()
{
    bn::core::init();

    bn::sprite_text_generator text = bn::sprite_text_generator(common::variable_8x16_sprite_font);
    // bn::regular_bg_ptr bg = bn::regular_bg_items::overworld.create_bg(0, 0);

    dnd::Math math;
    dnd::World world(math, text);

    while (true)
    {
        bn::core::update();
        world.update();
    }
}
