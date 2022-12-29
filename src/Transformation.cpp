#include "Transformation.h"
#include <cmath>
#include <algorithm>
#include <iostream>
namespace Color
{
    void rgb_to_cmy(double r, double g, double b, double &c, double &m, double &y)
    {
        c = (1.0 - r / 255.0) * 100;
        m = (1.0 - g / 255.0) * 100;
        y = (1.0 - b / 255.0) * 100;
    }

    void rgb_to_hsv(double r, double g, double b, double &h, double &s, double &v)
    {

        double cmax = std::max(std::max(r, g), b);
        double cmin = std::min(std::min(r, g), b);
        double delta = cmax - cmin;

        v = std::floor((cmax / 255.0) * 100);
        if (cmax != 0.0)
        {
            s = std::floor((delta / cmax) * 100);
        }
        else
        {
            // r = g = b = 0
            s = 0;
            h = -1;
            return;
        }

        if (r == cmax)
        {
            h = std::floor((g - b) / delta);
        }
        else if (g == cmax)
        {
            h = std::floor(2 + (b - r) / delta);
        }
        else
        {
            h = std::floor(4 + (r - g) / delta);
        }
        h *= 60;
        if (h < 0)
        {
            h += 360;
        }
    }

    void rgb_to_xyz(double r, double g, double b, double &x, double &y, double &z)
    {
        // RGB değerlerini [0, 1] aralığında bir sayıya dönüştürün
        double r_ = r / 255.0;
        double g_ = g / 255.0;
        double b_ = b / 255.0;

        // XYZ değerlerini hesaplayın
        x = 0.412453f * r_ + 0.357580f * g_ + 0.180423f * b_;
        y = 0.212671f * r_ + 0.715160f * g_ + 0.072169f * b_;
        z = 0.019334f * r_ + 0.119193f * g_ + 0.950227f * b_;
    }

    void cmy_to_rgb(double c, double m, double y, double &r, double &g, double &b)
    {
        r = (1.0 - c / 100) * 255;
        g = (1.0 - m / 100) * 255;
        b = (1.0 - y / 100) * 255;
    }

    void hsv_to_rgb(double h, double s, double v, double &r, double &g, double &b)
    {
        if (h > 360 || s > 100 || v > 100)
        {
            std::cout << "Hata: HSV değerleri 0-360, 0-100 aralığında olmalıdır." << std::endl;
            return;
        }

        int i;
        double f, p, q, t;
        if (s == 0)
        {
            // achromatic (grey)
            r = g = b = static_cast<int>(v * 255);
            return;
        }
        h /= 60; // sector 0 to 5
        s = s / 100;
        v = v / 100;
        i = static_cast<int>(floor(h));
        f = h - i; // factorial part of h
        p = v * (1 - s);
        q = v * (1 - s * f);
        t = v * (1 - s * (1 - f));
        switch (i)
        {
        case 0:
            r = v * 255;
            g = t * 255;
            b = p * 255;
            break;
        case 1:
            r = q * 255;
            g = v * 255;
            b = p * 255;
            break;
        case 2:
            r = p * 255;
            g = v * 255;
            b = t * 255;
            break;
        case 3:
            r = p * 255;
            g = q * 255;
            b = v * 255;
            break;
        case 4:
            r = t * 255;
            g = p * 255;
            b = v * 255;
            break;
        default: // case 5:
            r = v * 255;
            g = p * 255;
            b = q * 255;
            break;
        }
    }

    void xyz_to_rgb(double x, double y, double z, double &r, double &g, double &b)
    {
        // XYZ değerlerini [0, 1] aralığında bir sayıya dönüştürün
        double x_ = x / 100;
        double y_ = y / 100;
        double z_ = z / 100;

        // RGB değerlerini hesaplayın
        r = 3.24045420 * x_ - 1.5371385 * y_ - 0.4985314 * z_;
        g = -0.969266 * x_ + 1.8760108 * y_ + 0.0415560 * z_;
        b = 0.0556434 * x_ - 0.2040259 * y_ + 1.0572252 * z_;

        r = ((r > 0.0031308) ? (1.055 * std::pow(r, 1 / 2.4) - 0.055) : (12.92 * r)) * (255.0);
        g = ((g > 0.0031308) ? (1.055 * std::pow(g, 1 / 2.4) - 0.055) : (12.92 * g)) * (255.0);
        b = ((b > 0.0031308) ? (1.055 * std::pow(b, 1 / 2.4) - 0.055) : (12.92 * b)) * (255.0);
    }

    void cmyk_to_cmy(double c, double m, double y, double k, double &c_, double &m_, double &y_)
    {
        c_ = (c * (1 - k) + k);
        m_ = (m * (1 - k) + k);
        y_ = (y * (1 - k) + k);
    }

    void cmy_to_cmyk(double c, double m, double y, double &c_, double &m_, double &y_, double &k)
    {
        double min = c < m ? (c < y ? c : y) : (m < y ? m : y);
        k = min;
        c_ = (c - min);
        m_ = (m - min);
        y_ = (y - min);
    }

    void lab_to_xyz(double l, double a, double b, double ref_x, double ref_y, double ref_z, double &x, double &y, double &z)
    {
        y = (l + 16) / 116.0;
        x = a / 500.0 + y;
        z = y - b / 200.0;

        if (std::pow(y, 3) > 0.008856)
        {
            y = std::pow(y, 3);
        }
        else
        {
            y = (y - 16 / 116.0) / 7.787;
        }
        if (std::pow(x, 3) > 0.008856)
        {
            x = std::pow(x, 3);
        }
        else
        {
            x = (x - 16 / 116.0) / 7.787;
        }
        if (std::pow(z, 3) > 0.008856)
        {
            z = std::pow(z, 3);
        }
        else
        {
            z = (z - 16 / 116.0) / 7.787;
        }

        x = ref_x * x;
        y = ref_y * y;
        z = ref_z * z;
    }

    void xyz_to_lab(double x, double y, double z, double ref_x, double ref_y, double ref_z, double &l, double &a, double &b)
    {
        x = x / ref_x;
        y = y / ref_y;
        z = z / ref_z;

        if (x > 0.008856)
        {
            x = std::pow(x, 1 / 3.0);
        }
        else
        {
            x = (7.787 * x) + (16 / 116.0);
        }
        if (y > 0.008856)
        {
            y = std::pow(y, 1 / 3.0);
        }
        else
        {
            y = (7.787 * y) + (16 / 116.0);
        }
        if (z > 0.008856)
        {
            z = std::pow(z, 1 / 3.0);
        }
        else
        {
            z = (7.787 * z) + (16 / 116.0);
        }

        l = (116 * y) - 16;
        a = 500 * (x - y);
        b = 200 * (y - z);
    }

} // namespace Color
