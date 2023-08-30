#include "select.h"

namespace dnd
{
    Select::Select(Math _math)
    {
        // spr = bn::sprite_items::cursor.create_sprite(_math.isoToCart(bn::point(4, 3)).x(), _math.isoToCart(bn::point(4, 3)).y());
        // spr2 = bn::sprite_items::selected.create_sprite(_math.isoToCart(bn::point(4, 3)).x(), _math.isoToCart(bn::point(4, 3)).y());
        // spr.value().set_bg_priority(1);
        // spr2.value().set_bg_priority(1);
        // setBounds(_math);
    }

    void Select::setSelector()
    {
        math.tiles.at(5).highlight.emplace(bn::sprite_items::cursor.create_sprite(0, 0));
    }

    void Select::setBounds(Math _math)
    {
        // // Get the isometric coordinates of the point
        // int iso_x = _math.cartToIso(bn::point(spr.value().x().integer(), spr.value().y().integer())).x();
        // int iso_y = _math.cartToIso(bn::point(spr.value().x().integer(), spr.value().y().integer())).y();

        // // Loop through the offset array and calculate the coordinates
        // for (int i = 0; i < 13; i++)
        // {
        //     // Store the coordinates in the coordss array
        //     coordss[i][0] = iso_x + offset[i][0];
        //     coordss[i][1] = iso_y + offset[i][1];

        //     // Create a sprite at the coordinates
        // }
    }

    void Select::setLocation(int _x, int _y, Math math)
    {
        // cart = math.isoToCart(bn::point(_x, _y));
        // spr.value().set_position(cart.x(), cart.y() + 4);
    }

    void Select::update(Math math)
    {
        //     if (bn::keypad::left_pressed())
        //     {
        //         iso = math.cartToIso(bn::point(spr.value().x().integer(), spr.value().y().integer()));
        //         for (int i = 0; i < 13; i++)
        //         {
        //             if (coordss[i][0] == iso.x() - 1 && coordss[i][1] == iso.y())
        //             {
        //                 cart = math.isoToCart(bn::point(iso.x() - 1, iso.y()));
        //                 spr.value().set_position(cart.x(), cart.y() + 4);
        //                 bn::core::update();
        //             }
        //         }
        //     }
        //     if (bn::keypad::right_pressed())
        //     {
        //         iso = math.cartToIso(bn::point(spr.value().x().integer(), spr.value().y().integer()));
        //         for (int i = 0; i < 13; i++)
        //         {
        //             if (coordss[i][0] == iso.x() + 1 && coordss[i][1] == iso.y())
        //             {
        //                 cart = math.isoToCart(bn::point(iso.x() + 1, iso.y()));
        //                 spr.value().set_position(cart.x(), cart.y() + 4);
        //                 bn::core::update();
        //             }
        //         }
        //     }
        //     if (bn::keypad::up_pressed())
        //     {
        //         iso = math.cartToIso(bn::point(spr.value().x().integer(), spr.value().y().integer()));
        //         for (int i = 0; i < 13; i++)
        //         {
        //             if (coordss[i][0] == iso.x() && coordss[i][1] == iso.y() - 1)
        //             {
        //                 cart = math.isoToCart(bn::point(iso.x(), iso.y() - 1));
        //                 spr.value().set_position(cart.x(), cart.y() + 4);
        //                 bn::core::update();
        //             }
        //         }
        //     }
        //     if (bn::keypad::down_pressed())
        //     {
        //         iso = math.cartToIso(bn::point(spr.value().x().integer(), spr.value().y().integer()));
        //         for (int i = 0; i < 13; i++)
        //         {
        //             if (coordss[i][0] == iso.x() && coordss[i][1] == iso.y() + 1)
        //             {
        //                 cart = math.isoToCart(bn::point(iso.x(), iso.y() + 1));
        //                 spr.value().set_position(cart.x(), cart.y() + 4);
        //                 bn::core::update();
        //             }
        //         }
        //     }
    }
} // namespace dnd