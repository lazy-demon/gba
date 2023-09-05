#ifndef ENTITY_H
#define ENTITY_H

#include <bn_sprite_ptr.h>
#include "bn_sprite_items_entity.h"
#include "bn_string.h"
#include "bn_sprite_animate_actions.h"
#include <bn_random.h>
#include <bn_keypad.h>
#include <bn_core.h>
#include <bn_log.h>
#include <random>
#include "common_variable_8x16_sprite_font.h"
#include <bn_sprite_text_generator.h>
#include "math.h"

namespace dnd
{
    class Entity
    {
    private:
    public:
        Entity(int _x, int _y, bn::random _random, int _animIndex, int _mapindex, Math _math, bn::sprite_text_generator _text);

        int x;
        int y;
        bn::random random;
        int animIndex;
        int mapindex;
        bn::sprite_text_generator text;
        bn::vector<bn::sprite_ptr, 32> text_sprites;

        bn::optional<bn::sprite_ptr> spr;
        bn::optional<bn::sprite_animate_action<2>> anim;
        // bn::optional<bn::sprite_ptr> health;

        virtual void update(Math _math) = 0;
        virtual ~Entity() = default;
    };

    class Player : public Entity
    {
    private:
        std::vector<bn::sprite_ptr> sprites;
        int coordss[12][2];

    public:
        Player(int _x, int _y, bn::random _random, Math _math, bn::sprite_text_generator _text) : Entity(_x, _y, _random, 16, (((_x < 0) ? -_x : _x) * 10 + ((_y < 0) ? -_y : _y)), _math, _text)
        {

            spr = bn::sprite_items::entity.create_sprite(_math.isoToCart(bn::point(_x - 1, _y - 1)).x(), _math.isoToCart(bn::point(_x - 1, _y - 1)).y());
            spr.value().set_bg_priority(1);
            anim = bn::create_sprite_animate_action_forever(spr.value(), 30, bn::sprite_items::entity.tiles_item(), 0, 1);
        }
        void update(Math _math);
    };

    class Enemy : public Entity
    {
    private:
    public:
        Enemy(int _x, int _y, bn::random _random, Math _math, bn::sprite_text_generator _text) : Entity(_x, _y, _random, 40, (((_x < 0) ? -_x : _x) * 10 + ((_y < 0) ? -_y : _y)), _math, _text)
        {
            spr = bn::sprite_items::entity.create_sprite(_math.isoToCart(bn::point(_x, _y)).x(), _math.isoToCart(bn::point(_x, _y)).y());
            spr.value().set_bg_priority(0);
            anim = bn::create_sprite_animate_action_forever(spr.value(), 30, bn::sprite_items::entity.tiles_item(), 32, 33);
            text.set_bg_priority(0);
            text.generate(x + 8, y - 12, "Orc", text_sprites);
        }

        void update(Math _math);
    };
} // namespace dnd
#endif