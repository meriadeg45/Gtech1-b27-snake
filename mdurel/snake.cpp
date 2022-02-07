#include <SDL2/SDL.h>
#include "snake.hpp"

#include "constants.h"

Snake::Snake()
{
  this->head = NULL;
  this->tail = NULL;

  Eat();
  printf("%d\n", head->GetX());
}

void Snake::Move(int dir)
{
  // On calcul dx, dy;
  int dx=0, dy=0;
  switch (dir)
  {
  case UP:
    dy = -1;
    break;
  case DOWN:
    dy = 1;
    break;
  case LEFT:
    dx = -1;
    break;
  case RIGHT:
    dx = 1;
    break;
  }

  // Chaque Segment passe ses coordonnées à son "this->next":
  ???

  // On calcule les nouvelles coordonnées:
  int new_x = this->head->GetX() + ??;
  int new_y = this->head->GetY() + ??????;

  // On met à jour les coordonnées de head:
  ???

}

void Snake::Eat()
{
  Segment *newHead = new Segment(10, 10);
  Segment *temp;

  if (this->head == NULL)
  {
    this->head = newHead;
    return;
  }

  temp = this->head;
  this->head = newHead;
  newHead->SetNext(temp);
}

void Snake::EatBack()
{
  Segment *newBack = new Segment(10, 10);
  Segment *temp;

  if (this->tail == NULL)
  {
    this->tail = newBack;
    return;
  }

  temp = this->tail;
  this->tail = newBack;
  newBack->SetNext(temp);
}

Segment* Snake::getHead()
{
  return head;
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

Segment *Segment::GetNext()
{
  return this->next;
}

void Segment::SetNext(Segment *next_)
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

// void code()
// {
//   Segment *seg;
//   // seg.x = 5; // Interdit
//   seg->SetCoords(5, 6); // OK
// }; 