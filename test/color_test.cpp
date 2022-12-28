#include "../src/Color.h"
#include <iostream>

int main()
{
    Color::Rgb rgb(255, 255, 255);
    Color::Cmyk cmyk = rgb.To<Color::Cmyk>();
    std::cout << "cmyk: " << cmyk.c << ", " << cmyk.m << ", " << cmyk.y << ", " << cmyk.k << std::endl;
    Color::Rgb rgb2 = cmyk.To<Color::Rgb>();
    std::cout << "rgb: " << rgb2.r << ", " << rgb2.g << ", " << rgb2.b << std::endl;
    return 0;
}