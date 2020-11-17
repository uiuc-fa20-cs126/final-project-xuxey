
#include <interface/user_interface.h>

namespace breakout {

void UserInterface::RenderUI() const {
  for (const UISection* section : sections_) {
    section->Render();
  }
}

void UserInterface::UpdateUI() const {
  for (UISection* section : sections_) {
    section->Update();
  }
}

void UserInterface::AddUISection(UISection* section) {
  sections_.push_back(section);
}

void UserInterface::HandleMouseClick(dvec2 mouse_pos) const {
  for (UISection* section : sections_) {
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
  for (UISection* section : sections_) {
    delete section;
  }
  sections_.clear();
}
}  // namespace breakout