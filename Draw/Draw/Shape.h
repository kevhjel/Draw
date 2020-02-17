#ifndef _Shape_h_
#define _Shape_h_
#include "Image.h"

class Shape
{
public:

    virtual void draw(char red, char green, char blue, Image* image) = 0;
};


class Point:public Shape
{
public:
    int x;
    int y;
    Point(int x, int y);
    Point();
    void draw(char red, char green, char blue, Image* image);
};


class Line:public Shape
{
public:
    Point point1;
    Point point2;
    int thickness;
    Line(Point point1, Point point2, int thickness);
    Line(int x1, int y1, int x2, int y2, int thickness);
    void draw(char red, char green, char blue, Image* image);
};









#endif