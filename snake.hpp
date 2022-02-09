#pragma once
#include "fruit.hpp"

class Segment
{
public:
  Segment(int x, int y);
  ~Segment();

  int GetX();
  int GetY();
  void SetX(int);
  void SetY(int);
  Segment *AddSegment(Segment *tail);

  Segment *GetNext();
  void SetNext(Segment *next);

  int checkCollision(Segment *head);

private:
  int x, y;
  Segment *next;
};

class Snake
{
public:
  Snake();
  ~Snake();
  void Move(int dir);
  void Eat();
  void CheckFruit();

  int getNBApple();

  Fruit *GetFruit();
  Segment* getHead();

private:
  Segment *head;
  Segment *tail;
  Fruit *fruit;
  int appleEatten;
};