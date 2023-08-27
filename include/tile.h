#include <bn_sprite_ptr.h>
#include "bn_string.h"
#include "bn_sprite_animate_actions.h"

namespace dnd
{
    class Tile
    {
    private:
    public:
        Tile(bn::sprite_ptr _sprite);
        bn::optional<bn::sprite_ptr> highlight;
        bn::sprite_ptr sprite;
        void update();
    };
} // namespace dnd
