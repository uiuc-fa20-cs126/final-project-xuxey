#include <interface/breakout_app.h>
#include <interface/layout.h>
#include <logic/gamemodes/classic_mode.h>
#include <logic/gamemodes/easy_mode.h>
#include <logic/score_board.h>
#include <sections/button.h>
#include <sections/text_section.h>

#include <filesystem>

namespace fs = std::experimental::filesystem;
using glm::dvec2;

namespace breakout {

GameMode* BreakoutApp::active_game_mode_;
ci::Font BreakoutApp::primary_font_;
ci::Font BreakoutApp::secondary_font_;

BreakoutApp::BreakoutApp() {
  ci::app::setWindowSize(static_cast<int>(2 * Layout::kWindowHeight),
                         static_cast<int>(Layout::kWindowHeight));
  active_game_mode_ = new EasyMode();
  primary_font_ = ci::Font(ci::DataSourcePath::create(fs::path(
                               ci::app::getAssetPath("Goldman-Bold.ttf"))),
                           45);
  secondary_font_ = ci::Font(ci::DataSourcePath::create(fs::path(
                                 ci::app::getAssetPath("Kanit-Regular.ttf"))),
                             35);
}

void BreakoutApp::setup() {
  SetupGameUI();
  SetupHomePageUI();
  SetupGameEndUI();
  UserInterface::active_screen_id_ = "home_screen";
  background_ =
      ci::gl::Texture2d::create(ci::loadImage(loadAsset("background.jpg")));
  UserInterface::SetupUI();
}

void BreakoutApp::update() {
  UserInterface::UpdateUI();
}

void BreakoutApp::draw() {
  ci::gl::draw(background_, getWindowBounds());
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
          []() { UserInterface::active_screen_id_ = "game_screen"; }, "Start"));
  UserInterface::AddUISection(
      home_sections[1],
      new Button(
          Layout::kEasyModeButtonBottomLeft, Layout::kEasyModeButtonTopRight,
          []() {
            delete active_game_mode_;
            active_game_mode_ = new EasyMode();
            UserInterface::AccessSectionById("world")->Setup();
          },
          "Easy"));
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
          "Classic"));
  UserInterface::AddUISection(
      home_sections[3],
      new TextSection(
          []() { return "Selected: " + active_game_mode_->GetName(); },
          dvec2(1200, 400), ci::Color("aqua"), secondary_font_));
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
void BreakoutApp::SetupGameEndUI() {
  std::vector<std::string> game_end_sections;
  game_end_sections.push_back("score_text");
  game_end_sections.push_back("home_button");
  UserInterface::AddUISection(
      game_end_sections[0],
      new TextSection(
          []() {
            return "Game Over. Score: " +
                   std::to_string(ScoreBoard::GetLatestScore());
          },
          dvec2(1200, 400), ci::Color("aqua"), primary_font_));
  // todo add text to Layout
  UserInterface::AddUISection(
      game_end_sections[1],
      new Button(
          Layout::kEasyModeButtonBottomLeft, Layout::kClassicModeButtonTopRight,
          []() { UserInterface::active_screen_id_ = "home_screen"; },
          "Go Home"));
  // todo change layout ^
  // Register screen on user interface
  UserInterface::DefineScreen("game_end_screen", game_end_sections);
}

const ci::Font& BreakoutApp::GetPrimaryFont() {
  return primary_font_;
}

const ci::Font& BreakoutApp::GetSecondaryFont() {
  return secondary_font_;
}
}  // namespace breakout
