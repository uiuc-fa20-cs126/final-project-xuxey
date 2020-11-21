#include <interface/layout.h>

#include <glm/glm.hpp>
namespace breakout {
const dvec2 Layout::container_bottom_left_ =
    dvec2(kMargin, kWindowHeight - kMargin);
const dvec2 Layout::container_top_right_ =
    dvec2((2 * kWindowHeight) - kMargin, kMargin);
}  // namespace breakout