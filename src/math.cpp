#include <bn_array.h>
#include <bn_vector.h>
#include <bn_point.h>
#include <bn_core.h>

#include "math.h"

namespace dnd
{
    bn::array<int, 100> map = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
                               2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
                               2, 2, 2, 2, 46, 2, 2, 63, 56, 66,
                               2, 2, 45, 45, 49, 45, 56, 58, 13, 57,
                               5, 5, 2, 2, 46, 2, 13, 57, 13, 57,
                               5, 5, 5, 2, 46, 2, 2, 57, 13, 57,
                               5, 5, 5, 2, 46, 2, 2, 64, 56, 65,
                               5, 5, 2, 2, 2, 2, 2, 2, 2, 2,
                               2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
                               2, 2, 2, 2, 2, 2, 2, 2, 2, 2};

    bn::array<int, 100> depth = {12, 8, 8, 8, -8, -8, 4, 4, 0, 0,
                                 12, 8, 8, 8, 8, 4, 4, 4, 4, 4,
                                 12, 8, 8, 8, 4, 0, 0, 0, 0, 0,
                                 12, 8, 8, 4, -4, 0, 0, 0, 0, 0,
                                 8, 4, 0, 0, 0, 0, 0, 0, 0, 0,
                                 4, 4, 0, 0, 0, 0, 0, 0, 0, 0,
                                 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    int TileWidth = 16;
    int TileHeight = 16;

    bn::point Math::isoToCart(bn::point pos)
    {
        bn::point cart;

        cart.set_x(((pos.x() * dnd::TileWidth) / 2) - ((pos.y() * dnd::TileWidth) / 2));
        cart.set_y(((pos.x() * dnd::TileHeight) / 4) + ((pos.y() * dnd::TileHeight) / 4));

        return cart;
    }

    bn::point Math::cartToIso(bn::point pos)
    {
        bn::point iso;
        pos.set_y(pos.y());

        iso.set_x((pos.x() / (dnd::TileWidth / 2) + pos.y() / (dnd::TileHeight / 4)) / 2);
        iso.set_y((pos.y() / (dnd::TileHeight / 4) - pos.x() / (dnd::TileWidth / 2)) / 2);

        return iso;
    }
} // namespace dnd