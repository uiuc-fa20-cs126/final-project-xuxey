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
  // Set up world and associated sections
  void SetupGameUI();
  // Set up homepage sections
  void SetupHomePageUI();
  // Set up game over screen
  void SetupGameEndUI();
  // Current game mode
  static GameMode* active_game_mode_;
  // Background image
  ci::gl::Texture2dRef background_;
  // Game Fonts
  static ci::Font primary_font_;
  static ci::Font secondary_font_;
  // Scores file name
  const std::string kScoresFileName = "scores.txt";

 public:
  // Constructor
  explicit BreakoutApp();
  // Render heartbeat method to display app state
  void draw() override;
  // Update heartbeat method to update app state by one time frame
  void update() override;
  // Method to handle the mouse click event
  void mouseDown(ci::app::MouseEvent event) override;
  // Method to handle the key press event
  void keyDown(ci::app::KeyEvent event) override;
  // Method to set up user interface
  void setup() override;
  // Getter for active game mode
  static GameMode* GetActiveGameMode();
  // Font Getters
  static const ci::Font& GetPrimaryFont();
  static const ci::Font& GetSecondaryFont();
  // Destructor
  virtual ~BreakoutApp();
  void SetupScoreboard();
  void SaveScoreboard();
};

}  // namespace breakout
