#pragma once

class Snake
{
public:
  Snake();
  ~Snake();
  void Move(int dir);
  void Eat();
  void EatBack();

private:
  Segment *head;
  Segment *tail;
};

class Segment
{
public:
  Segment(int x, int y);
  ~Segment();

  int GetX();
  int GetY();
  void SetX(int);
  void SetY(int);

  Segment *GetNext();
  void SetNext(Segment *next);

private:
  int x, y;
  Segment *next;
};
