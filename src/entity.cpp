#include <bn_array.h>
#include <bn_vector.h>
#include <bn_point.h>
#include <bn_core.h>
#include "entity.h"
#include "bn_keypad.h"

namespace dnd
{
    Entity::Entity(int _x, int _y, bn::random _random, int _animIndex, int _mapindex, Math _math, bn::sprite_text_generator _text) : x(_x), y(_y), random(_random), animIndex(_animIndex), mapindex(_mapindex), text(_text)
    {
        bn::point cart = _math.isoToCart(bn::point(_x, _y));
        this->x = cart.x();
        this->y = cart.y();
    }

    void Player::update(Math _math)
    {

        if (anim.has_value() && !anim.value().done())
        {
            anim.value().update();
            bn::core::update();
        }
    }

    void Enemy::update(Math _math)
    {
        //     text_sprites[0].set_position(spr.get()->x() + 8, spr.get()->y() - 12);
        //     if (anim.has_value() && !anim.value().done())
        //     {
        //         anim.value().update();
        //         bn::core::update();
        //     }
    }
} // namespace dnd