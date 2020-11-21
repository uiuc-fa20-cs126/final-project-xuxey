#include <interface/breakout_app.h>
#include <interface/layout.h>
#include <sections/button.h>
#include <sections/text_section.h>

namespace breakout {

using glm::dvec2;

World* BreakoutApp::world_ = nullptr;

BreakoutApp::BreakoutApp() {
  ci::app::setWindowSize(static_cast<int>(2 * Layout::kWindowHeight),
                         static_cast<int>(Layout::kWindowHeight));
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
      "classic_world",
      new World(Layout::kWorldBottomLeft, Layout::kWorldTopRight));
  // Register screen on user interface
  std::vector<std::string> game_sections;
  game_sections.push_back("classic_world");
  UserInterface::DefineScreen("game_screen", game_sections);
}

void BreakoutApp::SetupHomePageUI() {
  std::vector<std::string> home_sections;
  home_sections.push_back("press_button");
  home_sections.push_back("button");
  UserInterface::AddUISection(
      home_sections[0],
      new TextSection("Press the button to start", Layout::kStartTextCenter,
                      ci::Color("white"), ci::Font("arial", 35)));
  UserInterface::AddUISection(
      home_sections[1],
      new Button(
          Layout::kStartButtonBottomLeft, Layout::kStartButtonTopRight,
          []() { UserInterface::active_screen_id_ = "game_screen"; }, "Start"));
  // Register home screen on user interface
  UserInterface::DefineScreen("home_screen", home_sections);
}
}  // namespace breakout
