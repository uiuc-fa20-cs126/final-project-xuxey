#include <interface/layout.h>

#include <glm/glm.hpp>
namespace breakout {
const dvec2 Layout::kWorldBottomLeft = dvec2(kMargin, kWindowHeight - kMargin);
const dvec2 Layout::kWorldTopRight =
    dvec2((2 * kWindowHeight) - kMargin, kMargin);

const dvec2 Layout::kSelectedTextCenter = dvec2(1200, 350);
const dvec2 Layout::kScoreViewTopCenter = dvec2(2000, 100);
const dvec2 Layout::kInstructionTextCenter = dvec2(600, 100);

const dvec2 Layout::kStartButtonTopRight = dvec2(1350, 400);
const dvec2 Layout::kStartButtonBottomLeft = dvec2(1050, 700);

const dvec2 Layout::kLeftButtonTopRight = dvec2(600, 800);
const dvec2 Layout::kLeftButtonBottomLeft = dvec2(300, 1100);

const dvec2 Layout::kRightButtonTopRight = dvec2(2100, 800);
const dvec2 Layout::kRightButtonBottomLeft = dvec2(1800, 1100);

const dvec2 Layout::kMiddleButtonTopRight = dvec2(1500, 800);
const dvec2 Layout::kMiddleButtonBottomLeft = dvec2(900, 1110);

const dvec2 Layout::kGameOverTextCenter = dvec2(1200, 400);
const dvec2 Layout::kGameEndScoreTextCenter = dvec2(1200, 500);

const dvec2 Layout::kWorldLiveScoreTextCenter = dvec2(1200, 100);
}  // namespace breakout