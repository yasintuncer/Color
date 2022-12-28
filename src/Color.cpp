#include "Color.h"
#include <cmath>
#include <algorithm>
namespace Color
{
    template <>
    Cmyk Rgb::To()
    {
        Cmyk cmyk;
        cmyk.c = 1.0 - r / 255.0;
        cmyk.m = 1.0 - g / 255.0;
        cmyk.y = 1.0 - b / 255.0;
        cmyk.k = std::min(cmyk.c, std::min(cmyk.m, cmyk.y));
        if (cmyk.k == 1.0)
        {
            cmyk.c = 0;
            cmyk.m = 0;
            cmyk.y = 0;
            cmyk.k = 100;
            return cmyk;
        }
        cmyk.c = ((cmyk.c - cmyk.k) / (1 - cmyk.k)) * 100;
        cmyk.m = ((cmyk.m - cmyk.k) / (1 - cmyk.k)) * 100;
        cmyk.y = ((cmyk.y - cmyk.k) / (1 - cmyk.k)) * 100;
        cmyk.k *= 100;

        return cmyk;
    }
    template <>
    Rgb Cmyk::To()
    {
        Rgb rgb;
        rgb.r = (1 - std::min(1.0, c * (1 - k) + k)) * 255;
        rgb.g = (1 - std::min(1.0, m * (1 - k) + k)) * 255;
        rgb.b = (1 - std::min(1.0, y * (1 - k) + k)) * 255;
        return rgb;
    }

    template <>
    Cmyk Cmyk::From(Rgb &other)
    {
        return other.To<Cmyk>();
    }

    template <>
    Rgb Rgb::From(Cmyk &other)
    {
        return other.To<Rgb>();
    }

    template <>
    Hsv Rgb::To()
    {
        Hsv hsv;
        double r = this->r / 255.0;
        double g = this->g / 255.0;
        double b = this->b / 255.0;
        double max = std::max(r, std::max(g, b));
        double min = std::min(r, std::min(g, b));
        double delta = max - min;
        if (delta == 0)
        {
            hsv.h = 0;
        }
        else if (max == r)
        {
            hsv.h = 60 * fmod(((g - b) / delta), 6);
        }
        else if (max == g)
        {
            hsv.h = 60 * (((b - r) / delta) + 2);
        }
        else if (max == b)
        {
            hsv.h = 60 * (((r - g) / delta) + 4);
        }
        if (hsv.h < 0)
        {
            hsv.h += 360;
        }
        if (max == 0)
        {
            hsv.s = 0;
        }
        else
        {
            hsv.s = (delta / max) * 100;
        }
        hsv.v = max * 100;
        return hsv;
    }

    template <>
    Rgb Hsv::To()
    {
        Rgb rgb;
        double c = v * s / 100;
        double x = c * (1 - std::abs(fmod(h / 60, 2) - 1));
        double m = v / 100 - c;
        double r, g, b;
        if (h >= 0 && h < 60)
        {
            r = c;
            g = x;
            b = 0;
        }
        else if (h >= 60 && h < 120)
        {
            r = x;
            g = c;
            b = 0;
        }
        else if (h >= 120 && h < 180)
        {
            r = 0;
            g = c;
            b = x;
        }
        else if (h >= 180 && h < 240)
        {
            r = 0;
            g = x;
            b = c;
        }
        else if (h >= 240 && h < 300)
        {
            r = x;
            g = 0;
            b = c;
        }
        else
        {
            r = c;
            g = 0;
            b = x;
        }
        rgb.r = (r + m) * 255;
        rgb.g = (g + m) * 255;
        rgb.b = (b + m) * 255;
        return rgb;
    }

    template <>
    Hsv Hsv::From(Rgb &other)
    {
        return other.To<Hsv>();
    }

    template <>
    Rgb Rgb::From(Hsv &other)
    {
        return other.To<Rgb>();
    }

} // namespace Color
