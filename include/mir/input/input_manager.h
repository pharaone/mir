/*
 * Copyright © 2012 Canonical Ltd.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 3 as
 * pasfublished by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Authored by: Robert Carr <robert.carr@canonical.com>
 *              Daniel d'Andradra <daniel.dandrada@canonical.com>
 */

#ifndef MIR_INPUT_INPUT_MANAGER_H_
#define MIR_INPUT_INPUT_MANAGER_H_
#include <memory>

#include "mir/input/event_filter.h"

namespace mir
{
namespace input
{

class InputManager 
{
public:
    virtual ~InputManager() {}

    virtual void add_filter(std::shared_ptr<EventFilter> const& filter) = 0;
    virtual void start() = 0;
    virtual void stop() = 0;
protected:
    InputManager() = default;
    InputManager(const InputManager&) = delete;
    InputManager& operator=(const InputManager&) = delete;
};

}
}

#endif // MIR_INPUT_INPUT_MANAGER
