#ifndef SELECT_H
#define SELECT_H

#include <bn_sprite_ptr.h>
#include "bn_string.h"
#include "bn_sprite_animate_actions.h"
#include <bn_random.h>
#include <bn_keypad.h>
#include <bn_core.h>
#include <bn_log.h>
#include <random>
#include "bn_sprite_items_selected.h"
#include "math.h"

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

    public:
        Select(Math _math);

        void setSelector();
        Math math;
        int animIndex;
        int mapindex;
        bn::vector<bn::sprite_ptr, 32> text_sprites;
        bn::vector<bn::sprite_ptr, 13> range;

        void setBounds(Math _math);
        void setLocation(int _x, int _y, Math math);
        void update(Math math);

    private:
        int offset[13][2] = {{0, 0}, {1, 1}, {-1, -1}, {-1, 1}, {1, -1}, {0, 1}, {0, -1}, {1, 0}, {-1, 0}, {0, -2}, {0, 2}, {-2, 0}, {2, 0}};
        int coordss[13][2];
        bn::optional<bn::sprite_animate_action<2>> anim;
    };
} // namespace dnd

#endif