//
// Created by soham on 11/8/2020.
//

#ifndef IDEAL_GAS_USER_INTERFACE_H
#define IDEAL_GAS_USER_INTERFACE_H

#include <cinder/app/MouseEvent.h>

#include <glm/vec2.hpp>
#include <vector>

#include "ui_section.h"

namespace breakout {
using glm::dvec2;
/**
 * User interface class to handle UISection implementations
 */
class UserInterface {
  std::vector<UISection*> sections_;

 public:
  /**
   * Calls the appropriate onClick method based on the UISection region that has
   * been clicked
   * @param mouse_pos position of the mouse in the app, origin top left
   */
  void HandleMouseClick(dvec2 mouse_pos) const;
  // Adds a new UISection to the interface
  void AddUISection(UISection* section);
  // Updates all UISections
  void UpdateUI() const;
  // Renders all UISections
  void RenderUI() const;
  // Destructor
  virtual ~UserInterface();
};
}  // namespace breakout
#endif  // IDEAL_GAS_USER_INTERFACE_H
