#include <iostream>
#include <stdlib.h>
using namespace std;
#include "Shape.h"






//---------------------------------------------------------------- Shape Code ------------------------------------------------------------------------




//---------------------------------------------------------------- Point Code ------------------------------------------------------------------------


Point::Point(int x, int y)
{
    this->x = x;
    this->y = y;
}

Point::Point()
{
    x = 0;
    y = 0;
}

void Point::draw(char red, char green, char blue, Image* image)
{

}


//---------------------------------------------------------------- Line Code ------------------------------------------------------------------------


Line::Line(Point p1, Point p2, int thickness)
{
    point1 = p1;
    point2 = p2;
    this->thickness = thickness;

}

Line::Line(int x1, int y1, int x2, int y2, int thickness)
{
    point1 = Point(x1, y1);
    point2 = Point(x2, y2);
    this->thickness = thickness;

}

void Line::draw(char red, char green, char blue, Image* image)
{
    int x, y, dx, dy, dx1, dy1, px, py, xe, ye, i;
    dx = point2.x - point1.x;
    dy = point2.y - point1.y;
    dx1 = fabs(dx);
    dy1 = fabs(dy);
    px = 2 * dy1 - dx1;
    py = 2 * dx1 - dy1;


    Pixel p = { red, green, blue };

    if (dy1 <= dx1)
    {
        if (dx >= 0)
        {
            x = point1.x;
            y = point1.y;
            xe = point2.x;
        }
        else
        {
            x = point2.x;
            y = point2.y;
            xe = point1.x;
        }
        image->pixelBuffer[(image->height - 1 - y) * image->width + x] = p;
        for (i = 0; x < xe; i++)
        {
            x = x + 1;
            if (px < 0)
            {
                px = px + 2 * dy1;
            }
            else
            {
                if ((dx < 0 && dy < 0) || (dx > 0 && dy > 0))
                {
                    y = y + 1;
                }
                else
                {
                    y = y - 1;
                }
                px = px + 2 * (dy1 - dx1);
            }

            image->pixelBuffer[(image->height - 1 - y) * image->width + x] = p;
        }
    }
    else
    {
        if (dy >= 0)
        {
            x = point1.x;
            y = point1.y;
            ye = point2.y;
        }
        else
        {
            x = point2.x;
            y = point2.y;
            ye = point1.y;
        }
        image->pixelBuffer[(image->height - 1 - y) * image->width + x] = p;
        for (i = 0; y < ye; i++)
        {
            y = y + 1;
            if (py <= 0)
            {
                py = py + 2 * dx1;
            }
            else
            {
                if ((dx < 0 && dy < 0) || (dx > 0 && dy > 0))
                {
                    x = x + 1;
                }
                else
                {
                    x = x - 1;
                }
                py = py + 2 * (dx1 - dy1);
            }
            
            image->pixelBuffer[(image->height - 1 - y) * image->width + x] = p;
        }
    }

}