#include <bn_sprite_ptr.h>
#include "bn_string.h"
#include "bn_sprite_animate_actions.h"
#include "entity.h"
#include "tile.h"

namespace dnd
{
    class World
    {
    private:
        dnd::Math math;
        bn::sprite_text_generator text;
        dnd::Player plr;
        bn::vector<dnd::Tile, 100> tiles;

    public:
        World(dnd::Math _math, bn::sprite_text_generator _text);
        void setDepth(bool invert);
        void update();
    };
} // namespace dnd
