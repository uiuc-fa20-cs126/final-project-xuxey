#include <cinder/gl/gl.h>
#include <sections/text_section.h>
namespace breakout {

void breakout::TextSection::Render() const {
  ci::gl::drawStringCentered(text_function_(), bottom_left_, color_, font_);
}
TextSection::TextSection(const std::string& text_content, dvec2 position,
                         ci::Color color, ci::Font font)
    : color_(color), font_(font) {
  bottom_left_ = position;
  text_function_ = [text_content]() { return text_content; };
}

TextSection::TextSection(const std::function<std::string()> text_function,
                         dvec2 position, ci::Color color, ci::Font font)
    : color_(color), font_(font), text_function_(text_function) {
  bottom_left_ = position;
}
}  // namespace breakout