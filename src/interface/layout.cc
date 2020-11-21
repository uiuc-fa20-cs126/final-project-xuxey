#include <interface/layout.h>

#include <glm/glm.hpp>
namespace breakout {
const dvec2 Layout::kWorldBottomLeft = dvec2(kMargin, kWindowHeight - kMargin);
const dvec2 Layout::kWorldTopRight =
    dvec2((2 * kWindowHeight) - kMargin, kMargin);

const dvec2 Layout::kStartButtonTopRight = dvec2(1350, 450);
const dvec2 Layout::kStartButtonBottomLeft = dvec2(1050, 750);

const dvec2 Layout::kStartTextCenter = dvec2(1200, 400);
}  // namespace breakout