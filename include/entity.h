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

        void moveUp()
        {
            spr.value().set_y(spr.value().y() - 1);

            for (int j = 0; j < 2; j++)
            {
                spr.value().set_x(spr.value().x() + 1);
            }
            bn::core::update();
        }
        void moveDown()
        {
            spr.value().set_y(spr.value().y() + 1);

            for (int j = 0; j < 2; j++)
            {
                spr.value().set_x(spr.value().x() - 1);
            }
            bn::core::update();
        }
        void moveLeft()
        {
            spr.value().set_y(spr.value().y() - 1);

            for (int j = 0; j < 2; j++)
            {
                spr.value().set_x(spr.value().x() - 1);
            }
            bn::core::update();
        }
        void moveRight()
        {
            spr.value().set_y(spr.value().y() + 1);

            for (int j = 0; j < 2; j++)
            {
                spr.value().set_x(spr.value().x() + 1);
            }
            bn::core::update();
        }

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

            bn::point cart = _math.isoToCart(bn::point(_x - 1, _y - 1));
            spr = bn::sprite_items::entity.create_sprite(cart.x(), cart.y());
            spr.value().set_bg_priority(1);
            anim = bn::create_sprite_animate_action_forever(spr.value(), 30, bn::sprite_items::entity.tiles_item(), 0, 1);

            // // Loop over the array and create sprites with the corresponding coordinates
            // for (int i = 0; i < 12; i++)
            // {
            //     int x = coordss[i][0];
            //     int y = coordss[i][1];
            //     bn::sprite_ptr sprite = bn::sprite_items::selected.create_sprite(_math.isoToCart(bn::point(x, y)).x(), _math.isoToCart(bn::point(x, y)).y() + 4);
            //     // sprites[0].set_position(_math.cartToIso(bn::point(spr.value().x().integer(), spr.value().y().integer())).x() + 1, _math.cartToIso(bn::point(spr.value().x().integer(), spr.value().y().integer())).y() + 1);

            //     sprites.push_back(sprite);

            //     // Set the background priority and blending for each sprite
            //     sprite.set_bg_priority(2);
            //     sprite.set_blending_enabled(true);
            // }
        }
        // void setLocation(Math _math)
        // {
        //     spr.value().set_x(selz.spr.value().x().integer());
        //     spr.value().set_y(selz.spr.value().y().integer() - 4);
        // }
        void updateField(Math _math)
        {
            int coordss[12][2] = {
                {_math.cartToIso(bn::point(spr.value().x().integer(), spr.value().y().integer())).x() + 1, _math.cartToIso(bn::point(spr.value().x().integer(), spr.value().y().integer())).y() + 1},
                {_math.cartToIso(bn::point(spr.value().x().integer(), spr.value().y().integer())).x() - 1, _math.cartToIso(bn::point(spr.value().x().integer(), spr.value().y().integer())).y() - 1},
                {_math.cartToIso(bn::point(spr.value().x().integer(), spr.value().y().integer())).x() - 1, _math.cartToIso(bn::point(spr.value().x().integer(), spr.value().y().integer())).y() + 1},
                {_math.cartToIso(bn::point(spr.value().x().integer(), spr.value().y().integer())).x() + 1, _math.cartToIso(bn::point(spr.value().x().integer(), spr.value().y().integer())).y() - 1},
                {_math.cartToIso(bn::point(spr.value().x().integer(), spr.value().y().integer())).x(), _math.cartToIso(bn::point(spr.value().x().integer(), spr.value().y().integer())).y() + 1},
                {_math.cartToIso(bn::point(spr.value().x().integer(), spr.value().y().integer())).x(), _math.cartToIso(bn::point(spr.value().x().integer(), spr.value().y().integer())).y() - 1},
                {_math.cartToIso(bn::point(spr.value().x().integer(), spr.value().y().integer())).x() + 1, _math.cartToIso(bn::point(spr.value().x().integer(), spr.value().y().integer())).y()},
                {_math.cartToIso(bn::point(spr.value().x().integer(), spr.value().y().integer())).x() - 1, _math.cartToIso(bn::point(spr.value().x().integer(), spr.value().y().integer())).y()},
                {_math.cartToIso(bn::point(spr.value().x().integer(), spr.value().y().integer())).x(), _math.cartToIso(bn::point(spr.value().x().integer(), spr.value().y().integer())).y() - 2},
                {_math.cartToIso(bn::point(spr.value().x().integer(), spr.value().y().integer())).x(), _math.cartToIso(bn::point(spr.value().x().integer(), spr.value().y().integer())).y() + 2},
                {_math.cartToIso(bn::point(spr.value().x().integer(), spr.value().y().integer())).x() - 2, _math.cartToIso(bn::point(spr.value().x().integer(), spr.value().y().integer())).y()},
                {_math.cartToIso(bn::point(spr.value().x().integer(), spr.value().y().integer())).x() + 2, _math.cartToIso(bn::point(spr.value().x().integer(), spr.value().y().integer())).y()}};

            for (int i = 0; i < 12; i++)
            {
                int xx = coordss[i][0];
                int yy = coordss[i][1];
                sprites[i].set_position(_math.isoToCart(bn::point(xx, yy)).x(), _math.isoToCart(bn::point(xx, yy)).y() + 4);
            }
        };
        void update(Math _math);
    };

    class Enemy : public Entity
    {
    private:
    public:
        Enemy(int _x, int _y, bn::random _random, Math _math, bn::sprite_text_generator _text) : Entity(_x, _y, _random, 40, (((_x < 0) ? -_x : _x) * 10 + ((_y < 0) ? -_y : _y)), _math, _text)
        {
            bn::point cart = _math.isoToCart(bn::point(_x, _y));
            spr = bn::sprite_items::entity.create_sprite(cart.x(), cart.y());
            spr.value().set_bg_priority(0);
            anim = bn::create_sprite_animate_action_forever(spr.value(), 30, bn::sprite_items::entity.tiles_item(), 32, 33);
            text.set_bg_priority(0);
            text.generate(x + 8, y - 12, "Orc", text_sprites);
        }

        void update(Math _math);
    };
} // namespace dnd
#endif