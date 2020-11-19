//
// Created by soham on 11/8/2020.
//

#ifndef IDEAL_GAS_USER_INTERFACE_H
#define IDEAL_GAS_USER_INTERFACE_H

#include <cinder/app/MouseEvent.h>

#include <glm/vec2.hpp>
#include <unordered_map>
#include <vector>

#include "ui_section.h"

namespace breakout {
using glm::dvec2;
/**
 * User interface class to handle UISection implementations
 */
class UserInterface {
  std::unordered_map<std::string, UISection*> sections_;

 public:
  /**
   * Calls the appropriate onClick method based on the UISection region that has
   * been clicked
   * @param mouse_pos position of the mouse in the app, origin top left
   */
  void HandleMouseClick(dvec2 mouse_pos) const;
  // Adds a new UISection to the interface
  void AddUISection(std::string id, UISection* section);
  // Updates all UISections
  void UpdateUI() const;
  // Renders all UISections
  void RenderUI() const;
  // Handles Key Presses
  void HandleKeyPress(ci::app::KeyEvent event) const;
  // Destructor
  virtual ~UserInterface();
};
}  // namespace breakout
#endif  // IDEAL_GAS_USER_INTERFACE_H
