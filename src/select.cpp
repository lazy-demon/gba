#include "select.h"

namespace dnd
{
    Select::Select(Math &math) : math(math) {}

    void Select::select(Player plr)
    {
        if (math.tiles.at(index).sprite.x().integer() == plr.spr.value().x() && math.tiles.at(index).sprite.y().integer() == plr.spr.value().y() + 8)
        {
            selected ? math.tiles.at(index).highlight.value().set_tiles(bn::sprite_items::cursor.tiles_item(), 0) : math.tiles.at(index).highlight.value().set_tiles(bn::sprite_items::cursor.tiles_item(), 1);
            selected ? selected = false : selected = true;
        }
    }

    void Select::setSelector()
    {

        math.tiles.at(index).highlight.emplace(bn::sprite_items::cursor.create_sprite(math.tiles.at(index).sprite.x().integer(), math.tiles.at(index).sprite.y().integer() - 3));
    }

    void Select::update(Player plr)
    {
        if (bn::keypad::a_pressed())
        {
            select(plr);
        }

        // on movement
        if (bn::keypad::left_pressed() || bn::keypad::right_pressed() || bn::keypad::up_pressed() || bn::keypad::down_pressed())
        {
            selected = false;
            math.tiles.at(index).highlight.reset();
            if (bn::keypad::left_pressed())
            {
                if (index > 0)
                    index--;
            }
            if (bn::keypad::right_pressed())
            {
                if (index < math.tiles.size() - 1)
                    index++;
            }
            if (bn::keypad::up_pressed())
            {
                if (index - (math.worldHeight - 1) > 0)
                    index -= math.worldHeight;
            }
            if (bn::keypad::down_pressed())
            {
                if (index + (math.worldHeight - 1) < math.tiles.size() - 1)
                    index += math.worldHeight;
            }
            math.tiles.at(index).highlight.emplace(bn::sprite_items::cursor.create_sprite(math.tiles.at(index).sprite.x().integer(), math.tiles.at(index).sprite.y().integer() - 3));
        }
    }
} // namespace dnd