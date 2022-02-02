#include <SDL2/SDL.h>
#include "snake.hpp"




Segment::Segment() {
}

Segment::~Segment() {
}

int Segment::GetX() {
  
}

int Segment::GetY() {
  
}

void Segment::SetX(int x_) {
  this->x = x_;
}

void Segment::SetY(int y_) {
  this->y = y_;
}

void code() {
  Segment seg;
  // seg.x = 5; // Interdit
  seg.SetCoords(5, 6); // OK
}