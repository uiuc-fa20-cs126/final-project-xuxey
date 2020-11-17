
#include <cinder/Color.h>
#include <cinder/gl/gl.h>
#include <sections/button.h>

namespace breakout {

breakout::Button::Button(dvec2 bottom_left, dvec2 top_right,
                         std::function<void(void)> on_click,
                         std::string label) {
  bottom_left_ = bottom_left;
  top_right_ = top_right;
  on_click_ = on_click;
  label_ = label;
}

void Button::Render() const {
  ci::gl::color(ci::Color8u(34, 34, 34));
  dvec2 center = dvec2(bottom_left_.x + (top_right_.x - bottom_left_.x) / 2,
                       top_right_.y + (bottom_left_.y - top_right_.y) / 2.25);
  ci::gl::drawSolidRoundedRect(ci::Rectf(bottom_left_, top_right_), 50.0f, 1);
  ci::gl::color(ci::Color8u(51, 51, 51));
  ci::gl::drawStrokedRect(ci::Rectf(bottom_left_, top_right_), 20);
  ci::gl::drawStringCentered(label_, center, ci::Color("white"),
                             ci::Font("arial", 45));
}

void Button::OnClick(glm::dvec2 relative_pos) {
  on_click_();
}
}  // namespace breakout