#include <interface/layout.h>

#include <glm/glm.hpp>
namespace breakout {
const dvec2 Layout::top_instructions_ = dvec2(kWindowHeight / 2, kMargin / 2);

const dvec2 Layout::bottom_instructions_ =
    dvec2(kWindowHeight / 2, kWindowHeight - (kMargin / 2));

const dvec2 Layout::container_bottom_left_ =
    dvec2(kMargin, kWindowHeight - kMargin);
const dvec2 Layout::container_top_right_ =
    dvec2((2 * kWindowHeight) - kMargin, kMargin);

const dvec2 Layout::clear_bottom_left_ = dvec2(1300, 350);
const dvec2 Layout::clear_top_right_ = dvec2(1550, 100);

const dvec2 Layout::blue_btn_bottom_left_ = dvec2(1550, 350);
const dvec2 Layout::blue_btn_top_right_ = dvec2(1800, 100);

const dvec2 Layout::cyan_btn_bottom_left_ = dvec2(1550, 600);
const dvec2 Layout::cyan_btn_top_right_ = dvec2(1800, 350);

const dvec2 Layout::aqua_btn_bottom_left_(1300, 600);
const dvec2 Layout::aqua_btn_top_right_(1550, 350);

const dvec2 Layout::aqua_graph_bottom_left_(1300, 1100);
const dvec2 Layout::aqua_graph_top_right_(1800, 600);

const dvec2 Layout::cyan_graph_bottom_left_(1850, 1100);
const dvec2 Layout::cyan_graph_top_right_(2350, 600);

const dvec2 Layout::blue_graph_bottom_left_(1850, 600);
const dvec2 Layout::blue_graph_top_right_(2350, 100);
}  // namespace breakout