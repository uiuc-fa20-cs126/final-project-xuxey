#include <interface/layout.h>

#include <glm/glm.hpp>
namespace breakout {
const dvec2 Layout::kWorldBottomLeft = dvec2(kMargin, kWindowHeight - kMargin);
const dvec2 Layout::kWorldTopRight =
    dvec2((2 * kWindowHeight) - kMargin, kMargin);

const dvec2 Layout::kStartButtonTopRight = dvec2(1350, 400);
const dvec2 Layout::kStartButtonBottomLeft = dvec2(1050, 700);

const dvec2 Layout::kEasyModeButtonTopRight = dvec2(600, 800);
const dvec2 Layout::kEasyModeButtonBottomLeft = dvec2(300, 1100);

const dvec2 Layout::kClassicModeButtonTopRight = dvec2(2100, 800);
const dvec2 Layout::kClassicModeButtonBottomLeft = dvec2(1800, 1100);
}  // namespace breakout