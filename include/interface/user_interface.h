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
  static string active_screen_id_;
  static unordered_map<string, UISection*> sections_;
  static unordered_map<string, std::vector<string>> screens_;

 public:
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
  /**
   * Adds a screen to the user interface.
   * @param id screen id, must be unique. Non unique id will overwrite the
   * previous screen.
   * @param section_ids A list of section ids that are rendered when screen is
   * active
   */
  void DefineScreen(string id, vector<string> section_ids);
  /**
   * Removes a screen from available screen types.
   * Does nothing if the screen to remove is the active screen, or if the screen
   * with the given id does not exist
   * @param id id of the screen to remove
   */
  void UndefineScreen(string id);
  // Destructor
  virtual ~UserInterface();
};
}  // namespace breakout
#endif  // IDEAL_GAS_USER_INTERFACE_H
