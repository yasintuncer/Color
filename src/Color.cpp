#include "Color.h"
#include "Transformation.h"
#include <cmath>
#include <algorithm>
#include <iostream>
namespace Color
{
    const Xyz REF_XYZ(95.047, 100.000, 108.883);

    template <>
    void Rgb::To(Cmyk &other)
    {
        double c, m, y;
        rgb_to_cmy(r, g, b, c, m, y);
        cmy_to_cmyk(c, m, y, other.c, other.m, other.y, other.k);
        return;
    }

    template <>
    void Rgb::To(Hsv &hsv)
    {
        rgb_to_hsv(r, g, b, hsv.h, hsv.s, hsv.v);
        return;
    }

    template <>
    void Rgb::To(Xyz &xyz)
    {
        rgb_to_xyz(r, g, b, xyz.x, xyz.y, xyz.z);
        return;
    }

    template <>
    void Rgb::To(Lab &lab)
    {
        double x, y, z;
        rgb_to_xyz(r, g, b, x, y, z);
        xyz_to_lab(x, y, z, REF_XYZ.x, REF_XYZ.y, REF_XYZ.z, lab.l, lab.a, lab.b);
        return;
    }

    template <>
    void Cmyk::To(Rgb &rgb)
    {
        double c, m, y;
        cmyk_to_cmy(this->c, this->m, this->y, this->k, c, m, y);
        std::cout << "cmylaallp: " << c << " " << m << " " << y << std::endl;

        cmy_to_rgb(c, m, y, rgb.r, rgb.g, rgb.b);
        rgb.r = std::round(rgb.r);
        rgb.g = std::round(rgb.g);
        rgb.b = std::round(rgb.b);

        return;
    }

    template <>
    void Hsv::To(Rgb &rgb)
    {
        hsv_to_rgb(this->h, this->s, this->v, rgb.r, rgb.g, rgb.b);
        rgb.r = std::round(rgb.r);
        rgb.g = std::round(rgb.g);
        rgb.b = std::round(rgb.b);

        return;
    }

    template <>
    void Xyz::To(Rgb &rgb)
    {
        xyz_to_rgb(this->x, this->y, this->z, rgb.r, rgb.g, rgb.b);
        return;
    }
    template <>
    void Xyz::To(Lab &lab)
    {
        xyz_to_lab(this->x, this->y, this->z, REF_XYZ.x, REF_XYZ.y, REF_XYZ.z, lab.l, lab.a, lab.b);
        return;
    }

    template <>
    void Lab::To(Xyz &xyz)
    {
        lab_to_xyz(this->l, this->a, this->b, REF_XYZ.x, REF_XYZ.y, REF_XYZ.z, xyz.x, xyz.y, xyz.z);
        return;
    }

    template <>
    void Lab::To(Rgb &rgb)
    {
        double x, y, z;
        lab_to_xyz(this->l, this->a, this->b, REF_XYZ.x, REF_XYZ.y, REF_XYZ.z, x, y, z);
        xyz_to_rgb(x, y, z, rgb.r, rgb.g, rgb.b);
        return;
    }

} // namespace Color
