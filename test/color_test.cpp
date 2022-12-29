#include "../src/Color.h"
#include <iostream>

int main()
{
    Color::Rgb rgb(255, 255, 255);
    Color::Cmyk cmyk;
    rgb.To(cmyk);
    std::cout << "cmyk: " << cmyk.c << ", " << cmyk.m << ", " << cmyk.y << ", " << cmyk.k << std::endl;
    Color::Rgb rgb2; 
    cmyk.To(rgb2);
    std::cout << "rgb: " << rgb2.r << ", " << rgb2.g << ", " << rgb2.b << std::endl;

    Color::Hsv hsv(0, 82,98);

    Color::Rgb rgb3;
    hsv.To(rgb3);
    std::cout << "rgb: " << rgb3.r << ", " << rgb3.g << ", " << rgb3.b << std::endl;

    Color::Hsv hsv2;
    rgb3.To(hsv2);
    std::cout << "hsv: " << hsv2.h << ", " << hsv2.s << ", " << hsv2.v << std::endl;


    Color::Xyz xyz(49.37, 100.00, 25.38);

    Color::Rgb rgb4;
    xyz.To(rgb4);
    std::cout << "rgb: " << rgb4.r << ", " << rgb4.g << ", " << rgb4.b << std::endl;

    Color::Lab lab;
    rgb4.To(lab);
    std::cout << "lab: " << lab.l << ", " << lab.a << ", " << lab.b << std::endl;
    xyz.To(lab);
    std::cout << "lab: " << lab.l << ", " << lab.a << ", " << lab.b << std::endl;
    return 0;
}