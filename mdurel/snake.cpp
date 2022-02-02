#include <SDL2/SDL.h>
#include "snake.hpp"

Snake::Move(int dir)
{
}

Snake::Eat()
{
  Segment newHead = new Segment(10, 10);
  Segment temp;

  if (this->head == NULL)
  {
    this->head = newHead;
    return;
  }

  temp = this->head;
  this->head = newHead;
  newHead.SetNext(temp);
}

Snake::EatBack()
{
  
}

Segment::Segment(int x_, int y_)
{
  this->SetX(x_);
  this->SetY(y_);
  this->next = NULL;
}

Segment::~Segment()
{
}

int Segment::GetX()
{
  return this->x;
}

int Segment::GetY()
{
  return this->y;
}

Segment Segment::GetNext()
{
  return this->next;
}

void Segment::SetNext(Segment next_)
{
  this->next = next_;
}

void Segment::SetX(int x_)
{
  this->x = x_;
}

void Segment::SetY(int y_)
{
  this->y = y_;
}

void code()
{
  Segment seg;
  // seg.x = 5; // Interdit
  seg.SetCoords(5, 6); // OK
}