
#include <cinder/Color.h>
#include <cinder/DataSource.h>
#include <cinder/app/AppBase.h>
#include <cinder/gl/gl.h>
#include <sections/button.h>

namespace fs = std::experimental::filesystem;
namespace breakout {

breakout::Button::Button(dvec2 bottom_left, dvec2 top_right,
                         std::function<void(void)> on_click,
                         std::string label) {
  bottom_left_ = bottom_left;
  top_right_ = top_right;
  on_click_ = on_click;
  label_ = label;
  background_color_ = ci::Color8u(34, 34, 34);
}

breakout::Button::Button(dvec2 bottom_left, dvec2 top_right,
                         std::function<void(void)> on_click, std::string label,
                         ci::Color color) {
  bottom_left_ = bottom_left;
  top_right_ = top_right;
  on_click_ = on_click;
  label_ = label;
  background_color_ = color;
}

void Button::Render() const {
  ci::gl::color(background_color_);
  dvec2 center = dvec2(bottom_left_.x + (top_right_.x - bottom_left_.x) / 2,
                       top_right_.y + (bottom_left_.y - top_right_.y) / 2.5);
  ci::gl::drawSolidRoundedRect(ci::Rectf(bottom_left_, top_right_), 50.0f, 1);

  ci::gl::drawStringCentered(
      label_, center, ci::Color("white"),
      ci::Font(ci::DataSourcePath::create(
                   fs::path(ci::app::getAssetPath("Goldman-Bold.ttf"))),
               45));
}

void Button::OnClick(glm::dvec2 relative_pos) {
  on_click_();
}
}  // namespace breakout