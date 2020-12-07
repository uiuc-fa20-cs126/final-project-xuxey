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
  SetupScoreboard();
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

void BreakoutApp::mouseDown(ci::app::MouseEvent event) {
  UserInterface::HandleMouseClick(event.getPos());
}

void BreakoutApp::keyDown(ci::app::KeyEvent event) {
  UserInterface::HandleKeyPress(event);
}

void BreakoutApp::SetupGameUI() {
  std::vector<std::string> game_sections;
  game_sections.push_back("world");
  game_sections.push_back("score");
  UserInterface::AddUISection(
      game_sections[0],
      new World(Layout::kWorldBottomLeft, Layout::kWorldTopRight));
  UserInterface::AddUISection(
      game_sections[1],
      new TextSection(
          []() {
            int score = ScoreBoard::GetLatestScore();
            return (score > 0) ? "Score: " + std::to_string(score) : "";
          },
          dvec2(1200, 100), ci::Color("white"), secondary_font_));
  // Register screen on user interface
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
          dvec2(1200, 300), ci::Color("aqua"), secondary_font_));
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
  game_end_sections.push_back("game_over_text");
  game_end_sections.push_back("score_text");
  game_end_sections.push_back("home_button");
  UserInterface::AddUISection(
      game_end_sections[0], new TextSection("Game Over", dvec2(1200, 400),
                                            ci::Color("white"), primary_font_));
  UserInterface::AddUISection(
      game_end_sections[1],
      new TextSection(
          []() {
            return "Score: " + std::to_string(ScoreBoard::GetLatestScore());
          },
          dvec2(1200, 500), ci::Color("aqua"), secondary_font_));
  // todo add text to Layout
  UserInterface::AddUISection(
      game_end_sections[2],
      new Button(
          Layout::kEasyModeButtonBottomLeft, Layout::kClassicModeButtonTopRight,
          [this]() {
            UserInterface::active_screen_id_ = "home_screen";
            // Reset scoreboard
            ScoreBoard::RegisterScore(
                BreakoutApp::GetActiveGameMode()->GetName(), 0);
            SaveScoreboard();
          },
          "Back"));
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

void BreakoutApp::SetupScoreboard() {
  std::ifstream file_stream;
  std::string filename = "scores.txt";
  file_stream.open(filename);
  if (!file_stream) {
    std::ofstream output_file;
    output_file.open(filename);
  }
  ScoreBoard::InitializeScores(file_stream);
}

void BreakoutApp::SaveScoreboard() {
  std::ofstream output_file;
  // todo class member
  output_file.open("scores.txt");
  ScoreBoard::ExportScores(output_file);
  output_file.close();
}

}  // namespace breakout
