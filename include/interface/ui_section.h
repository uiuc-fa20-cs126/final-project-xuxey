//
// Created by soham on 11/8/2020.
//

#ifndef IDEAL_GAS_UI_SECTION_H
#define IDEAL_GAS_UI_SECTION_H

#include <cinder/app/KeyEvent.h>
#include <cinder/app/MouseEvent.h>

#include <glm/vec2.hpp>

namespace breakout {
using glm::dvec2;
/**
 * Abstract class used to implement a section of the UI
 */
class UISection {
 protected:
  dvec2 top_right_;
  dvec2 bottom_left_;
  bool update_when_inactive = false;

 public:
  /**
   * Render a UI Section using the cinder gl library
   * Important: Rendering requires actual positions, relative positions will
   * cause improper rendering.
   * @see UISection#GetActualPos(glm::dvec2 relative_pos)
   */
  virtual void Render() const = 0;
  // Used to update the state of this UI Section
  virtual void Update() = 0;
  /**
   * Used to handle primary mouse click events
   * @param relative_pos relative position within this section
   * Relative position origin is at bottom left corner.
   */
  virtual void OnClick(glm::dvec2 relative_pos){};
  // Used to handle key presses
  virtual void OnKeyPress(ci::app::KeyEvent event){};
  // Used to set up section members
  virtual void Setup(){};
  /**
   * Helper function to convert relative position to global app position
   * @param relative_pos relative position within UI, origin at bottom left
   * @return Actual position within the App
   */
  dvec2 GetActualPos(dvec2 relative_pos) const;
  // Getter for top_right_ position
  const dvec2& GetTopRight() const;
  // Getter for bottom_left_ position
  const dvec2& GetBottomLeft() const;
  // Getter for update_when_inactive
  bool ShouldUpdateWhenInactive() const;
  // Returns true if the given position is within the section
  bool IsPositionWithin(dvec2 position);
  // Converts global position to relative position within section
  dvec2 ToRelativePos(dvec2 actual_position);
  // Virtual destructor
  virtual ~UISection(){};
};
}  // namespace breakout

#endif  // IDEAL_GAS_UI_SECTION_H
