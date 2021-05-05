
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
bool UISection::ShouldUpdateWhenInactive() const {
  return update_when_inactive;
}

bool UISection::IsPositionWithin(dvec2 position) {
  return position.x > bottom_left_.x && position.x < top_right_.x &&
         position.y > top_right_.y && position.y < bottom_left_.y;
}

dvec2 UISection::ToRelativePos(dvec2 actual_position) {
  return dvec2(actual_position.x - bottom_left_.x,
               actual_position.y - bottom_left_.y);
}
}  // namespace breakout