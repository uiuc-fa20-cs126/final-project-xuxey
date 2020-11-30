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

using std::string;
using std::unordered_map;
using std::vector;

namespace breakout {
using glm::dvec2;
/**
 * User interface class to handle UISection implementations
 */
class UserInterface {
  static unordered_map<string, UISection*> sections_;
  static unordered_map<string, std::vector<string>> screens_;

 public:
  static string active_screen_id_;
  /**
   * Calls the appropriate onClick method based on the UISection region that has
   * been clicked
   * @param mouse_pos position of the mouse in the app, origin top left
   */
  static void HandleMouseClick(dvec2 mouse_pos);
  // Adds a new UISection to the interface
  static void AddUISection(string id, UISection* section);
  // Updates all UISections
  static void UpdateUI();
  // Renders all UISections
  static void RenderUI();
  // Handles Key Presses
  static void HandleKeyPress(ci::app::KeyEvent event);
  // Initialize sections on setup
  static void SetupUI();
  static void DefineScreen(string id, vector<string> section_ids);
  static UISection* AccessSectionById(string id);
  // Destructor
  virtual ~UserInterface();
};
}  // namespace breakout
#endif  // IDEAL_GAS_USER_INTERFACE_H
