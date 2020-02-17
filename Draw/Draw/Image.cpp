#include <iostream>
#include <stdlib.h>
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"
using namespace std;
#include "Image.h"

Image::Image(int width, int height)
{
	this->width = width;
	this->height = height;
	pixelBuffer = (Pixel*)malloc(width * height * 3);
}

void Image::exportImage()
{
	stbi_write_png("Image.jpg", width, height, 3, pixelBuffer, 3 * width);
}
