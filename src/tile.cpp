#include <bn_array.h>
#include <bn_vector.h>
#include <bn_point.h>
#include <bn_core.h>
#include "select.h"

#include "tile.h"
#include "bn_keypad.h"

namespace dnd
{
    Tile::Tile(bn::sprite_ptr _sprite) : sprite(_sprite)
    {
        // highlight->set_bg_priority(2);
        // highlight->set_visible(false);
    }

    void Tile::update()
    {
    }
} // namespace dnd