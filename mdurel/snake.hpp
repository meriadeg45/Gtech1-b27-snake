#pragma once

class Snake {
public:
  Snake();
  ~Snake();
  Move(int dir);
  Eat();
  EatBack();

private:
  Segment *head;
  Segment *tail;
};

class Segment {
public:
  Segment(int x_, int y_);
  ~Segment();
  
  int GetX();
  int GetY();
  void SetX(int);
  void SetY(int);

  Segment GetNext();
  void SetNext(Segment next_);

private:
  int x, y;
  Segment *next;
}