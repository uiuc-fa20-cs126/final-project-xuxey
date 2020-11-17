
#include <interface/ui_section.h>

namespace breakout {

dvec2 UISection::GetActualPos(dvec2 relative_pos) const {
  dvec2 top_right = dvec2(bottom_left_.x, top_right_.y);
  return top_right + relative_pos;
}

const dvec2& UISection::GetTopRight() const {
  return top_right_;
}

const dvec2& UISection::GetBottomLeft() const {
  return bottom_left_;
}
}  // namespace breakout