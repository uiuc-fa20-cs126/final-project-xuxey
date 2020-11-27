//
// Created by soham on 11/8/2020.
//

#ifndef IDEAL_GAS_BUTTON_H
#define IDEAL_GAS_BUTTON_H

#include <interface/ui_section.h>
namespace breakout {
/**
 * Clickable UISection which executes a given function when clicked
 */
class Button : public UISection {
  std::function<void(void)> on_click_;
  std::string label_;
  ci::Color background_color_;

 public:
  /**
   * @param bottom_left Bottom left position of the button
   * @param top_right Top right position of the button
   * @param on_click function to be executed when clicked
   * @param label displayed title of the button
   */
  Button(dvec2 bottom_left, dvec2 top_right, std::function<void(void)> on_click,
         std::string label);
  Button(dvec2 bottom_left, dvec2 top_right, std::function<void(void)> on_click,
         std::string label, cinder::Color color);
  void Render() const override;
  void OnClick(glm::dvec2 relative_pos) override;
  void Update() override{};
};
}  // namespace breakout

#endif  // IDEAL_GAS_BUTTON_H
