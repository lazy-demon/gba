#ifndef SELECT_H
#define SELECT_H

#include <bn_log.h>
#include <random>
#include "bn_sprite_items_selected.h"
#include "math.h"
#include <bn_keypad.h>
#include "entity.h"

#include "common_variable_8x16_sprite_font.h"
#include <bn_sprite_text_generator.h>
#include "bn_sprite_items_cursor.h"
#include "bn_blending_actions.h"

namespace dnd
{
    class Select
    {
    private:
        bn::point iso;
        bn::point cart;
        bool selected = false;

        int offset[13][2] = {{0, 0}, {1, 1}, {-1, -1}, {-1, 1}, {1, -1}, {0, 1}, {0, -1}, {1, 0}, {-1, 0}, {0, -2}, {0, 2}, {-2, 0}, {2, 0}};
        int coordss[13][2];
        bn::optional<bn::sprite_animate_action<2>> anim;
        Math &math;

    public:
        Select(Math &math);
        int index = 13;
        int animIndex;
        int mapindex;
        bn::vector<bn::sprite_ptr, 32> text_sprites;
        bn::vector<bn::sprite_ptr, 13> range;

        void setSelector();
        void update(Player plr);
        void select(Player plr);
    };
} // namespace dnd

#endif