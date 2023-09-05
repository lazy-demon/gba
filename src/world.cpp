#include <bn_array.h>
#include <bn_vector.h>
#include <bn_point.h>
#include <bn_core.h>

#include "bn_sprite_items_world.h"
#include "world.h"
#include "bn_keypad.h"

namespace dnd
{

    World::World(dnd::Math _math, bn::sprite_text_generator _text) : math(_math), text(_text), plr(math.isoToCart(bn::point(0, 0)).x(), math.isoToCart(bn::point(0, 0)).y(), bn::random(), math, text), selector(math)
    {
        for (int y = 0; y < math.worldHeight; y++)
        {
            for (int x = 0; x < math.worldWidth; x++)
            {
                bn::point cart = math.isoToCart(bn::point(x, y));
                dnd::Tile tile(bn::sprite_items::world.create_sprite(cart.x(), cart.y()));
                tile.sprite.set_tiles(bn::sprite_items::world.tiles_item(), math.map[math.tiles.size()] - 1);
                tile.sprite.set_bg_priority(3);
                math.tiles.push_back(tile);
            }
        }
        selector.setSelector();
    }

    void World::setDepth(bool invert)
    {
        for (size_t isa = 0; isa < 100; isa++)
        {
            if (invert ? (math.depth[isa] < 0) : (math.depth[isa] > 0))
                for (size_t i = 0; i < abs(math.depth.at(isa)); i++)
                {
                    math.tiles.at(isa).sprite.set_y(math.tiles.at(isa).sprite.y() - 1);
                    bn::core::update();
                }
            if (invert ? (math.depth[isa] > 0) : math.depth[isa] < 0)
                for (size_t i = 0; i < abs(math.depth.at(isa)); i++)
                {
                    math.tiles.at(isa).sprite.set_y(math.tiles.at(isa).sprite.y() + 1);
                    bn::core::update();
                }
        }
    }

    void World::update()
    {

        plr.update(math);
        selector.update(plr);
    }
} // namespace dnd