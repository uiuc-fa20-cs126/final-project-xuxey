
#include <interface/user_interface.h>
using std::count;
using std::string;
using std::unordered_map;
using std::vector;

namespace breakout {
string UserInterface::active_screen_id_;
unordered_map<string, std::vector<string>> UserInterface::screens_;
unordered_map<string, UISection*> UserInterface::sections_;

void UserInterface::RenderUI() {
  if (screens_.empty()) {
    for (auto pair : sections_) {
      pair.second->Render();
    }
    return;
  }
  vector<string> active_screen = screens_.at(active_screen_id_);
  for (auto pair : sections_) {
    if (count(active_screen.begin(), active_screen.end(), pair.first) == 1) {
      pair.second->Render();
    }
  }
}

void UserInterface::UpdateUI() {
  if (screens_.empty()) {
    for (auto pair : sections_) {
      pair.second->Update();
    }
    return;
  }
  vector<string> active_screen = screens_.at(active_screen_id_);
  for (auto pair : sections_) {
    if (count(active_screen.begin(), active_screen.end(), pair.first) > 0 ||
        pair.second->ShouldUpdateWhenInactive()) {
      pair.second->Update();
    }
  }
}

void UserInterface::AddUISection(std::string id, UISection* section) {
  sections_.insert({id, section});
}

void UserInterface::HandleMouseClick(dvec2 mouse_pos) {
  if (screens_.empty()) {
    for (auto pair : sections_) {
      if (pair.second->IsPositionWithin(mouse_pos)) {
        pair.second->OnClick(pair.second->ToRelativePos(mouse_pos));
      }
    }
    return;
  }
  vector<string> active_screen = screens_.at(active_screen_id_);
  for (auto pair : sections_) {
    if (count(active_screen.begin(), active_screen.end(), pair.first) > 0) {
      if (pair.second->IsPositionWithin(mouse_pos)) {
        pair.second->OnClick(pair.second->ToRelativePos(mouse_pos));
      }
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
  if (screens_.empty()) {
    for (auto pair : sections_) {
      pair.second->OnKeyPress(event);
    }
    return;
  }
  vector<string> active_screen = screens_.at(active_screen_id_);
  for (auto pair : sections_) {
    if (count(active_screen.begin(), active_screen.end(), pair.first) > 0 ||
        pair.second->ShouldUpdateWhenInactive()) {
      pair.second->OnKeyPress(event);
    }
  }
}

void UserInterface::DefineScreen(string id, vector<string> section_ids) {
  screens_.insert({id, section_ids});
}

UISection* UserInterface::AccessSectionById(string id) {
  return sections_.at(id);
}
void UserInterface::SetupUI() {
  for (auto pair : sections_) {
    pair.second->Setup();
  }
}
}  // namespace breakout