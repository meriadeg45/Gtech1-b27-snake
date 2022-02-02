#pragma once

class Snake {
public:
  Snake();
  ~Snake();
  Move(int dir);
  Eat();

private:
  Segment *head;
  Segment *tail;
};

class Segment {
public:
  Segment();
  ~Segment();
  
  int GetX();
  int GetY();
  void SetX(int);
  void SetY(int);

  ... GetNext();

private:
  int x, y;
  Segment *next;
}