//
// Created by soham on 11/8/2020.
//

#ifndef IDEAL_GAS_USER_INTERFACE_H
#define IDEAL_GAS_USER_INTERFACE_H

#include <cinder/app/MouseEvent.h>
#include <interface/ui_section.h>

#include <glm/vec2.hpp>
#include <string>
#include <unordered_map>
#include <vector>

namespace breakout {
using glm::dvec2;
/**
 * User interface class to handle UISection implementations
 */
class UserInterface {
  // static std::string active_screen_;
  static std::unordered_map<std::string, UISection*> sections_;
  // static std::unordered_map<std::string, std::vector<std::string>> screens_;

 public:
  /**
   * Calls the appropriate onClick method based on the UISection region that has
   * been clicked
   * @param mouse_pos position of the mouse in the app, origin top left
   */
  static void HandleMouseClick(dvec2 mouse_pos);
  // Adds a new UISection to the interface
  static void AddUISection(std::string id, UISection* section);
  // Updates all UISections
  static void UpdateUI();
  // Renders all UISections
  static void RenderUI();
  // Handles Key Presses
  static void HandleKeyPress(ci::app::KeyEvent event);
  // Destructor
  virtual ~UserInterface();
};
}  // namespace breakout
#endif  // IDEAL_GAS_USER_INTERFACE_H
