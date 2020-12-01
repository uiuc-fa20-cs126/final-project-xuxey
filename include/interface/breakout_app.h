#pragma once

#include <logic/gamemodes/game_mode.h>

#include <string>
#include <unordered_map>

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
  // Add gas container and instructions to the UI
  void SetupGameUI();
  // Add buttons to the UI
  void SetupHomePageUI();
  // Current game mode
  static GameMode* active_game_mode_;
  // Background image
  ci::gl::Texture2dRef background_;

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
  // Getter for active game mode
  static GameMode* GetActiveGameMode();
  // Destructor
  virtual ~BreakoutApp();
};

}  // namespace breakout
