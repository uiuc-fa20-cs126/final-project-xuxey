//
// Created by soham on 11/17/2020.
//

#ifndef FINAL_PROJECT_BALL_H
#define FINAL_PROJECT_BALL_H

#include <cinder/Color.h>

#include <glm/glm.hpp>
namespace breakout {
class Ball {
  /**
   * Position of the particle in 2D space.
   * Origin at bottom left
   */
  glm::dvec2 position_;
  /**
   * Velocity of the particle in 2D space.
   * Origin at top left
   */
  glm::dvec2 velocity_;
  // Color of the particle as displayed in the GUI
  const static ci::Color color_;
  // Radius of the circular particle in pixels
  const double radius_ = 30;

 public:
  Ball(const glm::dvec2& position, const glm::dvec2& velocity);
  // Const-reference Getter for particle position
  const glm::dvec2& GetPos() const;
  // Const-reference Getter for particle velocity
  const glm::dvec2& GetVelocity() const;
  /**
   * Updates the particle position by one time frame
   */
  void UpdateNextPosition();
  // Negates the X component of the particle velocity
  void InvertXVelocity();
  // Negates the Y component of the particle velocity
  void InvertYVelocity();
  // Gets the predicted position of the particle in the next time frame
  const glm::dvec2 GetNextPosition() const;
  // Getter for particle color
  const cinder::Color& GetColor() const;
  // Getter for particle radius
  double GetRadius() const;
  // Copy Constructor
  Ball(const Ball& source);
};
}  // namespace breakout

#endif  // FINAL_PROJECT_BALL_H
