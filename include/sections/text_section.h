//
// Created by soham on 11/8/2020.
//

#ifndef IDEAL_GAS_TEXT_SECTION_H
#define IDEAL_GAS_TEXT_SECTION_H

#include <cinder/Color.h>
#include <cinder/Font.h>

#include "interface/ui_section.h"
namespace breakout {
/**
 * Text rendering UISection
 */
class TextSection : public UISection {
 protected:
  std::function<std::string()> text_function_;
  ci::Font font_;
  ci::Color color_;

 public:
  TextSection(const std::string& text_content, dvec2 position, ci::Color color,
              ci::Font font);
  TextSection(const std::function<std::string()> text_function, dvec2 position,
              ci::Color color, ci::Font font);
  void Render() const override;
  void Update() override{};
};
}  // namespace breakout

#endif  // IDEAL_GAS_TEXT_SECTION_H
