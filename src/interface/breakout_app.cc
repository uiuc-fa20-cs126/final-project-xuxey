#include <interface/breakout_app.h>
#include <interface/layout.h>
#include <logic/gamemodes/classic_mode.h>
#include <logic/gamemodes/easy_mode.h>
#include <sections/button.h>
#include <sections/text_section.h>

using glm::dvec2;

namespace breakout {

GameMode* BreakoutApp::active_game_mode_;

BreakoutApp::BreakoutApp() {
  ci::app::setWindowSize(static_cast<int>(2 * Layout::kWindowHeight),
                         static_cast<int>(Layout::kWindowHeight));
  active_game_mode_ = new EasyMode();
}

void BreakoutApp::setup() {
  SetupGameUI();
  SetupHomePageUI();
  UserInterface::active_screen_id_ = "home_screen";
}

void BreakoutApp::update() {
  UserInterface::UpdateUI();
}

void BreakoutApp::draw() {
  // Gray background
  ci::gl::clear(ci::Color8u(51, 51, 51));
  UserInterface::RenderUI();
}

void BreakoutApp::mouseDrag(ci::app::MouseEvent event) {
  mouseDown(event);
}

void BreakoutApp::mouseDown(ci::app::MouseEvent event) {
  UserInterface::HandleMouseClick(event.getPos());
}

void BreakoutApp::keyDown(ci::app::KeyEvent event) {
  UserInterface::HandleKeyPress(event);
}

void BreakoutApp::SetupGameUI() {
  UserInterface::AddUISection(
      "world", new World(Layout::kWorldBottomLeft, Layout::kWorldTopRight));
  // Register screen on user interface
  std::vector<std::string> game_sections;
  game_sections.push_back("world");
  UserInterface::DefineScreen("game_screen", game_sections);
}

void BreakoutApp::SetupHomePageUI() {
  std::vector<std::string> home_sections;
  home_sections.push_back("start_button");
  home_sections.push_back("easy_mode_button");
  home_sections.push_back("classic_mode_button");
  home_sections.push_back("active_section_text");
  UserInterface::AddUISection(
      home_sections[0],
      new Button(
          Layout::kStartButtonBottomLeft, Layout::kStartButtonTopRight,
          []() { UserInterface::active_screen_id_ = "game_screen"; }, "Start",
          ci::Color8u(51, 51, 51)));
  UserInterface::AddUISection(
      home_sections[1],
      new Button(
          Layout::kEasyModeButtonBottomLeft, Layout::kEasyModeButtonTopRight,
          []() {
            delete active_game_mode_;
            active_game_mode_ = new EasyMode();
            UserInterface::AccessSectionById("world")->Setup();
          },
          "Easy", ci::Color8u(51, 51, 51)));
  UserInterface::AddUISection(
      home_sections[2],
      new Button(
          Layout::kClassicModeButtonBottomLeft,
          Layout::kClassicModeButtonTopRight,
          []() {
            delete active_game_mode_;
            active_game_mode_ = new ClassicMode();
            UserInterface::AccessSectionById("world")->Setup();
          },
          "Classic", ci::Color8u(51, 51, 51)));
  UserInterface::AddUISection(
      home_sections[3],
      new TextSection(
          []() { return "Selected: " + active_game_mode_->GetName(); },
          dvec2(1200, 400), ci::Color("aqua"), ci::Font("arial", 45)));
  // todo add text to Layout
  // Register home screen on user interface
  UserInterface::DefineScreen("home_screen", home_sections);
}
GameMode* BreakoutApp::GetActiveGameMode() {
  return active_game_mode_;
}

BreakoutApp::~BreakoutApp() {
  delete active_game_mode_;
}
}  // namespace breakout
