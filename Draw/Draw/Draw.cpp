#include <iostream>
#include <stdlib.h>
#include <thread>
#include "Shape.h"

using namespace std;




void main()
{
	Image image(2000, 2000);
	Line line1(50, 50, 1900, 1900, 10);
	Line line2(50, 1900, 1900, 50, 10);
	Line line3(50, 50, 1900, 50, 10);
	Line line4(50, 1900, 1900, 1900, 10);
	line1.draw(255, 0, 0, &image);
	line2.draw(255, 0, 0, &image);
	line3.draw(255, 0, 0, &image);
	line4.draw(255, 0, 0, &image);

	image.exportImage();
}



