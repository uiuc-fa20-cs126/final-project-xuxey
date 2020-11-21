
#include <interface/user_interface.h>

namespace breakout {

std::unordered_map<std::string, UISection*> UserInterface::sections_;

void UserInterface::RenderUI() {
  for (auto pair : sections_) {
    pair.second->Render();
  }
}

void UserInterface::UpdateUI() {
  for (auto pair : sections_) {
    pair.second->Update();
  }
}

void UserInterface::AddUISection(std::string id, UISection* section) {
  sections_.insert({id, section});
}

void UserInterface::HandleMouseClick(dvec2 mouse_pos) {
  for (auto pair : sections_) {
    UISection* section = pair.second;
    // Check that mouse_pos is within section boundary
    if (mouse_pos.x > section->GetBottomLeft().x &&
        mouse_pos.x < section->GetTopRight().x &&
        mouse_pos.y > section->GetTopRight().y &&
        mouse_pos.y < section->GetBottomLeft().y) {
      dvec2 relative_pos(mouse_pos.x - section->GetBottomLeft().x,
                         mouse_pos.y - section->GetTopRight().y);
      section->OnClick(relative_pos);
    }
  }
}

UserInterface::~UserInterface() {
  for (auto pair : sections_) {
    delete pair.second;
  }
  sections_.clear();
}

void UserInterface::HandleKeyPress(ci::app::KeyEvent event) {
  for (auto pair : sections_) {
    pair.second->OnKeyPress(event);
  }
}
}  // namespace breakout