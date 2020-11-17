#include <cinder/gl/gl.h>
#include <sections/text_section.h>
namespace breakout {

void breakout::TextSection::Render() const {
  ci::gl::drawStringCentered(text_content_, bottom_left_, color_, font_);
}
TextSection::TextSection(const std::string& text_content, dvec2 position,
                         ci::Color color, ci::Font font)
    : text_content_(text_content), color_(color), font_(font) {
  bottom_left_ = position;
}
}  // namespace breakout