#include <interface/breakout_app.h>
#include <interface/layout.h>
#include <sections/text_section.h>

namespace breakout {

using glm::dvec2;

World* BreakoutApp::world_ = nullptr;

BreakoutApp::BreakoutApp() {
  ci::app::setWindowSize(static_cast<int>(2 * Layout::kWindowHeight),
                         static_cast<int>(Layout::kWindowHeight));
}

void BreakoutApp::setup() {
  SetupContainerUI();
  SetupButtonUI();
}

void BreakoutApp::update() {
  user_interface_.UpdateUI();
}

void BreakoutApp::draw() {
  // Gray background
  ci::gl::clear(ci::Color8u(51, 51, 51));
  user_interface_.RenderUI();
}

void BreakoutApp::mouseDrag(ci::app::MouseEvent event) {
  mouseDown(event);
}

void BreakoutApp::mouseDown(ci::app::MouseEvent event) {
  user_interface_.HandleMouseClick(event.getPos());
}

void BreakoutApp::keyDown(ci::app::KeyEvent event) {
}

void BreakoutApp::SetupContainerUI() {
  glm::dvec2 midpoint(
      (Layout::container_top_right_.x - Layout::container_bottom_left_.x) / 2,
      300);
  world_ =
      new World(Layout::container_bottom_left_, Layout::container_top_right_,
                Ball(midpoint, glm::dvec2(1.0, -1.0)));
  user_interface_.AddUISection(world_);
}

void BreakoutApp::SetupButtonUI() {
}
}  // namespace breakout
