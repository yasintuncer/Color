#ifndef COLOR_H
#define COLOR_H
namespace Color
{

    typedef struct Rgb
    {
        double r;
        double g;
        double b;
        Rgb() { r = 0, g = 0, b = 0; }
        Rgb(double r_, double g_, double b_) { r = r_, g = g_, b = b_; }
        ~Rgb() {}
        Rgb &operator=(Rgb &other)
        {
            r = other.r;
            g = other.g;
            b = other.b;
            return *this;
        }
        template <typename TColor>
        void To(TColor &other);

    } Rgb;

    typedef struct Cmyk
    {
        double c;
        double m;
        double y;
        double k;
        Cmyk() { c = 0, m = 0, y = 0, k = 0; }
        Cmyk(double c_, double m_, double y_, double k_) { c = c_, m = m_, y = y_, k = k_; }
        ~Cmyk() {}
        Cmyk &operator=(Cmyk &other)
        {
            c = other.c;
            m = other.m;
            y = other.y;
            k = other.k;
            return *this;
        }
        template <typename TColor>
        void To(TColor &other);

        void ToRgb(Rgb &rgb);

    } Cmyk;

    typedef struct Hsv
    {
        double h;
        double s;
        double v;
        Hsv() { h = 0, s = 0, v = 0; }
        Hsv(double h_, double s_, double v_) { h = h_, s = s_, v = v_; }
        ~Hsv() {}
        Hsv &operator=(Hsv &other)
        {
            h = other.h;
            s = other.s;
            v = other.v;
            return *this;
        }

        template <typename TColor>
        void To(TColor &other);

        void ToRgb(Rgb &rgb);

    } Hsv;

    typedef struct Lab
    {
        double l;
        double a;
        double b;
        double ref_x;
        double ref_y;
        double ref_z;
        Lab() { l = 0, a = 0, b = 0;}
        Lab(double l_, double a_, double b_) { l = l_, a = a_, b = b_; }
        ~Lab() {}
        Lab &operator=(Lab &other)
        {
            l = other.l;
            a = other.a;
            b = other.b;
            return *this;
        }
        template <typename TColor>
        void To(TColor &other);
        void ToRgb(Rgb &rgb);

    } Lab;

    struct Xyz
    {
        double x;
        double y;
        double z;
        double kappa;
        double epsilon;
        double whitePoint[3];
        Xyz() { x = 0, y = 0, z = 0; }
        Xyz(double x_, double y_, double z_) { x = x_, y = y_, z = z_; }
        ~Xyz() {}
        Xyz &operator=(Xyz &other)
        {
            x = other.x;
            y = other.y;
            z = other.z;
            return *this;
        }
        template <typename TColor>
        void To(TColor &other);
        void ToRgb(Rgb &rgb);
    };

}
#endif // COLOR_H
