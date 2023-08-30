#ifndef MATH_H
#define MATH_H

#include <bn_array.h>
#include <bn_vector.h>
#include <bn_point.h>
#include <bn_core.h>
#include "tile.h"

namespace dnd
{
    class Math
    {
    private:
        int index = 0;

    public:
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
        bn::vector<int, 100> depth;
        bn::vector<dnd::Tile, 100> tiles;

        bn::point isoToCart(bn::point pos);
        bn::point cartToIso(bn::point pos);
    };
} // namespace dnd
#endif