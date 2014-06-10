/*
 * Copyright © 2014 Canonical Ltd.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 3 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Authored by: Kevin DuBois <kevin.dubois@canonical.com>
 */

#include "mir/graphics/display_buffer.h"
#include "mir/compositor/compositor_report.h"
#include "mir/compositor/scene.h"
#include "demo_compositor.h"

namespace me = mir::examples;
namespace mg = mir::graphics;
namespace mc = mir::compositor;

me::DemoCompositor::DemoCompositor(
    mg::DisplayBuffer& display_buffer,
    std::shared_ptr<mc::Scene> const& scene,
    mg::GLProgramFactory const& factory,
    std::shared_ptr<mc::CompositorReport> const& report) :
    display_buffer(display_buffer),
    scene(scene),
    report(report),
    shadow_radius(80.0f),
    titlebar_height(30.0f),
    renderer(factory, display_buffer.view_area(), shadow_radius, titlebar_height) 
{
}

bool me::DemoCompositor::composite()
{
    report->began_frame(this);

    auto renderable_list = scene->renderable_list_for(this);
    //mc::filter_occlusions_from(renderable_list, display_buffer.view_area();

    display_buffer.make_current();

    renderer.set_rotation(display_buffer.orientation());
    renderer.begin();
    renderer.render(renderable_list);
    display_buffer.post_update();
    renderer.end();
    report->finished_frame(false, this);

    return false;
}
