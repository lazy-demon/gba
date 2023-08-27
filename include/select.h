#include <bn_sprite_ptr.h>
#include "bn_string.h"
#include "math.h"
#include "bn_sprite_animate_actions.h"
#include <bn_random.h>
#include <bn_keypad.h>
#include <bn_core.h>
#include <bn_log.h>
#include <random>
#include "bn_sprite_items_selected.h"

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
        Select(Math _math)
        {

            spr = bn::sprite_items::cursor.create_sprite(_math.isoToCart(bn::point(4, 3)).x(), _math.isoToCart(bn::point(4, 3)).y());
            spr2 = bn::sprite_items::selected.create_sprite(_math.isoToCart(bn::point(4, 3)).x(), _math.isoToCart(bn::point(4, 3)).y());
            spr.value().set_bg_priority(1);
            spr2.value().set_bg_priority(1);
            setBounds(_math);
            // spr2.value().set_blending_enabled(true);
            // bn::blending::set_transparency_alpha(0.2);
        };

        int animIndex;
        int mapindex;
        bn::vector<bn::sprite_ptr, 32> text_sprites;
        bn::vector<bn::sprite_ptr, 13> range;

        // Define the offset array
        int offset[13][2] = {{0, 0}, {1, 1}, {-1, -1}, {-1, 1}, {1, -1}, {0, 1}, {0, -1}, {1, 0}, {-1, 0}, {0, -2}, {0, 2}, {-2, 0}, {2, 0}};

        // Initialize the coordss array
        int coordss[13][2];
        bn::optional<bn::sprite_ptr> spr;
        bn::optional<bn::sprite_ptr> spr2;
        bn::optional<bn::sprite_animate_action<2>> anim;

        void setBounds(Math _math)
        {
            // Get the isometric coordinates of the point
            int iso_x = _math.cartToIso(bn::point(spr.value().x().integer(), spr.value().y().integer())).x();
            int iso_y = _math.cartToIso(bn::point(spr.value().x().integer(), spr.value().y().integer())).y();

            // Loop through the offset array and calculate the coordinates
            for (int i = 0; i < 13; i++)
            {
                // Store the coordinates in the coordss array
                coordss[i][0] = iso_x + offset[i][0];
                coordss[i][1] = iso_y + offset[i][1];

                // Create a sprite at the coordinates
            }
            // range[0] = bn::sprite_items::cursor.create_sprite(0, 0);
        }

        void setLocation(int _x, int _y, Math math)
        {
            cart = math.isoToCart(bn::point(_x, _y));
            spr.value().set_position(cart.x(), cart.y() + 4);
        }

        void update(Math math)
        {

            if (bn::keypad::left_pressed())
            {
                iso = math.cartToIso(bn::point(spr.value().x().integer(), spr.value().y().integer()));
                for (int i = 0; i < 13; i++)
                {
                    if (coordss[i][0] == iso.x() - 1 && coordss[i][1] == iso.y())
                    {
                        cart = math.isoToCart(bn::point(iso.x() - 1, iso.y()));
                        spr.value().set_position(cart.x(), cart.y() + 4);
                        bn::core::update();
                    }
                }
            }
            if (bn::keypad::right_pressed())
            {
                iso = math.cartToIso(bn::point(spr.value().x().integer(), spr.value().y().integer()));
                for (int i = 0; i < 13; i++)
                {
                    if (coordss[i][0] == iso.x() + 1 && coordss[i][1] == iso.y())
                    {
                        cart = math.isoToCart(bn::point(iso.x() + 1, iso.y()));
                        spr.value().set_position(cart.x(), cart.y() + 4);
                        bn::core::update();
                    }
                }
            }
            if (bn::keypad::up_pressed())
            {
                iso = math.cartToIso(bn::point(spr.value().x().integer(), spr.value().y().integer()));
                for (int i = 0; i < 13; i++)
                {
                    if (coordss[i][0] == iso.x() && coordss[i][1] == iso.y() - 1)
                    {
                        cart = math.isoToCart(bn::point(iso.x(), iso.y() - 1));
                        spr.value().set_position(cart.x(), cart.y() + 4);
                        bn::core::update();
                    }
                }
            }
            if (bn::keypad::down_pressed())
            {
                iso = math.cartToIso(bn::point(spr.value().x().integer(), spr.value().y().integer()));
                for (int i = 0; i < 13; i++)
                {
                    if (coordss[i][0] == iso.x() && coordss[i][1] == iso.y() + 1)
                    {
                        cart = math.isoToCart(bn::point(iso.x(), iso.y() + 1));
                        spr.value().set_position(cart.x(), cart.y() + 4);
                        bn::core::update();
                    }
                }
            }
            // bn::core::update();
        }
    };

} // namespace dnd
