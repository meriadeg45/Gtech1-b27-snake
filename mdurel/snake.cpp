#include <SDL2/SDL.h>
#include "snake.hpp"

#include "constants.h"

Snake::Snake()
{
  this->head = NULL;
  this->tail = NULL;

  head = new Segment(10, 10);
  tail = head;
  fruit = new Fruit();
  printf("%d\n", head->GetX());
}

Snake::~Snake()
{
  delete this->head;
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
  Segment* s = this->head;
  int x = s->GetX(), y = s->GetY();
  while (s->GetNext())
  {
    int xnext = s->GetNext()->GetX();
    int ynext = s->GetNext()->GetY();

    s->GetNext()->SetX(x);
    s->GetNext()->SetY(y);

    x = xnext;
    y = ynext;

    s = s->GetNext();
  }

  // On calcule les nouvelles coordonnées:
  int new_x = this->head->GetX() + dx;
  int new_y = this->head->GetY() + dy;

  // On met à jour les coordonnées de head:
  this->head->SetX(new_x);
  this->head->SetY(new_y);
}

void Snake::CheckFruit(){
    printf("Head: %d, %d\n", head->GetX(), head->GetY());
    printf("Fruit: %d, %d\n", fruit->getX(), fruit->getY());

   if (head->GetX() == fruit->getX() && head->GetY() == fruit->getY()){
      printf("Detct fruit\n");
      Eat();
      fruit->setRandomCoord();
   }
}

void Snake::Eat()
{
  
  tail=tail->AddSegment(tail);

}

Fruit *Snake::GetFruit(){return fruit;}

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
  if (next)
    delete this->next;
}

Segment *Segment::AddSegment(Segment *tail){
  Segment *temp = new Segment(tail->GetX()-32, tail->GetY()-32);
  tail->SetNext(temp);
  tail = temp;

  return tail;
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