#pragma once

class Pixel
{
public:
    unsigned char red;
    unsigned char green;
    unsigned char blue;

};

class Image
{
public:
    Pixel* pixelBuffer;
    int width;
    int height;
    Image(int width, int height);
    void exportImage();
};