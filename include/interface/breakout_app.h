#pragma once

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "sections/world.h"
#include "user_interface.h"

namespace breakout {
/**
 * Cinder App class
 */
class BreakoutApp : public ci::app::App {
  // Gas Container holding particle states
  static World* world_;
  // Add gas container and instructions to the UI
  void SetupContainerUI();
  // Add buttons to the UI
  void SetupButtonUI();

 public:
  // Constructor
  explicit BreakoutApp();
  // Render heartbeat method to display app state
  void draw() override;
  // Update heartbeat method to update app state by one time frame
  void update() override;
  // Method to handle the mouse click event
  void mouseDown(ci::app::MouseEvent event) override;
  // Method to handle mouse drag event
  void mouseDrag(ci::app::MouseEvent event) override;
  // Method to handle the key press event
  void keyDown(ci::app::KeyEvent event) override;
  // Method to set up user interface
  void setup() override;
};

}  // namespace breakout
